#include <bits/stdc++.h>
using namespace std;

void build_tree(vector<long long>  &arr,long long s,long long e, vector<long long> &tree,long long index){
  //base case
  if(s==e){
    tree[index]=arr[s];
  }
  //recurssive case
  long long mid = (s+e)/2 ;
  build_tree(arr,s,mid,tree,2*index);
  build_tree(arr,mid+1,e,tree,2*index+1);

  tree[index] = min(tree[2*index],tree[2*index+1]);
  return ;
}

long long query(vector<long long> &tree,long long ss,long long se,long long qs,long long qe,long long index){

    //complete overlap
    if(qe>=se and qs<=ss){
        return tree[index];
    }
    //No overlap
    if(qe<ss or qs>se){
        return INT_MAX;
    }
    //partial overlapp
    long long mid =(ss+se)/2;
    long long left = query(tree,ss,mid,qs,qe,2*index);
    long long right = query(tree,mid+1,se,qs,qe,2*index+1);

    return min(left,right);

}


void update(vector<long long> &tree,long long ss,long long se,long long i,long long increment,long long index){

    //case where I is out of bound
    if(i<ss||i>se){
        return ;
    }
    //leaf node 
    if(ss==se){
        tree[index]+=increment;
        return ;
    }
    //otherwise
    long long mid =(ss+se)/2;
    update(tree,ss,mid,i,increment,2*index);
    update(tree,mid+1,se,i,increment,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);

}

void update_range(vector<long long> &tree,long long ss,long long se,long long l,long long r,long long increment,long long index){

    //out of bound
    if(r<ss||l>se){
        return ;
    }
    //leaf node 
    if(ss==se){
        tree[index]+=increment;
        return ;
    }
    //otherwise
    long long mid =(ss+se)/2;
    update_range(tree,ss,mid,l,r,increment,2*index);
    update_range(tree,mid+1,se,l,r,increment,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);

}



int main(){


  return 0;

}
