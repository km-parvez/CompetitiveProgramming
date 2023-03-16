// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define MX 1000006

using namespace std;
using ll = long long;
int ask(int n){
    cout<<"? "<<n<<'\n';
    int rep;cin>>rep;
    return rep;
}
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    if(n==1){
        cout<<"! "<<1<<'\n';return 0 ;
    }
    int low = 1, hi = n-1;
    int mid;
    while(low<=hi){
        mid = (hi+low)/2;
        ll m1 = ask(mid);
        ll m2 = ask(mid+1);
        if( m1>m2){
            low = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    cout<<"! "<<low<<'\n';
    fflush(stdout);
    
    return 0;
}