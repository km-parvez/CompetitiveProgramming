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
#define MX 105

using namespace std;
using ll = long long;

int arr[MX];
pair<int,ll> dp[MX][MX];
pair<int,ll> marge(pair<int,ll> l,pair<int,ll> r){
	pair<int,ll> tmp;
	tmp.first = (l.first+r.first)%100;
	tmp.second = l.second+r.second+(ll)(l.first*r.first);
	return tmp;
}
pair<int,ll> chinmul(int b,int e){

	if(e<b)return {0,0};
	if(b==e)return {arr[b],0};
	if(dp[b][e].first!=-1){
		return dp[b][e];
	}
	pair<int,ll> ans = {INT_MAX,INT_MAX};
	for(int i=b; i<e; i++) {
		pair<int,ll> l = chinmul(b,i);
		pair<int,ll> r = chinmul(i+1,e);
		pair<int,ll> tmp = marge(l,r);
		if(ans.second==tmp.second){
			if(ans.first>tmp.first){
				ans = tmp;
			}
		}
		else if(ans.second>tmp.second){
			ans = tmp;
		}
	}
	dp[b][e]= ans;
	return dp[b][e];
}
void solve(int n){
    
 	for(int i=0; i<n+2; i++) {
    	for(int j=0; j<n+2; j++)
		dp[i][j]={-1,-1};	
    }
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    pair<int,ll> ans = chinmul(0,n-1);
    cout<<ans.second<<'\n';
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin>>n){
        solve(n);
    }
    return 0;
}