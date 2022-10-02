unordered_map <int,int> mp;
    int num =-1;
    for(int i=n-1; i>=0; i--)
    {
        if(mp.find(arr[i])==mp.end())
        {
            mp.insert({arr[i],1});
        }
        else{
            
            num =i;
        }
    }
    if(num != -1)
    return num+1 ;
    else 
    return num;
