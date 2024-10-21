# Write your MySQL query statement below
select id,
    case
        when mod(id,2) = 0 then LAG(student) over(order by id)
        else IFNULL(LEAD(student) over(order by id), student) end as student
from Seat; 