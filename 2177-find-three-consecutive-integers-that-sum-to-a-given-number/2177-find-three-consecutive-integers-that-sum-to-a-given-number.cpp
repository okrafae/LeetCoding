class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if( num % 3 == 0)
        {
            vector<long long> ans = { (num/3 - 1), (num/3), (num/3+1) };
            return ans;
        }
        return {};
    }
};