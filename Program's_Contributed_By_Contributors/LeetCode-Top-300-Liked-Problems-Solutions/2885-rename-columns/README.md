<h2><a href="https://leetcode.com/problems/rename-columns">2885. Rename Columns</a></h2><h3>Easy</h3><hr><pre>
DataFrame <code>students</code>
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| id          | int    |
| first       | object |
| last        | object |
| age         | int    |
+-------------+--------+
</pre>

<p>Write a solution to rename the columns as follows:</p>

<ul>
	<li><code>id</code> to <code>student_id</code></li>
	<li><code>first</code> to <code>first_name</code></li>
	<li><code>last</code> to <code>last_name</code></li>
	<li><code>age</code> to <code>age_in_years</code></li>
</ul>

<p>The result format is in the following example.</p>

<p>&nbsp;</p>
<pre>
<strong class="example">Example 1:</strong>
<strong>Input:
</strong>+----+---------+----------+-----+
| id | first   | last     | age |
+----+---------+----------+-----+
| 1  | Mason   | King     | 6   |
| 2  | Ava     | Wright   | 7   |
| 3  | Taylor  | Hall     | 16  |
| 4  | Georgia | Thompson | 18  |
| 5  | Thomas  | Moore    | 10  |
+----+---------+----------+-----+
<strong>Output:</strong>
+------------+------------+-----------+--------------+
| student_id | first_name | last_name | age_in_years |
+------------+------------+-----------+--------------+
| 1          | Mason      | King      | 6            |
| 2          | Ava        | Wright    | 7            |
| 3          | Taylor     | Hall      | 16           |
| 4          | Georgia    | Thompson  | 18           |
| 5          | Thomas     | Moore     | 10           |
+------------+------------+-----------+--------------+
<strong>Explanation:</strong> 
The column names are changed accordingly.</pre>
