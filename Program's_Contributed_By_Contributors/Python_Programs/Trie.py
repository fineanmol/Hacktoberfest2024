class Trie:

    def __init__(self) -> None:
        self.children = {}
        self.isTerminal = 0


def insertNode(root: Trie, word: str):

    if not word:
        root.isTerminal = 1
        return
    
    if word[0].lower() in root.children:
        child = root.children[word[0].lower()]
    else:
        child = Trie()
        root.children[word[0].lower()] = child
    
    insertNode(child, word[1:])

def printTrie(root: Trie, string:str = ""):

    for child in root.children:
        string = string + child
        if root.children[child].isTerminal:
            print(string)
        printTrie(root.children[child], string)
        string = string[:-1]

def searchWord(root: Trie, word:str):

    if not word:
        return root.isTerminal
    
    if word[0].lower() in root.children:
        return searchWord(root.children[word[0].lower()], word[1:])
    else:
        return 0

def deleteword(root: Trie, word: str):

    if not word:
        if root.isTerminal:
            root.isTerminal = 1
            return 1
        else:
            return 0
    
    if word[0].lower() in root.children:
        return deleteword(root.children[word[0].lower()], word[1:])
    else:
        return 0

def findDictionary(root: Trie, string: str, output: list, temp: str):

    if not string:
        for child in root.children:
            temp = temp + child
            if root.children[child].isTerminal:
                output.append(temp)
            
            findDictionary(root.children[child], "", output, temp)
            temp = temp[:-1]
        
        return
    
    if string[0].lower() in root.children:
        temp = temp + string[0].lower()
        if root.children[string[0].lower()].isTerminal:
            output.append(temp)
        
        findDictionary(root.children[string[0].lower()], string[1:], output, temp)


root = Trie()

insertNode(root, "coding")
insertNode(root, "code")
insertNode(root, "coder")
insertNode(root, "came")
insertNode(root, "Hacktober")
insertNode(root, "Hacking")

print("Printing Trie..........")
printTrie(root)
print("Printing Done..........\n")

print("Search word in Trie..........")
if searchWord(root, "came"):
    print("word found")
else:
    print("word not found")
print()

print("finding dictionary in Trie..........")
find = "co"

for i in range(1, len(find)+1):

    print(f"for {find[:i]} ==> ", end=" ")
    ans = []
    temp = ""
    findDictionary(root, find[:i], ans, temp)
    print(ans)
