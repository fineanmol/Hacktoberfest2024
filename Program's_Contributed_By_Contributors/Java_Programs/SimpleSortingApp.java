package packageDA;

public class SimpleSortingApp {

	public static void main(String[] args) {
		
		SimpleSorting k = new SimpleSorting(7);
		k.insert(8);
		k.insert(7);
		k.insert(2);
		k.insert(6);
		k.display();
		k.bubbleSort();
		k.display();

	}

}

class SimpleSorting {
	 private int[] a;//ref to array a
	 private int nElems;//number of data items
	 //------------------------------------------------------
	 public SimpleSorting(int max) {
	//constructor
		 this.a = new int[max];
		 this.nElems=0;
	 }
	 public void insert(int value){
	//put element into array
		 if(nElems==a.length) {
			 System.out.print("Array is full");
			 return;
		 }
		 this.a[this.nElems]=value;
		 this.nElems++;
		// System.out.print(value);
	 }
	 public void display(){
	//display array contents
		 System.out.println("Array content :");
		 for(int i=0;i<this.nElems;i++) {
			 System.out.println(this.a[i]);
		 }
		 System.out.println();
		 
	 }											// 0, 1, 2, 3, 4, 5
	 private void swap(int index1, int index2) // [2, 3, 4, 5, 6, 8]
	 {
	//swaps array elements in a[index1] and a[index2]
		 int temp;
		 temp = a[index1];
		 a[index1] = a[index2];
		 a[index2]= temp;
	 }
	 
//---------------------Bubble sort--------------------------------
	 
	 public void bubbleSort() {

		 for (int i=0;i<nElems-1;i++) {
			for(int j =0 ; j < (nElems-1)-i ;j++ ) {
				if (a[j]> a[j+1]) {
					swap(j, j+1);
				}
			}
		 }
		 System.out.println("Numbers sorted using Bubble sorting");
	 }

	 
//---------------------Selection sort--------------------------------
	 
	 public void selectionSort() {
	
		 for(int i =0; i<nElems-1;i++) {
			 int minIndex = i;
			 for(int j =i+1; j< nElems;j++) {
				 if(a[j]< a[minIndex]) {
					 minIndex =j;
				 }
			 }
			 swap(i,minIndex);
		 }
		 System.out.println("Numbers sorted using selection sorting");
	 }
	 
	 
//---------------------Insertion sort--------------------------------
	 
	 public void insertionSort() {
	
		   for(int i=1;i<nElems;i++){
		        int key =a[i];
		        int j = i -1;
		        while(j>=0){
		            if(a[j]>key){
		                a[j+1] = a[j];
		            } else {
		                break;
		            }
		            j--;
		        }
		        a[j+1] = key;
		    }
		    System.out.println("Numbers are sorted using insertionSort...");
		    
		    
		    
		    
	 }}   
		    
