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
constexpr ll mod = 1000000007;
constexpr int MX = 200005;

void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}

int tree[MX];
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx = idx-(idx & -idx);

    }
    return sum;
}

void update(int idx,int val,int n){
    while(idx<=n){
        tree[idx]+=val;
        idx= idx+ (idx & -idx);
    }
}

void solve(int caseno){
    cout<<"Case "<<caseno<<":"<<endl;
    int n,q;
    cin>>n>>q;
    for(int i=0; i<=n; i++) {
        tree[i]=0;
    }
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        update(i,x,n);
    }
    while(q--){
        int type;cin>>type;
        if(type == 1){
            int ind;
            cin>>ind;
            ind++;
            int up = query(ind);
            int low = query(ind-1);
            int  ans = up - low;
            cout<<ans<<endl;
            update(ind,-ans,n);

        }
        else if(type==2){
            int ind,val;
            cin>>ind>>val;
            ind++;
            update(ind,val,n);

        }
        else{
            int ind1,ind2;
            cin>>ind1>>ind2;
            ind1++;ind2++;
            int up = query(ind2);
            int low = query(ind1-1);
            cout<<(up-low)<<endl;
        }
  }
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