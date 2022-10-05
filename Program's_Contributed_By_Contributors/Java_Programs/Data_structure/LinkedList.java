class LinkList{
    //if we do not define constructors than class will call constructor implicitly and assign null and 0 according to data type
    int info;
    LinkList next,ptr,start,n;
    LinkList(){
        // this.start=null; //even without this program will work as implicit default constructor has given values 
    }    
    LinkList(int info){
        this.info=info;
        // this.next=null; //even without this program will work as implicit default constructor has given values 
    }    
    
    void add(int info){
        n=new LinkList(info);
        if(start==null){
            start=n;            
        }
        else{
            ptr=start;
            while(ptr.next!=null){
                ptr=ptr.next;
            }
            ptr.next=n; // !!important :how it is reflected to start : since ptr has a referance of start so any changes in ptr reflects to start .
        }
    }


    void push(int info){
        n=new LinkList(info);
        if(start==null){
            start=n;
        }
        else{
            n.next=start;  //only this code can do all work
            start=n;
        }
    }
    
    void add(int info,int index){
        n=new LinkList(info);
        if(start==null){
            start=n;
        }
        else if(index==0){
            push(info);
        }        
        else{            
            ptr=start;
            int count=1;
            while(count<index && ptr!=null){  //can be modified to ptr.next!=null
                ptr=ptr.next;
                count++;
            }
            if(ptr==null || ptr.next==null){   //(not sure)can be ommited of upper condition is ptr.next!=null
                add(info);
            }
            else{
                n.next=ptr.next;
                ptr.next=n;
            }
        }
    }

    void after(int element,int info){
        n=new LinkList(info);
        ptr=start;
        while(ptr.info!=element && ptr!=null){
            ptr=ptr.next;
        }
        if(ptr!=null){
            n.next=ptr.next;
            ptr.next=n;
        }
    }

    void before(int element,int info){
        n=new LinkList(info);
        ptr=start;
        LinkList preptr=new LinkList();
        while(ptr.info!=element && ptr!=null){
            preptr=ptr;
            ptr=ptr.next;
        }      
        if(ptr!=null){
            n.next=ptr;
            preptr.next=n; //it is reflected to ptr then to start
        }  
    }
    
    LinkList pop(){ //deleting at beggining
        if(start==null){
            System.out.println("Underflow");
            return null;
        }
        LinkList temp=start;
        start=start.next;//refrence or address changed
        temp.next=null; //it is not reflected to start as start has new address
        return temp;
    }

    void delete(){
        if(start==null){
            System.out.println("Underflow");
        }
        else if(start.next==null){
            start=null;
        }
        else{
            LinkList ptr=start;
            while(ptr.next.next!=null){
                ptr=ptr.next;
            }
            ptr.next=null;
        }
    }

    void delete(int pos){
        if(pos==1){
            pop();
        }
        else{
            ptr=start;
            int count=1;
            while(count<pos-1 && ptr.next!=null){ //one place before LinkList that has to be deleted
                ptr=ptr.next;
                count++;
            }
            
            if(ptr.next!=null){
                LinkList x=ptr.next;
                ptr.next=x.next;
                x=null;                
            }
            else{
                System.out.println("Overflow");
            }
        }
    }
    int mid(){
        LinkList t=start;
        LinkList r=start;
        while(r!=null && r.next!=null){ //or while(r.next!=null && r.next.next!=null) First is appropriate
            t=t.next;
            r=r.next.next;
        }
        return t.info;
    }


    int get(int index){
        ptr=start;
        if(ptr==null){
            System.out.print("Empty List=> ");
            return -1;
        }
        else{
            int count=1;
            while(count<=index && ptr!=null){ //for position ie. start index=1  count<index
                ptr=ptr.next;
                count++;
            }
            if(ptr==null){
                System.out.print("Overflow=> ");
                return -1;
            }
    }
    return ptr.info;
    }
    
    int nthLast(int n){
        if(start==null){
            System.out.print("Empty List=> ");
            return -1;
        }
        else{
            int count=1;
            LinkList t=start;//turtule rabbit approach
            LinkList r=start; 
            while(count<n && r!=null){ //traversing r to nth pos
                r=r.next;
                count++;
            }
            if(r==null){
                System.out.print("Overflow=> ");
                return -1;
            }
            else{
                while(r.next!=null){ //traversing to last position from nth position
                    t=t.next; //traversing to nth last
                    r=r.next;
                }
            }
            return t.info;
        }
    }
    
    void trimSorted(){ //only applies to sorted Linked list
        if(start==null){
            System.out.println("Underflow");
        }
        else{
            ptr=start;
            LinkList x;
            while(ptr.next!=null){
                if(ptr.info==ptr.next.info){
                    x=ptr.next;
                    ptr.next=x.next;
                    x=null;
                }
                else{
                    ptr=ptr.next;
                }
            }
        }
    }
    void print_Even_Odd(){
        if(start==null){
            System.out.println("UnderFlow");
        }
        else{
            ptr=start;
            LinkList even=new LinkList();
            LinkList odd=new LinkList();
            while(ptr!=null){                
                if(ptr.info%2==0){
                even.add(ptr.info);
                }
                else{
                    odd.add(ptr.info);                 
                }
                ptr=ptr.next;
            }
        System.out.print("Even Nos ");
        even.print();
        System.out.print("Odd Nos ");
        odd.print();
        }
    }
    
        void swap(int x,int y){    ///new approach take pre and post pointer of linked list
        ptr=start;
        LinkList preptr=null;
        while(ptr!=null && ptr.info!=x){
            preptr=ptr;
            ptr=ptr.next;
        }
        LinkList ptrX=ptr;
        LinkList preptrX=preptr;
        ptr=start;
        preptr=null;
        while(ptr!=null && ptr.info!=y){
            preptr=ptr;
            ptr=ptr.next;
        }
        LinkList ptrY=ptr;
        LinkList preptrY=preptr;

        LinkList temp=ptrY.next;
        ptrY.next=ptrX.next;
        ptrX.next=temp;
        if(preptrX==null){
            start=ptrY;
            preptrY.next=ptrX;
        }
        if(preptrY==null){
            start=ptrX;
            preptrX.next=ptrY;
        }
        if(preptrX!=null && preptrY!=null){
            preptrX.next=ptrY;
            preptrY.next=ptrX;
        }
    }  
    
    void reverse(){
        if(start==null || start.next==null){
            return;
        }
        LinkList prev=null;
        ptr=start;
        while(ptr!=null){
            LinkList temp=ptr.next;
            ptr.next=prev;
            prev=ptr;
            ptr=temp;
        }
        start=prev;
    }
    
    LinkList reverseInNumbers(LinkList start,int k){ 
        if(start==null || start.next==null){
            return start;
        }
        ptr=start;
        LinkList next=null,prev=null;
        int count=0;
        while(count<k && ptr!=null){
            next=ptr.next;
            ptr.next=prev;
            prev=ptr;
            ptr=next;
            count++;
        }
        if(next!=null){
            start.next=reverseInNumbers(next, k); //start is at end of first reversed linked sublist ,prev.next has start 
        }
        return prev; //head of list
    }

    void rotateClockwise(int n){
        if(n==0){
            return;
        }
        LinkList t=start,r=start;
        int count=1;
        while(count<=n && r!=null){ //for one place after nth 
            r=r.next;
            count++;
        }
        if(r==null){
            return;
        }
        while(r.next!=null){ // t will be one place before nth last
            t=t.next;
            r=r.next;
        }
        LinkList p=t.next;
        r.next=start;
         t.next=null;
        start=p;        
    }

    void rotateCounterClockwise(int n){
        if(n==0){
            return;
        }
        LinkList ptr=start,r=start;
        while(ptr.next!=null){
            ptr=ptr.next;
        }
        int count=1;
        while(count<n && r!=null){
            r=r.next;
            count++;
        }
        if(r==null){
            return;
        }
        ptr.next=start;
        start=r.next;
        r.next=null;
    }

    void BubbleSort(){ //find error
        LinkList ptr,prev=null,end=start;
        while(end.next!=null){
            end=end.next;
        }
        while(end!=start){
        ptr=start;
        while(ptr!=end){
            if(ptr.next.info<ptr.info){
                int temp=ptr.info;
                ptr.info=ptr.next.info;
                ptr.next.info=temp;
                prev=ptr;
                ptr=ptr.next;
            }
        }
        end=prev;
    }
    }

    void print(){
        if(start==null){
            System.out.println("No element in list");
        }
        else{
            ptr=start;
            while(ptr!=null){
                System.out.print(ptr.info+" ");
                ptr=ptr.next;
            }
        }
        System.out.println();
    }

}
class SingleLinkedList{
    static LinkList tailReverse(LinkList ptr,LinkList prev){
        if(ptr==null){
            ptr=prev;
            return ptr;
        }
        LinkList temp=ptr.next;
        ptr.next=prev;
        prev=ptr;
        ptr=temp;
        return tailReverse(ptr,prev);
    }

    public static void main(String[] args) {
        LinkList x=new LinkList();
        x.pop();
        x.add(15);
        x.add(12);
        x.add(17);
        x.add(16);
        x.push(7);
        x.push(6);
        x.push(3);
        x.push(1);
        x.print();
        x.add(13,4);
        x.add(64,16);
        x.add(34,1);
        x.print();
        x.before(17, 156);
        x.before(7, 214);
        x.after(3, 23);
        x.after(3,10);
        x.print();
        x.pop();
        x.pop();
        x.pop();
        x.print();
        x.delete(6);
        x.delete(100);
        x.delete(3);
        x.delete(12);
        x.print();
        x.delete();
        x.delete();
        x.delete();
        x.add(34);
        x.print();  
        System.out.println(x.mid());  
        System.out.println(x.get(0));
        System.out.println(x.get(1)); 
        System.out.println(x.get(2));
        System.out.println(x.get(100));
        System.out.println(x.nthLast(5));
        System.out.println(x.nthLast(0));
        System.out.println(x.nthLast(50));
        LinkList sorted=new LinkList();
        sorted.add(1);
        sorted.add(2);
        sorted.add(2);
        sorted.add(2);
        sorted.add(3);
        sorted.add(3);
        sorted.add(4);
        sorted.add(4);
        sorted.add(4);
        sorted.add(4);
        sorted.add(5);
        sorted.add(5);
        sorted.add(6);
        sorted.add(6);
        sorted.add(7);
        sorted.add(7);
        sorted.add(8);
        sorted.add(9);
        sorted.add(9);
        sorted.print();
        sorted.trimSorted();
        sorted.print();
        x.print();
        x.add(1,0);
        x.add(2,1);
        x.add(5,67);
        x.print();
        LinkList y=new LinkList();
        y.add(1);
        y.add(2);
        y.add(3);
        y.print();
        y.add(34,1);
        y.add(45);
        y.add(22);
        y.add(89);
        y.add(33);
        y.print();
        y.print_Even_Odd();
        LinkList sts=new LinkList();
        sts.add(1);
        sts.add(2);
        sts.add(3);
        sts.add(4);
        sts.add(5); 
        sts.add(5);
        sts.add(7);
        sts.add(8);
        sts.add(9);
        sts.add(10);
        sts.add(11);
        sts.add(12);
        sts.print();
        sts.reverse();
        sts.print();
        sts.swap(11, 1);
        sts.swap(12, 11);
        // sts.swap(100, 2); //throws errors
        sts.print();    
        sts.rotateClockwise(2);
        sts.print();  
         sts.start=sts.reverseInNumbers(sts.start, 3);
         sts.print();
        //  sts.BubbleSort();
        //  sts.print();
        System.out.println(sts.nthLast(1));
        sts.rotateClockwise(4);
        sts.print();
        sts.rotateCounterClockwise(4);
        sts.print();
        sts.start=tailReverse(sts.start, null);
        sts.print();
    }
}