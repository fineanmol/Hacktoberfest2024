class Solution {
    public boolean wordPattern(String pattern, String s) {
        
        String[] arr= s.split(" ");
        HashMap<Character, String> map = new HashMap<>();
        
        if(arr.length!= pattern.length())
            return false;
        
        for(int i = 0; i<arr.length; i++) {
            if(map.containsKey(pattern.charAt(i))) {
                if(!map.get(pattern.charAt(i)).equals(arr[i]))
                    return false;
                
            }
            
            else
                if(map.containsValue(arr[i]))
                    return false;
                map.put(pattern.charAt(i), arr[i]);
        }
        
        return true;
    }
}
