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

#define int long long

// try binary search,BIT,segment tree, dp, dfs, union find, set, priority queue, sorting, two pointer, gready.
class SegmentTree {
private:
    vector<vector<int>> tree;
    vector<int> arr;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {arr[start]};
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);

            merge(tree[2 * node].begin(), tree[2 * node].end(),
                  tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
                  back_inserter(tree[node]));
        }
    }

    int query(int node, int start, int end, int l, int r, int k) {
        if (r < start || l > end) {
            return 0; // No overlap
        }

        if (l <= start && end <= r) {
            return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
        }

        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r, k) + query(2 * node + 1, mid + 1, end, l, r, k);
    }

public:
    SegmentTree(const vector<int>& input) {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    int query(int l, int r, int k) {
        return query(1, 0, n - 1, l, r, k);
    }
};
void solve(int caseno){
    int n,k;
    cin>>n>>k;
    vector<int> a(n),b(n);
    vector<pair<int,int> > pii(n);
    vector<int> tmp;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    for(int i=0; i<n; i++) {
        cin>>b[i];
        pii[i] = {a[i],b[i]};
    }
    for(int i=0; i<n; i++) {
        tmp.push_back(a[i]);
        tmp.push_back(b[i]);
    }

    sort(tmp.begin(),tmp.end());    
    int ans = 0;
    vector<int> ext = b;
    sort(ext.begin(),ext.end(),greater<int>());
    ans = 0;

    sort(pii.begin(),pii.end(),greater<pair<int,int> >());  
    for(int i=0; i<n; i++) {
        a[i] = -pii[i].first;
        b[i] = pii[i].second;
    }
    SegmentTree segTree(b);
    
    for(int i=0; i<tmp.size(); i++) {
        int tot = upper_bound(a.begin(), a.end(), -tmp[i]) - a.begin();
        int can =segTree.query(tot, n-1, tmp[i]-1 );
        if(can>k)continue;
        int take = tot+can;
        ans = max(ans,take*tmp[i]);
    }
    
    cout<<ans<<'\n';
    
    return;
    
}
main()
{
    ios::sync_with_stdio(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}       