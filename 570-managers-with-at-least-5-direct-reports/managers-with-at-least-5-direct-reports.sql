select e.name
from Employee e join Employee ee on ee.managerId=e.id
group by e.id,e.name
having count(*)>4