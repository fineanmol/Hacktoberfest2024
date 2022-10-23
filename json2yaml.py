import json
import os
import sys
import yaml

# Checking there is a file name passed
if len(sys.argv) > 1:
    # Opening the file
    if os.path.exists(sys.argv[1]):
        source_file = open(sys.argv[1], "r")
        source_content = json.load(source_file)
        source_file.close()
    # Failikng if the file isn't found
    else:
        print("ERROR: " + sys.argv[1] + " not found")
        exit(1)
# No file, no usage
else:
    print("Usage: json2yaml.py <source_file.json> [target_file.yaml]")

# Processing the conversion
output = yaml.dump(source_content)

# If no target file send to stdout
if len(sys.argv) < 3:
    print(output)
# If the target file already exists exit
elif os.path.exists(sys.argv[2]):
    print("ERROR: " + sys.argv[2] + " already exists")
    exit(1)
# Otherwise write to the specified file
else:
    target_file = open(sys.argv[2], "w")
    target_file.write(output)
    target_file.close()
