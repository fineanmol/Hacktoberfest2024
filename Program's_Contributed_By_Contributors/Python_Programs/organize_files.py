import os
import shutil

def organize_files(source_dir, target_dir):
    for filename in os.listdir(source_dir):
        source_path = os.path.join(source_dir, filename)
        if os.path.isfile(source_path):
            file_extension = filename.split('.')[-1]
            target_subdir = os.path.join(target_dir, file_extension)
            os.makedirs(target_subdir, exist_ok=True)
            target_path = os.path.join(target_subdir, filename)
            shutil.move(source_path, target_path)

if __name__ == "__main__":
    source_directory = 'source_directory'
    target_directory = 'target_directory'
    organize_files(source_directory, target_directory)
