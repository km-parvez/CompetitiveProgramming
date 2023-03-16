// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define MX 200005

using namespace std;
using ll = long long;

void solve(int caseno){
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll  x,y;cin>>x>>y;
    ll wsum[n+2],esum[n+2];
    x = min(x,3*y);
    y = min(y,3*x);
    for(int i=0; i<n; i++) {
    	if(s[i]=='N'){wsum[i]=y;esum[i]=x;}
    	if(s[i]=='S'){wsum[i]=x;esum[i]=y;}
    	if(s[i]=='E'){wsum[i]=2LL*min(x,y);esum[i]=0;}
    	if(s[i]=='W'){wsum[i]=0;esum[i]=2LL*min(x,y);}
    }
  
    for(int i=1; i<n; i++) {
    	esum[i]+=esum[i-1];
    }

    for(int i=n-2; i>=0; i--) {
    	wsum[i]+=wsum[i+1];
    }
    ll ans = esum[n-1];
    for(int i=0; i<n; i++) {
    	ll tmpAns = wsum[i]+(i==0?0:esum[i-1]);
    //	if(tmpAns<ans)whatis2(i,tmpAns);
    	ans = min(ans,tmpAns);
    }
    cout<<ans<<'\n';
    
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}