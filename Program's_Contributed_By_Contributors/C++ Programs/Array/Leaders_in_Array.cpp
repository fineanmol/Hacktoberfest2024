#include <vector>
using namespace std;

vector<int> superiorElements(vector<int> &a) {
    vector<int> ans;
    int i, j;
    
    for (i = 0; i < a.size(); i++) {
        bool leader = true;
        for (j = i + 1; j < a.size(); j++) {
            if (a[i] < a[j]) {
                leader = false;
                break;
            }
        }
        
        if (leader) {
            ans.push_back(a[i]);
        }
    }
    
    return ans;
}
