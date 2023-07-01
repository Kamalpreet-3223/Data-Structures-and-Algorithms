class Solution {
public:
    

    string longestPalindrome(string& s) {
        int n = s.size();

        // Create a table to store the results of subproblems
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        int maxLength = 1;  // Length of the longest palindromic substring
        int start = 0;     // Starting index of the longest palindromic substring

        // Check for substrings of length 2 or more
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                // Check if the substring between i and j is a palindrome
                if (s[i] == s[j] && (len == 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;

                    // Update the longest palindrome if necessary
                    if (len > maxLength) {
                        maxLength = len;
                        start = i;
                    }
                }
            }
        }

        // Extract the longest palindromic substring
        return s.substr(start, maxLength);
    }
};