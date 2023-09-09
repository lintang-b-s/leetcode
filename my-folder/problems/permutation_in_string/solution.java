
/*
ide: s2 mengandung permutasi dari s1 jika di s2 ada jumlah kemunculan karakter s1 yang sama dg jumlah kemuncukan karakter bersesuaian di s1.
buat array kemunculan karakter a-z .
buat variabel count=0 untuk menghitung jumlah kemunculan karakter di mapS1 yang sama dg kemunculan karakter mapS2.
ALGORITMA:
1)catat kemunculan karakter di s2 ke maps2 dan maps1 dari indeks ke 0 hingga indeks terakhir dari s1.
2) iterasi kedua map jika kemunculan karakter di kedua map sama ada yang sama maka variabel count ditambah 1, untuk menandakan ada dua kemunculan karakter bersesuaian yang sama.
3) buat sliding window berukuran panjang s1 , lalu gerakkan window ke kanan, jika jumlah kemunculan elemen yang baru di right pointer sama dg jumlah kemunculan elemen bersesuaian di s1 maka tambah variabel count, jika berbeda maka kurangi count. jika jml kemunculan elemen left pointer s2 sama dg jumlah kemunculan elemen yang bersesuaian di s1, maka tambah count, jika beda maka kurangi count.
4) setelah sekian window , jika count sama dengan 26 maka ada permutasi di string s2, karena 
5) karena window yang panjangnya sama dengan panjang string s1, maka jika di suatu window jumlah karakter yang bersesuaian sama maka return true

s1=ab s2=eidbaooo
1)initial:
s1map = {1,1,0,0,0, ..... , 0} 26 length
s2map = {0,0,0,0,1,0,0,0,1,.... ,0} 26 length
count = 22
2)
ab

eidbaooo 
l r
s1      s2
a 1      a
b 1      b
         e
         i
         o

*/

class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length())
            return false;
        int[] s1map = new int[26];
        int[] s2map = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            s1map[s1.charAt(i) - 'a']++;
            s2map[s2.charAt(i) - 'a']++;
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (s1map[i] == s2map[i])
                count++;
        }

        for (int i = 0; i < s2.length() - s1.length(); i++) {
            int r = s2.charAt(i + s1.length()) - 'a', l = s2.charAt(i) - 'a';
            if (count == 26)
                return true;
            s2map[r]++;
            if (s2map[r] == s1map[r]) {
                count++;
            } else if (s2map[r] == s1map[r] + 1) {
                count--;
            }
            s2map[l]--;
            if (s2map[l] == s1map[l]) {
                count++;
            } else if (s2map[l] == s1map[l] - 1) {
                count--;
            }
        }
        return count == 26;
    }
}