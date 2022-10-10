class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort( intervals.begin(), intervals.end());
        vector<vector<int>> merge;
        merge.push_back(intervals[0]);
        for( int i = 1; i < intervals.size(); i++)
        {
            merge.push_back(intervals[i]);
            int n = merge.size();
            //2nd is completely inside first one
            if( merge[n-1][1] <= merge[n-2][1] )
            {
                merge.pop_back();

            }
            // both have some common elements in the range
            else if( merge[n-2][1] >= merge[n-1][0])
            {
                merge[n-2][1] = max( merge[n-2][1],merge[n-1][1]);                                           merge.pop_back();
            }            
        }
        return merge;
    }
};