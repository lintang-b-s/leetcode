/*
[73,74,75,71,69,72,76,73] res =  [] stack = [0, ]
    i
[73,74,75,71,69,72,76,73] res =  [1] stack = [1]
      i
[73,74,75,71,69,72,76,73] res =  [1,1] stack = [2]
        i
[73,74,75,71,69,72,76,73] res =  [1,1] stack = [2,3,4], 72> 69
                 i
[73,74,75,71,69,72,76,73] res =  [1,1, 0,2, 1 ] stack = [2], 72>71
                i
[73,74,75,71,69,72,76,73] res =  [1,1, 0,2, 1 ] stack = [2], 72>71
                    i
[73,74,75,71,69,72,76,73] res =  [1,1, 0,2, 1 ] stack = [2],  76>75
                    i
[73,74,75,71,69,72,76,73] res =  [1,1,6-2(4) ,2, 1 ] stack = [], 76>75
                    i
[73,74,75,71,69,72,76,73] res =  [1,1,6-2(4) ,2, 1 , 0] stack = [7],
                       i
*/
class Solution {
   public int[] dailyTemperatures(int[] temperatures) {
    Stack<Integer> stack = new Stack<>();
    int[] ret = new int[temperatures.length];
    for(int i = 0; i < temperatures.length; i++) {
        while(!stack.isEmpty() && temperatures[i] > temperatures[stack.peek()]) {
            int idx = stack.pop();
            ret[idx] = i - idx;
        }
        stack.push(i);
    }
    return ret;
}
}