<h2><a href="https://leetcode.com/problems/number-of-wonderful-substrings">1915. Number of Wonderful Substrings</a></h2><h3>Medium</h3><hr><p>A <strong>wonderful</strong> string is a string where <strong>at most one</strong> letter appears an <strong>odd</strong> number of times.</p>

<ul>
	<li>For example, <code>&quot;ccjjc&quot;</code> and <code>&quot;abab&quot;</code> are wonderful, but <code>&quot;ab&quot;</code> is not.</li>
</ul>

<p>Given a string <code>word</code> that consists of the first ten lowercase English letters (<code>&#39;a&#39;</code> through <code>&#39;j&#39;</code>), return <em>the <strong>number of wonderful non-empty substrings</strong> in </em><code>word</code><em>. If the same substring appears multiple times in </em><code>word</code><em>, then count <strong>each occurrence</strong> separately.</em></p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> word = &quot;aba&quot;
<strong>Output:</strong> 4
<strong>Explanation:</strong> The four wonderful substrings are underlined below:
- &quot;<u><strong>a</strong></u>ba&quot; -&gt; &quot;a&quot;
- &quot;a<u><strong>b</strong></u>a&quot; -&gt; &quot;b&quot;
- &quot;ab<u><strong>a</strong></u>&quot; -&gt; &quot;a&quot;
- &quot;<u><strong>aba</strong></u>&quot; -&gt; &quot;aba&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> word = &quot;aabb&quot;
<strong>Output:</strong> 9
<strong>Explanation:</strong> The nine wonderful substrings are underlined below:
- &quot;<strong><u>a</u></strong>abb&quot; -&gt; &quot;a&quot;
- &quot;<u><strong>aa</strong></u>bb&quot; -&gt; &quot;aa&quot;
- &quot;<u><strong>aab</strong></u>b&quot; -&gt; &quot;aab&quot;
- &quot;<u><strong>aabb</strong></u>&quot; -&gt; &quot;aabb&quot;
- &quot;a<u><strong>a</strong></u>bb&quot; -&gt; &quot;a&quot;
- &quot;a<u><strong>abb</strong></u>&quot; -&gt; &quot;abb&quot;
- &quot;aa<u><strong>b</strong></u>b&quot; -&gt; &quot;b&quot;
- &quot;aa<u><strong>bb</strong></u>&quot; -&gt; &quot;bb&quot;
- &quot;aab<u><strong>b</strong></u>&quot; -&gt; &quot;b&quot;
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> word = &quot;he&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> The two wonderful substrings are underlined below:
- &quot;<b><u>h</u></b>e&quot; -&gt; &quot;h&quot;
- &quot;h<strong><u>e</u></strong>&quot; -&gt; &quot;e&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word</code> consists of lowercase English letters from <code>&#39;a&#39;</code>&nbsp;to <code>&#39;j&#39;</code>.</li>
</ul>