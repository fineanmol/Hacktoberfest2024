public boolean containsDups(int[] arr) {
    if(arr==null || arr.length==0)
        return false;
 
    HashSet<Integer> s = new HashSet<Integer>();
    for(int i: arr){
        if(!s.add(i)){
            return true;
        }
    }
 
    return false;
}
