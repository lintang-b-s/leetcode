# Write your MySQL query statement below
# buat tabel baru cte, yang isinya account_id, sama tipe salary
# buat tabel baru cte_name, yang isinya name dari category
# left join cte_name dan cte, lalu di group by category dan count(account_id)
# sehingga bisa dijumlah account tiap salary category dan yang categorynya tidak ada akunnya bisa dihitung sebagai 0 karena telah di left join
WITH CTE AS (
    SELECT account_id, 
    CASE 
        WHEN income < 20000 then 'Low Salary'
        WHEN income > 50000 then 'High Salary'
        ELSE 'Average Salary'
    END AS category
    FROM Accounts
),

CTE_NAME AS (
    SELECT 'Low Salary'  AS category
    UNION
    SELECT 'High Salary' AS category
    UNION
    SELECT 'Average Salary' AS category

)

SELECT CTE_NAME.category, COUNT(account_id) as accounts_count
FROM CTE_NAME LEFT JOIN CTE ON CTE.category=CTE_NAME.category
GROUP BY CTE_NAME.category;