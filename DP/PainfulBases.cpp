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
#define MAXX 1004

using namespace std;
using ll = long long;
void setBit(int &mask,int pos){
	mask=mask|(1<<pos);
}
bool isOn(int mask,int pos){
	return (mask>>pos)&1;
}
bool isAll(int mask,int n){
	return mask==(1<<n)-1;
}
int fact[13];
void makeFact(){
	fact[0] = 1;
	for(int i=1; i<=10; i++) {
		fact[i] = fact[i-1]*i;
	}
}
int arr[17];
string str;
int len,d,base;
ll dp[8192][101];
ll func(int mask,int rem){
	int pos = __builtin_popcount(mask);
	if(pos==len){
		return rem==0;
	}
	if(dp[mask][rem]!=-1)return dp[mask][rem];
	ll val = 0;
	for(int i=0; i<len; i++) {
		if(!isOn(mask,i)){
			val+= func(mask|1<<i,(rem*base+(arr[i]))%d); 
		}
	}
	return dp[mask][rem] = val;
}

void solve(int caseno){
    cin>>base>>d;
    cin>>str;
    len = str.size();
    
    for(int i=0; i<len; i++) {
        if(str[i]>='A'|| str[i]>='F')
            arr[i] = 10+(str[i]-'A');
        else 
            arr[i] = str[i]-'0';
    }
   // whatisArray(arr,len);
    memset(dp,-1,sizeof(dp));
    ll ans = func(0,0);
    caseprint(caseno,ans);
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases,caseno=0;
    makeFact();
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}