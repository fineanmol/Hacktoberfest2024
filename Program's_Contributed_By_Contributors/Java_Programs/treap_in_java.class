import java.util.Random;

class Node {
    int key;
    int priority;
    Node left, right;

    Node(int key) {
        this.key = key;
        this.priority = new Random().nextInt(100); // Assign a random priority
        this.left = this.right = null;
    }
}

public class Treap {
    Node root;

    Node rotateRight(Node y) {
        Node x = y.left;
        Node T2 = x.right;

        x.right = y;
        y.left = T2;

        return x;
    }

    Node rotateLeft(Node x) {
        Node y = x.right;
        Node T2 = y.left;

        y.left = x;
        x.right = T2;

        return y;
    }

    Node insert(Node root, int key) {
        if (root == null)
            return new Node(key);

        if (key <= root.key) {
            root.left = insert(root.left, key);

            if (root.left.priority > root.priority)
                root = rotateRight(root);
        } else {
            root.right = insert(root.right, key);

            if (root.right.priority > root.priority)
                root = rotateLeft(root);
        }

        return root;
    }

    void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.println("Key: " + root.key + ", Priority: " + root.priority);
            inorder(root.right);
        }
    }

    public static void main(String[] args) {
        Treap treap = new Treap();

        // Insert keys with random priorities
        treap.root = treap.insert(treap.root, 10);
        treap.root = treap.insert(treap.root, 20);
        treap.root = treap.insert(treap.root, 5);

        // Print inorder traversal
        treap.inorder(treap.root);
    }
}
