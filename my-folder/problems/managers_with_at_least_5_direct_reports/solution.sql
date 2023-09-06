# Write your MySQL query statement below
# group by manager , dikelompokin berdasarkan managerIdnya dan hitung id employee tiap manager ada berapa.
# join employee e dan employee m , buat select manager name
SELECT m.name
FROM Employee e
INNER JOIN EMPLOYEE m ON e.managerId=m.id
GROUP BY e.managerId 
HAVING COUNT(e.id) >=5;