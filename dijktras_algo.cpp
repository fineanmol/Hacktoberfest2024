//1.     Initialize the distance from the source node S to all other nodes as infinite (999999999999) and to itself as 0.
//2.    Insert the pair of < distance , node > for source i.e < 0, S > in a priority-based SET [C++]
//       where the priority of the elements in the set is based on the length of the distance.
//3.    While the SET is not empty do
//4.       pair_at_top = SET . top( );
//         Remove the element from the top of the SET.
//         current_source_node = pair_at_top . second.
//5.       For every adjacent_node to current_source_node do
//6.            If ( distance [ adjacent_node ] > length_of_path_to_adjacent_node_from_current_source + distance [ current_source_node ] ) then
//7.                 distance [ adjacent_node ] = length_of_path_to_adjacent_node_from_current_source + distance [ current_source_node ]
//8.                 Update the SET with the new pair < distance [ adjacent_node ], adjacent_node >
#include<iostream>
#include<vector>
#include<set>

using namespace std;
typedef pair<int,unsigned long long> PII;
typedef vector<PII> VPII;
typedef vector<VPII> VVPII;

void DijkstrasShortestPath (int source_node, int node_count, VVPII& graph) {

    // Assume that the distance from source_node to other nodes is infinite 
    // in the beginnging, i.e initialize the distance vector to a max value
    const long long INF = 999999999999;
    vector<unsigned long long> dist(node_count, INF);
    set<PII> set_length_node;
    
    // Distance from starting vertex to itself is 0
    dist[source_node] = 0;
    set_length_node.insert(PII(0,source_node));

    while (!set_length_node.empty()) {

        PII top = *set_length_node.begin();
        set_length_node.erase(set_length_node.begin());

        int current_source_node = top.second;

        for (auto& it : graph[current_source_node]) {

            int adj_node = it.first;
            int length_to_adjnode = it.second;
    
            // Edge relaxation 
            if (dist[adj_node] > length_to_adjnode + dist[current_source_node]) {
    
                // If the distance to the adjacent node is not INF, means the pair <dist, node> is in the set
                // Remove the pair before updating it in the set.
                if (dist[adj_node] != INF) {
                   set_length_node.erase(set_length_node.find(PII(dist[adj_node],adj_node))); 
                }
                dist[adj_node] = length_to_adjnode + dist[current_source_node];
                set_length_node.insert(PII(dist[adj_node], adj_node));
            }
        }
    }   

    for (int i=0; i<node_count; i++)
        cout << "Source Node(" << source_node << ") -> Destination Node(" << i << ") : " << dist[i] << endl;
}

int main(){

    vector<VPII> graph;

    // Node 0: <1,5> <2,1> <3,4>
    VPII a = {{1,5}, {2,1}, {3,4}};
    graph.push_back(a);

    // Node 1: <0,5> <2,3> <4,8>
    VPII b = {{0,5}, {2,3}, {4,8}};
    graph.push_back(b);

    // Node 2: <0,1> <1,3> <3,2> <4,1>
    VPII c = {{0,1}, {1,3}, {3,2}, {4,1}};
    graph.push_back(c);

    // Node 3: <0,4> <2,2> <4,2> <5,1>
    VPII d = {{0,4}, {2,2}, {4,2}, {5,1}};
    graph.push_back(d);

    // Node 4: <1,8> <2,1> <3,2> <5,3>
    VPII e = {{1,8}, {2,1}, {3,2}, {5,3}};
    graph.push_back(e);

    // Node 5: <3,1> <4,3> 
    VPII f = {{3,1}, {4,3}};
    graph.push_back(f);

    int node_count  = 6;

    int source_node = 0;
    DijkstrasShortestPath(source_node, node_count, graph);
    cout << endl;

    source_node = 5;
    DijkstrasShortestPath(source_node, node_count, graph);

    return 0;
}
