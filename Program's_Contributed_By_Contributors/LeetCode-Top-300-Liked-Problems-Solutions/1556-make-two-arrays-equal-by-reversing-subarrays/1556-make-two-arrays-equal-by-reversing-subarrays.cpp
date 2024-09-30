class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size(), m = arr.size();
        if(n != m) return false;
        for(int i = 0; i < n; i++){
            if(target[i] != arr[i]){
                int start = -1;
                for(int j = i + 1; j < n; j++){
                    if(target[i] == arr[j]){
                        start = j;
                        break;
                    }
                }
                if(start == -1) return false;
                reverse(arr.begin() + i, arr.begin() + start + 1);
            }
        }
        return true;
    }
};