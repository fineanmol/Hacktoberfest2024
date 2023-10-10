#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<vector<int>> matrix = {{1,0,1},{1,1,0},{1,1,1}};
	int fr =0, fc= 0;
        for(int i=0;i<matrix.size();i++)
        {
            
            for(int j=0;j<matrix[i].size();j++)
            {
                if((matrix[i][j]==0)&&i==0)
                    fc =1;
                if((matrix[i][j]==0)&&j==0)
                    fr =1;
                if((matrix[i][j]==0)&&i&&j)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
                
            }
        }
        for(int i=1;i<matrix.size();i++)
        {
            if(matrix[i][0]==0)
            {
                for(int j=0;j<matrix[i].size();j++)
                    matrix[i][j]=0;
            }
        }
        
        for(int i=1;i<matrix[0].size();i++)
        {
            if(matrix[0][i]==0)
            {
                for(int j=0;j<matrix.size();j++)
                    matrix[j][i]=0;
            }
        }
        if(fc)
        {
            for(int i=0;i<matrix[0].size();i++)
                matrix[0][i]=0;
        }
        if(fr)
        {
            for(int i=0;i<matrix.size();i++)
                matrix[i][0]=0;
        }
        for(int i=0;i<matrix.size();i++)
        {
        	for(int j=0;j<matrix[0].size();j++)
        	{
        		cout<<matrix[i][j]<<" ";
        	}
        	cout<<endl;
        }
        return 0;
}