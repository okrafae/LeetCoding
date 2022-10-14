class Solution {
public:
bool isIdealPermutation(vector<int>& nums) {
int n = nums.size(), countOfGlobalInversions = 0, countOfLocalInversions = 0;
for( int i = 0; i < n; i++)
{
for( int j = i + 1; j < n; j++)
{
if( nums[i] > nums[j])
{
countOfGlobalInversions++;
if( j == i + 1) countOfLocalInversions++;
}
}
}
if( countOfGlobalInversions == countOfLocalInversions) return true;
else return false;
}
};