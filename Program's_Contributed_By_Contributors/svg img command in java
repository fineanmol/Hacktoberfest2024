import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import org.apache.batik.dom.GenericDOMImplementation;
import org.apache.batik.svggen.SVGGraphics2D;
import org.w3c.dom.DOMImplementation;
import org.w3c.dom.Document;

class TreeNode {
    int data;
    TreeNode left;
    TreeNode right;
    
    public TreeNode(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
    
    public void insert(int data) {
        if (data < this.data) {
            if (this.left == null) {
                this.left = new TreeNode(data);
            } else {
                this.left.insert(data);
            }
        } else {
            if (this.right == null) {
                this.right = new TreeNode(data);
            } else {
                this.right.insert(data);
            }
        }
    }
}

public class BinaryTreeSVGExporter {
    public static void export(TreeNode root, String filename) throws IOException {
        DOMImplementation domImpl = GenericDOMImplementation.getDOMImplementation();
        Document doc = domImpl.createDocument(null, "svg", null);
        SVGGraphics2D svg = new SVGGraphics2D(doc);
        
        // Traverse the tree and draw the nodes and edges
        traverse(root, svg, 100, 50, 50);
        
        // Write the SVG file
        File file = new File(filename);
        FileWriter fw = new FileWriter(file);
        svg.stream(fw, true);
    }
    
    private static void traverse(TreeNode node, SVGGraphics2D svg, int x, int y, int dx) {
        if (node == null) {
            return;
        }
        
        // Draw the node
        svg.drawOval(x - 10, y - 10, 20, 20);
        svg.drawString(String.valueOf(node.data), x - 4, y + 4);
        
        // Draw the left child and edge
        if (node.left != null) {
            svg.drawLine(x, y, x - dx, y + 50);
            traverse(node.left, svg, x - dx, y + 50, dx / 2);
        }
        
        // Draw the right child and edge
        if (node.right != null) {
            svg.drawLine(x, y, x + dx, y + 50);
            traverse(node.right, svg, x + dx, y + 50, dx / 2);
        }
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(10);
        root.insert(5);
        root.insert(15);
        root.insert(3);
        root.insert(7);
        root.insert(13);
        root.insert(17);
        
        try {
            BinaryTreeSVGExporter.export(root, "binary_tree.svg");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
