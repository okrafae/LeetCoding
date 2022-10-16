class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int mostFrequentElement = INT_MIN, secondMostFrequentElement = INT_MIN, countOfMostFrequentElement = 0, countOfSecondMostFrequentElement = 0;
        vector<int> ans;
        for( int i = 0; i < n; i++)
        {
            if( nums[i] == mostFrequentElement) countOfMostFrequentElement++;
            else if( nums[i] == secondMostFrequentElement ) countOfSecondMostFrequentElement++;
            else if( countOfMostFrequentElement == 0 ) 
            {
                mostFrequentElement = nums[i];
                countOfMostFrequentElement++;
            }
            else if( countOfSecondMostFrequentElement == 0){
                secondMostFrequentElement = nums[i];
                countOfSecondMostFrequentElement++;
            }
            else
            {
                countOfMostFrequentElement--;
                countOfSecondMostFrequentElement--;
            }
        }
        countOfMostFrequentElement = 0, countOfSecondMostFrequentElement = 0;
        for( auto i : nums)
        {
            if( i == mostFrequentElement ) countOfMostFrequentElement++;
            if( i == secondMostFrequentElement ) countOfSecondMostFrequentElement++;
        }
        if( countOfMostFrequentElement > n/3 ) ans.push_back(mostFrequentElement);
        if( countOfSecondMostFrequentElement > n/3) ans.push_back(secondMostFrequentElement);
        return ans;
    }
};