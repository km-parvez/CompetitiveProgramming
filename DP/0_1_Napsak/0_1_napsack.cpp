// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define whatArray2D(arr,m,n) cout<<#arr<<", Size: "<<m<<","<<n<<'\n';for(int mm=0;mm<m;mm++){for(int nn=0;nn<n;nn++)cout<<arr[mm][nn]<<" ";cout<<'\n';} 
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define MX 1003

using namespace std;
using ll = long long;
int op[MX];
int knapSack(int W, int wt[], int val[], int n)
{
    // making and initializing dp array
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {
 
            if (wt[i - 1] <= w)
                // finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W]; // returning the maximum value of knapsack
}
void solve(int caseno){
    int n,k;
    cin>>n>>k;
    k= min(k,15003);
    int b[n+5],c[n+5],w[n+5];
    for(int i=0;i<n;i++) {
        cin>>b[i];
        w[i] = op[b[i]];
    }
    for(int i=0;i<n;i++) {
        cin>>c[i];
    }
//    whatisArray(w,n);
    int ans=0;
    ans = knapSack(k,w,c,n);
    cout<<ans<<'\n';
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    for(int i=0; i<MX; i++) {
        op[i]=1003;
    }
  //  op[0]=0;
    op[1]=0;
    for(int i=1; i<MX; i++) {
        for(int j=1; j<=i; j++) {
            int nw= i+(i/j);
            op[nw] = min(op[nw],op[i]+1);
        }
    }
   // whatisArray(op,10);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}