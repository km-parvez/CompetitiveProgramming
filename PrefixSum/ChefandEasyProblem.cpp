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
#define MX 100005

using namespace std;
using ll = long long;

void solve(int caseno){
    int n,q;
    cin>>n>>q;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }
    int bit[n+3][32]={0};
    for(int i=1; i<=n; i++) {
    	int pos = 0;
    	int tmp = v[i];
    	while(tmp>0){
    		bit[i][pos] = tmp&1;
    		tmp=tmp>>1;
 			pos++;   	
    	}
    }
    for(int i=1; i<=n; i++) {
    	for(int j=0; j<32; j++) {
    		bit[i][j]+=bit[i-1][j];
    	}
    }
    while(q--){
    	ll ans = 1LL<<31;
    	ans--;
    	int l,r;
    	cin>>l>>r;
    	int totnum = (r-l+1);
    	if(totnum&1)totnum++;
    	totnum/=2;
    	for(int i=0; i<32; i++) {
    		int onbit=(bit[r][i]-bit[l-1][i]);
    		//whatis3(i,onbit,totnum);
    		if(onbit>=totnum){
    		//	whatis3(i,onbit,totnum);
    			ans-=(1<<i);
    		}
    	}
    	cout<<ans<<'\n';
    }

    
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases=1,caseno=0;
    //cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}