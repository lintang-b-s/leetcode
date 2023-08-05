/*
"leetcode"
{l: 0}
{l: 0, e: 1}
{l: 0, e: -1}
{l: 0, e: -1, t: 3}
{l: 0, e: -1, t: 3, c:4}
{l: 0, e: -1, t: 3, c:4, o:5}
{l: 0, e: -1, t: 3, c:4, o:5, d:6}
{l: 0, e: -1, t: 3, c:4, o:5, d:6}




*/

class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i =0; i< s.length(); i++){
            char current = s.charAt(i);
            if (map.containsKey(current)){
                map.put(current, -1);
            }else{
                map.put(current, i);
            }
        }

        int min = Integer.MAX_VALUE;
        for(char c: map.keySet()){
            int firstUnixIndex = map.get(c);
            if ( firstUnixIndex> -1 && firstUnixIndex<min){
                min =firstUnixIndex;
            }
        }
        return min == Integer.MAX_VALUE ? -1 : min;
    }
}