 public String DpFunction(int[] cost, int target) { 
        String strg[] = new String[target + 1]; 
        strg[0] = ""; 
  
        for (int i = 1; i <= target; i++) { 
            String maxstr = ""; 
            int val=0;
            
            for (int j = 0; j <cost.length; j++){ 
                if(i==cost[j] && maxstr==""){
                     val=Math.max(val,j+1);
                }
                
                if((i-cost[j])>0){
                    if(maxstr.length()<strg[i - cost[j]].length()){
                        val=Math.max(val,j+1);
                     maxstr=strg[i - cost[j]]; 
                    }else if(maxstr.length()==strg[i - cost[j]].length()){
                        for(int ii=0;ii<maxstr.length();ii++){
                     if(strg[i - cost[j]].charAt(ii)>maxstr.charAt(ii)){
                        maxstr=strg[i - cost[j]];
                        val=Math.max(val,j+1);
                        break;
                     }else if(strg[i - cost[j]].charAt(ii)<maxstr.charAt(ii)){
                        break;
                     }
                    }
                 } 
                    if(maxstr.equals(strg[i-cost[j]]) && maxstr!="")val=Math.max(val,j+1);
             }
           }
            if(val!=0){    
            strg[i] = maxstr+val; 
            }else{
                strg[i] = maxstr;
            }
       }
        
      return strg[target]; 
   }
    
    public String largestNumber(int[] cost, int target) {
       String ans=DpFunction(cost,target);
        if(ans==""){
            return "0";
        }
        return ans;
    }
}  
