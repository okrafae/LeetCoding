class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if( n == 0 || n == 1 ) return n;
        int low =  0, high = 1,maxLen = 0;
        unordered_map<char,int> m;
        m[s[0]]++;
        while( high < n)
        {
            while( high < n && m[s[high]] == 0) 
            {
                m[s[high]]++;
                high++;
            }
            maxLen = max( maxLen, high-low);
            m[s[low]]--;
            low++;
        }
        return maxLen;
    }
};