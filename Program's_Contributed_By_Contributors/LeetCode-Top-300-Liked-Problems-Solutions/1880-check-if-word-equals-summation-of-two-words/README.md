<h2><a href="https://leetcode.com/problems/check-if-word-equals-summation-of-two-words">1880. Check if Word Equals Summation of Two Words</a></h2><h3>Easy</h3><hr><p>The <strong>letter value</strong> of a letter is its position in the alphabet <strong>starting from 0</strong> (i.e. <code>&#39;a&#39; -&gt; 0</code>, <code>&#39;b&#39; -&gt; 1</code>, <code>&#39;c&#39; -&gt; 2</code>, etc.).</p>

<p>The <strong>numerical value</strong> of some string of lowercase English letters <code>s</code> is the <strong>concatenation</strong> of the <strong>letter values</strong> of each letter in <code>s</code>, which is then <strong>converted</strong> into an integer.</p>

<ul>
	<li>For example, if <code>s = &quot;acb&quot;</code>, we concatenate each letter&#39;s letter value, resulting in <code>&quot;021&quot;</code>. After converting it, we get <code>21</code>.</li>
</ul>

<p>You are given three strings <code>firstWord</code>, <code>secondWord</code>, and <code>targetWord</code>, each consisting of lowercase English letters <code>&#39;a&#39;</code> through <code>&#39;j&#39;</code> <strong>inclusive</strong>.</p>

<p>Return <code>true</code> <em>if the <strong>summation</strong> of the <strong>numerical values</strong> of </em><code>firstWord</code><em> and </em><code>secondWord</code><em> equals the <strong>numerical value</strong> of </em><code>targetWord</code><em>, or </em><code>false</code><em> otherwise.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> firstWord = &quot;acb&quot;, secondWord = &quot;cba&quot;, targetWord = &quot;cdb&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong>
The numerical value of firstWord is &quot;acb&quot; -&gt; &quot;021&quot; -&gt; 21.
The numerical value of secondWord is &quot;cba&quot; -&gt; &quot;210&quot; -&gt; 210.
The numerical value of targetWord is &quot;cdb&quot; -&gt; &quot;231&quot; -&gt; 231.
We return true because 21 + 210 == 231.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> firstWord = &quot;aaa&quot;, secondWord = &quot;a&quot;, targetWord = &quot;aab&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong> 
The numerical value of firstWord is &quot;aaa&quot; -&gt; &quot;000&quot; -&gt; 0.
The numerical value of secondWord is &quot;a&quot; -&gt; &quot;0&quot; -&gt; 0.
The numerical value of targetWord is &quot;aab&quot; -&gt; &quot;001&quot; -&gt; 1.
We return false because 0 + 0 != 1.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> firstWord = &quot;aaa&quot;, secondWord = &quot;a&quot;, targetWord = &quot;aaaa&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> 
The numerical value of firstWord is &quot;aaa&quot; -&gt; &quot;000&quot; -&gt; 0.
The numerical value of secondWord is &quot;a&quot; -&gt; &quot;0&quot; -&gt; 0.
The numerical value of targetWord is &quot;aaaa&quot; -&gt; &quot;0000&quot; -&gt; 0.
We return true because 0 + 0 == 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= firstWord.length, </code><code>secondWord.length, </code><code>targetWord.length &lt;= 8</code></li>
	<li><code>firstWord</code>, <code>secondWord</code>, and <code>targetWord</code> consist of lowercase English letters from <code>&#39;a&#39;</code> to <code>&#39;j&#39;</code> <strong>inclusive</strong>.</li>
</ul>
