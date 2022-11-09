class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = INT_MIN;
        for( int i = 0; i < n; i++)
        {
            int currentProduct = 1,j = i;
            while( j<n && nums[j]!=0 )
            {
                currentProduct *= nums[j];
                if( currentProduct > maxProduct) maxProduct = currentProduct;
                j++;
            }
            int k = i;
            while( k < j && j-i != 1)
            {
                currentProduct /= nums[k];
                if( currentProduct > maxProduct ) maxProduct = currentProduct;
                k++;
            }
            if( j < n && nums[j] == 0) maxProduct = max( maxProduct,0);
            i = j;
        }
        return maxProduct;
    }
};