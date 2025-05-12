class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        // Correct type: freq first for max-heap sorting by frequency
        priority_queue<pair<int, char>> maxheap;
        for (auto& [ch, freq] : mp) {
            maxheap.push({freq, ch});
        }

        string result = "";
        while (!maxheap.empty()) {
            auto [freq, ch] = maxheap.top();
            maxheap.pop();
            result += string(freq, ch);  // safer way to append
        }

        return result;
    }
};
