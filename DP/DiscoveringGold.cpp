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
    int n;
    cin>>n;
    vector<double> v(n+10);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    v[n] = 0;
    int co=1;
    double slider = v[n-1];
    for(int i=n-2; co<6&&i>=0; i--) {
    	double sum = 0.0;
    	for(int j=i+1; j<n; j++) {
    		sum+=v[j];
    	}
    	v[i] += sum/co; 
    	slider+=v[i];
    	co++;
    }
   // whatisArray(v,n);
   // whatis2(slider,v[n-7]);
    for(int i=n-7; i>=0; i--) {
    	slider=0;
    	for(int j=0; j<6; j++) {
    		slider+=v[i+j+1];
    	}
    	 v[i]=v[i]+(slider/6.0);
    	
    }
   // whatisArray(v,n);
    cout.precision(8); cout<<fixed ;
    caseprint(caseno,v[0]);
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