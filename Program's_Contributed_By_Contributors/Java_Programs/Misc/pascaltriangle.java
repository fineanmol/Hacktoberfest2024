class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row.add(1);
                } else {
                    row.add(ans.get(i - 1).get(j - 1) + ans.get(i - 1).get(j));
                }
            }
            ans.add(row);
        }
        return ans;
    }
}

// Output -
/*
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/

// Algorithm -
/*
1. We first initialize an empty list of lists.
2. We then iterate through the number of rows we want to generate.
3. For each row, we initialize a new list.
4. We then iterate through the row and add elements to the list.
5. If the element is the first or last element, we add 1.
6. Otherwise, we add the sum of the two elements above it.
*/

// Time & Space Complexity -
/*
Time - O(numRows2)
because, we are creating a 2D array of size (numRows * numCols) (where 1 <= numCols <= numRows), and we are traversing through each of the cells to update it with its correct value

Space - O(numRows2)
Since we are creating a 2D array
*///by satyam
