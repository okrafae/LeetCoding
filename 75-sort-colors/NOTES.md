class Solution {
public:
void sortColors(vector<int>& nums) {
int pointerZero = 0, pointerTwo = nums.size() - 1,countOfTwo = 0;
for( int i = 0; i < nums.size() - countOfTwo; i++)
{
if( nums[i] == 0 )
{
swap( nums[i], nums[pointerZero++]);
if( nums[i] == 2)
{
swap( nums[i], nums[pointerTwo--]);
countOfTwo++;
i--;
}
}
}
};
​