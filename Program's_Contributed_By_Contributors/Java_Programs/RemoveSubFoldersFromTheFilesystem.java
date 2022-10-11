// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
package com.sharan;
// Revisit
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
// O(nLog(n)) 88.23% Faster
public class RemoveSubFoldersFromTheFilesystem {
    public static void main(String[] args) {
        String[] arr = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
        System.out.println(removeSubfolders(arr));
    }
    public static List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);
        List<String> ans = new ArrayList();
        String main = folder[0] + "/";
        ans.add(folder[0]);
        for (int i = 1; i < folder.length; i++){
            if(!(folder[i].contains(main) && folder[i].startsWith(main))) {
                ans.add(folder[i]);
                main = folder[i]+"/";
            }
        }
        return ans;
    }
}
