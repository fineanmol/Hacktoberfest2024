<h2><a href="https://leetcode.com/problems/number-of-arithmetic-triplets/">2442. Number of Arithmetic Triplets</a></h2><h3>Easy</h3><hr><p>You are given a <strong>0-indexed</strong>, <strong>strictly increasing</strong> integer array <code>nums</code> and a positive integer <code>diff</code>. A triplet <code>(i, j, k)</code> is an <strong>arithmetic triplet</strong> if the following conditions are met:</p>

<ul>
	<li><code>i &lt; j &lt; k</code>,</li>
	<li><code>nums[j] - nums[i] == diff</code>, and</li>
	<li><code>nums[k] - nums[j] == diff</code>.</li>
</ul>

<p>Return <em>the number of unique <strong>arithmetic triplets</strong>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,4,6,7,10], diff = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong>
(1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
(2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,5,6,7,8,9], diff = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong>
(0, 2, 4) is an arithmetic triplet because both 8 - 6 == 2 and 6 - 4 == 2.
(1, 3, 5) is an arithmetic triplet because both 9 - 7 == 2 and 7 - 5 == 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 200</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 200</code></li>
	<li><code>1 &lt;= diff &lt;= 50</code></li>
	<li><code>nums</code> is <strong>strictly</strong> increasing.</li>
</ul>
