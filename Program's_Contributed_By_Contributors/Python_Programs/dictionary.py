import json
import difflib
data = json.load(open("data.json"))
def get_meaning(word):
    key=word.lower()
    if key in data:
        return (data[key])
    elif key.title() in data:
        return (data[key.title()])
    elif key.upper() in data:
        return (data[key.upper()])
    elif len(difflib.get_close_matches(key,data.keys()))>1:
        match=difflib.get_close_matches(key,data.keys())[0]
        print("Do you mean? "+match)
        ans=input("press y if yes:")
        if(ans=='y'):
            return data[match]
        else:
            return 1

        
    else :
        return 1


word=input("Enter the word:")
meaning=get_meaning(word)
if meaning!=1:
    for m in meaning:
        print(m)
else:
    print("not found")