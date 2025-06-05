<h2><a href="https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal">2602. Minimum Operations to Make All Array Elements Equal</a></h2><h3>Medium</h3><hr><p>You are given an array <code>nums</code> consisting of positive integers.</p>

<p>You are also given an integer array <code>queries</code> of size <code>m</code>. For the <code>i<sup>th</sup></code> query, you want to make all of the elements of <code>nums</code> equal to<code> queries[i]</code>. You can perform the following operation on the array <strong>any</strong> number of times:</p>

<ul>
	<li><strong>Increase</strong> or <strong>decrease</strong> an element of the array by <code>1</code>.</li>
</ul>

<p>Return <em>an array </em><code>answer</code><em> of size </em><code>m</code><em> where </em><code>answer[i]</code><em> is the <strong>minimum</strong> number of operations to make all elements of </em><code>nums</code><em> equal to </em><code>queries[i]</code>.</p>

<p><strong>Note</strong> that after each query the array is reset to its original state.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,1,6,8], queries = [1,5]
<strong>Output:</strong> [14,10]
<strong>Explanation:</strong> For the first query we can do the following operations:
- Decrease nums[0] 2 times, so that nums = [1,1,6,8].
- Decrease nums[2] 5 times, so that nums = [1,1,1,8].
- Decrease nums[3] 7 times, so that nums = [1,1,1,1].
So the total number of operations for the first query is 2 + 5 + 7 = 14.
For the second query we can do the following operations:
- Increase nums[0] 2 times, so that nums = [5,1,6,8].
- Increase nums[1] 4 times, so that nums = [5,5,6,8].
- Decrease nums[2] 1 time, so that nums = [5,5,5,8].
- Decrease nums[3] 3 times, so that nums = [5,5,5,5].
So the total number of operations for the second query is 2 + 4 + 1 + 3 = 10.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,9,6,3], queries = [10]
<strong>Output:</strong> [20]
<strong>Explanation:</strong> We can increase each value in the array to 10. The total number of operations will be 8 + 1 + 4 + 7 = 20.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>m == queries.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], queries[i] &lt;= 10<sup>9</sup></code></li>
</ul>
