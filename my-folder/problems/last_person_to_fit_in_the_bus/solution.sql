# Write your MySQL query statement below
# kalau mau lihat penjelasannya coba 

#SELECT q1.person_name, q2.person_name, q1.turn
# FROM Queue q1 JOIN Queue q2 ON q1.turn >= q2.turn
# self join artinya , tabel q1 merupakan row yang turn-nya lebih terakhir dibandingkan turn q2, sehingga jika di group by q1.turn  dan having  sum(q2.weight)<=1000 akan didapat berat dari rombongan orang turn 1 sampai n yang beratnya kurang dari 1000
# order by sum(q2.weight) desc -> akan mengurutkan  rombongan dari yang terberat

SELECT q1.person_name
FROM Queue q1 JOIN Queue q2 ON q1.turn >= q2.turn
GROUP BY q1.turn
HAVING SUM(q2.weight) <= 1000
ORDER BY SUM(q2.weight) DESC
LIMIT 1;