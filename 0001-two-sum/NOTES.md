// two pointer using pairs
class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
int i = 0, n = nums.size(), j = n - 1;
vector<pair<int,int>> arr(n);
for( int i = 0; i < n; i++)
{
arr[i].first = nums[i];
arr[i].second = i;
}
sort( arr.begin(), arr.end());
vector<int> ans;
while( i < j )
{
if( arr[i].first + arr[j].first == target )
{
ans.push_back(arr[i].second);
ans.push_back(arr[j].second);
break;
}
else if( arr[i].first + arr[j].first < target ) i++;
else j--;
}
return ans;
}
};