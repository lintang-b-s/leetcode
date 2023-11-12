/*
- resource untuk heap data structure: https://www.geeksforgeeks.org/introduction-to-heap-data-structure-and-algorithm-tutorials/
- resource utk priority queue: https://www.geeksforgeeks.org/priority-queue-using-binary-heap/
- resource priority_queue: https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/


Input: stones = [2,7,4,1,8,1]
Output: 1
max-heap = [8,7,4,2,1,1]

(1) max-heap.size() > 1
 8 & 7
 [4,  2, 8-7, 1, 1] = [4, 2, 1 ,1 ,1]
(2) max-heap.size() > 1
 4 & 2
[4-2, 1, 1, 1] = [2,1,1,1]
(3) max-heap.size() > 1
2 & 1
[2-1, 1, 1] = [1, 1, 1]

(4)  max-heap.size() > 1
1 & 1
[1, 1-1] = [1,0]

(5)  max-heap.size() > 1
1 &  0
[1-0] = [1]

(6)  max-heap.size() < 1
return max-heap.top()



*/

class Solution {
private:

public:
    int lastStoneWeight(vector<int>& stones) {
        // buat priority queue
        priority_queue<int> pq(stones.begin(), stones.end());
       
     
        while (pq.size() > 1) {
            int highest = pq.top();  // get highest elemnt
            pq.pop(); // pop highest element
            int highestTwoNd = pq.top(); // get higshet 2nd element
            pq.pop();  // pop highest 2nd element

            if ( highest != highestTwoNd) {
                pq.push(abs(highest - highestTwoNd));
            }
        }

         if (pq.empty() ) {
            return 0 ;
        }

        return pq.top();

    }
};