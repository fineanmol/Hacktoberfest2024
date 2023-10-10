//Leetcode 225

class Mystack {
    public:

    queue<int> q;
    Mystack(){

    }
    void push(int x){
       if(q.empty())q.push(x);
       else{
        int s = q.size();
        q.push(x);
        while(s--){
            int top = q.front();
            q.pop();
            q.push(top);
        }
       } 
    }
    int pop(){
        int top = q.front();
        q.pop();
        return top;
    }
    int top(){
        return q.front();
    }
    bool empty(){
        if(q.empty())return true;
        else return false;
    }

};