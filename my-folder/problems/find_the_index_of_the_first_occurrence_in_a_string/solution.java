/*
AAAAABAAABA

pake Knuth morris Pratt


AAAA

phi table
p= 0, i =1
q    1 2 3 4
patt -> A A A A
              p i
phi -> [0, 1 , 2, 3 ]  =1 size  = 4
patt -> A  A   A  A


    a b a b a c
    p           i
phi [ 0, 0, 1, 2, 3 , 0 ]



text -> AAAAABAAABA
            i
patt -> A A  A  A
                j == patt.length { return i- j }

text ->   a b a b a f e
                        i
patt ->   a b a b a c
          j





 */



class Solution {
   private int[] pi;

//    public KMP(String text, String pattern, int[] pi) {
//        this.text = text;
//        this.pattern = pattern;
//        this.pi = new int[pattern.length()];
//    }

    public void constructTable(String pattern){
        int prefixCounter= 0;
        int i = 1;
        pi = new int[pattern.length()];
        while (i < pattern.length()){
            Character currentChar = pattern.charAt(i);
            if (currentChar == pattern.charAt(prefixCounter)) {
                prefixCounter++;
                pi[i] = prefixCounter;
                i++;
            }else{
                if (prefixCounter != 0){
                    prefixCounter= pi[prefixCounter-1];
                }else{
                    pi[i]= 0;
                    i++;
                }
            }
        }
    }

    public int strStr(String haystack, String needle) {
        int i =0, j=0;
        constructTable(needle);
        while (i < haystack.length() && j<needle.length()){
            if (haystack.charAt(i) == needle.charAt(j)){
                i++;j++;
            }
            if (j == needle.length()){
                return i-j;
            }

            if (i< haystack.length() && haystack.charAt(i) != needle.charAt(j)){
                if (j != 0) {
                    j = pi[j-1];
                }else{
                    i++;
                }
            }
        }
        return -1;
    }
}