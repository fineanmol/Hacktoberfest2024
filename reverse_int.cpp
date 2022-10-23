class Solution {
public:
    int reverse(int x) { 
        int b=0,a;
        while (x!=0){
        a= x%10;
        x=x/10;
        if (b>INT_MAX/10 ||(b==INT_MAX && a>7)) return 0;
        if (b<INT_MIN/10 || (b==INT_MIN && a<-8)) return 0;
        b=b*10+a;
    }
    return b;
}
};
