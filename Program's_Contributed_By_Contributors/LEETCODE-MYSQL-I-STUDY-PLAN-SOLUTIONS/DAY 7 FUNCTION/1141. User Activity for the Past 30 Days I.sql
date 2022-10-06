SELECT activity_date as day, COUNT(DISTINCT user_id) as active_users
FROM Activity
where datediff('2019-07-27', activity_date) < 30 and activity_date <= '2019-07-27'
GROUP BY activity_date;
