class Solution {
public:
   string longestPalindrome(string s) {
    if (s.empty()) return "";

    int start = 0, end = 0;

    // Helper function to expand around center and return length of palindrome
    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    };

    for (int i = 0; i < s.size(); i++) {
        // Expand around center for odd-length palindromes
        int len1 = expandAroundCenter(i, i);
        // Expand around center for even-length palindromes
        int len2 = expandAroundCenter(i, i + 1);
        
        // Get the maximum length from odd or even expansion
        int maxLen = max(len1, len2);
        
        // Update start and end indices if a longer palindrome is found
        if (maxLen > end - start) {
            start = i - (maxLen - 1) / 2;
            end = i + maxLen / 2;
        }
    }

    // Return the longest palindromic substring
    return s.substr(start, end - start + 1);
}
};