class Graph:
    def __init__(self, vertices):
        self.Destination = vertices
        self.edges = []
        self.component = {}
    def add_edge(self, Source, Destination, weight):
        self.edges.append([Source, Destination, weight])
    def find_component(self, Source):
        if self.component[Source] == Source:
            return Source
        return self.find_component(self.component[Source])

    def set_component(self, Source):
        if self.component[Source] == Source:
            return
        else:
            for k in self.component.keys():
                self.component[k] = self.find_component(k)

    def union(self, component_size, Source, Destination):
        if component_size[Source] <= component_size[Destination]:
            self.component[Source] = Destination
            component_size[Destination] += component_size[Source]
            self.set_component(Source)

        elif component_size[Source] >= component_size[Destination]:
            self.component[Destination] = self.find_component(Source)
            component_size[Source] += component_size[Destination]
            self.set_component(Destination)

        print(self.component)

    def boruvka(self):
        component_size = []
        mst_weight = 0

        minimum_weight_edge = [-1] * self.Destination

        for node in range(self.Destination):
            self.component.update({node: node})
            component_size.append(1)

        num_of_components = self.Destination

        print("---------Forming MST------------")
        while num_of_components > 1:
            for i in range(len(self.edges)):

                Source = self.edges[i][0]
                Destination = self.edges[i][1]
                w = self.edges[i][2]

                Source_component = self.component[Source]
                Destination_component = self.component[Destination]

                if Source_component != Destination_component:
                    if minimum_weight_edge[Source_component] == -1 or \
                            minimum_weight_edge[Source_component][2] > w:
                        minimum_weight_edge[Source_component] = [Source, Destination, w]
                    if minimum_weight_edge[Destination_component] == -1 or \
                            minimum_weight_edge[Destination_component][2] > w:
                        minimum_weight_edge[Destination_component] = [Source, Destination, w]

            for node in range(self.Destination):
                if minimum_weight_edge[node] != -1:
                    Source = minimum_weight_edge[node][0]
                    Destination = minimum_weight_edge[node][1]
                    w = minimum_weight_edge[node][2]

                    Source_component = self.component[Source]
                    Destination_component = self.component[Destination]

                    if Source_component != Destination_component:
                        mst_weight += w
                        self.union(component_size, Source_component, Destination_component)
                        print("edge_Added [" + str(Source) + " - "
                              + str(Destination) + "]\n"
                              + "weight_Added: " + str(w) + "\n")
                        num_of_components -= 1

            minimum_weight_edge = [-1] * self.Destination
        print("-------------Hacktoberfest2022---------------------")
        print("The minimum spanning tree is overall weighed is: " + str(mst_weight))

g = Graph(9)
g.add_edge(0, 1, 4)
g.add_edge(0, 6, 7)
g.add_edge(1, 6, 11)
g.add_edge(1, 7, 20)
g.add_edge(1, 2, 9)
g.add_edge(2, 3, 6)
g.add_edge(2, 4, 2)
g.add_edge(3, 4, 10)
g.add_edge(3, 5, 5)
g.add_edge(4, 5, 15)
g.add_edge(4, 7, 1)
g.add_edge(4, 8, 5)
g.add_edge(5, 8, 12)
g.add_edge(6, 7, 1)
g.add_edge(7, 8, 3)
g.boruvka()

#by: Max Muller