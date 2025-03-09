class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
int n = colors.size();
    int count = 0;
    
    // Extend the array virtually by appending first (k-1) elements at the end
    vector<int> extendedColors(colors.begin(), colors.end());
    for (int i = 0; i < k - 1; ++i) {
        extendedColors.push_back(colors[i]);
    }

    // Check the first window of size k
    bool isAlternating = true;
    for (int i = 1; i < k; ++i) {
        if (extendedColors[i] == extendedColors[i - 1]) {
            isAlternating = false;
            break;
        }
    }
    if (isAlternating) count++;

    // Sliding Window: Check for new window by removing the first element and adding a new one
    for (int i = 1; i < n; ++i) {
        if (extendedColors[i + k - 1] == extendedColors[i + k - 2]) {
            isAlternating = false;
        }
        if (extendedColors[i] == extendedColors[i - 1]) {
            isAlternating = true;
            for (int j = i; j < i + k - 1; ++j) {
                if (extendedColors[j] == extendedColors[j + 1]) {
                    isAlternating = false;
                    break;
                }
            }
        }
        if (isAlternating) count++;
    }

    return count;
    }
};