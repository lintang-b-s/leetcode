# Write your MySQL query statement below
# yang product setelah changed_date 2019-08-16 digabung sama yang product yang new pricenya diganti sebelum tanggal 2019-08-17
SELECT product_id, 10 as price 
FROM Products
GROUP BY product_id
HAVING MIN(change_date)>'2019-08-16'
UNION ALL
SELECT product_id, new_price
FROM Products
WHERE (product_id, change_date) IN
    (
        SELECT product_id, MAX(change_date) as last_changed_price
        FROM Products
        WHERE change_date <= '2019-08-16'
        GROUP BY product_id
    )
ORDER BY product_id;