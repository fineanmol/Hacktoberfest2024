//Question Link= https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


import java.util.*;

public class BestTimeToBuyAndSellStockOne{

    public static void main(String[] args) throws Exception { 
      int prices[]={1,3,4,2,6,1,6};
      System.out.println(maxProfit(prices));
    }


    public static int maxProfit(int[] prices) {
          Map<String,Integer> mp=new HashMap<>();
          return solve(prices,0,true,1,mp);
    }

    public static int solve(int price[],int i,boolean canBuy,int count,Map<String,Integer> mp){

        if(i>=price.length || count<=0) return 0;

          String key=i+"!"+canBuy+"!"+count;

        if(mp.containsKey(key)) return mp.get(key);

        if(canBuy){

           int idle=solve(price,i+1,canBuy,count,mp);
           int buying=(-1*price[i])+solve(price,i+1,false,count,mp);
           mp.put(key,Math.max(idle,buying));
           return mp.get(key);

        }else{

           int idle=solve(price,i+1,canBuy,count,mp);
           int selling=price[i]+solve(price,i+1,true,count-1,mp);
           mp.put(key,Math.max(idle,selling)); 
           return mp.get(key);

        }
    }
  }
