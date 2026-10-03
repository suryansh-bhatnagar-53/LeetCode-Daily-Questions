/*
 * More efficient memory allocation
 */

void backtrack(char** ans, int* count, char* str, int pos, int open, int close, int n) {
    if (pos == n * 2) {
        str[pos] = '\0';
        ans[*count] = (char*)malloc((pos + 1) * sizeof(char));
        strcpy(ans[*count], str);
        (*count)++;
        return;
    }
    
    if (open < n) {
        str[pos] = '(';
        backtrack(ans, count, str, pos + 1, open + 1, close, n);
    }
    
    if (close < open) {
        str[pos] = ')';
        backtrack(ans, count, str, pos + 1, open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    // Catalan number C_n = (2n)! / ((n+1)! * n!)
    // For n=1: 1, n=2: 2, n=3: 5, n=4: 14
    int capacity = 2000; // Safe upper bound for reasonable n
    
    char** result = (char**)malloc(capacity * sizeof(char*));
    char* buffer = (char*)malloc((2 * n + 1) * sizeof(char));
    *returnSize = 0;
    
    backtrack(result, returnSize, buffer, 0, 0, 0, n);
    
    free(buffer);
    return result;
}