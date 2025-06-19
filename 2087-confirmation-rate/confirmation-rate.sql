select s.user_id , 
round(1.0*count(case when c.action='confirmed' then 1 end)/
count(*),2) as confirmation_rate 
from Signups s left join Confirmations c on c.user_id=s.user_id
group by s.user_id