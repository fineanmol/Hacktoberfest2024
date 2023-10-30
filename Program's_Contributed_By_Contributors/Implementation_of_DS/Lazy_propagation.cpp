#include<bits/stdc++.h>
using namespace std;

int lazy[10000] ={0};

void update_range_lazy(int *tree,int ss,int se,int l,int r,int increment,int index){

     // pahle backlog clear karo---------------------------------------------------------------------->

    //before going down resolve the values if it exists
     if(lazy[index]!=0){
        tree[index]+=lazy[index];
        //non leaf node 
        if(ss!=se){
            lazy[2*index] =lazy[index];
            lazy[2*index+1] =lazy[index];
        }
        //clearing the lazy value at current node
        lazy[index]=0;
     }
     //base case--->no overlapp
     if(ss>r or se<l){
        return;
     }
     //complete overlapp case
     if(l<=ss and r>=se){
        tree[index]+=increment;
        if(ss!=se){
            lazy[2*index] +=increment;
            lazy[2*index+1] +=increment;
        }
        return;
     }
     //Recurssive-->partial overlapping
    int mid =(ss+se)/2;
    update_range_lazy(tree,ss,mid,l,r,increment,index);
    update_range_lazy(tree,mid+1,se,l,r,increment,index);
    //update the tree
    tree[index]= min(tree[2*index],tree[2*index+1]);
     return ;


}

int lazy_query(int *tree,int ss,int se,int qs,int qe,int index){
     //before going down resolve at the current node
     if(lazy[index]!=0){
        tree[index]+=lazy[index];
        //non leaf node 
        if(ss!=se){
            lazy[2*index] =lazy[index];
            lazy[2*index+1] =lazy[index];
        }
        //clearing the lazy value at current node
        lazy[index]=0;
     }

     //query logic
     // no overlapping
     if(qe<ss or qs>se){
        return INT_MAX;
     }
    //complete overlapping
    if(qs<=ss and qe>=se){
        return tree[index];
    }
    //partial overlapping
    int mid = (ss+se)/2;
    lazy_query(tree,ss,mid,qs,qe,2*index);
    lazy_query(tree,mid+1,se,qs,qe,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);


   return tree[index];

}

void build_tree(int *arr,int s,int e,int *tree,int index){
  //base case
  if(s==e){
    tree[index]=arr[s];
  }
  //recurssive case
  int mid = (s+e)/2 ;
  build_tree(arr,s,mid,tree,2*index);
  build_tree(arr,mid+1,e,tree,2*index+1);

  tree[index] = min(tree[2*index],tree[2*index+1]);
  return ;
}

int main (){



    return 0;
}
