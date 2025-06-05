<h2><a href="https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-i">3543. Count Substrings That Satisfy K-Constraint I</a></h2><h3>Easy</h3><hr><p>You are given a <strong>binary</strong> string <code>s</code> and an integer <code>k</code>.</p>

<p>A <strong>binary string</strong> satisfies the <strong>k-constraint</strong> if <strong>either</strong> of the following conditions holds:</p>

<ul>
	<li>The number of <code>0</code>&#39;s in the string is at most <code>k</code>.</li>
	<li>The number of <code>1</code>&#39;s in the string is at most <code>k</code>.</li>
</ul>

<p>Return an integer denoting the number of <span data-keyword="substring-nonempty">substrings</span> of <code>s</code> that satisfy the <strong>k-constraint</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;10101&quot;, k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">12</span></p>

<p><strong>Explanation:</strong></p>

<p>Every substring of <code>s</code> except the substrings <code>&quot;1010&quot;</code>, <code>&quot;10101&quot;</code>, and <code>&quot;0101&quot;</code> satisfies the k-constraint.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;1010101&quot;, k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">25</span></p>

<p><strong>Explanation:</strong></p>

<p>Every substring of <code>s</code> except the substrings with a length greater than 5 satisfies the k-constraint.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;11111&quot;, k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">15</span></p>

<p><strong>Explanation:</strong></p>

<p>All substrings of <code>s</code> satisfy the k-constraint.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50 </code></li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
	<li><code>s[i]</code> is either <code>&#39;0&#39;</code> or <code>&#39;1&#39;</code>.</li>
</ul>
