class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size(), peakIndex, justGreaterIndex;
        for( int i = n - 1; i > 0; i--)
        {
            if( nums[i] > nums[i-1] )
            {
                peakIndex = i - 1;
                break;
            }
        }
        if( peakIndex == -1 ) reverse( nums.begin(), nums.end());
        else
        {
            for( int i = n - 1; i > peakIndex; i--)
            {
                if( nums[i] > nums[peakIndex] )
                {
                    justGreaterIndex = i;
                    break;
                }
            }
            swap( nums[justGreaterIndex],nums[peakIndex]);
            reverse(nums.begin() + peakIndex + 1, nums.end());
        }
        
    }
};