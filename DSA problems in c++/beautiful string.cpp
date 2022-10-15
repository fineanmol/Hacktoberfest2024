int makeBeautiful(string str) {
	// Write your code here
    int count1 = 0;
    int count2 = 0;
    int n = str.size();
    
    for(int i = 0; i < n; i ++)
    {
        if(i % 2 == 0 && str[i] != '1')
            count1++;
        else if(i % 2 == 1 && str[i] != '0')
            count1++;
    }
    
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0 && str[i] != '0')
            count2++;
        else if(i % 2 == 1 && str[i] != '1')
            count2++;
    }
    
    int mini = min(count1,count2);
    return mini;
}
