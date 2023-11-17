/*

Input: s = "eccbbbbdec"
- utk membuat partisi dg panjang terbanyak & setiap karakter hny muncul di 1 partisi, kita harus tahu lastIndex dari setiap karakter.
- misal lastIndex 'e' =9, berarti partisi yg ada 'e' bisa 9 karakter 
- cek lagi setiap elemen di partisi 1 , ternyata c lastIndex nya 10, berarti partisi yg ada 'ec' bisa 10 karakter.

- Input: s = "ababcbacadefegdehijhklij"
- lastIndex dari a = 9, berati partisi 1 yg ada 'a' bisa 9 karakter
- iterate setiap karakter di paritisi 1, apakah ada lastIndex yg lebih panjang
- setelah iterate partisi 1, cek lastIndex dari d , lastIndex d= 15, berarti partisi 2 bisa 15-9 = 6 karakter.
- iterate setiap karakter di partisi 2, cek apakah ada karakter yg lastIndex nya lebih panjanng. ternyata lastIndex dari e = 16, berarti partiis 2 bisa 16-9 =7 karakter.
- setleah iteratepartisi 2, cek lastIndex dari h=19, berati partisi 3 bisa 20-16=4.
- itrate setiap karakter di partisi 3, cek apakah ada karakter yg lastIndex nya lebih panjanng.  ternyata lastIndex j =24, berati p-artisi 3 bisa 24-16=8 karakter 

*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex ;
        for (int i=0; i < s.length(); i++){
            lastIndex[s[i]] = i;
        }

        int endOfPart = 0, size = 0;
        vector<int> res ;
        for (int i =0 ; i < s.length() ; i++){
            size += 1;
            endOfPart = max(endOfPart, lastIndex[s[i]]);
            cout << "end: " << endOfPart << endl;
            if (i == endOfPart){
                cout << "size: " << size << endl;
                res.push_back(size);
                size = 0;
            }
        }
        return res;
        
    }
};