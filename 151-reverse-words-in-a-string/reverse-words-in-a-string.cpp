class Solution {
public:
    string removespaces(const string& str)
    {
        stringstream ss(str);
        string word,result;

        while(ss >> word)
        {
            if(!result.empty())
                result+=" ";    
            result+=word;
        }
        return result;
    }
    string reverse(const string& str)
    {
        stringstream ss(str);
        string word,result;

        stack<string>words;
        while(ss >> word)
        {
            words.push(word);
        }
        while(!words.empty())
        {
            result += words.top();
            words.pop();
            if(!words.empty())
                result+=" ";
        }
        return result;
    }
    string reverseWords(string s) 
    {
        string str = removespaces(s);    
        string result = reverse(str);
        return result;
    }
};