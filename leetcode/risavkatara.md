class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(),ast.end());
        long long x=mass;
        for(int i=0;i<ast.size();i++){
            if(ast[i]>x){
                return false;
            }
            else{
                x+=ast[i];
            }
        }
        return true;
    }
};
Output:-
![Screenshot (231)](https://user-images.githubusercontent.com/87906280/197376058-3aeb93fe-8313-45cb-b67b-6d99a3570d75.png)
