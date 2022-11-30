class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> m;
        for( int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }
        unordered_map<int,int> freq;
        for( auto i : m )
        {
            freq[i.second]++;
            if( freq[i.second] != 1 ) return false;
        }
        return true;
    }
};