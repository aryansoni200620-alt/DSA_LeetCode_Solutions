#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int expandAroundCenter(char* s, int left, int right, int n) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    // Length is (right - 1) - (left + 1) + 1
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n < 1) return "";

    int start = 0, end = 0;

    for (int i = 0; i < n; i++) {
        // Case 1: Odd length (center is s[i])
        int len1 = expandAroundCenter(s, i, i, n);
        // Case 2: Even length (center is between s[i] and s[i+1])
        int len2 = expandAroundCenter(s, i, i + 1, n);

        int maxLen = (len1 > len2) ? len1 : len2;

        if (maxLen > (end - start + 1)) {
            start = i - (maxLen - 1) / 2;
            end = i + maxLen / 2;
        }
    }

    
    int resultLen = end - start + 1;
    char* result = (char*)malloc((resultLen + 1) * sizeof(char));
    strncpy(result, s + start, resultLen);
    result[resultLen] = '\0';

    return result;
}
