


//Created by Suparna 


// Christmas HUT Challenge in KOTLIN


// Creating pattern


/*





             *
           * * * 
         * * * * *
       * * * * * * *
     * * * * * * * * *
     * * *       * * *
     * * *       * * *
     * * *       * * *






*/

fun main(args: Array<String>) {
    
for(i in 1..5)    
    {
    print("           ")
        for(j in 1..5-i)
        {
            print("  ")
        }
        for(k in 1..2*i-1)
        {
            print(" *")
        }
        println()
    }  

for(i in 1..3)    
    {
    print("           ")
        for(j in 1..9)
        {
        if(j>=4 && j<7)
            print("  ")
       else
            print(" *")
        }
        
        println()
    }  
     
}

