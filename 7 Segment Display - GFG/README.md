# 7 Segment Display
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Using <a href="https://www.electronics-tutorials.ws/blog/7-segment-display-tutorial.html" target="_blank">seven segment display</a>, you can write down any digit from 0 to 9 using at most seven segments. Given a positive number <strong>N</strong> and then a string <strong>S</strong> representing a number of<strong> </strong>N digits. You have to rearrange the segments in this N digit number to get the smallest possible N digit number. This number can have leading zeros. You can not waste any segment or add any segment from your own. You have to use all of the segments of the given N digits. </span></p>

<p><span style="font-size:18px"><strong>Note:</strong> You can refer this diagram for more details</span></p>

<p><span style="font-size:18px"><img alt="" src="https://media.geeksforgeeks.org/img-practice/ScreenShot2022-02-17at11-1646053217.png" style="height:104px; width:500px" class="img-responsive"></span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong></span><strong>:</strong>
<span style="font-size:18px"><strong>N = </strong>6</span>
<span style="font-size:18px"><strong>S = </strong>"234567"</span>
<span style="font-size:18px"><strong>Output:</strong></span>
<span style="font-size:18px">000011</span>
<span style="font-size:18px"><strong>Explanation:</strong></span>
<span style="font-size:18px">234567 has a total of 28 segments and
we can rearrange them to form 000011
which has 28 segments too. 000011 is the
smallest possible number which can be
formed on rearrangement.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong></span><strong>:</strong>
<span style="font-size:18px"><strong>N = </strong>3</span>
<span style="font-size:18px"><strong>S = </strong>"011"</span>
<span style="font-size:18px"><strong>Output:</strong></span>
<span style="font-size:18px">011</span>
<span style="font-size:18px"><strong>Explanation:</strong></span>
<span style="font-size:18px">011 has a total of 10 segments and this
is the smallest number with 10 segments.
</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>sevenSegments()</strong> which takes an Integer N and a String S of length N as input and returns the smallest possible N digit number which can be made using all of the segments given.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span><br>
<span style="font-size:18px">1 &lt;= N &lt;= 10<sup>4</sup></span></p>
 <p></p>
            </div>