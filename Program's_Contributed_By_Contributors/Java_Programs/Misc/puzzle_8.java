/*
 * Given a 3*3 box which consists of 8 tiles numbered from 1-8 placed in a random order and a blank space.
 * the problem is to print the minimum number of moves required to reach the goal state
 * under the condition that we can only move the blank space left, up, right and down by one space and the blank space should not go out of the 3*3 box.
 * for example
 * 
 * initial state   goal state 
 * 		3 7 6		5 3 6
 * 		5 1 2		7 _ 2
 * 		4 _ 8		4 1 8
 */
import java.util.*;
public class puzzle_8 {

	public static void main(String[] args) {
		int[] arr=new int[9];
		
		/*int[][] initial_state= {{1,2,3},{0,4,6},{7,5,8}};
		int[][] goal_state= {{1,2,3},{4,5,6},{7,8,0}};
		*/
		
		int[][] initial_state= {{3,7,6},{5,1,2},{4,0,8}};
		int[][] goal_state= {{5,3,6},{7,0,2},{4,1,8}};
		
		fillArray(arr,initial_state,goal_state);
		print_state(initial_state);
		System.out.println("Initial State :: manhatan distance --> "+calculateM(arr));
		print(arr);
		
		//index of blank space
		int index=search(0,initial_state);
		int row=index/3;
		int col=index-row*3;
		
		//store the values of manhatan distance after performing up,down,right,left
		int[][] dir= {{-1,0},{1,0},{0,-1},{0,1}};
		int[] manahatan_distance=new int[4];
		int[][] num_value=new int[4][2];
		int counter=1;
		while(calculateM(arr)!=0) {
			System.out.println("Step "+counter++);
			int minM=Integer.MAX_VALUE;
			int currentM=calculateM(arr);
			
			//up 
			if((row+dir[0][0])>=0) {
				int num=initial_state[row+dir[0][0]][col];
				int dis=-arr[num]+distance(row,col,search(num,goal_state));
				manahatan_distance[0]=currentM+dis;
				num_value[0][0]=num;
				num_value[0][1]=dis;
				System.out.println("for up  -> "+manahatan_distance[0]);
			}
			else {
				manahatan_distance[0]=Integer.MAX_VALUE;
			}
	
			//down
			if((row+dir[1][0])<initial_state.length) {
				int num=initial_state[row+dir[1][0]][col];
				int dis=-arr[num]+distance(row,col,search(num,goal_state));
				manahatan_distance[1]=currentM+dis;
				num_value[1][0]=num;
				num_value[1][1]=dis;
				System.out.println("for down  -> "+manahatan_distance[1]);
			}
			else {
				manahatan_distance[1]=Integer.MAX_VALUE;
			}
			//left
			if((col+dir[2][1])>=0) {
				int num=initial_state[row][col+dir[2][1]];
				int dis=-arr[num]+distance(row,col,search(num,goal_state));
				manahatan_distance[2]=currentM+dis;
				num_value[2][0]=num;
				num_value[2][1]=dis;
				System.out.println("for left  -> "+manahatan_distance[2]);
			}
			else {
				manahatan_distance[2]=Integer.MAX_VALUE;
			}
			//right
			if((col+dir[3][1])<initial_state.length) {
				int num=initial_state[row][col+dir[3][1]];
				int dis=-arr[num]+distance(row,col,search(num,goal_state));
				manahatan_distance[3]=currentM+dis;
				num_value[3][0]=num;
				num_value[3][1]=dis;
				System.out.println("for right  -> "+manahatan_distance[3]);
				
			}
			else {
				manahatan_distance[3]=Integer.MAX_VALUE;
			}
			
			int finalMove=0;
			//finding final move
			for(int i=0;i<manahatan_distance.length;i++) {
				if(minM>manahatan_distance[i]) {
					minM=manahatan_distance[i];
					finalMove=i;
				}
			}
			System.out.println("Move played in "+ movePlayed(finalMove)+" direction");
			
			swap(row,col,initial_state,dir[finalMove][0],dir[finalMove][1]);
			arr[num_value[finalMove][0]]=arr[num_value[finalMove][0]]+num_value[finalMove][1];
			print(arr);
			System.out.println("Current State");
			print_state(initial_state);
			System.out.println("-------------");
			row=row+dir[finalMove][0];
			col=col+dir[finalMove][1];
		}
		System.out.println("goal state");
		print_state(goal_state);
	}
	
	private static void print_state(int[][] arr) {
		 for (int[] is : arr) {
			for (int is2 : is) {
				System.out.print(is2==0?"_\t":is2+"\t");
			}
			System.out.println();
		}
	}

	private static void swap(int row, int col, int[][] initial_state, int i, int j) {
		initial_state[row][col]=initial_state[row+i][col+j];
		initial_state[row+i][col+j]=0;
		
	}

	private static int calculateM(int[] arr) {
		int sum=0;
		for (int i : arr) {
			sum+=i;
		}
		return sum;
	}
	public static void print(int[] arr) {
		System.out.print("Manhatan Array --> ");
		for (int is : arr) {
			System.out.print(is+"\t");
		}
		System.out.println();
	}
	private static void fillArray(int[] arr, int[][] initial_state, int[][] goal_state) {
		
		for (int i = 0; i < initial_state.length; i++) {
			for (int j = 0; j < initial_state.length; j++) {
				if(initial_state[i][j]!=0) {
				int index=search(initial_state[i][j],goal_state);
				arr[initial_state[i][j]]=distance(i,j,index);
				}
			}
		}
		
	}

	public static String movePlayed(int num){
		if(num==0) return "Up";
		else if(num==1) return "Down";
		else if(num==2) return "Left";
		else return "Right";
	}
	private static int distance(int i, int j, int index) {
		int row=index/3;
		int col=index-row*3;
		return Math.abs(i-row)+Math.abs(j-col);
	}
	private static int search(int i, int[][] arr) {
		for (int j = 0; j < arr.length; j++) {
			for (int j2 = 0; j2 < arr.length; j2++) {
				if(arr[j][j2]==i) return j*3+j2;
			}
		}
		return 0;
	}

}
