# Updated code to handle multiple distinct pairs of similar files and improved logging.

import os
import hashlib
import re
import sys
import time
from typing import List, Dict

# Utility Functions
def calculate_file_hash(file_path: str, file_extension: str) -> str:
    """Compute and return the hash of a code file, ignoring comments and whitespace."""
    hasher = hashlib.md5()

    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.readlines()

    # Remove comments and whitespaces based on file extension
    if file_extension == '.py':
        content = [re.sub(r'#.*', '', line) for line in content]
    elif file_extension == '.js':
        content = [re.sub(r'//.*', '', line) for line in content]

    content = [line.strip() for line in content]
    content = ''.join(content).encode('utf-8')

    hasher.update(content)
    return hasher.hexdigest()


def get_all_files(directory_path: str, extensions: List[str]) -> List[str]:
    """Return all code file paths in the directory."""
    file_paths = []
    for root, dirs, files in os.walk(directory_path):
        for name in files:
            if any(name.endswith(ext) for ext in extensions):
                file_paths.append(os.path.join(root, name))
    return file_paths


# Core Function
def find_duplicates(directory_path: str, extensions: List[str]) -> Dict[str, List[str]]:
    """Find duplicate code files based on hash."""
    file_hashes = {}
    duplicate_files = {}

    print("Initializing scan for duplicate code files...")
    sys.stdout.flush()
    time.sleep(2)

    for file_path in get_all_files(directory_path, extensions):
        sys.stdout.write(f"\rChecking: {file_path}")
        sys.stdout.flush()

        file_extension = os.path.splitext(file_path)[1]
        file_hash = calculate_file_hash(file_path, file_extension)

        if file_hash in file_hashes:
            if file_hash in duplicate_files:
                duplicate_files[file_hash].append(file_path)
            else:
                duplicate_files[file_hash] = [file_hashes[file_hash], file_path]
        else:
            file_hashes[file_hash] = file_path

        time.sleep(0.1)

    return duplicate_files


# Main Function
if __name__ == "__main__":
    try:
        user_directory_path = input("\nEnter the directory path to find duplicate code files: ")
        confirm = input(f"You entered '{user_directory_path}'. Are you sure? (y/n): ")

        if confirm.lower() == 'y':
            user_code_extensions = ['.py', '.js']  # Supported extensions

            found_duplicates = find_duplicates(user_directory_path, user_code_extensions)

            if found_duplicates:
                print("\nDuplicate code files found:")
                for file_hash, file_paths in found_duplicates.items():
                    print(f"\nFiles with hash {file_hash} are duplicates:")
                    for path in file_paths:
                        print(f"  - {path}")
            else:
                print("\nNo duplicate code files found.")

        else:
            print("Operation cancelled.")

    except FileNotFoundError:
        print("\nDirectory not found. Please enter a valid directory.")
    except PermissionError:
        print("\nPermission denied. Please run the script as an administrator.")
    except Exception as e:
        print(f"\nAn unexpected error occurred: {e}")

    input("\nPress Enter to exit...")