# Busca em largura

import queue


def bfs(grafo, vertice_fonte):
    queue
    visitados, fila = set(), [vertice_fonte]
    while fila:
        vertice = queue.pop(0)
        if vertice not in visitados:
            visitados.add(vertice)
            fila.extend(grafo[vertice] - visitados)
    return visitados
# Busca em Profundidade

def dfs(grafo):
    def dfs_recursiva(grafo, vertice):
        visitados.add(vertice)
        for vizinho in grafo[vertice]:
            if vizinho not in visitados:
                dfs_recursiva(grafo, vizinho)

    visitados = set()
    for vertice in grafo:
        if not vertice in visitados:
            dfs_recursiva(grafo, vertice)