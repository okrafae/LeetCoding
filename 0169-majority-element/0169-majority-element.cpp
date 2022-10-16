class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0, majority_element;
        for( auto i : nums)
        {
            if( count == 0 ) majority_element = i;
            if( i == majority_element ) count++;
            else count--;
        }
        return majority_element;
    }
};