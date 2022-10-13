package CodeChef;
import java.util.*;
public class Maximize_Power {
	public static void main(String[] args) {
		List<Integer> arr = new ArrayList<Integer>();
		arr.add(2);
		arr.add(4);
		arr.add(2);
		arr.add(1);
		arr.add(6);
		List<Integer> power = new ArrayList<Integer>();
		power.add(4);
		power.add(1);
		power.add(1);
		power.add(3);
		
		int sum=0;
		List<Integer> a = new ArrayList<Integer>();
		for(int i=0; i<power.size(); i++){
			for(int j=1; j<power.size(); j++){
				int temp1 = power.get(i);
				int temp2 = power.get(j);
				int min=0;
				if(temp1<temp2){
					min = temp1;
				}
				else{
					min  = temp2;
				}
				int max = Math.max(temp1, temp2);
				if(max == arr.size()){
					for(int k=min; k<=max-1; k++){
						sum +=arr.get(k);
					}
				}
				else{
					for(int k=min; k<=max; k++){
						sum +=arr.get(k);
					}	
				}
				a.add(sum);
				sum=0;
			}
			
		}
		Collections.sort(a);
		HashSet<Integer> set = new HashSet<Integer>();
		for(Integer n : a){
			set.add(n);
		}
		int max = Collections.max(set);
		a = new ArrayList<Integer>(set);
		System.out.println(a);
		System.out.println(a.get(a.size()-2)+max);
	}
}
