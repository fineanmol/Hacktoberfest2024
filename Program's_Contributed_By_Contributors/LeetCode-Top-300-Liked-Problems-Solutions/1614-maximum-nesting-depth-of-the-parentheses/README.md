<h2><a href="https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses">1614. Maximum Nesting Depth of the Parentheses</a></h2><h3>Easy</h3><hr><p>A string is a <strong>valid parentheses string</strong> (denoted <strong>VPS</strong>) if it meets one of the following:</p>

<ul>
	<li>It is an empty string <code>&quot;&quot;</code>, or a single character not equal to <code>&quot;(&quot;</code> or <code>&quot;)&quot;</code>,</li>
	<li>It can be written as <code>AB</code> (<code>A</code> concatenated with <code>B</code>), where <code>A</code> and <code>B</code> are <strong>VPS</strong>&#39;s, or</li>
	<li>It can be written as <code>(A)</code>, where <code>A</code> is a <strong>VPS</strong>.</li>
</ul>

<p>We can similarly define the <strong>nesting depth</strong> <code>depth(S)</code> of any VPS <code>S</code> as follows:</p>

<ul>
	<li><code>depth(&quot;&quot;) = 0</code></li>
	<li><code>depth(C) = 0</code>, where <code>C</code> is a string with a single character not equal to <code>&quot;(&quot;</code> or <code>&quot;)&quot;</code>.</li>
	<li><code>depth(A + B) = max(depth(A), depth(B))</code>, where <code>A</code> and <code>B</code> are <strong>VPS</strong>&#39;s.</li>
	<li><code>depth(&quot;(&quot; + A + &quot;)&quot;) = 1 + depth(A)</code>, where <code>A</code> is a <strong>VPS</strong>.</li>
</ul>

<p>For example, <code>&quot;&quot;</code>, <code>&quot;()()&quot;</code>, and <code>&quot;()(()())&quot;</code> are <strong>VPS</strong>&#39;s (with nesting depths 0, 1, and 2), and <code>&quot;)(&quot;</code> and <code>&quot;(()&quot;</code> are not <strong>VPS</strong>&#39;s.</p>

<p>Given a <strong>VPS</strong> represented as string <code>s</code>, return <em>the <strong>nesting depth</strong> of </em><code>s</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;(1+(2*3)+((<u>8</u>)/4))+1&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> Digit 8 is inside of 3 nested parentheses in the string.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;(1)+((2))+(((<u>3</u>)))&quot;
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists of digits <code>0-9</code> and characters <code>&#39;+&#39;</code>, <code>&#39;-&#39;</code>, <code>&#39;*&#39;</code>, <code>&#39;/&#39;</code>, <code>&#39;(&#39;</code>, and <code>&#39;)&#39;</code>.</li>
	<li>It is guaranteed that parentheses expression <code>s</code> is a <strong>VPS</strong>.</li>
</ul>
