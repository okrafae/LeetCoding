//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {

  public:

    string removeReverse(string S) {

        int n=S.size();

        vector<int> freq(26);

        bool rev=false;

        for(int i=0;i<n;i++) freq[S[i]-'a']++;

        

        vector<int> arr(n,0);

        

        int i=0 ,j=n-1;

        while(i<=j){

            if(rev==false){

                if(freq[S[i]-'a']==1){

                    arr[i]=1;

                    i++;

                    continue;

                }

                else{

                    freq[S[i]-'a']--;

                    rev=true;

                }

                i++;

            }

            else{

                if(freq[S[j]-'a']==1){

                    arr[j]=1;

                    j--;

                    continue;

                }

                else{

                     freq[S[j]-'a']--;

                    rev=false;

                }

                j--;

            }

        }

        

        string ans;

        for(int i=0;i<n;i++){

            if(arr[i]==0)

                continue;

            ans.push_back(S[i]);

        }

        

        if(rev==true)

        {

            reverse(ans.begin(),ans.end());

            return ans;

        }

        

        return ans;

    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends