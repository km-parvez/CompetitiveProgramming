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
ll arr[1004][1004];
ll rowsum[1004][1004];
ll colsum[1004][1004];
void solve(int caseno){
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;

    ll rr = rowsum[x2][y2]-rowsum[x2][y1];
    ll cc = colsum[x2][y1]-colsum[x1-1][y1];

    ll ans=rr+cc;
    cout<<ans<<'\n';
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    arr[0][1] = 0;
    for(int i=1; i<1004; i++) {
    	arr[i][1] = arr[i-1][1]+i;
    	int go = i;
    	for(int j=2; j<1004; j++) {
    		arr[i][j]= arr[i][j-1]+go;
    		go++;
    	}
    }
    for(int i=1; i<1004; i++) {
    	for(int j=1; j<1004; j++) {
    		rowsum[i][j]= rowsum[i][j-1]+arr[i][j];
    	}
    }
    for(int i=1; i<1004; i++) {
    	for(int j=1; j<1004; j++) {
    		colsum[j][i]= colsum[j-1][i]+arr[j][i];
    	}
    }
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}