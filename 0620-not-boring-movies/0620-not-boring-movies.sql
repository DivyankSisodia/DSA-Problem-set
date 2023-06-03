# Write your MySQL query statement below
# select * from Cinema order by rating desc limit 2 and description != 'boring';
select *
from cinema
where mod(id, 2) = 1 and description != 'boring'
order by rating DESC
;