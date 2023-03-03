class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int k = needle.size(), flag = 0;
        if( k == 0 ) return 0;
        if( k > n ) return -1;
        int i = 0;
        for( i = 0; i < n-k+1 ; i++)
        {
            if( haystack[i] == needle[0] && haystack[i+k-1] == needle[k-1] )
            {
                int l = i, m = 0;
                while( m < k)
                {
                    if( haystack[l+m] != needle[m] ) break;
                    m++;
                }
                if( m == k)
                {
                    flag = 1;
                    break;
                }
            }
        }
        cout<<i<<" ";
        if( flag == 1) return i;
        // cout<<" HI ";
        return -1;
        
    }
};