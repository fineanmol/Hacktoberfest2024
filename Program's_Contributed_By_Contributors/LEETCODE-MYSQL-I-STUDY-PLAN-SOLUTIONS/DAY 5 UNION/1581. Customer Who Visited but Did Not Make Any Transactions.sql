SELECT customer_id, COUNT(v.visit_id) AS count_no_trans 
FROM Visits v
NATURAL LEFT JOIN Transactions t
WHERE t.visit_id IS NULL
GROUP BY customer_id;