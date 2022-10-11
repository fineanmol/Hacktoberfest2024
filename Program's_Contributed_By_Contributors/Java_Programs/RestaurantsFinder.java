// https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
package com.sharan;
// Incomplete Solution.
import java.util.ArrayList;
import java.util.List;
// Tyr in python.
public class RestaurantsFinder {
    public static void main(String[] args) {
        int[][] arr = {{1, 4, 1, 40, 10}, {2, 8, 0, 50, 5}, {3, 8, 1, 30, 4}, {4, 10, 0, 10, 3}, {5, 1, 1, 15, 1}};
        int vf = 1;
        int mp = 50;
        int md = 10;
        filterRestaurants(arr, vf, mp, md);
    }

    public static void filterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        System.out.println(isVeganFriendly(restaurants,veganFriendly,maxPrice,maxDistance));
    }
    public static List<Integer> isVeganFriendly(int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        ArrayList<Integer> ans = new ArrayList<>();
        ArrayList<Integer> ansFinal = new ArrayList<>();
        for (int i = 0; i < restaurants.length; i++) {
            if (restaurants[i][2] == veganFriendly) {
                if (restaurants[i][3] <= maxPrice) {
                    if (restaurants[i][4] <= maxDistance) {
                        ans.add(restaurants[i][1]);
                        ansFinal.add(restaurants[i][0]);
                    }
                }
            }
        }
        return ansFinal;
    }
}
