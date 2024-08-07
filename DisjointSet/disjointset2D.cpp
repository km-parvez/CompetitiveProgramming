// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define whatArray2D(arr,m,n) cout<<#arr<<", Size: "<<m<<","<<n<<'\n';for(int mm=0;mm<m;mm++){for(int nn=0;nn<n;nn++)cout<<arr[mm][nn]<<" ";cout<<'\n';} 
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'

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
// Function to initialize the disjoint set
void initializeDisjointSet(int rows, int cols, std::vector<int>& parent, std::vector<int>& size) {
    parent.resize(rows * cols);
    size.resize(rows * cols, 1);  // Initially, each set is of size 1
    for (int i = 0; i < rows * cols; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
}

// Function to find the root of an element with path compression
int find(int x, std::vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

// Function to unite two elements with union by rank and update the size
void unite(int x1, int y1, int x2, int y2, int cols, std::vector<int>& parent, std::vector<int>& size) {
    int root1 = find(x1 * cols + y1, parent);
    int root2 = find(x2 * cols + y2, parent);
    if (root1 != root2) {
        parent[root2] = root1;
        size[root1] += size[root2];
    }
}

// Function to check if two elements are connected
bool isConnected(int x1, int y1, int x2, int y2, int cols, std::vector<int>& parent) {
    return find(x1 * cols + y1, parent) == find(x2 * cols + y2, parent);
}

// Function to get the size of the set containing a specific element
int getSetSize(int x, int y, int cols, std::vector<int>& parent, std::vector<int>& size) {
    int root = find(x * cols + y, parent);
    return size[root];
}


int func(vector<string>  ch, int n,int m){

    int rows = n, cols = m;
    std::vector<int> parent, size;
    int pre[m+5];
    initializeDisjointSet(rows, cols, parent, size);
    
    for(int j=0; j<m; j++) {
        for(int i=0; i<n; i++) {
            if(ch[i][j]!='#')continue;
            if(i>0){
                if(ch[i-1][j] == '#'){
                    unite(i-1, j, i, j, cols, parent,  size);
                }
            }
            if(j>0){
                if(ch[i][j-1] == '#'){
                    unite(i, j-1, i, j, cols, parent, size);
                }
            }
            
        }
        set<int> st;
        int sum = 0;
        for(int i=0; i<n; i++) {
            if(ch[i][j]!='#')continue;
            
            int root = find(i * cols + j, parent);
            if(st.find(root)==st.end()){
                st.emplace(root);
                sum+= getSetSize(i, j, cols, parent, size);
            }
        }
        pre[j] = sum;

    }

    int suf[m+5];
    initializeDisjointSet(rows, cols, parent, size);
    
    for(int j=m-1; j>=0; j--) {
        for(int i=0; i<n; i++) {
            if(ch[i][j]!='#')continue;
            if(i>0){
                if(ch[i-1][j] == '#'){
                    unite(i-1, j, i, j, cols, parent, size);
                }
            }
            if(j<(m-1)){
                if(ch[i][j+1] == '#'){
                    unite(i, j+1, i, j, cols, parent, size);
                }
            }
            
        }
        set<int> st;
        int sum = 0;
        for(int i=0; i<n; i++) {
            if(ch[i][j]!='#')continue;
            
            int root = find(i * cols + j, parent);
            if(st.find(root)==st.end()){
                st.emplace(root);
                int cnt = getSetSize(i, j, cols, parent, size);
                sum+= cnt;
            }
        }
        suf[j] = sum;
    }
    
    int mx = 0;
    for(int j=0; j<m; j++) {
        int tmp = 0;
        if(j>0){
            tmp+=pre[j-1];
        }
        if(j<(m-1)){
            tmp+=suf[j+1];
        }

        mx = max(mx,tmp+n);
    }
    return mx;
}
void solve(int caseno){

    int n,m;
    cin>>n>>m;
    vector<string> ch(n);
    for(int i=0; i<n; i++) {
        cin>>ch[i];
    }
    int ans = func(ch,n,m);
    vector<string> tmp(m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            tmp[j].push_back(ch[i][j]);
        }
    }
    ans = max(ans,func(tmp,m,n));
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