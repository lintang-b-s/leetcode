/*
gambar penjelasan https://assets.leetcode.com/users/joinyoung/image_1552620441.png


*/

class Solution {
     public int carFleet(int target, int[] position, int[] speed) {
        if(position.length == 1) return 1;
        Stack<Double> stack = new Stack<>();
        int[][] posAndSpeed = new int[position.length][2];
        for (int i=0; i<position.length; i++){
            posAndSpeed[i][0] = position[i];
            posAndSpeed[i][1] = speed[i];
        }
        Arrays.sort(posAndSpeed, Comparator.comparingInt(p -> p[0]));
        for( int i=position.length -1; i>=0; i--){
            double currentTime = (double) (target - posAndSpeed[i][0]) / posAndSpeed[i][1];
            if (!stack.isEmpty() && currentTime <= stack.peek()) {
                continue;
            } else {
                stack.push(currentTime);
            }
        }
        return stack.size();
    }
}