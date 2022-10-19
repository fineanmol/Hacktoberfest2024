bool isPowerOfTwo(int n) {
        
        int res=0;
        for(int i =0;i<=30;i++)
        {
            res=pow(2,i);
            if(res==n)
                return true;
            
        }
        
        return false;
        
    }