# Write your MySQL query statement below
# if action confirmed= dihitung 1 di fungsi AVG() , jika action 'timeout' dihitung 0 di fungsi AVG() nya
SELECT s.user_id, ROUND(AVG(if(c.action="confirmed", 1,0)),2) as confirmation_rate
FROM Signups s 
LEFT JOIN Confirmations c ON s.user_id=c.user_id
GROUP BY s.user_id;