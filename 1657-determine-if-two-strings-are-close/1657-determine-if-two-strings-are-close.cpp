class Solution {
public:
    bool closeStrings(string word1, string word2) {
     int n = word1.size(), m = word2.size();
        if( n != m ) return false;
        vector<int> a(26,0),b(26,0);
        for( int i = 0; i < n; i++)
        {
            a[word1[i] - 'a']++;
            b[word2[i] - 'a']++;
        }
        for( int i = 0; i < 26; i++)
        {
            if( (a[i] == 0 && b[i] != 0) || ( a[i] !=0 && b[i] == 0) ) return false;
        }
        unordered_map<int,int> mp;
        for( int i = 0; i < 26; i++)
        {
            if( a[i] != 0 ) mp[a[i]]++;
        }
        for( int i = 0; i < 26; i++)
        {
            if( b[i] != 0 ) mp[b[i]]--;
        }
        for( auto i : mp )
        {
            if( i.second != 0 ) return false;
        }
        return true;
    }
};