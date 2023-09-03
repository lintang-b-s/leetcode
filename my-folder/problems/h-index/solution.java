

/*

3,0,6,1,5
c
3,0,6,1,5
  c
3,0,6,1,5
    c
3,0,6,1,5
      c
3,0,6,1,5
        c
n = 5


bucket = []
[0,0,0,1,0,0]
[1,0,0,1,0,0]
[1,0,0,1,0,1]
[1,1,0,1,0,1]
[1,1,0,1,0,2]

count (c) = 0, i = 5 -> 0
count  = 2, i=4
count  = 2+ 0 ,i=3
count  = 2+ 1, i=2
count  =  3+ , i =1


*/



class Solution {
    public int hIndex(int[] citations) {
    int n = citations.length;
    int[] buckets = new int[n+1];
    for(int c : citations) {
        if(c >= n) {
            buckets[n]++;
        } else {
            buckets[c]++;
        }
    }
    int count = 0;
    for(int i = n; i >= 0; i--) {
        count += buckets[i];
        if(count >= i) {
            return i;
        }
    }
    return 0;
}
}