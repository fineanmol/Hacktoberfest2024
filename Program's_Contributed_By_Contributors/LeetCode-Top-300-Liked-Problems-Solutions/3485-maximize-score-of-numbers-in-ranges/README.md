<h2><a href="https://leetcode.com/problems/maximize-score-of-numbers-in-ranges">3485. Maximize Score of Numbers in Ranges</a></h2><h3>Medium</h3><hr><p>You are given an array of integers <code>start</code> and an integer <code>d</code>, representing <code>n</code> intervals <code>[start[i], start[i] + d]</code>.</p>

<p>You are asked to choose <code>n</code> integers where the <code>i<sup>th</sup></code> integer must belong to the <code>i<sup>th</sup></code> interval. The <strong>score</strong> of the chosen integers is defined as the <strong>minimum</strong> absolute difference between any two integers that have been chosen.</p>

<p>Return the <strong>maximum</strong> <em>possible score</em> of the chosen integers.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">start = [6,0,3], d = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>The maximum possible score can be obtained by choosing integers: 8, 0, and 4. The score of these chosen integers is <code>min(|8 - 0|, |8 - 4|, |0 - 4|)</code> which equals 4.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">start = [2,6,13,13], d = 5</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p>The maximum possible score can be obtained by choosing integers: 2, 7, 13, and 18. The score of these chosen integers is <code>min(|2 - 7|, |2 - 13|, |2 - 18|, |7 - 13|, |7 - 18|, |13 - 18|)</code> which equals 5.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= start.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= start[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= d &lt;= 10<sup>9</sup></code></li>
</ul>
