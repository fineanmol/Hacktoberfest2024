<h2><a href="https://leetcode.com/problems/reach-end-of-array-with-max-score">3528. Reach End of Array With Max Score</a></h2><h3>Medium</h3><hr><p>You are given an integer array <code>nums</code> of length <code>n</code>.</p>

<p>Your goal is to start at index <code>0</code> and reach index <code>n - 1</code>. You can only jump to indices <strong>greater</strong> than your current index.</p>

<p>The score for a jump from index <code>i</code> to index <code>j</code> is calculated as <code>(j - i) * nums[i]</code>.</p>

<p>Return the <strong>maximum</strong> possible <b>total score</b> by the time you reach the last index.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,3,1,5]</span></p>

<p><strong>Output:</strong> 7</p>

<p><strong>Explanation:</strong></p>

<p>First, jump to index 1 and then jump to the last index. The final score is <code>1 * 1 + 2 * 3 = 7</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,3,1,3,2]</span></p>

<p><strong>Output:</strong> 16</p>

<p><strong>Explanation:</strong></p>

<p>Jump directly to the last index. The final score is <code>4 * 4 = 16</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>
