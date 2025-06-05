<h2><a href="https://leetcode.com/problems/delete-node-in-a-linked-list/?envType=daily-question&envId=2024-05-05">237. Delete Node in a Linked List</a></h2><h3>Medium</h3><hr><p>There is a singly-linked list <code>head</code> and we want to delete a node <code>node</code> in it.</p>

<p>You are given the node to be deleted <code>node</code>. You will <strong>not be given access</strong> to the first node of <code>head</code>.</p>

<p>All the values of the linked list are <strong>unique</strong>, and it is guaranteed that the given node <code>node</code> is not the last node in the linked list.</p>

<p>Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:</p>

<ul>
	<li>The value of the given node should not exist in the linked list.</li>
	<li>The number of nodes in the linked list should decrease by one.</li>
	<li>All the values before <code>node</code> should be in the same order.</li>
	<li>All the values after <code>node</code> should be in the same order.</li>
</ul>

<p><strong>Custom testing:</strong></p>

<ul>
	<li>For the input, you should provide the entire linked list <code>head</code> and the node to be given <code>node</code>. <code>node</code> should not be the last node of the list and should be an actual node in the list.</li>
	<li>We will build the linked list and pass the node to your function.</li>
	<li>The output will be the entire list after calling your function.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/01/node1.jpg" style="width: 400px; height: 286px;" />
<pre>
<strong>Input:</strong> head = [4,5,1,9], node = 5
<strong>Output:</strong> [4,1,9]
<strong>Explanation: </strong>You are given the second node with value 5, the linked list should become 4 -&gt; 1 -&gt; 9 after calling your function.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/01/node2.jpg" style="width: 400px; height: 315px;" />
<pre>
<strong>Input:</strong> head = [4,5,1,9], node = 1
<strong>Output:</strong> [4,5,9]
<strong>Explanation: </strong>You are given the third node with value 1, the linked list should become 4 -&gt; 5 -&gt; 9 after calling your function.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of the nodes in the given list is in the range <code>[2, 1000]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
	<li>The value of each node in the list is <strong>unique</strong>.</li>
	<li>The <code>node</code> to be deleted is <strong>in the list</strong> and is <strong>not a tail</strong> node.</li>
</ul>
