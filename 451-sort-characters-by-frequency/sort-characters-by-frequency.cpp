class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int>mp;
        for(char c : s)
        {
            mp[c]++;
        }    
        priority_queue<pair<int,char>>maxheap;
        for(auto& [ch,freq] : mp)
        {
            maxheap.push({freq,ch});
        }
        string result = "";
        while(!maxheap.empty())
        {
            auto [freq,ch] = maxheap.top();
            maxheap.pop();
            result.append(freq,ch);
        }
        return result;
    }
};