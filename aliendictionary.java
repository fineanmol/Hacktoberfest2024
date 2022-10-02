
class Solution
{
    public List<Integer> topo(int V,List<List<Integer>> adj)
    {
        int indegree[]=new int[V];
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj.get(i).size();j++)
            {
                indegree[adj.get(i).get(j)]+=1;
            }
        }
        
        Queue<Integer> qu=new LinkedList<>();
    
        for(int i=0;i<V;i++)
            if(indegree[i]==0)
                qu.add(i);
                
        List<Integer> ans=new ArrayList<>();
        
        while(qu.size()>0)
        {
            int rm=qu.remove();
            ans.add(rm);
            
            for(int i=0;i<adj.get(rm).size();i++)
            {
                int vtx=adj.get(rm).get(i);
                indegree[vtx]-=1;
                if(indegree[vtx]==0)
                {
                    qu.add(vtx);
                }
            }
            
        }
        return ans;
    }
    public String findOrder(String [] dict, int N, int K)
    {
        // Write your code here
        
        List<List<Integer>> adj=new ArrayList<>();
        
        for(int i=0;i<K;i++)
            adj.add(new ArrayList<>());
        
        for(int i=0;i<N-1;i++)
        {
            String s1=dict[i];
            String s2=dict[i+1];
            
            int len=Math.min(s1.length(),s1.length());
            for(int j=0;j<len;j++)
            {
                if(s1.charAt(j)!=s2.charAt(j))
                {    adj.get(s1.charAt(j)-'a').add(s2.charAt(j)-'a');
                     break;
                }
            }
        }
        
        List<Integer> topoSort=topo(K,adj);
        
        String s="";
        
        for(int i=0;i<topoSort.size();i++)
          
        {
            s+=(char)(topoSort.get(i)+(int)'a');
        }
        
        
        return s;
        
    }
}
