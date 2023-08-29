class Solution {
     public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<HashMap<Character, Integer>, ArrayList<String>> map =  new HashMap<>();
        
        for ( String s : strs){
            HashMap<Character, Integer> kemunculanChar = new HashMap<>();
            
            for ( int i = 0; i < s.length(); i++){
                if (kemunculanChar.containsKey(s.charAt(i))){
                    int x = kemunculanChar.get(s.charAt(i));
                    kemunculanChar.put(s.charAt(i), ++x);
                } else {
                    kemunculanChar.put(s.charAt(i), 1);
                }
            }
            
            
            if (map.containsKey(kemunculanChar)){
                map.get(kemunculanChar).add(s);
            }else{
                ArrayList<String > arrString = new ArrayList<>();
                arrString.add(s);
                map.put(kemunculanChar, arrString);
            }
        }
        
        
       List<List<String>> res = new ArrayList<>();
        for (HashMap<Character, Integer> charInt : map.keySet()){
            res.add(map.get(charInt));
        }
        
        return res;
    }
}