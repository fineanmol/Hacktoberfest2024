<h2><a href="https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/?envType=daily-question&envId=2023-10-10">2119. Minimum Number of Operations to Make Array Continuous</a></h2><h3>Hard</h3><hr><p>You are given an integer array <code>nums</code>. In one operation, you can replace <strong>any</strong> element in <code>nums</code> with <strong>any</strong> integer.</p>

<p><code>nums</code> is considered <strong>continuous</strong> if both of the following conditions are fulfilled:</p>

<ul>
	<li>All elements in <code>nums</code> are <strong>unique</strong>.</li>
	<li>The difference between the <strong>maximum</strong> element and the <strong>minimum</strong> element in <code>nums</code> equals <code>nums.length - 1</code>.</li>
</ul>

<p>For example, <code>nums = [4, 2, 5, 3]</code> is <strong>continuous</strong>, but <code>nums = [1, 2, 3, 5, 6]</code> is <strong>not continuous</strong>.</p>

<p>Return <em>the <strong>minimum</strong> number of operations to make </em><code>nums</code><em> </em><strong><em>continuous</em></strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,2,5,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong>&nbsp;nums is already continuous.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,5,6]
<strong>Output:</strong> 1
<strong>Explanation:</strong>&nbsp;One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,10,100,1000]
<strong>Output:</strong> 3
<strong>Explanation:</strong>&nbsp;One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>
