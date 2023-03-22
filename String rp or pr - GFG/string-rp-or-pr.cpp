//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string s){
        
        long long ans = 0, f1 = 0 , f2 = 0 , f3 = 0 , f4 = 0;
        stack<char>st;
        int n = s.size();
        
        if(X > Y)
        {
            //pr
            for(int i=0;i<n;i++)
            {
                if(st.empty()) st.push(s[i]);
                
                else if(s[i] == 'r' && st.top() == 'p'){
                    f1++;
                    st.pop();
                }
                
                else{
                    st.push(s[i]);
                }
            }
            
            //rp
            int cnt = 0;
            while(!st.empty())
            {
                if(st.top() == 'p')
                {
                    cnt++;
                    st.pop();
                }
                
                else if(st.top() == 'r' && cnt > 0)
                {
                    f2++;
                    cnt--;
                    st.pop();
                }
                
                else {
                    st.pop();
                    cnt = 0;
                }
            }
            
        }
        
        else{
            
            //rp
            for(int i=0;i<n;i++)
            {
                if(st.empty()) st.push(s[i]);
                
                else if(s[i] == 'p' && st.top() == 'r'){
                    f3++;
                    st.pop();
                }
                
                else{
                    st.push(s[i]);
                }
            }
            
            
            //pr
            int cnt = 0;
            while(!st.empty())
            {
                if(st.top() == 'r')
                {
                    cnt++;
                    st.pop();
                }
                
                else if(st.top() == 'p' && cnt > 0)
                {
                    f4++;
                    cnt--;
                    st.pop();
                }
                
                else {
                    st.pop();
                    cnt = 0;
                }
            }
        }
        
        ans = (f1 * X) + (f2 * Y) + (f3 * Y) + (f4 * X);
        return ans;
    }

};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends