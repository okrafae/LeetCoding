class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size();
        int count = 0;
        if( N == 1)
        {
            if( flowerbed[0] == 0 ) count++;
        }
        else
        {
            for( int i = 0; i < N ; i++)
            {
                if( i == 0)
                {
                    if( N > 1 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
                    {
                        count++;
                        flowerbed[i] = 1;
                    }
                }
                else if( i == N - 1)
                {
                    if( N > 1 && flowerbed[i] == 0 && flowerbed[i-1] == 0)
                    {
                        count++;
                        flowerbed[i] = 1;
                    }
                }
                else if( flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
                {
                    count++;
                    flowerbed[i] = 1;
                }
            }
        }
        return count >= n;
        
    }
};