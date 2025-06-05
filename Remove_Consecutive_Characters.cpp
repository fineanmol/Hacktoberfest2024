class Solution{
public:
    string removeConsecutiveCharacter(string S)
    {
        string temp = "";
        for(int i = 0 ; i< S.length(); i++){
            if(S[i] == S[i+1]){
                continue;
                i++;
                
            }else{
                temp.push_back(S[i]);
            }
        }
        return temp;
    }
};
