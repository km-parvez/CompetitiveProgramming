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
constexpr ll mod = 1000000007;
constexpr int MX = 200005;

void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}

#define int long long

// try binary search,BIT,segment tree, dp, dfs, union find, set, priority queue, sorting, two pointer, gready.
string findSum(string X, string Y) {
    string ans;
   
    reverse(X.begin(),X.end());
    reverse(Y.begin(),Y.end());
    int dif = X.size()-Y.size();
    if(dif>0){
        for(int i=0; i<dif; i++) {
            Y.push_back('0');
        }   
    }
    else{
        for(int i=0; i<-dif; i++) {
            X.push_back('0');
        }  
    } 
    int c=0;
    for(int i=0; i<X.size(); i++) {
        int d = c+(X[i]-'0')+(Y[i]-'0');
        if(d>=10){
            int rem = d%10;
            char ch = '0'+rem;
            ans.push_back(ch);
            c=1;     
        }
        else{
            char ch = '0'+d;
            ans.push_back(ch);     
            c=0; 
        }
    }
    if(c>0){
        ans.push_back('1'); 
    }
    while(ans.size()>1){
        if(ans.back()!='0'){
            break;
        }
        else{
            ans.pop_back();
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
main()
{
    ios::sync_with_stdio(0);
    string x,y;
    cin>>x>>y;
    string ans = findSum(x,y);
    cout<<ans<<'\n';
    
    
    return 0;
}       