#include<iostream>
#include<algorithm>
using namespace std;

//The box class
class Box{
public:
    int w;
    int h;
    int d;

    Box(int width=0,int height=0,int depth=0):w(width),h(height),d(depth){}

    friend ostream& operator<<(ostream& os, const Box& bt){
    os<<"Box :"<<bt.w<<","<<bt.h<<","<<bt.d<<endl;
    return os;
    }
};


//Area height*width (Height is length here)
bool compare(const Box&b1,const Box&b2)
{
return (b1.w)*(b1.h) > (b2.w)*(b2.h);
}

int BoxStackHeight(Box b[],int n){
Box box[300];

int j=0;

//Generate the 3side permutations.
for(int i=0;i<n;i++){
box[j] = b[i];
j++;

box[j].w = b[i].h;
box[j].h = max( b[i].w,b[i].d);
box[j].d = min( b[i].w,b[i].d);
j++;


box[j].w = b[i].d;
box[j].h = max( b[i].w,b[i].h);
box[j].d = min( b[i].w,b[i].h);
j++;
}

//Sort the boxes on the basis of decreasing base area.
n=3*n;
sort(box,box + n,compare);
//Run LIS on depths.
int lis[n];

for(int i=0;i<n;i++){
    lis[i]=box[i].d;
    cout<<box[i]<<endl;
}

for(int i=1;i<n;i++){
    for(j=0;j<i;j++){
        if(box[j].w < box[i].w &&box[j].h < box[i].h && lis[j]+box[j].d> lis[i]){
            lis[i] = lis[j]+box[j].d;

        }
    }
}
int ans=0;
for(int i=0;i<n;i++){
    ans=max(ans,lis[i]);

    }

return ans;
}


int main(){

//Note this sytax is allowed !
Box b[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
int n = sizeof(b)/sizeof(Box);

cout<<BoxStackHeight(b,n)<<endl;
return 0;
}
