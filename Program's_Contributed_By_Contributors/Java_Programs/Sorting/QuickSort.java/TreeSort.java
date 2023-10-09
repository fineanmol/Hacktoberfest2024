import java.util.*;
class TreeNode {
    int data;
    TreeNode left, right;

    public TreeNode(int data) {
        this.data = data;
        left = right = null;
    }
}

public class TreeSort {
    private TreeNode root;

    public void insert(int data) {
        root = insertRec(root, data);
    }

    private TreeNode insertRec(TreeNode root, int data) {
        if (root == null) {
            root = new TreeNode(data);
            return root;
        }

        if (data < root.data) {
            root.left = insertRec(root.left, data);
        } else if (data > root.data) {
            root.right = insertRec(root.right, data);
        }

        return root;
    }

    public void inOrderTraversal(TreeNode root, int[] arr, int[] index) {
        if (root != null) {
            inOrderTraversal(root.left, arr, index);
            arr[index[0]++] = root.data;
            inOrderTraversal(root.right, arr, index);
        }
    }

    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        TreeSort treeSort = new TreeSort();

        // Insert elements into the binary search tree
        for (int value : arr) {
            treeSort.insert(value);
        }

        // Perform in-order traversal to get sorted elements
        int[] sortedArr = new int[arr.length];
        int[] index = {0};
        treeSort.inOrderTraversal(treeSort.root, sortedArr, index);

        System.out.println("Original array: " + Arrays.toString(arr));
        System.out.println("Sorted array: " + Arrays.toString(sortedArr));
    }
}
