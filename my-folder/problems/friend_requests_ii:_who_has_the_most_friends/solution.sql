# Write your MySQL query statement below
/*
ide:
di innner query, pilih requester_id union accepter_id sebagai id1 yang akan dihitung friendsnya. Llau pilih  requester_id union accepter_id  sebagai idCount
untuk jumlah teman masing masing id1
Lalu di outer query, group by id1 dan count(idCount). untuk menghtiung jumlah teman masing masing id1

*/
SELECT id1 as id, count(idCount) as num
FROM (
    SELECT  requester_id as id1 , accepter_id  as idCount
    FROM RequestAccepted
    UNION
    SELECT accepter_id as id1, requester_id as idCount
    FROM RequestAccepted
) friendIdAndCount
GROUP BY id1
ORDER BY num DESC
LIMIT 1; 