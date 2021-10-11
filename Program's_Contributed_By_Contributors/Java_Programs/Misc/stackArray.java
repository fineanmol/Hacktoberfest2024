class stackjava {
	public static void main(String[] args) {
		StackX theStack = new StackX(10);  // create a stack with max size 10
		
		theStack.push(30);  // insert given items
		theStack.push(80);
		theStack.push(100);
		theStack.push(25);
        
        //To peak the the last element pushed
        System.out.println(theStack.peek());
		
		while(!theStack.isEmpty()) {    // until it is empty, delete item from stack
		
			double val = theStack.pop();
			System.out.print(val);
			System.out.print(" ");
		}
	}
}

//Implementation of Stack Class
class StackX {

   private int maxSize;    // size of stack array
   private double[] stackArray;
   private int top;           //top of the stack

   public StackX(int s) {   // constructor
          
    maxSize = s;       // set array size
    stackArray = new double[maxSize];
    top = -1;             // no items
   }

   public void push(double j) {
         
	// check whether stack is full
	    if (top == maxSize - 1)
	      System.out.println("Stack is full");
	    else
	      stackArray[++top] = j;
    }

    public double pop() {
        if (top == -1)
            return -99;
        else
            return stackArray[top--];
    }
        
    public double peek() {
        if (top == -1)
            return -99;
        else
            return stackArray[top];
    }

    //Stack isEmpty method
    public boolean isEmpty(){
        return(top == -1);
    }
    
    //Stack isEmpty method
    public boolean isFull(){
        return (top == (maxSize -1));
    }
}