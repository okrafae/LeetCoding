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
​
class Solution {
public:
int mergeSort(int low, int high, vector<int> &nums)
{
if( low >= high ) return 0;
int mid = low + (high - low)/2;
int ans1 = mergeSort(low,mid,nums);
int ans2 = mergeSort(mid + 1,high,nums);
int ans3 = merge(low,mid,high,nums);
return ans1 + ans2 + ans3;
}
int merge(int low,int mid, int high, vector<int> &nums)
{
vector<int> copy(nums);