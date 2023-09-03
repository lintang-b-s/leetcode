class Solution {
     public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> charMap = new HashMap<>();
        char c=  'a';
        for ( int i =0 ; i<s.length(); i++){
            char currentCharInS = s.charAt(i);
            char currentCharInT = t.charAt(i);
            if (charMap.containsKey(currentCharInS)){
                 c = charMap.get(currentCharInS);
                if (c != currentCharInT){
                    return false;
                }
            }else if (!charMap.containsValue(currentCharInT)){
                charMap.put(s.charAt(i), t.charAt(i));
            }else{
                return false;
            }
        }
        return true;
    }
}