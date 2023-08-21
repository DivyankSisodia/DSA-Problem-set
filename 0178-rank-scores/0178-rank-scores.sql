# Write your MySQL query statement below

# dense rank is used to give order number for duplicates and non duplicates

select score, DENSE_RANK() over (order by score desc) as 'rank' from scores;