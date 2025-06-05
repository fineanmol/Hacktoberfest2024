<h2><a href="https://leetcode.com/problems/distribute-coins-in-binary-tree/?envType=daily-question&envId=2024-05-18">979. Distribute Coins in Binary Tree</a></h2><h3>Medium</h3><hr><p>You are given the <code>root</code> of a binary tree with <code>n</code> nodes where each <code>node</code> in the tree has <code>node.val</code> coins. There are <code>n</code> coins in total throughout the whole tree.</p>

<p>In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.</p>

<p>Return <em>the <strong>minimum</strong> number of moves required to make every node have <strong>exactly</strong> one coin</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/01/18/tree1.png" style="width: 250px; height: 236px;" />
<pre>
<strong>Input:</strong> root = [3,0,0]
<strong>Output:</strong> 2
<strong>Explanation: </strong>From the root of the tree, we move one coin to its left child, and one coin to its right child.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/01/18/tree2.png" style="width: 250px; height: 236px;" />
<pre>
<strong>Input:</strong> root = [0,3,0]
<strong>Output:</strong> 3
<strong>Explanation: </strong>From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is <code>n</code>.</li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= Node.val &lt;= n</code></li>
	<li>The sum of all <code>Node.val</code> is <code>n</code>.</li>
</ul>
