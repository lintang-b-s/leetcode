class Solution {
  public boolean isAnagram(String s, String t) {
        Map<Character, Integer> s1 = new HashMap<>();
        Map<Character, Integer> s2 = new HashMap<>();


        putInMap(s1, s);putInMap(s2, t);

        if (s.length() != t.length()) { return false;}

        Iterator<Map.Entry<Character, Integer>> iter = s1.entrySet().iterator();

        boolean isAnagram = true;
        while (iter.hasNext() ){
            Character key= iter.next().getKey();

            boolean charCountInBothMapEqual = s1.get(key).equals(s2.get(key));
            if (  !s2.containsKey(key)|| !charCountInBothMapEqual  ) {
                isAnagram = false;
            }
        }

        return isAnagram;
    }

    public void putInMap(Map<Character,Integer> map, String string)
    {
        for (int i= 0; i<string.length(); i++){
            char curr = string.charAt(i);
            if (!map.containsKey(curr)){
                map.put(curr, 0);
            }
            int countCurrChar = map.get(curr);
            map.put(curr, countCurrChar+1);
        }
    }
}