<h2><a href="https://leetcode.com/problems/divide-array-into-arrays-with-max-difference">2966. Divide Array Into Arrays With Max Difference</a></h2><h3>Medium</h3><hr><p>You are given an integer array <code>nums</code> of size <code>n</code> and a positive integer <code>k</code>.</p>

<p>Divide the array into one or more arrays of size <code>3</code> satisfying the following conditions:</p>

<ul>
	<li><strong>Each</strong> element of <code>nums</code> should be in <strong>exactly</strong> one array.</li>
	<li>The difference between <strong>any</strong> two elements in one array is less than or equal to <code>k</code>.</li>
</ul>

<p>Return <em>a </em><strong>2D</strong><em> array containing all the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return <strong>any</strong> of them.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,4,8,7,9,3,5,1], k = 2
<strong>Output:</strong> [[1,1,3],[3,4,5],[7,8,9]]
<strong>Explanation:</strong> We can divide the array into the following arrays: [1,1,3], [3,4,5] and [7,8,9].
The difference between any two elements in each array is less than or equal to 2.
Note that the order of elements is not important.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,3,2,7,3], k = 3
<strong>Output:</strong> []
<strong>Explanation:</strong> It is not possible to divide the array satisfying all the conditions.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>n</code> is a multiple of <code>3</code>.</li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>
