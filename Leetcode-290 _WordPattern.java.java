import java.util.HashMap;

class Solution 
{
    public boolean wordPattern(String pattern, String s)
    {
        // O(n) time | O(n) space
        HashMap<Character, String> myMap = new HashMap<>();
        String[] words = s.split(" ");
        
        // pattern = " a b c" && s = "mice cat dog chicken" then return false directly
        if(pattern.length() != words.length)    return false;

        // update myMap in for-loop
        for(int i = 0; i < words.length; i++)
        {
            char ch = pattern.charAt(i);
            
            if(!myMap.containsKey(ch))
            {
                // we need to check the case that, we dont' have such a key in map but value already exists
                // for example, pattern = "abab" && s = "dog dog dog dog"
                if(myMap.containsValue(words[i]))
                    return false;
                
                myMap.put(ch, words[i]);
            }
            else
                if(!myMap.get(ch).equals(words[i]))
                    return false;
        }
        return true;
    }
}