/*
mirip dg interval scheduling: https://www.geeksforgeeks.org/scheduling-in-greedy-algorithms/
resource: https://informatika.stei.itb.ac.id/~rinaldi.munir/Stmik/2020-2021/Algoritma-Greedy-(2021)-Bag1.pdf

[waktuMulai, waktuSelesai]
- minimum interval yg dihapus agar tidak ada interval bertabrakan = n - maxIntervalSchedlule
- algoritma:
    - sort interval berdasarkan waktu selesai , dari yg paling terdahulu ke paling terakhir
    - buat variable prev , dimana prev menunjukkan interval terakhir yg dipilih.
    - iterate setiap interval: 
        - jika waktu mulai interval  yg saat ini dipilih > waktu selesai interval prev, set prev ke interval saat ini dan increment maxIntervalSchedlule

*/

class Solution {
public:
    static bool sortByEndTime(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), sortByEndTime);
        int prev = 0; 
        int maxIntervalSchedlule = 1; // jumlah interval maksimum agar tidak bertabrakan
        
        for (int i=0; i < n; i++){
            if (intervals[i][0] >= intervals[prev][1]) {
                prev = i;
                maxIntervalSchedlule ++;
            }
        }
        return n-maxIntervalSchedlule;
    }   
};