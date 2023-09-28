import heapq
def astar(start,goal,graph,heuristic):
    opened=[]
    heapq.heappush(opened, (0, start))
    nodefrom={}
    cost_till={}
    nodefrom[start]=None
    cost_till[start]=0
    while opened:
        current=heapq.heappop(opened)[1]
        print(nodefrom[current],'->',current)
        if current==goal:
            print(cost_till[goal])
            return
        for neighbour in graph[current]:
            new_cost=cost_till[current]+graph[current][neighbour]
            if neighbour not in cost_till or cost_till[neighbour]>new_cost:
                cost_till[neighbour]=new_cost
                nodefrom[neighbour]=current
                heapq.heappush(opened,(heuristic[neighbour]+new_cost,neighbour))

heuristic={
    's':14,
    'b':12,
    'c':11,
    'd':6,
    'e':4,
    'f':11,
    'g':0
}
graph={
    's':{'b':4,'c':3},
    'b':{'f':5,'e':12},
    'c':{'e':10,'d':7},
    'd':{'e':2},
    'e':{'g':5},
    'f':{'g':16}
}

astar('s','g',graph,heuristic)