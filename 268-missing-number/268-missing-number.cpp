class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int actualSum = (nums.size()*(nums.size()+1))/2;
        for( auto i : nums) sum+= i;
        return actualSum - sum;
    }
};