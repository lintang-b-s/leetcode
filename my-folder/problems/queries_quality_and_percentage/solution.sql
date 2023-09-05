# Write your MySQL query statement below
SELECT query_name, ROUND(AVG(rating/position),2) as quality,  ROUND(AVG(RATING <3 ) *100 ,2) as poor_query_percentage
FROM Queries
GROUP BY query_name;

