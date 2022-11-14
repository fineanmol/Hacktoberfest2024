
public class Trapped_Rainwater {
    public static int TrappedRainwater(int height[]){
		int n = height.length;
		//left_max_boundary (create auxillary array)
		int leftmax[] = new int[n];
		leftmax[0] = height[0];
		for(int i=1; i<n; i++) {
			leftmax[i] = Math.max(height[i], leftmax[i-1]);
		}
		//right_max_boundary (create auxillary array)
		int rightmax[] = new int[n];
		rightmax[n-1] = height[n-1];
		for(int i=n-2; i>=0; i--) {
			rightmax[i] = Math.max(height[i], rightmax[i+1]);
		}
		int trapped_rainwater = 0;
		//loop;
		for(int i=0; i<n; i++) {
			//Waterlevel = Min(leftmax,rightmax)
			int Waterlevel = Math.min(leftmax[i], rightmax[i]);
			//TrappedRainwater = Waterlevel-height
			trapped_rainwater = trapped_rainwater + (Waterlevel-height[i]);
		}
		return trapped_rainwater;
	}
	public static void main(String[] args) {
		int height[] = {4,2,0,6,3,2,5};
		System.out.println(TrappedRainwater(height));
	}

}
