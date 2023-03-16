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
vector<int> divs[MX];
double dp[MX];
void solve(int caseno){
    int n;
    cin>>n;
    double ans = dp[n];
    cout.precision(6); cout<<fixed; 
    caseprint(caseno,ans);
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases,caseno=0;
    for(int i=2; i<MX; i++) {
    	int sqr = sqrt(i);
    	for(int j=2; j<=sqr; j++) {
    		if(i%j==0){
    			divs[i].push_back(j);
    			divs[i].push_back(i/j);
    		}
    	}
    	if(sqr*sqr==i){
    		divs[i].pop_back();
    	}
    	
    }
    dp[1]=0;
      for(int i=2; i<MX; i++) {
    	double sum = 0;
    	for(int j=0; j<divs[i].size(); j++) {
    		sum+=dp[divs[i][j]];
    	}
    	
    	dp[i]=(2+sum+divs[i].size());
    	if(divs[i].size()>0){
    		dp[i]/=(divs[i].size()+1);
    	}
    }
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}