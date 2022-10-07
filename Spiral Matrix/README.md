# To solve the problem follow the below idea:

Draw the path that the spiral makes. We know that the path should turn clockwise whenever it would go out of bounds or into a cell that was previously visited

# Follow the given steps to solve the problem:

- Let the array have R rows and C columns
- seen[r] denotes that the cell on the r-th row and c-th column was previously visited. Our current position is (r, c), facing direction di, and we want to visit R x C total cells.
- As we move through the matrix, our candidate’s next position is (cr, cc). 
- If the candidate is in the bounds of the matrix and unseen, then it becomes our next position; otherwise, our next position is the one after performing a clockwise turn