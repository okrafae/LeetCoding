class Solution {
public:
//comments
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missing = 0;
        for( int i = 0; i < n; i++)
        {
            missing = missing ^ nums[i];
            missing = missing ^ i;
        }
        missing = missing ^ n;
        return missing;
    }
};