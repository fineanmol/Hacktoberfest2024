
select customer_number from Orders
group by customer_number
order by count(customer_number) desc limit 1;
