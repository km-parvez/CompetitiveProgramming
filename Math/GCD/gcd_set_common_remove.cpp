// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define whatArray2D(arr,m,n) cout<<#arr<<", Size: "<<m<<","<<n<<'\n';for(int mm=0;mm<m;mm++){for(int nn=0;nn<n;nn++)cout<<arr[mm][nn]<<" ";cout<<'\n';} 
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
constexpr ll mod = 998244353;
constexpr int MX = 200005;

void solve(int caseno){
    ll a,m;
    cin>>a>>m;

    ll num = m;
    ll gcd = __gcd(a,m);
    ll ans = 1;
   
    ll extra = m/gcd;
    vector<ll> bad;
    num = extra;
    ll sq = sqrt(num)+2;
    for(ll i=2; i<=sq; i++) {
        bool flag = false;
        while(num>1&&(num%i)==0){
            num/=i;
            if(!flag)bad.push_back(i);
            flag = true;
        }
    }
    if(num>1)bad.push_back(num);
       
    ll op = (a+m-1);
    ll rem = 0;
    set<ll>prd[bad.size()+5];
    prd[0].emplace(1);
    for(int x=1; x<=bad.size(); x++) {
        for(int t=0; t<bad.size(); t++) {
            for(auto c: prd[x-1]) {
                if(c%bad[t]!=0){
                    prd[x].emplace(c*bad[t]);
                }
            }
        }
        for(auto c:prd[x]){
            if(x%2==1)
                rem+=( (op/(gcd*c) ) - ((a-1)/(gcd*c)));
            else 
                rem-=( (op/(gcd*c) ) - ((a-1)/(gcd*c)));
        }
    }

//  whatis3(gcd,op,rem);
    op = (op/gcd ) - ((a-1)/gcd);
    op -=rem;
    ans=op;
    
    cout<<ans<<'\n';
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}