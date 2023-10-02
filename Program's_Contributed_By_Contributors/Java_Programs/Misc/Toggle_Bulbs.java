
/*
Toggle The Bulbs

There are N bulbs that are initially off. In the first round, you turn ON all the bulbs, 
then you turn off every second bulb in the second round. 
On the third round, you toggle every third bulb 
(turning ON if it's OFF or vice-versa). 
For the Ith round, you toggle every Ith bulb.
 For the Nth round, you only toggle the last bulb.
Return the number of bulbs that are ON after the N rounds.
Example 1:
Input: 
3
Output: 
1
Explanation: 
At first, the status of the three bulbs is [OFF, OFF, OFF].
After the first round, the status of the three bulbs is [ON, ON, ON].
After the second round, the status of the three bulbs is [ON, OFF, ON].
After the third round, the status of the three bulbs is [ON, OFF, OFF]. 
So you should return 1, because there is only one bulb that is ON.
Example 2:
Input:
1
Output: 
1
Explanation:
You should return 1, because there is only one bulb.
*/
// SOlultion: SQRT(N) <--- is the Answer
import java.util.*;
public class Toggle_Bulbs {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] bulbs= new int[n];
        
        for(int i=0;i<n;i++)
        {
            System.out.println("Round"+i+":"+bulbs[i]);

        }
    }
}
