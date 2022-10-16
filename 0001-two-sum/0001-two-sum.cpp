class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> m;
        vector<int> ans;
        for( int i = 0; i < n; i++)
        {
            if( m.count(target-nums[i]) != 0 )
            {
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            else
            {
                m[nums[i]] = i;
            }
        }
        return ans;
    }
};