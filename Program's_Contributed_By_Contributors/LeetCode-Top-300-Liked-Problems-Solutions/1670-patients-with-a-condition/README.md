<h2><a href="https://leetcode.com/problems/patients-with-a-condition/?envType=study-plan-v2&envId=top-sql-50">1670. Patients With a Condition</a></h2><h3>Easy</h3><hr><p>Table: <code>Patients</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| patient_id   | int     |
| patient_name | varchar |
| conditions   | varchar |
+--------------+---------+
patient_id is the primary key (column with unique values) for this table.
&#39;conditions&#39; contains 0 or more code separated by spaces. 
This table contains information of the patients in the hospital.
</pre>

<p>&nbsp;</p>

<p>Write a solution to find the patient_id, patient_name, and conditions of the patients who have Type I Diabetes. Type I Diabetes always starts with <code>DIAB1</code> prefix.</p>

<p>Return the result table in <strong>any order</strong>.</p>

<p>The&nbsp;result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> 
Patients table:
+------------+--------------+--------------+
| patient_id | patient_name | conditions   |
+------------+--------------+--------------+
| 1          | Daniel       | YFEV COUGH   |
| 2          | Alice        |              |
| 3          | Bob          | DIAB100 MYOP |
| 4          | George       | ACNE DIAB100 |
| 5          | Alain        | DIAB201      |
+------------+--------------+--------------+
<strong>Output:</strong> 
+------------+--------------+--------------+
| patient_id | patient_name | conditions   |
+------------+--------------+--------------+
| 3          | Bob          | DIAB100 MYOP |
| 4          | George       | ACNE DIAB100 | 
+------------+--------------+--------------+
<strong>Explanation:</strong> Bob and George both have a condition that starts with DIAB1.
</pre>
