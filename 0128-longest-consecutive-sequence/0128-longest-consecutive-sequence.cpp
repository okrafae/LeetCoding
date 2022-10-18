class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        // taking input in a map
        for( int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }
        int maxCount = 0;
        // iterating the map
        for( auto i : m )
        {
            int count = 1;
            //checking only if element-1 does not exist
            if( m.count((i.first)-1) == 0 )
            {
                int t = 1;
                while( m.count((i.first)+t) != 0 ) {
                    count++;
                    t++;
                }
            }
            //updating maxCount
            maxCount = max( maxCount, count);
        }
        return maxCount;
    }
};