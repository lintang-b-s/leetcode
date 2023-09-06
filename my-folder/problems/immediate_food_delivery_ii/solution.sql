# Write your MySQL query statement below
# AVG(order_date=customer_pref_delivery_date) artinya menghitung rata-rata jumlah order saat order_date=customer_pref-delivery_date
SELECT ROUND(AVG(order_date=customer_pref_delivery_date)*100,2) as immediate_percentage
FROM Delivery 
WHERE (customer_id, order_date) IN
(
    SELECT customer_id, min(order_date) as first_order
    FROM Delivery
    GROUP BY customer_id
) ;