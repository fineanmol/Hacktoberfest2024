<h2><a href="https://leetcode.com/problems/bag-of-tokens">948. Bag of Tokens</a></h2><h3>Medium</h3><hr><p>You start with an initial <strong>power</strong> of <code>power</code>, an initial <strong>score</strong> of <code>0</code>, and a bag of tokens given as an integer array <code>tokens</code>, where each&nbsp;<code>tokens[i]</code> donates the value of token<em><sub>i</sub></em>.</p>

<p>Your goal is to <strong>maximize</strong> the total <strong>score</strong> by strategically playing these tokens. In one move, you can play an <strong>unplayed</strong> token in one of the two ways (but not both for the same token):</p>

<ul>
	<li><strong>Face-up</strong>: If your current power is <strong>at least</strong> <code>tokens[i]</code>, you may play token<em><sub>i</sub></em>, losing <code>tokens[i]</code> power and gaining <code>1</code> score.</li>
	<li><strong>Face-down</strong>: If your current score is <strong>at least</strong> <code>1</code>, you may play token<em><sub>i</sub></em>, gaining <code>tokens[i]</code> power and losing <code>1</code> score.</li>
</ul>

<p>Return <em>the <strong>maximum</strong> possible score you can achieve after playing <strong>any</strong> number of tokens</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block" style="
    border-color: var(--border-tertiary);
    border-left-width: 2px;
    color: var(--text-secondary);
    font-size: .875rem;
    margin-bottom: 1rem;
    margin-top: 1rem;
    overflow: visible;
    padding-left: 1rem;
">
<p><strong>Input:</strong> <span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">tokens = [100], power = 50</span></p>

<p><strong>Output:</strong> <span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">0</span></p>

<p><strong>Explanation</strong><strong>:</strong> Since your score is <code>0</code> initially, you cannot play the token face-down. You also cannot play it face-up since your power (<code>50</code>) is less than <code>tokens[0]</code>&nbsp;(<code>100</code>).</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block" style="
    border-color: var(--border-tertiary);
    border-left-width: 2px;
    color: var(--text-secondary);
    font-size: .875rem;
    margin-bottom: 1rem;
    margin-top: 1rem;
    overflow: visible;
    padding-left: 1rem;
">
<p><strong>Input:</strong> <span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">tokens = [200,100], power = 150</span></p>

<p><strong>Output:</strong> <span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">1</span></p>

<p><strong>Explanation:</strong> Play token<em><sub>1</sub></em> (<code>100</code>) face-up, reducing your power to&nbsp;<code>50</code> and increasing your score to&nbsp;<code>1</code>.</p>

<p>There is no need to play token<em><sub>0</sub></em>, since you cannot play it face-up to add to your score. The maximum score achievable is <code>1</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block" style="
    border-color: var(--border-tertiary);
    border-left-width: 2px;
    color: var(--text-secondary);
    font-size: .875rem;
    margin-bottom: 1rem;
    margin-top: 1rem;
    overflow: visible;
    padding-left: 1rem;
">
<p><strong>Input:</strong> <span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">tokens = [100,200,300,400], power = 200</span></p>

<p><strong>Output:</strong> <span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">2</span></p>

<p><strong>Explanation:</strong> Play the tokens in this order to get a score of <code>2</code>:</p>

<ol>
	<li>Play token<em><sub>0</sub></em> (<code>100</code>) face-up, reducing power to <code>100</code> and increasing score to <code>1</code>.</li>
	<li>Play token<em><sub>3</sub></em> (<code>400</code>) face-down, increasing power to <code>500</code> and reducing score to <code>0</code>.</li>
	<li>Play token<em><sub>1</sub></em> (<code>200</code>) face-up, reducing power to <code>300</code> and increasing score to <code>1</code>.</li>
	<li>Play token<em><sub>2</sub></em> (<code>300</code>) face-up, reducing power to <code>0</code> and increasing score to <code>2</code>.</li>
</ol>

<p><span style="color: var(--text-secondary); font-size: 0.875rem;">The maximum score achievable is </span><code style="color: var(--text-secondary); font-size: 0.875rem;">2</code><span style="color: var(--text-secondary); font-size: 0.875rem;">.</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= tokens.length &lt;= 1000</code></li>
	<li><code>0 &lt;= tokens[i], power &lt; 10<sup>4</sup></code></li>
</ul>
