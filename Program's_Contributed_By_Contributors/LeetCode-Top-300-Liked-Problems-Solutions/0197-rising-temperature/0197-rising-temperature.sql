# Write your MySQL query statement below
select w1.id as Id from weather w1, weather w2
where datediff(w1.recordDate, w2.recordDate) = 1 and w1.temperature > w2.temperature; 