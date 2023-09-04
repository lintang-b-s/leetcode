class Solution {
   public boolean canConstruct(String ransomNote, String magazine) {

        HashMap<Character, Integer> magazineWord=  new HashMap<>();
        for(int i=0; i< magazine.length(); i++){
            char m = magazine.charAt(i);
            magazineWord.put(m, magazineWord.getOrDefault(m, 0)+1);
        }
        for (int i=0;i <ransomNote.length(); i++){
            char charRansom = ransomNote.charAt(i);
            int magazineWordFreq= magazineWord.getOrDefault(charRansom, 0);
            if (magazineWordFreq == 0){
                return false;
            }
            magazineWord.put(charRansom, magazineWordFreq -1);
        }
        
        return true;
    }
}