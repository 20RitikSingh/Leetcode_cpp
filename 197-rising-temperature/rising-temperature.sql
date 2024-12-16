# Write your MySQL query statement below
select a.id as id
from Weather as a
join Weather as b on 
datediff(a.recordDate,b.recordDate)=1 and
a.temperature > b.temperature;