SELECT product_id, product_name
FROM Sales 
JOIN Product 
Using(product_id)
GROUP BY product_id
HAVING MIN(sale_date) >= '2019-01-01' AND MAX(sale_date) <= '2019-03-31';
