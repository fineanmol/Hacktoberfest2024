//https://leetcode.com/problems/best-poker-hand/

class BestPokerHand {
    public String bestHand(int[] ranks, char[] suits) {
        
        HashSet<Character> answerSuit = new HashSet<>();
        for(char suit: suits)
            answerSuit.add(suit);
        if(answerSuit.size() == 1)
            return "Flush";
        
        
        HashMap<Integer, Integer> answerRank = new HashMap<>();
        int max = 0;
        
        for(int i=0;i<ranks.length;i++) {
            answerRank.put(ranks[i], answerRank.getOrDefault(ranks[i], 0)+1);
            max = Math.max(max, answerRank.get(ranks[i]));   
        }
        
        
        if(max >= 3)
            return "Three of a Kind";
        if(max == 2)
            return "Pair";
        return "High Card";
    }
}
