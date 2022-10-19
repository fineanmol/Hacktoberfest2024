import fnmatch
import os

rootPath = '/'
ext=input("Enter file extension (like: mp3,png,exe and txt) : ")
pattern = f'*.{ext}'

for root, dirs, files in os.walk(rootPath):
    for filename in fnmatch.filter(files, pattern):
        print( os.path.join(root, filename))
