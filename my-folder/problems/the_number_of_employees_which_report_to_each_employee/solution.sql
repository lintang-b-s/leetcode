# Write your MySQL query statement below

SELECT mgr.employee_id, mgr.name, COUNT(emp.employee_id) as reports_count, ROUND(AVG(emp.age)) as average_age
FROM employees emp JOIN employees mgr
ON emp.reports_to=mgr.employee_id
GROUP BY mgr.employee_id
ORDER BY mgr.employee_id;