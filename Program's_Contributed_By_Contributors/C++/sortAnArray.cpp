#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> &v, int temp);
void sort(vector<int> &v);

int main() {

    vector<int> v = {0,1,3,4,5,7};
    vector<int> m = {1,0,3,2,6,7,5};

    //insert(v, 2);
    sort(m);
    for(auto i: m){
        cout<<i<<" ";
    }

    return 0;
}

void sort(vector<int> &v){
    if(v.size()<=1){
        return;
    }

    int temp = v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v, temp);
}

void insert(vector<int> &v, int temp){
    if((v[v.size()-1] < temp) || v.empty()){
        v.push_back(temp);
        return;
    }

    int num = v[v.size()-1];
    v.pop_back();
    insert(v, temp);

    v.push_back(num);
}