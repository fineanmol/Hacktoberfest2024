import java.util.*;
// Question 1
// The interns at Amazon were asked to review the company's
// stock value over a period . Given the stock prices of n
// months , the net price change for the Ah month is defined as
// the absolute difference between the average of stock prices
// for the first / months and for the remaining ( n - i ) months
// where 1 si < n . Note that these averages are rounded down
// to an integer .

// Given an array of stock prices , find the month at which the
// net price change is minimum . If there are several such
// months , return the earliest month .


 class MinNetPrice {

    public static void main(String[] args){
        MinNetPrice minNetPrice = new MinNetPrice();
        System.out.println(minNetPrice.minNetPrice(new int[]{1,3,2,3}));
    }
    public int minNetPrice(int[] stockPrice){
        int sum = 0;
        for(int i : stockPrice){
            sum+=i;
        }
        int minNetPrice = Integer.MAX_VALUE, month=-1, n = stockPrice.length;
        int leftSum=0,rightSum = sum;
        for(int i=1;i<n;i++){
           leftSum+=stockPrice[i-1];
           rightSum-=stockPrice[i-1];
           int currNet = Math.abs((leftSum/i)-(rightSum/(n-i)));
           if(minNetPrice>currNet){
               minNetPrice = currNet;
               month = i;
               if(minNetPrice==0) break;
           }
        }
        return month;
    }
    }
// Question 2
//  For n tv channels, given show start time, end time & bandwidth needed for each channels, find the maximum bandwidth required at peak. a show represented as [1,30,2] meaning [show-start-time, show-end-time, bandwidth-needed].

// e.g. n =3 channels,
// [[1,30, 2],[31,60, 4],[61,120, 3],
// [1,20,2],[21,40,4],[41,60,5],[61,120,3],
// [1,60,4],[61,120,4]]

// Ans: 13, for time slot between 41-60 each channel need 4,5,4 bandwidth respectively. 13 is highest (peek/max) bandwidth.


 class Main {
	
	public static void main(String[] args) {
		List<List<Integer>> list = new ArrayList<>();
		list.add(Arrays.asList(1, 30, 2));
		list.add(Arrays.asList(31, 60, 4));
		list.add(Arrays.asList(61, 120, 3));
		list.add(Arrays.asList(1, 20, 2));
		list.add(Arrays.asList(21, 40, 4));
		list.add(Arrays.asList(41, 60, 5));
		list.add(Arrays.asList(61, 120, 3));
		list.add(Arrays.asList(1, 60, 4));
		list.add(Arrays.asList(61, 120, 4));
		int ret = maxBandwith(list);
		System.out.println(ret);
	}
	
	public static class Item {
		int t;
		int b;
		int p; // 1 if plus, 0 if minus.
		
		public Item(int t, int b, int p) {
			this.t = t;
			this.b = b;
			this.p = p;
		}
	}
    public static int maxBandwith(List<List<Integer>> list) {
    	int ret = 0;
    	int curr = 0;
    	PriorityQueue<Item> pq = new PriorityQueue<>((a, b) -> (a.t == b.t ? a.p - b.p : a.t - b.t));
    	for(List<Integer> l : list) {
    		if (l.get(2) == 0)
    			continue;
    		pq.offer(new Item(l.get(0), l.get(2), 1));
    		pq.offer(new Item(l.get(1), l.get(2), 0));
    	}
    	
    	while(!pq.isEmpty()) {
    		Item item = pq.poll();
    		if (item.p == 1) {
    			curr += item.b;
    			ret = Math.max(ret,  curr);
    		} else {
    			curr -= item.b;
    		}
    	}
    	
    	return ret;
    }

}

// Question 3:
// Give you a list servers. Their processing power is given as a array of integer, and boot power as a array of integer.
// Write a function to return the max length of sub array which's power consumption is less than or equal to max power limit.
// Formula to calculate the power consumption for a subArray is:
// Max(bootPower[i...j]) + Sum(processPower[i....j]) * length of subArray.

// Note: Single server is also a subArray, return 0 if no such subArray can be found.

 class b {
    public static void main(String[] args){
    int[] processingPower = new int[]{4,1,4,5,3};
    int[] bootingPower = new int[]{8,8,10,9,12};
    long maxPower = 33;
    
            b test = new b();
            System.out.println(test.maxLengthValidSubArray(processingPower, bootingPower, maxPower));   // output should be 2
        }
    
        public int maxLengthValidSubArray(int[] processingPower, int[] bootingPower, long maxPower){
            if(processingPower == null || bootingPower == null
                    || processingPower.length == 0 || processingPower.length != bootingPower.length){
                return 0;
            }
    
            PriorityQueue<Integer> maxBootingPower = new PriorityQueue<>((a, b) -> Integer.compare(b, a));
            int maxLength = 0;
            int currentLength = 1;
    
            int start = 0;
            int end = 0;
    
            long currentSumProcessingPower = processingPower[0];
            maxBootingPower.add(bootingPower[0]);
            while(end < processingPower.length){
                int currentBootingPower = maxBootingPower.peek();
                long currentPower = currentBootingPower + currentSumProcessingPower * currentLength;
    
                if(currentPower <= maxPower){
                    maxLength = currentLength;
                    end++;
                    currentLength++;
                }
                else{
                    currentSumProcessingPower -= processingPower[start];
                    maxBootingPower.remove(bootingPower[start]);
                    start++;
                    end++;
                }
    
                if(end < processingPower.length){
                    maxBootingPower.add(bootingPower[end]);
                    currentSumProcessingPower += processingPower[end];
                }
            }
    
            return maxLength;
        }
 }

    // Question 4
    // Maximum Number of Events That Can Be Attended
    class event{
 
    public int maxEvents(int[][] events) {
        Arrays.sort(events, Comparator.comparingInt(eventStartDay -> eventStartDay[0]));
        int maxEventsThatCanBeAttended = 0, i = 0, numberOfEvents = events.length;
        // The default PriorityQueue is implemented with Min-Heap, that is the top element is the minimum one in the heap.
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int day = 1; day <= 100000; day++) {

            // Store end dates in a priority queue if start date == day
            while (i < numberOfEvents && events[i][0] == day){
                    minHeap.add(events[i++][1]);
            }

            // Remove from queue if the event is over
            while(!minHeap.isEmpty() && minHeap.peek() < day){
                minHeap.poll();
            }

            // Be greedy and use day to attend to the event that closes earlier
            // which is at the head of the queue
            if(!minHeap.isEmpty()){
                maxEventsThatCanBeAttended++;
                // Removes the head of this queue
                minHeap.poll();
            }
        }
        return maxEventsThatCanBeAttended;
    }
}