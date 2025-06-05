# Write your MySQL query statement below
select customer_number from orders 
group by customer_number order by count(order_number) desc limit 1;