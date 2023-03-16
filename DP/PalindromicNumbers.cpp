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
#define MAXX 1000006

using namespace std;
using ll = long long;
string str;
int n;
ll dp[18][3][18];
int half;
ll func(int pos,int isSmall,int hasStarted){
	int right = n-pos-1+hasStarted;
	if(right<pos)return 0;


	if(dp[pos][isSmall][hasStarted]!=-1){
		return dp[pos][isSmall][hasStarted];
	}
	int low = 0,hi = 9;
	if(!isSmall){ 
		hi=str[pos]-'0';
		if(pos>0&&right<n-1&& str[pos-1]>str[right+1]){isSmall=1;hi--;}
	}
whatis3(pos,hasStarted,hi);
whatis2(str[pos],str[right]);
	ll val = 0; 
	for(int i=low; i<=hi; i++) {
		int newSmall = isSmall|i<hi;
		if(hasStarted==pos&&i==0)
		val += func(pos+1,newSmall,hasStarted+1);
		else if(isSmall)
		val += func(pos+1,newSmall,hasStarted)+1;
		else if(!isSmall&&i<=str[right]-'0')		
		val += func(pos+1,newSmall,hasStarted)+1;
		else if(!isSmall&&i>str[right]-'0')
		val += func(pos+1,newSmall,hasStarted);
	}
	whatis2(pos,val);
	return dp[pos][isSmall][hasStarted]=val;


}

void solve(int caseno){
    ll a,b;
	memset(dp,-1,sizeof(dp));
    cin>>b;
    str = to_string(b);
   	n = str.size();
   	half = (n+1)/2;
    ll ans1 =func(0,0,0);
    whatis1(ans1);
  
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