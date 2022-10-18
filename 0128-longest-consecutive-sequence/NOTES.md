// nlogn solution by sorting
class Solution {
public:
int longestConsecutive(vector<int>& nums) {
int n = nums.size(), maxLength = 1, currLength = 1;
if( n == 1 || n == 0 ) return n;
sort( nums.begin(), nums.end());
int previous_i = 0;
for( int i = 1; i < n; i++)
{
if( nums[i] == nums[previous_i] ) continue;
if( nums[i] == nums[previous_i] + 1)
{
previous_i = i;
currLength++;
}
else
{
previous_i = i;
currLength = 1;
}
maxLength = max( maxLength, currLength);
}
return maxLength;
}
};