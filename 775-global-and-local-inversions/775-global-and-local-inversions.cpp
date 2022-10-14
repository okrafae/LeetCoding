class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        
    int n = nums.size();
    int maxVal = nums[0];
    for ( int i = 0; i + 2 < n; i++)
    {
        maxVal = max( nums[i], maxVal);
        if( maxVal > nums[i+2] ) return false;

    }
        return true;
        
    }
};