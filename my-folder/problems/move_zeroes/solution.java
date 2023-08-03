 /* """
    buat pointer yg nunjuk di awal array. iterasi setaip elemen array jika 
    elemen tidak sama dengan 0 maka elemen di pointer j diassign ke elemen 
    yg lagi diiterasi, lalu j ditambah 1
    setelah iterasi selesai. iterasi array dari j sampai n assign etiap elmeennya ke 0
    
    [0,1,0,3,12]
     j n
    [1,1,0,3,12]
       j   n
    [1,3,0,3,12]
         j   n
    [1,3,12,3,12]
            j
    [1,3,12,0,0]
            
    """
*/

class Solution {
    public void moveZeroes(int[] nums) {
        int j = 0;
        int n = nums.length;
        for (int num : nums){
            if (num != 0){
                nums[j] = num;
                j++;
            }
        }
        
        while ( j< nums.length){
            nums[j] = 0;
            j++;
            }
    }
}