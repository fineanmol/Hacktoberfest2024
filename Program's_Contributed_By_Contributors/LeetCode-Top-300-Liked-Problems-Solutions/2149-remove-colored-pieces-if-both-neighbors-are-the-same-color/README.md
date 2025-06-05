<h2><a href="https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/?envType=daily-question&envId=2023-10-02">2149. Remove Colored Pieces if Both Neighbors are the Same Color</a></h2><h3>Medium</h3><hr><p>There are <code>n</code> pieces arranged in a line, and each piece is colored either by <code>&#39;A&#39;</code> or by <code>&#39;B&#39;</code>. You are given a string <code>colors</code> of length <code>n</code> where <code>colors[i]</code> is the color of the <code>i<sup>th</sup></code> piece.</p>

<p>Alice and Bob are playing a game where they take <strong>alternating turns</strong> removing pieces from the line. In this game, Alice moves<strong> first</strong>.</p>

<ul>
	<li>Alice is only allowed to remove a piece colored <code>&#39;A&#39;</code> if <strong>both its neighbors</strong> are also colored <code>&#39;A&#39;</code>. She is <strong>not allowed</strong> to remove pieces that are colored <code>&#39;B&#39;</code>.</li>
	<li>Bob is only allowed to remove a piece colored <code>&#39;B&#39;</code> if <strong>both its neighbors</strong> are also colored <code>&#39;B&#39;</code>. He is <strong>not allowed</strong> to remove pieces that are colored <code>&#39;A&#39;</code>.</li>
	<li>Alice and Bob <strong>cannot</strong> remove pieces from the edge of the line.</li>
	<li>If a player cannot make a move on their turn, that player <strong>loses</strong> and the other player <strong>wins</strong>.</li>
</ul>

<p>Assuming Alice and Bob play optimally, return <code>true</code><em> if Alice wins, or return </em><code>false</code><em> if Bob wins</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> colors = &quot;AAABABB&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong>
A<u>A</u>ABABB -&gt; AABABB
Alice moves first.
She removes the second &#39;A&#39; from the left since that is the only &#39;A&#39; whose neighbors are both &#39;A&#39;.

Now it&#39;s Bob&#39;s turn.
Bob cannot make a move on his turn since there are no &#39;B&#39;s whose neighbors are both &#39;B&#39;.
Thus, Alice wins, so return true.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> colors = &quot;AA&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong>
Alice has her turn first.
There are only two &#39;A&#39;s and both are on the edge of the line, so she cannot move on her turn.
Thus, Bob wins, so return false.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> colors = &quot;ABBBBBBBAAA&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong>
ABBBBBBBA<u>A</u>A -&gt; ABBBBBBBAA
Alice moves first.
Her only option is to remove the second to last &#39;A&#39; from the right.

ABBBB<u>B</u>BBAA -&gt; ABBBBBBAA
Next is Bob&#39;s turn.
He has many options for which &#39;B&#39; piece to remove. He can pick any.

On Alice&#39;s second turn, she has no more pieces that she can remove.
Thus, Bob wins, so return false.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;colors.length &lt;= 10<sup>5</sup></code></li>
	<li><code>colors</code>&nbsp;consists of only the letters&nbsp;<code>&#39;A&#39;</code>&nbsp;and&nbsp;<code>&#39;B&#39;</code></li>
</ul>
