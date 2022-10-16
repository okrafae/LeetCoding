class Solution {
public:
    
    int mergeSort(int low, int high, vector<int> &nums)
    {
        if( low >= high ) return 0;
        int mid = low + ( high - low )/2;
        int ans = 0;
        ans += mergeSort(low, mid, nums);
        ans += mergeSort(mid + 1, high, nums);
        ans += merge(low, mid, high, nums);
        return ans;
    }
    
    int merge( int low, int mid, int high,vector<int> &nums)
    {
        vector<int> temp;
        int i = low, j = mid + 1, k = low, reversePairCount = 0, b = mid + 1;
        for( int a = low; a <= mid; a++)
        {
            while( b <= high && (long long int)nums[a] > (long long int) 2*nums[b] ) b++;
            reversePairCount += ( b - mid - 1);
        }
        //sort( nums.begin() + low, nums.begin() + high + 1);
        while( i <= mid && j <= high)
        {
            if( nums[i] <= nums[j] ) temp.push_back(nums[i++]);
            else
            {
                temp.push_back(nums[j++]);
            }
        }
        while( i <= mid ) temp.push_back(nums[i++]);
        while( j <= high ) temp.push_back(nums[j++]);
        for( int i = low; i <= high; i++)
        {
            nums[i] = temp[i-low];
        }
        return reversePairCount;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = mergeSort(0,n-1,nums);
        return ans;
    }
};