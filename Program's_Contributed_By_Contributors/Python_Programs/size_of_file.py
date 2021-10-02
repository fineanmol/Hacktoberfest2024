import os

file_stat = os.stat('my_file.txt')

print(file_stat.st_size)
