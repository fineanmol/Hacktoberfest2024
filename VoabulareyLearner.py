# create a Vocabs.json file in the same folder and put you vocabs in like this:
#"given" : "answer",
#"another" : "pair"



import json
import random


def main():
    known = []
    while True:
        VocabChecker(known)


def VocabChecker(known):
    with open("Vocabs.json", "r") as read_file:
        json_data = json.load(read_file)
        str_data = json.dumps(json_data)
        old_data = str_data.replace("{", "")
        middle_data = old_data.replace('"', "")
        new_data = middle_data.replace("}", "")
        data = new_data.split(",")
        index = random.randrange(len(data))
        value = data[index].split(":")
        for i in known:
            if value == i:
                return
        print(value[0].replace(" ", ""))
        Eingabe = ""
        while Eingabe != value[1]:
            Eingabe = " " + input()
            if Eingabe == value[1]:
                known.append(value)
                print(known)
                continue
        print('\x1b[32m' + 'korrekt' + '\x1b[32m' + "\x1b[0m")


if __name__ == "__main__":
    main()
