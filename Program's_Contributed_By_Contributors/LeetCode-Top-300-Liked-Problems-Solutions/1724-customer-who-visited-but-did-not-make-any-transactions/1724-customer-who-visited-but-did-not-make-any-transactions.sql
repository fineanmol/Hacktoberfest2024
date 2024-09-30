# Write your MySQL query statement below
select v.customer_id, count(v.visit_id) as count_no_trans from visits v where v.visit_id NOT IN (select visit_id from transactions) group by v.customer_id;