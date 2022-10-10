from zipfile import ZipFile
import os
import re

#Insert your path with zip file in it
path = input('Put your path that already has a zip file here: ')
print("")

path = re.sub(r"\\", "/", path)
n = 0

for filename in os.listdir(path):
    if filename.endswith(".zip"):
        try:
            zip = ZipFile(f"{path}/{filename}", "r")
            filename = re.sub(".zip","", filename)
            target_folder = f"{path}/{filename}"
            os.mkdir(target_folder)
            zip.extractall(target_folder)
        except FileExistsError:
            print(f"Folder with name {filename}, already exist")
            n += 1
            continue


print("===============================")
print("")
print("Extract Success")
print(f"Failed to unzip {n} file/s")
print("")
print("===============================")