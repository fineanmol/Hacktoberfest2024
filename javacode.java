public class SpiralMatrix {
    public static void main(String[] args) {
        int[][] arr={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
        Spiral(arr); 
        for(int i=0;i<arr.length;i++){
            for(int j=0 ;j<arr[i].length;j++){    //i<arr[0].length
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }  
    }  

    public static void Spiral(int[][] arr){
    int minR=0;
    int maxR=arr.length-1;
    int minC=0;
    int maxC=arr[0].length-1;
    int te=arr.length*arr[0].length;
    int c=0;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    
    while(c<te){
        for(int i=minC;i<=maxC && c<te;i++){
            System.out.print(arr[minR][i]+" ");
        }
        minR++;
    
        for(int i=minR;i<=maxR && c<te;i++){
            System.out.print(arr[i][maxC]+" ");
        }
        maxC--;
    
       for(int i=maxC;i>=minC && c<te;i--){
            System.out.print(arr[maxR][i]+" ");
            }
        maxR--;
            
        for(int i=maxR;i>=minR && c<te;i--){
            System.out.print(arr[i][minC]+" ");
            }
        minC++;
            
        }
    }
    
}
