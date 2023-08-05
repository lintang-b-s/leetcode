/*
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
["h","e","l","l","o"]
  l.              r
["o","l","l","e","h"]
      l.      r
["o","l","l","e","h"]
          lr
          

*/

class Solution {
    public void reverseString(char[] s) {
        int l = 0; int r= s.length-1;
        while (l< r){
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            
            l++;
            r--;
        }
        
    }
}