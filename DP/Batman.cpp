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
#define MAXX 55

using namespace std;
using ll = long long;
string ch1,ch2,ch3;
int len1,len2,len3;
int dp[MAXX][MAXX][MAXX];
int lcs(int pos1,int pos2,int pos3){
	if(pos1>=len1 || pos2>=len2 ||pos3>=len3)
		return 0;
	if(dp[pos1][pos2][pos3]!=-1)
		return dp[pos1][pos2][pos3];
	if(ch1[pos1]==ch2[pos2]&&ch1[pos1]==ch3[pos3]){
		return dp[pos1][pos2][pos3]=lcs(pos1+1,pos2+1,pos3+1)+1;
	}
	else
	{
		int ans1= lcs(pos1+1,pos2,pos3);
		int ans2= lcs(pos1,pos2+1,pos3);
		int ans3= lcs(pos1,pos2,pos3+1);
		return dp[pos1][pos2][pos3] = max(ans1,max(ans2,ans3));
	}
}
void solve(int caseno){
    cin>>ch1>>ch2>>ch3;
    len1= ch1.size();
    len2= ch2.size();
    len3= ch3.size();
    memset(dp,-1,sizeof(dp));
    int res = lcs(0,0,0);
    caseprint(caseno,res);
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