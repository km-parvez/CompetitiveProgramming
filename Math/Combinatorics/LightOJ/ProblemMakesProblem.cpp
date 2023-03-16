// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 1000006

using namespace std;
using ll = long long;
int mod = 1e9+7;

ll fact[MAXX];
int powMod(ll b,ll p){
	ll res = 1;
	while(p>0){
		if(p&1)
		{
			res = (res*b)%mod;
		}
		b = (b*b)%mod;
		p=p>>1;
	}
	return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0]=1;
    for(int i=1; i<MAXX; i++) {
    	fact[i] = (fact[i-1]*i)%mod;
    }
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        ll n,k;
        cin>>n>>k;
       
       // db1(n+k-1);
        //*****|*|*
        //(n+k-1) C (k-1) = (n+k-1)!/{(k-1)!n!}
        ll inv = (fact[k-1]*fact[n])%mod;
        ll ans = (fact[n+k-1]*powMod(inv,mod-2))%mod;
        caseprint(caseno,ans);
    
    }
    return 0;
}