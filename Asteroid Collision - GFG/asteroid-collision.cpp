//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here

        vector<int> answer;
        stack<int> st;
        for( int i = 0; i < N; i++)
        {
            if( st.empty()) st.push(asteroids[i]);
            else
            {
                if( asteroids[i] > 0 ) st.push(asteroids[i]);
                else
                {
                    if( st.top() > 0 )
                    {
                        while( !st.empty() && st.top() > 0 && abs(asteroids[i]) > abs(st.top()) ) st.pop();
                        if( st.empty() ) st.push(asteroids[i]);
                        else if( st.top() == abs(asteroids[i]) ) st.pop();
                        else if( st.top() < abs(asteroids[i])) st.push(asteroids[i]);
                    }
                    else
                    {
                        st.push(asteroids[i]);
                    }
                }
            }
        }
        
        while( !st.empty() )
        {
            int temp = st.top();
            answer.push_back(temp);
            st.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends