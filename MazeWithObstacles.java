public class MazeWithObstacles {  
    public static void main(String[] args) {
        boolean[][] board = {
                {true, true, true},
                {true, false, true},
                {true, true, true}
        };
        pathRestriction("", board, 0, 0);

    }
    static void pathRestriction(String p, boolean[][] maze, int r, int c){ //boolean array
        if (r == maze.length - 1 && c == maze[0].length - 1){ //0 = length of col
            System.out.println(p);
            return;
        }
        if (!maze[r][c]){ // if maze[r][c] == false // if not true //if there is a obstacle
            return;
        }

        if (r < maze.length - 1){
            pathRestriction(p + 'D', maze, r+1, c); //down
        }
        if (c < maze[0].length - 1){
            pathRestriction(p + 'R', maze, r, c+1); //right
        }
    }
}
