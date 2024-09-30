<h2><a href="https://leetcode.com/problems/smallest-string-starting-from-leaf">988. Smallest String Starting From Leaf</a></h2><h3>Medium</h3><hr><p>You are given the <code>root</code> of a binary tree where each node has a value in the range <code>[0, 25]</code> representing the letters <code>&#39;a&#39;</code> to <code>&#39;z&#39;</code>.</p>

<p>Return <em>the <strong>lexicographically smallest</strong> string that starts at a leaf of this tree and ends at the root</em>.</p>

<p>As a reminder, any shorter prefix of a string is <strong>lexicographically smaller</strong>.</p>

<ul>
	<li>For example, <code>&quot;ab&quot;</code> is lexicographically smaller than <code>&quot;aba&quot;</code>.</li>
</ul>

<p>A leaf of a node is a node that has no children.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/01/30/tree1.png" style="width: 534px; height: 358px;" />
<pre>
<strong>Input:</strong> root = [0,1,2,3,4,3,4]
<strong>Output:</strong> &quot;dba&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/01/30/tree2.png" style="width: 534px; height: 358px;" />
<pre>
<strong>Input:</strong> root = [25,1,3,1,3,0,2]
<strong>Output:</strong> &quot;adz&quot;
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/02/01/tree3.png" style="height: 490px; width: 468px;" />
<pre>
<strong>Input:</strong> root = [2,2,1,null,1,0,null,0]
<strong>Output:</strong> &quot;abc&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 8500]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 25</code></li>
</ul>
