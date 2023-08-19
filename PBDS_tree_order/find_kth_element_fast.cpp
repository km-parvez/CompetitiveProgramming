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
constexpr int MX = 1000005;

void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}

int tree[4*MX];
void update(int node,int l,int r,int pos,int u){
     if(pos>r || pos<l)
        return ;
     if(l==r){
        tree[node]+=u;
        return ;
     }
     int mid=(l+r)>>1;
     if(pos<=mid)
        update(2*node,l,mid,pos,u);
     else
        update(2*node+1,mid+1,r,pos,u);

     tree[node]=tree[2*node]+tree[2*node+1];
}
int query(int node,int l,int r,int x = 0){
    if(l==r){
        return l;
    }
    int mid=(l+r)>>1;
    if(tree[2*node]>=x)
        return query(2*node,l,mid,x);
    else
        return query(2*node+1,mid+1,r,x-tree[2*node]);
}

void solve(int caseno){
    int n,q;
    cin>>n>>q;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        update(1,0,n+1,x,1);
    }
    // this value will be found when there is no value.
    update(1,0,n+1,n+1,1);
    
    int k;
    for(int i=0; i<q; i++) {
        cin>>k;
        if(k<0){
            k=-k;
            int val = query(1,0,n+1,k);
           // whatis1(val);
            assert(val>0);
            update(1,0,n+1,val,-1);
        }
        else{
            update(1,0,n+1,k,1);
        }
    }       
   
    int val = 0;
    val= query(1,0,n+1,1);
    if(val==n+1)
    {
        cout<<0<<'\n';
        return;
    }
    cout<<val<<'\n';
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases,caseno=0;
    cases=1;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}           