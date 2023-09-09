/*
ide: 
intinya cari window terbesar yang punya longestreplacement, awalnya dari window yang lebih kecil dulu  ke window yang lebih besar, setelah itu cari window yang lebih besar yang mengandung valid substring. setiap pergeseran right pointer update maxfrequency character dari string

untuk mengecek apakah string window valid atau tidak (maksudnya valid adalah k character di string bisa diganti sehingga semua karakter sama) dengan cara end+1-start-maxFreq <= k, jika tidak true maka geser left pointer ke kiri karena string tersebut tidak mengandung valid string. sehingga langkah selanjutnya tinggal cari window yang lebih besar ke kanan yang mengandung valid string. Untuk menghitung longestReplacement=end+1-start atau sama dg ukuran window karena memang string window kita selalu valid string 

intinya Window selalu bergerak ke kanan . Setiap langkah  jika tidak ada valid window, tidak perlu mengurangi ukuran window. kita meningkatkan ukuran ketika kita menemukan valid window dengan ukuran lebih besar

walktrough:

s = start , e = end
    CAAABCBABBA
    se              , maxfreq= 3
    CAAABCBABBA
    s   e           , e+1-s-maxFreq <= k , 4+1-0-3 = 2 <= k, maxfreq = 3 
    longestSubstringLength=5
    CAAABCBABBA
    s    e          , 5+1-0-3 = 6-3 = 3 <= k false, maxfreq = 3 longestSubstringLength=6
    CAAABCBABBA
     s.  e          , 5+1-1-3 = 2 = 2 <= k true, maxfreq=. 3 
     longestSubstringLength=5
    CAAABCBABBA    , 6+1-1-3 =  3  <= k false, maxfreq= 3 
     s.   e
     longestSubstringLength=5
    CAAABCBABBA , 6+1-2-3 = 2 = 2 <= k=2  true , maxfreq= 3 
      s.  e
      longestSubstringLength=5
    CAAABCBABBA., 7+1-2-3= 3 <= k false, maxfreq = 3
      s.   e
    longestSubstringLength=6

*/
class Solution {
    public int characterReplacement(String s, int k) {
        int start = 0;
        int maxFrequency= 0;
        int[] frequencymap = new int[26];
        int longestSubstringLength = 0;

        for (int end=0; end <s.length(); end++){
            int currentChar = s.charAt(end) - 'A';

            frequencymap[currentChar] += 1;

            maxFrequency = Math.max(maxFrequency,  frequencymap[currentChar]);
            Boolean isValidString = (end+ 1-start-maxFrequency <=k);
            if (!isValidString){
                int outgouingChar = s.charAt(start) - 'A';
                frequencymap[outgouingChar] -=1;
                start += 1;
            }

            longestSubstringLength = end +  1 - start;
            }
            return longestSubstringLength;
                    
    }
}