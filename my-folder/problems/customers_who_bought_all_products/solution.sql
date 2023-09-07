# Write your MySQL query statement below
SELECT DISTINCT c1.customer_id 
FROM Customer c1
GROUP BY c1.customer_id
HAVING COUNT(DISTINCT c1.product_key) = (SELECT COUNT(distinct product_key ) FROM Product);