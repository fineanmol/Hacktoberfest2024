// https://leetcode.com/problems/3sum

class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        for (int i = 0;i<arr.size()-1;i++){
            int front = i+1,rear = arr.size()-1;
            while (front<rear){

                 int sum = arr[i]+arr[front]+arr[rear];
                

                if (sum>0){

                    while (rear>1 && arr[rear-1]==arr[rear]){
                        rear--;
                    }
                    rear--;
                } else if (sum<0){
                    while (front<arr.size()-1 && arr[front+1]==arr[front]){
                        front++;
                    }
                    front++;
                } else {
                    vector<int> triplet = {arr[i],arr[front],arr[rear]};
                    result.push_back(triplet);
                    
                    while (front<rear && arr[rear-1]==arr[rear]){
                        rear--;
                    } 

                    while (front<rear && arr[front+1]==arr[front]){
                        front++;
                    }
                    
                    rear--;front++;

                }
            }
            
            while (i<arr.size()-1 && arr[i+1]==arr[i]){
                i++;
            }
            
           
        }
        
        return result;
    }
};