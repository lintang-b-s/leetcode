# Write your MySQL query statement below
# count jumlah approved transaction nya menggunakan count(if) -> jika state = approved dijumlah 1 jjika state='declined' dihitung null
#
SELECT LEFT(trans_date, 7) as month, country,
COUNT(id) as trans_count,
COUNT(IF(state='approved', 1, NULL))as approved_count,
SUM(amount) as trans_total_amount,
SUM(CASE
    WHEN state='approved' THEN amount
    ELSE 0
    END) as approved_total_amount
FROM Transactions
GROUP BY month, country;