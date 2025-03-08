class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int n = blocks.size();
    int min_operations = k; // Initialize with the maximum possible operations (i.e., recoloring all 'W' to 'B')

    // Count how many 'W's are in the first window of size k
    int whiteCount = 0;
    for (int i = 0; i < k; i++) {
        if (blocks[i] == 'W') {
            whiteCount++;
        }
    }

    // The initial window has `whiteCount` number of 'W's to be changed to 'B'
    min_operations = whiteCount;

    // Slide the window across the string
    for (int i = k; i < n; i++) {
        // Remove the effect of the leftmost character of the previous window
        if (blocks[i - k] == 'W') {
            whiteCount--;
        }
        // Add the effect of the new character in the window
        if (blocks[i] == 'W') {
            whiteCount++;
        }

        // Update the minimum operations required
        min_operations = min(min_operations, whiteCount);
    }

    return min_operations;    
    }
};