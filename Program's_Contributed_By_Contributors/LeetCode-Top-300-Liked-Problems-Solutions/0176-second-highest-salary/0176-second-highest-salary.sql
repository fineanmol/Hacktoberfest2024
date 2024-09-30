# Write your MySQL query statement below
select MAX(salary) as SecondHighestSalary
From Employee where salary < ( Select MAX(salary) from Employee );
