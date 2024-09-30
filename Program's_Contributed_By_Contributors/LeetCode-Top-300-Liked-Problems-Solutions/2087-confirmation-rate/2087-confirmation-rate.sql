# Write your MySQL query statement below
SELECT s.user_id, ROUND(SUM(CASE WHEN c.action = 'confirmed' THEN 1 ELSE 0 END) / COUNT(*), 2) confirmation_rate
FROM signups s
LEFT JOIN confirmations c
ON c.user_id = s.user_id
GROUP BY s.user_id;