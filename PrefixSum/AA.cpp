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
#define MX 1000006

using namespace std;
using ll = long long;

void solve(int caseno){
    int n,m;
    cin>>n>>m;
    int arr[n+2][m+5];
    for(int i=0; i<n; i++) {
    	arr[i][0] = -1;arr[i][m+1]=mod;
    	for(int j=1; j<=m; j++) {
    		cin>>arr[i][j];
    	}
    }
    int x=-1,y=-1;
    for(int i=0; i<n; i++) {
    	int prv = arr[i][0];
    	for(int j=1; j<=m; j++) {
    		if(prv>arr[i][j]){
    			x = j-1;
    			y=j;
    			while(arr[i][x]==arr[i][x-1]){
    				x--;
    			}
    			break;
    		}
    		prv = arr[i][j];
    	}
    }
     for(int i=0; i<n; i++) {
    	int prv = arr[i][m];
    	for(int j=m-1; j>=0; j--) {
    		if(prv<arr[i][j]){

    			y=j+1;
    			while(arr[i][y]==arr[i][y+1]){
    				y++;
    			}
    			break;
    		}
    		prv = arr[i][j];
    	}
    }
    if(x==-1){
    	cout<<1<<" "<<1<<'\n';
    	return;
    }
    for(int i=0; i<n; i++) {
    	swap(arr[i][x],arr[i][y]);
    }
      int xx=-1;
    for(int i=0; i<n; i++) {
    	int prv = arr[i][0];
    	for(int j=1; j<=m; j++) {
    		if(prv>arr[i][j]){
    			xx = j-1;
    			break;
    		}
    		prv = arr[i][j];
    	}
    }
    if(xx==-1){
    	cout<<x<<" "<<y<<'\n';
    }
    else
    	cout<<-1<<'\n';
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