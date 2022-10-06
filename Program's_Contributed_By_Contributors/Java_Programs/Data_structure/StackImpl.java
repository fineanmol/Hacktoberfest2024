public class StackImpl {
	int top = 0;
	int MAX = 5;
	int[] a = new int[MAX]; 
	private boolean isFull() {
		if(top == MAX) {
			return true;
    }
    return false;
  }
  public void insert(int val) {
    if(isFull()) {
      System.out.println("Stack is full");
      return;
    }
    
    a[top++] = val;
  }
  
  private boolean isEmpty() {
    if(top == 0) {
      return true;
    }
    
    return false;
  }
  
  public int remove() {
    if(isEmpty()) {
      System.out.println("Stack is Empty");
      return Integer.MIN_VALUE;
    }
    
    return a[--top];
  }
  
  public int top() {
    if(isEmpty()) {
      System.out.println("Stack is Empty");
      return Integer.MIN_VALUE;
    }
    
    return a[top - 1];
  }
  public static void main(String[] args) {
    StackImpl a = new StackImpl();
    a.insert(12);
    a.insert(5);
    a.insert(34);
    a.insert(42);
    a.insert(91);
    a.insert(9);
    
    System.out.println(a.remove());
    a.insert(9);
    
    System.out.println("Top:" + a.top());
    
    System.out.println(a.remove());
    System.out.println(a.remove());
    System.out.println(a.remove());
    System.out.println(a.remove());
    System.out.println(a.remove());
    System.out.println(a.remove());
  }
}
