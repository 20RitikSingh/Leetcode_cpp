select w.id 
from Weather w
where w.temperature> 
(select temperature from Weather ww where datediff(day,ww.recordDate,w.recordDate)=1)