/* Write your T-SQL query statement below */
select s.student_id,s.student_name, sb.subject_name, (select count(*) from Examinations e where e.student_id=s.student_id and sb.subject_name=e.subject_name) as attended_exams
from Subjects sb cross join Students s 
order by s.student_id, sb.subject_name