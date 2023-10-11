-- Select all employees whose salary is above the average salary of employees.

SELECT *
FROM employees
WHERE salary > (SELECT AVG(salary) FROM employees);

-- Select all products that have sold more than 100 units.

SELECT *
FROM products
WHERE quantity_sold > (SELECT 100);

-- Select all students whose score is higher than the average score of students in their class.

SELECT *
FROM students
WHERE score > (SELECT AVG(score) FROM students WHERE class_id = students.class_id);