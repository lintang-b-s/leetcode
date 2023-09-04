# Write your MySQL query statement below
SELECT(
  SELECT num
  FROM MyNumbers
  GROUP BY num
  HAVING count(num) = 1
  ORDER BY num desc
  LIMIT 1 
) as num;