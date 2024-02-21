import os
import sys
import git
import shutil
import subprocess
from distutils.dir_util import copy_tree

build_dir = "build_dir"
supported_archs = ["esp32", "rpizerow", "wasm_emcc", "wasm_wamr"]
preprocessor = "./preprocessor"

git_ssh_identity_file = os.path.expanduser("~/.ssh/id_ed25519")
git_ssh_cmd = "ssh -i %s" % git_ssh_identity_file    

def print_help():
    print("Usage: python test.py <architecture>")
    print("Supported architectures:")
    for arch in supported_archs:
        print(" " + arch)

def architecture_supported(input):
    for arch in supported_archs:
        if input == arch:
            return
    return False

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


def copy_scgms_esp32():
    copy_tree("temp/filters", "build_dir/ESP32/components/filters")
    copy_tree("temp/scgms/sources", "build_dir/ESP32/components/scgms_embedded/sources")

def copy_scgms_rpizerow():
    copy_tree("temp/filters", "build_dir/RpiZeroW/sources/filters")
    copy_tree("temp/scgms/sources", "build_dir/RpiZeroW/sources/SmartCGMS")

def copy_scgms_wasm_emcc():
    copy_tree("temp/scgms/sources", "build_dir/Wasm_emcc/sources")
    copy_tree("temp/filters", "build_dir/Wasm_emcc/sources/filters")

def copy_scgms_wasm_wamr():
    copy_tree("temp/scgms/sources", "build_dir/Wasm_wamr/sources")
    copy_tree("temp/filters", "build_dir/Wasm_wamr/sources/filters")



def get_architecture_folder(repo_url, branch, folder_path):
    print("Cloning build environment")
    # Clone the repository
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
    # Copy the folder to the destination
    source_folder_path = os.path.join(repo_dir, folder_path)
    destination_path = os.path.join(build_dir, folder_path)
    if os.path.exists(destination_path):
        print("Selected architecture build dir already exists (delete it and then run the script again if needed)")
        return
    shutil.copytree(source_folder_path, destination_path)
    print("Successfully copied selected architecture to '" + build_dir + "'")

def main():
    # Check if the script is called with the correct number of arguments
    if len(sys.argv) != 2:
        print_help()
        return

    # Get the string argument from the command line
    arch = sys.argv[1]

    if not architecture_supported(arch):
        print_help()
        return

    output = subprocess.check_output(preprocessor, shell=True, stderr=subprocess.STDOUT)
    print("\nPreprocessor:")
    print(output.decode("utf-8"))

    repo_url = "git@github.com:PetrKocian/SCGMS-Build-Environments.git"
    branch_name = "main"

    clone_scgms()

    # Print the string argument
    if arch == "esp32":
        folder_to_pull = "ESP32"  
        get_architecture_folder(repo_url, branch_name, folder_to_pull)
        copy_scgms_esp32()
    elif arch == "rpizerow":
        folder_to_pull = "RpiZeroW"  
        get_architecture_folder(repo_url, branch_name, folder_to_pull)
        copy_scgms_rpizerow()
    elif arch == "wasm_emcc":
        folder_to_pull = "Wasm_emcc"  
        get_architecture_folder(repo_url, branch_name, folder_to_pull)
        copy_scgms_wasm_emcc()
    elif arch == "wasm_wamr":
        folder_to_pull = "Wasm_wamr"  
        get_architecture_folder(repo_url, branch_name, folder_to_pull)
        copy_scgms_wasm_wamr()


if __name__ == "__main__":
    main()