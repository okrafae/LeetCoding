class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long int> prefix(n,0);
        prefix[0] = nums[0];
        for( int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i-1] + nums[i];

        }
        long long int index = 0;
        long long int temp = INT_MAX,minDiff = INT_MAX;
        for( int i = 0; i < n-1; i++)
        {
            long long int avgDiff = abs( (prefix[i]/(i+1)) - ( (prefix[n-1] - prefix[i])/(n-i-1) ) );
            cout << avgDiff << " ";
            temp = minDiff;
            minDiff = min( minDiff, avgDiff  );
            if( temp != minDiff) index = i;
        }
        temp = minDiff;
        minDiff = min( minDiff, abs( prefix[n-1] / (n) )  );
        if( temp != minDiff) index = n-1;
        return index;
    }
};