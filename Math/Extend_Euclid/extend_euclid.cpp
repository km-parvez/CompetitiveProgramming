// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define whatArray2D(arr,m,n) cout<<#arr<<", Size: "<<m<<","<<n<<'\n';for(int mm=0;mm<m;mm++){for(int nn=0;nn<n;nn++)cout<<arr[mm][nn]<<" ";cout<<'\n';} 
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
constexpr int MX = 200005;
ll extendgcd(ll a,ll b, ll &x, ll &y){
    if(b==0) {
        x = 1;
        y = 0;
        return a;
    }
    ll xx,yy;
    ll ans =extendgcd(b,a%b,xx,yy);
    x = yy;
    y = xx-yy*(a/b);
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a,b;
    while(cin>>a>>b){
        ll x,y;
        ll gcd =  extendgcd(a,b,x,y);
        cout<<x<<" "<<y<<' ';
        cout<<gcd<<'\n';
    }
    
    
    return 0;
}