class Solution {
    
      /*"""
    buat pointer j buat ngelacak elemen yg unik
    loop arraynya jika elemen ke i tidak sama dg elemen selanjutnya, maka tukar dg  elemen yg ditunjuk pointer j
    setelah loop. elemen pointer ke j di ganti dg elemen terakhir

    dari
    1,1,2,3,3,4,4
    ke
    1,2,3,4

    1,1,2,3,3,4,4
    ij
    1,1,2,3,3,4,4
    i j
    1,1,2,3,3,4,4
      i j
    1,2,2,3,3,4,4
        i   j
    1,2,3,3,3,4,4
          i       j  end of loop
    1,2,3,4


    """
          
          */
    public int removeDuplicates(int[] nums) {
        int i = 0;
        int n = nums.length;
        for (int j=0; j<n -1; j++) {
            if (nums[j] != nums[j+1]) {
                nums[i] = nums[j];
                i++;
            }
        }
        nums[i++] = nums[n-1];
        
        return i;
    }
}