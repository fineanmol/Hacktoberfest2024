class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(!points.size()) return 0;

        sort(points.begin(), points.end());
        int arrows = 1;
        int last = points[0][1];

        for(int i = 1; i < points.size(); i++){
            if(points[i][0] > last){
                arrows += 1;
                last = points[i][1];
            }
            else
                last = min(last, points[i][1]);
        }
        return arrows;
    }
};
