select w.id 
from Weather w join Weather ww on datediff(day,ww.recordDate,w.recordDate)=1
where w.temperature> ww.temperature