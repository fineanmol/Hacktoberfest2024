class Solution {

    String prefix(String str[])
    {
        String fix =str[0];
        for(int i=1;i<str.length;i++)
        {
            fix = fixpre(fix ,str[i]);
        }
        return fix;
    }
    String fixpre (String s1, String s2)
    {
        int n=s1.length();
        int m=s2.length();
        String result="";
        for(int i=0,j=0;i<n && j<m ; i++,j++ )
        {
            if(s1.charAt(i)!=s2.charAt(j))
                break;
            result += s1.charAt(i);
        }
        return result;
    }

    public String longestCommonPrefix(String[] strs) {
        if(strs.length<=0)
            return "";
        String str =prefix(strs);
        if(str.length()> 0)
        {

            return str;
        }
        else
            return "";
    }
}