/*

 Input: s = "abcabcbb"
Output: 3

{ a: 0, b:1,  c:2  }
{  b:1,  c:2, a: 3  }
{   c:2, a: 3, b:4  }
{    a: 3, b:4 , c:5 }
{    a: 3 , c:5, b:6 }
{    a: 3 , c:5, b:7 }

buat dua pointer left dan right. right itu buat search ke kanan
setiap r geser kekanan masukan elemen yg ditunjuk r ke hashmap dan catat indexnya

maxLength =  max(maxLength, r-l+1)
jika elemen yg ditunjuk r ada di map , geser l
maxlength diset setiap r geser ke kanan


a b c a b c b b
lr
a b c a b c b b
l r                 maxLength= 2
a b c a b c b b
l   r               maxLength = 3
a b c a b c b b
l     r             maxLength = 3
a b c a b c b b
  l   r             maxlength = (3, r-l+1) = (3, 3) = 3
a b c a b c b b
    l   r           maxlength = (3, r-l+1) = (3, 3) = 3
a b c a b c b b
    l     r
a b c a b c b b
      l    r   maxlength = (3, r-l+1) = (3, 3) = 3
a b c a b c b b
          l r   maxlength = (3, r-l+1) = (3, 2) = 3

a b c a b c b b
              lr  maxlength = (3, r-l+1) = (3, 1) = 3


 */

class Solution {
    public  int lengthOfLongestSubstring(String s) {
        int l= 0, r = 0,maxLength = 0;
        int n = s.length();
        HashMap<Character, Integer> chara = new HashMap<>();
        while (l <n && r <n ) {
            Character current = s.charAt(r);
            if (chara.containsKey(current)) {
                l = Math.max(l, chara.get(current) + 1);
                chara.remove(current);
            }
            maxLength = Math.max(maxLength, r - l + 1);
            chara.put(current, r);
            r++;
        }

        return maxLength;

    }
}