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
#define MAXX 100005

using namespace std;
using ll = long long;
int presum[MAXX];
void solve(int caseno){
    int a,b;
    cin>>a>>b;
    int ans = presum[b]-presum[a-1];
    cout<<ans<<'\n';
    
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1; i<MAXX; i++) {
    	int lastdigit = i%10;
    	if(lastdigit==2||lastdigit==3||lastdigit==9)
    		presum[i]=1;
    }
    for(int i=1; i<MAXX; i++) {
    	presum[i]+=presum[i-1];
    }
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}