# Write your MySQL query statement below
SELECT DISTINCT l1.num as ConsecutiveNums
FROM Logs l1, Logs l2, Logs l3
WHERE
  l1.id = l2.id-1
  and l2.id= l3.id-1
  and l1.num = l2.num
  and l2.num= l3.num;