class Solution {
   public boolean isValid(String s) {
        ArrayDeque<Character> stack = new ArrayDeque<>();
        int n  =s.length();
        for (int i = 0; i<n ; i++){
            char c = s.charAt(i);

            if ( c== '{' || c == '[' || c == '('){
                stack.push(c);
                continue;
            }

            if (stack.isEmpty()){
                return false;
            }
            char charMatch;
            switch(c){
                case ')':
                    charMatch = stack.pop();
                    if (charMatch == '{' || charMatch == '['){
                        return false;
                    }
                    break;
                case '}':
                    charMatch= stack.pop();
                    if (charMatch == '[' || charMatch == '('){
                        return false;
                    }
                    break;
                case ']':
                    charMatch= stack.pop();
                    if(charMatch == '(' || charMatch == '{'){
                        return false;
                    }
                    break;
            }

        }
        return stack.isEmpty();

    }
}