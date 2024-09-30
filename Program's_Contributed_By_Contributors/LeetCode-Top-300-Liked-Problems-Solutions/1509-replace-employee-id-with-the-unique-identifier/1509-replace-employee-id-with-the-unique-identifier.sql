# Write your MySQL query statement below
select t2.unique_id, t1.name from employees t1 left outer join employeeuni t2
on t1.id = t2.id;