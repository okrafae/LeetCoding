class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0]+nums[1]+nums[2], n = nums.size();
        sort( nums.begin(),nums.end());
        for( int i = 0; i < n-2; i++)
        {
            int left = i + 1, right = n - 1;
            while( left < right )
            {
                int sum3 = nums[i] + nums[left] + nums[right];
                if( sum3 < target)
                {
                    if( abs(closest-target) > abs( sum3 - target))
                      {
                          closest = sum3;
                      }
                    left++;
                }
                else if( sum3 > target)
                {
                      if( abs(closest-target) > abs( sum3 - target))
                      {
                          closest = sum3;
                      }
                    right--;
                }
                else
                {
                    closest = target;
                    break;
                }
            }
        }
        return closest;
    }
};