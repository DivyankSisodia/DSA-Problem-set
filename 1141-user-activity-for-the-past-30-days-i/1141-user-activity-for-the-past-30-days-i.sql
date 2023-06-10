# Write your MySQL query statement below
SELECT activity_date as day, COUNT(distinct user_id) as active_users
FROM Activity
WHERE activity_date BETWEEN '20190628' and '20190727'
GROUP BY activity_date