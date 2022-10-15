vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m) 
{
    // Write your code here.
    vector<int> ans;
    
    int row = matrix.size();
    int col = matrix[0].size();
    int total = row * col;
    
    int startingrow = 0;
    int startingcol = 0;
    int endingcol = col - 1;
    int endingrow = row - 1;
    int count = 0;
    
    while(count < total)
    {
        //printing 1st row
        for(int index = startingcol; count < total && index <= endingcol; index++)
        {
            ans.push_back(matrix[startingrow][index]);
            count++;
        }
        startingrow++;
        
        //printing last column
        for(int index = startingrow; count < total && index <= endingrow; index++)
        {
            ans.push_back(matrix[index][endingcol]);
            count++;
        }
        endingcol--;
        
        //printing last row
        for(int index = endingcol; count < total && index >= startingcol; index--)
        {
             ans.push_back(matrix[endingrow][index]);
             count++;
        }
        endingrow--;
        
        //printing 1st column
        for(int index = endingrow; count < total && index >= startingrow; index--)
        {
            ans.push_back(matrix[index][startingcol]);
            count++;
        }
        startingcol++;
        
    }
    return ans;
}
