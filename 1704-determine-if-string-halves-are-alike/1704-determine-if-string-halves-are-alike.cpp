class Solution {
public:
    
    bool isVowel(char c)
    {
        if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' ||c == 'U' ) return true;
        return false;
    }
    
    bool halvesAreAlike(string s) {
        int n = s.size();
        int vowelCountInA = 0,vowelCountInB = 0;
        for( int i = 0; i < n; i++)
        {
            if( i < n/2 && isVowel(s[i]) ) vowelCountInA++;
            else if( isVowel(s[i]) ) vowelCountInB++;
        }
        if( vowelCountInA == vowelCountInB ) return true;
        else return false;
    }
};