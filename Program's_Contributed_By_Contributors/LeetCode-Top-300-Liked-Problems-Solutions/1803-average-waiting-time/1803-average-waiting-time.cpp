class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int t = customers[0][0], n = customers.size();
        double wt = 0, sum = 0;
        for(int i = 0; i < n; i++){
            if(customers[i][0] > t)
                t = customers[i][0];
            t += customers[i][1];
            cout << "Time: " << t << endl;
            wt = t - customers[i][0];
            cout << "Wt time: " << wt << endl;
            sum += wt;
            cout << "Sum: " << sum << endl;
        }
        sum /= n;
        return sum;
    }
};