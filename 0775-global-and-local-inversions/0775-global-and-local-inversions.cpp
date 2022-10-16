class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        for( int i = 0; i < n; i++)
        {
            if( abs(i-nums[i]) >= 2 ) return false;
        }
        return true;
    }
};