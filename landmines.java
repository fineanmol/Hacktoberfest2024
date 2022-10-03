package backtracking;

import java.util.LinkedList;

public class landmines {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] grid = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
				{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
				{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 }, { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
				{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
				{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 } };

		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				if (grid[i][j] == 0) {
					if (i - 1 >= 0)
						grid[i - 1][j] = -1;
					if (i + 1 < grid.length)
						grid[i + 1][j] = -1;
					if (j - 1 >= 0)
						grid[i][j - 1] = -1;
					if (j + 1 < grid[0].length)
						grid[i][j + 1] = -1;
				}
			}
		}

		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				if (grid[i][j] == -1) {
					grid[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < grid.length; i++) {
			solve(grid, i, 0, "", 0);
		}

		System.out.println(minpath);
		System.out.println(path);

		bfs(grid);

	}

	public static int minpath = Integer.MAX_VALUE;
	public static String path = "";

	public static void solve(int[][] grid, int i, int j, String ans, int l) {
		if (j == grid[0].length - 1) {
			if (l < minpath) {
				minpath = l;
				path = ans + "(" + i + " , " + j + ")";
			}
			return;
		}

		if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == 0 || grid[i][j] == -1) {
			return;
		}

		int[] rx = { 1, -1, 0, 0 };
		int[] ry = { 0, 0, 1, -1 };

		grid[i][j] = -1;
		for (int k = 0; k < ry.length; k++) {
			int ni = i + rx[k];
			int nj = j + ry[k];
			solve(grid, ni, nj, ans + "(" + i + " , " + j + ")", l + 1);
		}
		grid[i][j] = 1;

	}

	public static class pair {
		int i, j, dist;
		String path;

		pair(int i, int j, int dist, String p) {
			this.i = i;
			this.j = j;
			this.dist = dist;
			this.path = p;
		}

	}

	public static void bfs(int[][] grid) {
		LinkedList<pair> q = new LinkedList<>();

		for (int i = 0; i < grid.length; i++) {
			if (grid[i][0] == 1) {
				q.addLast(new pair(i, 0, 0, "(" + i + " , " + 0 + ")"));
			}
		}

		int[][] vis = new int[grid.length][grid[0].length];

		while (!q.isEmpty()) {
			pair rv = q.removeFirst();
			if (vis[rv.i][rv.j] == 1) {
				continue;
			}
			vis[rv.i][rv.j] = 1;

			if (rv.j == grid[0].length - 1) {
				System.out.println(rv.path);
				System.out.println(rv.dist);
				break;
			}

			// add nbrs
			int[] rx = { 1, -1, 0, 0 };
			int[] ry = { 0, 0, 1, -1 };
			for (int k = 0; k < ry.length; k++) {
				int ni = rv.i + rx[k];
				int nj = rv.j + ry[k];
				if (ni >= 0 && ni < grid.length && nj >= 0 && nj < grid[0].length && grid[ni][nj] == 1
						&& vis[ni][nj] == 0) {
					q.addLast(new pair(ni, nj, rv.dist + 1, rv.path + "(" + ni + " , " + nj + ")"));
				}
			}

		}

	}
}
