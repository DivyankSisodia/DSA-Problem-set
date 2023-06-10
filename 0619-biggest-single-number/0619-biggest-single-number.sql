# Write your MySQL query statement below



# COUNT(*) returns the number of rows in a specified table, and it preserves duplicate rows. It counts each row separately. This includes rows that contain null values

select num
from MyNumbers
group by num
having count(*) = 1
UNION ALL
select NULL
order by 1 desc 
limit 1