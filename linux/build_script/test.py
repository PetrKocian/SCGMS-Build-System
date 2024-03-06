import os
import sys
import git
import shutil
import subprocess
from distutils.dir_util import copy_tree

# PATHS TO TOOLCHAINS
esp_idf_path = "~/esp/esp-idf"
wasi_path = "/opt/wasi-sdk"
emsdk_path = "~/emsdk"

# GIT SSH KEY
git_ssh_identity_file = os.path.expanduser("~/.ssh/id_ed25519")
git_ssh_cmd = "ssh -i %s" % git_ssh_identity_file    

# some useful globals
build_dir = "build_dir"
supported_archs = ["esp32", "rpizerow", "wasm_emcc", "wasm_wamr", "all"]
preprocessor = "./preprocessor"

# prints help
def print_help():
    print("Usage: python test.py <architecture>")
    print("Supported architectures:")
    for arch in supported_archs:
        print(" " + arch)

# checks if architecture is supported
def architecture_supported(input):
    for arch in supported_archs:
        if input == arch:
            return True
    return False

# clones SCGMS core and common monolith repo to temp dir
def clone_scgms():
    print("Cloning SCGMS")
    repo_url = "git@github.com:PetrKocian/SCGMS-Embedded.git"
    repo_dir = "temp/scgms"
    if os.path.exists(repo_dir):
        repo = git.Repo(repo_dir)
        repo.remote().fetch()
    else:
        repo = git.Repo.clone_from(repo_url, repo_dir)
    print("Finished\n")


# copy all files for each architecture from temp to build_dir
def copy_scgms_esp32():
    copy_tree("temp/filters", "build_dir/ESP32/components/filters") # use copy tree instead of shutil.copy_tree since the destination folder is not empty
    copy_tree("temp/scgms/sources", "build_dir/ESP32/components/scgms_embedded/sources")

def copy_scgms_rpizerow():
    shutil.copytree("temp/filters", "build_dir/RpiZeroW/sources/filters")
    shutil.copytree("temp/scgms/sources", "build_dir/RpiZeroW/sources/SmartCGMS")

def copy_scgms_wasm_emcc():
    shutil.copytree("temp/scgms/sources", "build_dir/Wasm_emcc/smartcgms_sources")
    shutil.copytree("temp/filters", "build_dir/Wasm_emcc/smartcgms_sources/filters")

def copy_scgms_wasm_wamr():
    shutil.copytree("temp/scgms/sources", "build_dir/Wasm_wamr/smartcgms_sources")
    shutil.copytree("temp/filters", "build_dir/Wasm_wamr/smartcgms_sources/filters")

# create wasi_path.cmake
def add_wasi_path():
    with open('build_dir/Wasm_wamr/wasi_path.cmake', 'w') as file:
        file.write("SET (WASI_SDK_DIR \"")
        file.write(wasi_path)
        file.write("\")")

# create emsdk source script
def add_emcc_path():
    with open('build_dir/Wasm_emcc/emcc.sh', 'w') as file:
        file.write("cd " +emsdk_path+ "\n")
        file.write("source ./emsdk_env.sh\n")
        file.write("cd -\n")
    os.chmod('build_dir/Wasm_emcc/emcc.sh', 0o755)

# create esp-idf source script
def add_esp_idf_path():
    with open('build_dir/ESP32/make.sh', 'w') as file:
        file.write("cd "+esp_idf_path+"\n")
        file.write("source ./export.sh\n")
        file.write("cd -\n")
        file.write("idf.py build\n")
    os.chmod('build_dir/ESP32/make.sh', 0o755)
    with open('build_dir/ESP32/run.sh', 'w') as file:
        file.write("cd "+esp_idf_path+"\n")
        file.write("source ./export.sh\n")
        file.write("cd -\n")
        file.write("idf.py flash monitor\n")
    os.chmod('build_dir/ESP32/run.sh', 0o755)



# fetch specified build environment folder from git remote
def get_architecture_folder(repo_url, branch, folder_path):
    print("Cloning build environment")

    # check if repo is already cloned
    repo_dir = "temp/all_build_enviroments"
    if os.path.exists(repo_dir):
        repo = git.Repo(repo_dir)
        repo.remote().fetch()
    else:
        repo = git.Repo.clone_from(repo_url, repo_dir)

    # Switch to the desired branch
    repo.git.checkout(branch)

    # Pull changes
    origin = repo.remotes.origin
    origin.pull()

    print("Finished\n")
    print("Copying " + folder_path)
    
    # Copy the folder to the destination dir
    source_folder_path = os.path.join(repo_dir, folder_path)
    destination_path = os.path.join(build_dir, folder_path)
    if os.path.exists(destination_path):
        print("Selected architecture build dir already exists (delete it and then run the script again if needed)\n")
        return
    shutil.copytree(source_folder_path, destination_path)
    print("Successfully copied selected architecture to '" + build_dir + "'\n")

def main():
    # Check if the script is called with the correct number of arguments
    if len(sys.argv) != 2:
        print_help()
        return

    # Get the string argument from the command line
    arch = sys.argv[1]

    # Check if architecture is supported
    if not architecture_supported(arch):
        print_help()
        return

    # Delete temp and build_dir - do a clean build each time
    if os.path.exists("temp"):
        shutil.rmtree("temp")
    if os.path.exists("build_dir"):
        shutil.rmtree("build_dir")

    # run preprocessor on filters
    output = subprocess.check_output(preprocessor, shell=True, stderr=subprocess.STDOUT)
    print("\nPreprocessor:")
    print(output.decode("utf-8"))

    # clone SCGMS source code
    clone_scgms()

    # repo url for environments
    repo_url = "git@github.com:PetrKocian/SCGMS-Build-Environments.git"
    branch_name = "main"

    # Prepare specified architecture (pull build env repo, copy files to build_dir, and add path script if necessary)
    if arch == "esp32":
        folder_to_pull = "ESP32"  
        get_architecture_folder(repo_url, branch_name, folder_to_pull)
        copy_scgms_esp32()
        add_esp_idf_path()
    elif arch == "rpizerow":
        folder_to_pull = "RpiZeroW"  
        get_architecture_folder(repo_url, branch_name, folder_to_pull)
        copy_scgms_rpizerow()
    elif arch == "wasm_emcc":
        folder_to_pull = "Wasm_emcc"  
        get_architecture_folder(repo_url, branch_name, folder_to_pull)
        copy_scgms_wasm_emcc()
        add_emcc_path()
    elif arch == "wasm_wamr":
        folder_to_pull = "Wasm_wamr"  
        get_architecture_folder(repo_url, branch_name, folder_to_pull)
        copy_scgms_wasm_wamr()
        add_wasi_path()
    elif arch == "all":
        folder_to_pull = "ESP32"  
        get_architecture_folder(repo_url, branch_name, folder_to_pull)
        copy_scgms_esp32()
        add_esp_idf_path()
        folder_to_pull = "RpiZeroW"  
        get_architecture_folder(repo_url, branch_name, folder_to_pull)
        copy_scgms_rpizerow()
        folder_to_pull = "Wasm_emcc"  
        get_architecture_folder(repo_url, branch_name, folder_to_pull)
        copy_scgms_wasm_emcc()
        add_emcc_path()
        folder_to_pull = "Wasm_wamr"  
        get_architecture_folder(repo_url, branch_name, folder_to_pull)
        copy_scgms_wasm_wamr()
        add_wasi_path()

if __name__ == "__main__":
    main()
