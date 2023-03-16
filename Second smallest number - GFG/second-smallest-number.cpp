//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int s, int d){
        string ss;
        int sm=0;
        for(int i=0;i<d;i++){
            ss.push_back('0');
        }
        if(d==1)return "-1";
      
        for(int i=d-1;i>=0;i--){
            if(s>9){
                ss[i]='9';
                s-=9;
            }
            else{
                ss[i]=s+'0';
                s-=s;
            }
        }
       if(ss[0]=='0'){
           int f=0;
           for(int i=0;i<d;i++){
               if(ss[i]>'0'){
                   f=1;
                   ss[i]=(ss[i]-'0'-1)+'0';
                   ss[0]='1';
                   break;
               }
           }
           if(f==0)return "-1";
       }
       
        for(int i=d-1;i>0;i--){
            string tmp=ss;
          
                int t=tmp[i]-'0';
                t--;
                int t1=tmp[i-1]-'0'+1;
          
                if(t1<=9){
                    tmp[i-1]=t1+'0';
                    tmp[i]=t+'0';
                    return tmp;
                }
                
        }
      return "-1";
      }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends