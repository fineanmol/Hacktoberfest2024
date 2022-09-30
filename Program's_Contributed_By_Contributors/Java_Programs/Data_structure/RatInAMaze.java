/*In this problem, there is a given maze of size N x N. The source and the destination location is top-left cell and bottom right cell respectively. 
Some cells are valid to move and some cells are blocked. 
If one rat starts moving from start vertex to destination vertex, we have to find that is there any way to complete the path, 
if it is possible then mark the correct path for the rat.*/

public class RatInAMaze {
	
	public static boolean ratInAMaze(int maze[][]) {
		int n=maze.length;
		int path[][]= new int[n][n];
		
		return solveMaze(maze, 0, 0, path);
		
	}
	
	public static boolean solveMaze(int maze[][],int i,int j,int[][] path) {
		
		int n=maze.length;
		//Check if i,j cell is valid or not
		if(i<0 || i>=n || j<0 || j>=n || maze[i][j]==0 || path[i][j]==1) {
			return false;
		}
		
		//Include the cell in current path
		path[i][j]=1;
		
		if(i==n-1 && j==n-1) {
			return true;
		}
		
		//Explore further in all directions
		//top
		if(solveMaze(maze, i-1, j, path)) {
			return true;
		}
		//right
		if(solveMaze(maze, i, j+1, path)) {
			return true;
		}
		//Down
		if(solveMaze(maze, i+1, j, path)) {
			return true;
		}
		//Left
		if(solveMaze(maze, i, j-1, path)) {
			return true;
		}
		
		return false;
	
	}

	public static void main(String[] args) {
		
		int maze[][]= {{1,1,0},{1,0,1},{1,1,1}};
		boolean pathPossible =ratInAMaze(maze);
		System.out.println(pathPossible);

	}

}
