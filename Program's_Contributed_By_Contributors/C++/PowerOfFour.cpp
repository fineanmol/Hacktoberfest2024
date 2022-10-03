class Solution {
public:
    double value4(double d)
{
    return (log2(d))/2;
}
bool is_integer(float k)
{
  return std::floor(k) == k;
}
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        if(n==1){
            return true;
        }
        if(n%4!=0){
            return false;
        }
        else{
             if(is_integer(value4(n))){
        return true;
    }
    else{
        return false;
    }
        }
    }
};