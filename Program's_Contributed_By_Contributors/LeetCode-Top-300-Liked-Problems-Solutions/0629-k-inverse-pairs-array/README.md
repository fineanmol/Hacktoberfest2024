<h2><a href="https://leetcode.com/problems/k-inverse-pairs-array">629. K Inverse Pairs Array</a></h2><h3>Hard</h3><hr><p>For an integer array <code>nums</code>, an <strong>inverse pair</strong> is a pair of integers <code>[i, j]</code> where <code>0 &lt;= i &lt; j &lt; nums.length</code> and <code>nums[i] &gt; nums[j]</code>.</p>

<p>Given two integers n and k, return the number of different arrays consist of numbers from <code>1</code> to <code>n</code> such that there are exactly <code>k</code> <strong>inverse pairs</strong>. Since the answer can be huge, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 3, k = 0
<strong>Output:</strong> 1
<strong>Explanation:</strong> Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 3, k = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong> The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= k &lt;= 1000</code></li>
</ul>
