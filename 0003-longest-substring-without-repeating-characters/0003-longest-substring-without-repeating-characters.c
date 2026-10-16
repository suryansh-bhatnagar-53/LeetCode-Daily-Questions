/*
 * Time Complexity: O(n) - single pass through string
 * Space Complexity: O(1) - fixed size array for ASCII characters
 */
int lengthOfLongestSubstring(char* s) {
    // Array to store last index of each character (-1 if not seen)
    int lastIndex[128];
    for (int i = 0; i < 128; i++) {
        lastIndex[i] = -1;
    }
    
    int maxLength = 0;
    int start = 0; // Start of current window
    
    for (int end = 0; s[end] != '\0'; end++) {
        char currentChar = s[end];
        
        // If character seen in current window, move start
        if (lastIndex[currentChar] >= start) {
            start = lastIndex[currentChar] + 1;
        }
        
        // Update character's latest position
        lastIndex[currentChar] = end;
        
        // Update max length
        int currentLength = end - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    
    return maxLength;
}