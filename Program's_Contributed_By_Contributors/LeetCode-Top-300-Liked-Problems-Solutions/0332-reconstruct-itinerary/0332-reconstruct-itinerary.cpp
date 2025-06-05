class Solution {
private:
    // Create an adjacency list to represent the flights
    unordered_map<string, vector<string>> flightGraph;
    
    // Store the final itinerary
    vector<string> itinerary;

public:

    // Depth-First Search to traverse the flight itinerary
    void dfs(string airport) {
        vector<string> &destinations = flightGraph[airport];
        
        // Visit destinations in lexical order
        while (!destinations.empty()) {
            string nextDestination = destinations.back();
            destinations.pop_back();
            dfs(nextDestination);
        }
        
        // Add the current airport to the itinerary after visiting all destinations
        itinerary.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Populate the flight graph using ticket information
        for (int i = 0; i < tickets.size(); i++) {
            string from = tickets[i][0];
            string to = tickets[i][1];

            flightGraph[from].push_back(to);
        }
        
        // Sort destinations in reverse order to visit lexical smaller destinations first
        for (auto &entry : flightGraph) {
            sort(entry.second.rbegin(), entry.second.rend());
        }
        
        // Start the DFS from the JFK airport
        dfs("JFK");
        
        // Reverse the itinerary to get the correct order
        reverse(itinerary.begin(), itinerary.end());
        
        return itinerary;
    }
};