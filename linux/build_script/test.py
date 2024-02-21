import os
import sys
import git
import shutil

build_dir = 'build_dir'
supported_archs = ["esp32", "rpizerow", "wasm_emcc", "wasm_wamr"]

def get_architecture_folder(repo_url, branch, folder_path):
    git_ssh_identity_file = os.path.expanduser('~/.ssh/id_ed25519')
    git_ssh_cmd = 'ssh -i %s' % git_ssh_identity_file    

    # Clone the repository
    repo_dir = 'all_build_enviroments'
    if os.path.exists(repo_dir):
        repo = git.Repo(repo_dir)
        repo.remote().fetch()
    else:
        repo = git.Repo.clone_from(repo_url, repo_dir,env=dict(GIT_SSH_COMMAND=git_ssh_cmd))

    # Switch to the desired branch
    repo.git.checkout(branch)

    # Pull changes
    origin = repo.remotes.origin
    origin.pull()

    # Copy the folder to the destination
    source_folder_path = os.path.join(repo_dir, folder_path)
    destination_path = os.path.join(build_dir, folder_path)
    if os.path.exists(destination_path):
        print("Selected architecture build dir already exists, delete it and then run the script again")
        return
    shutil.copytree(source_folder_path, destination_path)
    print("Successfully copied selected architecture to '" + build_dir + "'")

def print_help():
    print("Usage: python test.py <architecture>")
    print("Supported architectures:")
    for arch in supported_archs:
        print(" " + arch)

def main():
    # Check if the script is called with the correct number of arguments
    if len(sys.argv) != 2:
        print_help()
        return

    # Get the string argument from the command line
    arch = sys.argv[1]

    repo_url = 'git@github.com:PetrKocian/SCGMS-Build-Environments.git'
    branch_name = 'main'

    # Print the string argument
    if arch == 'esp32':
        folder_to_pull = 'ESP32'  
        get_architecture_folder(repo_url, branch_name, folder_to_pull)
    elif arch == 'rpizerow':
        folder_to_pull = 'RpiZeroW'  
        get_architecture_folder(repo_url, branch_name, folder_to_pull)
    elif arch == 'wasm_emcc':
        folder_to_pull = 'Wasm_emcc'  
        get_architecture_folder(repo_url, branch_name, folder_to_pull)
    elif arch == 'wasm_wamr':
        folder_to_pull = 'Wasm_wamr'  
        get_architecture_folder(repo_url, branch_name, folder_to_pull)
    else:
        print_help()

if __name__ == "__main__":
    main()