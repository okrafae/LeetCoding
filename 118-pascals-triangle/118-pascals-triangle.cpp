class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for( int i = 0; i < numRows; i++)
        {
            vector<int> temp(1,1);
            int j = 0;
            while( temp.size() < i )
            {
                temp.push_back( ans[i-1][j] + ans[i-1][j + 1] );
                j++;
            }
            if( i != 0 ) temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};