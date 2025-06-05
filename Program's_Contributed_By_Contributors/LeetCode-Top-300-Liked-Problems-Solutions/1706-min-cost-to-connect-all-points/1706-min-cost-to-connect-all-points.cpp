class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int minCost=0, pSize=points.size(),includedEdges=0;
        vector<bool> visited(pSize,false);
        vector<int> minDist(pSize,INT_MAX);
        minDist[0]=0;
        while(includedEdges<pSize) {
            int minWeight=INT_MAX,currentPoint=-1;
            for(int point=0;point<pSize;point++) {
                if(!visited[point] && minDist[point]<minWeight) {
                    minWeight=minDist[point];
                    currentPoint=point;
                }
            }
            includedEdges++;
            minDist[currentPoint]=minWeight;
            visited[currentPoint]=true;
            minCost+=minWeight;
            for(int point=0;point<pSize;point++) {
                if(!visited[point]) {
                    int currentDist=abs(points[point][0]-points[currentPoint][0])+
                    abs(points[point][1]-points[currentPoint][1]);
                    if(minDist[point]>currentDist) {
                        minDist[point]=currentDist;
                    }
                }
            }
        }
        return minCost;        
    }
};