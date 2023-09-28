open_list = []
closed_list = []
parent = {}

def print_path(start,goal):
    curr = parent[goal]
    print(goal)
    while curr != start:
        print(curr)
        curr = parent[curr]
    print(curr)

def dfs(g,depth,max_depth,current,goal):
    if current == goal:
        print("depth = ",depth)
        print_path("a",goal)
        return
    if depth == max_depth:
        return
    if not g.get(current):
        return
    for i in g[current]:
        if i not in closed_list:
            open_list.append(i)
            parent[i] = current            
            dfs(g,depth+1,max_depth,i,goal)
            open_list.pop()
            closed_list.append(i)



def dfid(g,max_depth,start,goal):
    for i in range(1,max_depth+1):
        global open_list
        global closed_list
        global parent
        open_list = []
        closed_list = []
        parent = {}
        open_list.append(start)
        dfs(g,1,i,start,goal)





g={
"a": ["b", "c"], "b": ["d", "e"], "c": ["f", "g"], "d": ["h", "i"],
"e": ["j", "k"],
   "f": ["l", "m"],
   "g": ["n", "z"]
}

dfid(g, 4, "a", "z")
