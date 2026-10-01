/*
 * Time Complexity: O(n) - single pass through string
 * Space Complexity: O(n) - stack can contain up to n/2 elements
 * 
 * Approach:
 * 1. Use stack to track opening brackets
 * 2. For opening brackets: push to stack
 * 3. For closing brackets: check if matches top of stack
 * 4. Valid if stack is empty at end and all brackets matched
 */
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        
        for (char c : s.toCharArray()) {
            // Push opening brackets onto stack
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } 
            // For closing brackets, check matching
            else {
                // Stack empty means no matching opening bracket
                if (stack.isEmpty()) {
                    return false;
                }
                
                char top = stack.pop();
                
                // Check if brackets match
                if (c == ')' && top != '(') return false;
                if (c == ']' && top != '[') return false;
                if (c == '}' && top != '{') return false;
            }
        }
        
        // Valid only if all brackets were matched (stack empty)
        return stack.isEmpty();
    }
}