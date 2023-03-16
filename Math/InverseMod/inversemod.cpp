// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'

#define MAXX  1000006
using namespace std;
using ll = long long;
int mod = 1e9+7;
ll powMod(ll b,ll p){
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

        ll fact_6 = 720;
        ll fact_2 = 2;
        ll fact_4 = 24;
        // (a/b)%mod = a%mod * powMod(b,mod-2);
        ll invPart = (fact_2*fact_4)%mod; 
        long long ans = (fact_6* powMod(invPart,mod-2))%mod;
        cout<<ans<<endl;
    	
    return 0;
}