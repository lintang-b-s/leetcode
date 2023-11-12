
/*
- resource untuk heap data structure: https://www.geeksforgeeks.org/introduction-to-heap-data-structure-and-algorithm-tutorials/
- resource utk priority queue: https://www.geeksforgeeks.org/priority-queue-using-binary-heap/
- resource priority_queue: https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

Intuisi:
That's the key to solving this problem - use a min-heap (min means that the heap will remove/find the smallest element, a max heap is the same thing but for the largest element) and keep the heap at size k. That way, the smallest element in the heap (the one we can access in O(1)O(1)O(1)) will always be the kth largest element. This way, when adding a number to the heap with add(), we can do it very quickly in log⁡(n)\log(n)log(n) time. If our heap exceeds size k, then we can also remove it very quickly. In the end, the smallest element in the heap will be the answer.

dry run:
Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

buat min-heap dg size = 3
- jika heap.size() > 3, insert element baru jika hanya element baru > minimum, 
 agar yg didalam min-heap selalu 3 element terbesar 
- KthLargest
                4
               /. \
              5.   8
            atau 4 5 8
 2 < 4 tidak insert ke heap

- insert 3
3 < 4 tidak insert ke heap,agar min-heap isinya 3 elemen terbeesar

- insert 5
5 >4, insert ke min-heap
 - pop elemen terkecil
      5
     /
    8
    atau [5 8]
  - insert 5 ke min-heap
      5
    /  \
   8    5
   atau  5 5 8
- insert  10 ke heap
 10 > 5 insert ke min-heap
 - pop elemen terkecil
      5
     /
    8
-insert elemen 10
      5
    /. \
    8  10
    atau 5 8 10
- insert 9
 9 > 5 insert 10 ke min-heap 
  - pop elemen terkecil
        8
     /
    10
   - insert 9
        8
       / \
      10. 9
      atau 8 9 10
- insert 4
 4 < 8 tidak insert 4 ke min-heap    
    
*/

class KthLargest {
private:
    std::priority_queue<int, vector<int>, greater<int>> minheap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        if (minheap.size() < k) {
            // jika ukruan minHeap. < k
            minheap.push(val);
        }else if (val > minheap.top()) {
            // jika elemen baru yg ingin dimasukkann lebih besar dari minimum min-heap
            minheap.pop();
            minheap.push(val);

        }

        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */