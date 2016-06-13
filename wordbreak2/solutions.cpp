//Using Recursion
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> result;
        string prefix;
        wordBreaking(s, wordDict, prefix, result);
        return result;
    }
    void wordBreaking(string s, unordered_set<string>& wordDict, string &prefix, vector<string> &result) {
        for(int i = 1; i <= s.size(); i++)
        {
            if(dictContains(s.substr(0,i), wordDict))
            {
                if(i==s.size()){
                    result.push_back(prefix + s.substr(0,i));
                    return ;
                }
                string tmp = prefix +s.substr(0,i) + " ";
                wordBreaking(s.substr(i,s.size()-i), wordDict, tmp, result);
            }
        }
    }
    bool dictContains(string s, unordered_set<string>& wordDict)
    {

        if(wordDict.find(s) != wordDict.end())
            return true;

        return false;
    }
};
