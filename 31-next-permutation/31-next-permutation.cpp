class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if( nums.size() == 1 ) return;
        int i, arraySorted = 1,rightMinimum = INT_MAX, prevMinimum = INT_MAX, minimumIndex=nums.size() - 1;
        for( i = nums.size() - 1 ; i > 0; i--)
        {
            if( nums[i] > nums[i-1] )
            {
                int j = i;
                while( j < nums.size() && nums[j] > nums[i-1] )
                {
                    prevMinimum = rightMinimum;
                    rightMinimum = min( rightMinimum, nums[j] );
                    if( prevMinimum != rightMinimum ) minimumIndex = j;
                    j++;
                }
                swap( nums[minimumIndex], nums[i-1]);
                arraySorted = 0;
                break;
            }
        }
        if( arraySorted )
        {
            sort( nums.begin(), nums.end());
            return;
        }
        sort( nums.begin() + i, nums.end());
        return;
    }
};