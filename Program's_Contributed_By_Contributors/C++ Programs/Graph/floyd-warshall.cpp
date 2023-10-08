void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e9;
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            for(int k=0;k<n;k++){
	                matrix[j][k]=min(matrix[j][k],matrix[i][k]+matrix[j][i]);
	            }
	        }
	    }
        for(int i=0;i<n;i++){
            if(matrix[i][i]<0) return {-1};  //for detecting negative cycles
        }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	}

    //multi source expansion having negative values and cycles
    //time complexity 0(n^3)