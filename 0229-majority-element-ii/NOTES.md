class Solution {
public:
vector<int> majorityElement(vector<int>& nums) {
int n = nums.size();
unordered_map<int,int> m;
vector<int> ans;
for( int i = 0; i < n; i++)
{
m[nums[i]]++;
if( m[nums[i]] > n/3 )
{
m[nums[i]] = INT_MIN;
ans.push_back(nums[i]);
}
}
return ans;
}
};