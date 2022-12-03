 bool comp(const pair<char,int> &a, const pair<char,int> &b)
    {
        if( a.second == b.second ) return a.first < b.first;
        return a.second > b.second;
    }
class Solution {
public:
    
   
    
    string frequencySort(string s) {
        
        int n = s.size();
        unordered_map<char,int> m;
        for( int i = 0; i < n ;i++)
        {
            m[s[i]]++;
        }
        vector<pair<char,int>> v;
        for( auto i : m )
        {
            pair<char,int> t;
            t.first = i.first;
            t.second = i.second;
            v.push_back(t);
        }
        sort( v.begin(), v.end(), comp);
        string t = "";
        for( int i = 0; i < v.size(); i++)
        {
            string temp = "";
            for( int j = 0; j < v[i].second ; j++) temp+=v[i].first;
            t += temp;
        }
        return t;
    }
};