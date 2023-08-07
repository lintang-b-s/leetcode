class Solution {
    public boolean isPalindrome(String s) {
        String str =  s.replaceAll("[^a-zA-Z0-9]","");
        str = str.toLowerCase();
        int l= 0 ;int r= str.length()-1;

        while (l<=r){
            boolean  leftCharAndRightCharEqual = str.charAt(l)  == str.charAt(r);
            if (!leftCharAndRightCharEqual){
                return false;

            }
            l++;
            r--;
        }
        return true;
    }
}