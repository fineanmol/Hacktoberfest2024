import re  # import reges module

string = "sixteen:16 Eighty three:83."
pattern = "\d+"

def split_string(pattern, string)
    result = re.split(pattern, string)
    return result

print(split_string(pattern, string))

# Output: ['sixteen:', ' Eighty three:', '.']
