Select MAX(Salary) as SecondHighestSalary from Employee
where Salary < (Select MAX(Salary) from Employee);