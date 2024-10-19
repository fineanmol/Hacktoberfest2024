int main() {
    Graph g(6);

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, 2);

    g.setCoordinates(0, 0, 0);
    g.setCoordinates(1, 1, 1);
    g.setCoordinates(2, 4, 0);
    g.setCoordinates(3, 2, 2);
    g.setCoordinates(4, 3, 3);
    g.setCoordinates(5, 5, 5);

    vector<double> distDijkstra = g.dijkstra(0);
    cout << "Dijkstra's Algorithm (Shortest Paths from Node 0):";
    for (int i = 0; i < distDijkstra.size(); ++i) {
        cout << "Distance to node " << i << " = " << distDijkstra[i] << endl;
    }

    vector<int> pathAStar = g.aStar(0, 5);
    cout << "A* Algorithm (Shortest Path from Node 0 to Node 5):";
    cout << "Path: ";
    for (int node : pathAStar) {
        cout << node << " ";
    }
    cout << "Distance: " << distDijkstra[5] << endl;

    cout << "Updating edge (1, 3) weight to 7 due to traffic";
    g.updateEdge(1, 3, 7);

    distDijkstra = g.dijkstra(0);
    cout << "Dijkstra's Algorithm after updating edge (1, 3):\n";
    for (int i = 0; i < distDijkstra.size(); ++i) {
        cout << "Distance to node " << i << " = " << distDijkstra[i] << endl;
    }

    cout << "\nRemoving edge (2, 3) due to road closure...\n";
    g.removeEdge(2, 3);

    pathAStar = g.aStar(0, 5);
    cout << "A* Algorithm after removing edge (2, 3):\n";
    cout << "New path: ";
    for (int node : pathAStar) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
