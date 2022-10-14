import java.util.*;
public class CommonElement {
	public static void main(String[] args) {
		int a1[] = {1, 5, 10, 20, 40, 80};
		int a2[] = {6, 7, 20, 80, 100};
		int a3[] = {3, 4, 15, 20, 30, 70, 80, 120};
		ArrayList<Integer> a = new ArrayList<Integer>();
		Set<Integer>s  =new HashSet<Integer>();
		Set<Integer>s2  =new HashSet<Integer>();
		for(int se: a2){
			s.add(se);
		}
		Set<Integer>s1  =new HashSet<Integer>();
		for(int se: a3){
			s1.add(se);
		}
		for(int i=0; i<a1.length; i++)
		{
			if(s.contains(a1[i])&&s.contains(a1[i])){
				s2.add(a1[i]);
			}
		}
		for(int w:s2){
			a.add(w);
		}
		System.out.println(a);
	}
}
