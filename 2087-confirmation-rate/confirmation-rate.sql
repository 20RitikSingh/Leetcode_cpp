select s.user_id , 
round((select count(*) from Confirmations c where c.user_id=s.user_id and c.action='confirmed')/
((select count(*) from Confirmations c where c.user_id=s.user_id )+0.00001),2) as confirmation_rate
from Signups s