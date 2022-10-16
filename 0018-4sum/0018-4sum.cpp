class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size(), i = -1;
        sort( nums.begin(), nums.end() );
        vector<vector<int>> ans;
        while( i < n - 3 )
        {
            i++;
            if( nums[i] > target && nums[i] > 0 ) break;
            if( i > 0 && nums[i] == nums[i-1] ) continue;
            long long int sum3 = target - nums[i];
            int j = i;
            while( j < n - 2 )
            {
                j++;
                if( nums[j] > sum3 && nums[j] > 0 ) break;
                if( j > i+1 && nums[j] == nums[j-1]) continue;
                long long int sum2 = sum3 - nums[j];
                int k = j + 1,r = n - 1;
                while( k < r)
                {
                    long long int sum1 = sum2 - nums[k];
                    if( nums[r] == sum1 )
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[r]);
                        ans.push_back(temp);
                        int prevleft = k, prevright = r;
                        while( k < r && nums[k] == nums[prevleft] ) k++;
                        while( k < r && nums[r] == nums[prevright] ) r--; 
                    }
                    else if( nums[k] + nums[r] < sum2)
                    {
                        k++;
                    }
                    else
                    {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};