class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort( nums.begin(), nums.end() );
        int n = nums.size();
        set<vector<int>> s;
        for( int i = 0; i < n - 2; i++)
        {
            //if( i > 0 && nums[i] == nums[i-1] ) continue;
            int j = i + 1, k = n - 1;
            while( j < k )
            {
                if( nums[j] + nums[k] < -nums[i] ) j++;
                else if( nums[j] + nums[k] > -nums[i] ) k--;
                else
                {
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    s.insert(temp);
                    j++;
                    k--;
                //    int previous_j = j, previous_k = k;
              //      while( j < k && nums[previous_j] == nums[j] ) j++;
                  //  while( j < k && nums[previous_k] == nums[k] ) k--;
                }
            }
        }
        for( auto i : s )
            ans.push_back(i);
        return ans;
    }
};