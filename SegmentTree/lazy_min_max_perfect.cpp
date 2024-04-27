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
constexpr int MAX = 300005;

void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}

#define int long long

ll tree[MAX*4];
ll treeMax[MAX*4],lazyMax[MAX*4],treeMaxInd[MAX*4];
ll treeMin[MAX*4],lazyMin[MAX*4],treeMinInd[MAX*4];
ll ar[MAX];

//  Max Segment tree Find Max

void build_max_tree(int node, int a, int b) {
    if(a > b) {
    treeMax[node] = INT_MIN;
    return;
    } // Out of range
    
    if(a == b) { // Leaf node
        treeMaxInd[node]=a;
        treeMax[node] = ar[a]; // Init value
        return;
    }
    
    int left = node*2;
    int right  = left+1;
    build_max_tree(left, a, (a+b)/2); // Init left child
    build_max_tree(right, 1+(a+b)/2, b); // Init right child
   
    treeMax[node] = max(treeMax[left], treeMax[right]); // Init root value
   
    if(treeMaxInd[left]==-1)treeMaxInd[node] = treeMaxInd[right];
    else if(treeMaxInd[right]==-1)treeMaxInd[node] = treeMaxInd[left];
    else{
        if(treeMax[left]>=treeMax[right]){
            treeMaxInd[node] =treeMaxInd[left]; 
        }
        else 
            treeMaxInd[node] =treeMaxInd[right];
    }

    
}


void update_max_tree(int node, int a, int b, int i, int j, int value) {
  
    if(lazyMax[node] != 0) { // This node needs to be updated
        treeMax[node] += lazyMax[node]; // Update it

        if(a != b) {
            lazyMax[node*2] += lazyMax[node]; // Mark child as lazyMax
                lazyMax[node*2+1] += lazyMax[node]; // Mark child as lazyMax
        }

        lazyMax[node] = 0; // Reset it
    }
  
    if(a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;
    
    if(a >= i && b <= j) { // Segment is fully within range
            treeMax[node] += value;

        if(a != b) { // Not leaf node
            lazyMax[node*2] += value;
            lazyMax[node*2+1] += value;
        }

            return;
    }
    int left = node*2;
    int right  = left+1;
    update_max_tree(left, a, (a+b)/2, i, j, value); // Updating left child
    update_max_tree(right, 1+(a+b)/2, b, i, j, value); // Updating right child

    treeMax[node] = max(treeMax[left], treeMax[right]); // Updating root with min value

    if(treeMaxInd[left]==-1)treeMaxInd[node] = treeMaxInd[right];
    else if(treeMaxInd[right]==-1)treeMaxInd[node] = treeMaxInd[left];
    else{
        if(treeMax[left]>=treeMax[right]){
            treeMaxInd[node] =treeMaxInd[left]; 
        }
        else 
            treeMaxInd[node] =treeMaxInd[right];
    }

    
}

pair<int,int>  query_max_tree(int node, int a, int b, int i, int j) {
    
    if(a > b || a > j || b < i) return {-1,-1}; // Out of range

    if(lazyMax[node] != 0) { // This node needs to be updated
        treeMax[node] += lazyMax[node]; // Update it

        if(a != b) {
            lazyMax[node*2] += lazyMax[node]; // Mark child as lazyMax
            lazyMax[node*2+1] += lazyMax[node]; // Mark child as lazyMax
        }

        lazyMax[node] = 0; // Reset it
    }

    if(a >= i && b <= j) // Current segment is totally within range [i, j]
        return {treeMaxInd[node],treeMax[node]};

    pair<int,int>  q1 = query_max_tree(node*2, a, (a+b)/2, i, j); // Query left child
    pair<int,int>  q2 = query_max_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

    if(q1.first==-1)return q2;
    else if(q2.first==-1) return q1;
    else{
        if(q1.second>=q2.second){
            return q1;
        }
        else 
           return q2;
    }
}

void build_min_tree(int node, int a, int b) {
    if(a > b) {
    treeMin[node] = INT_MAX;
    return;
    } // Out of range
    
    if(a == b) { // Leaf node
        treeMinInd[node]=a;
        treeMin[node] = ar[a]; // Init value
        return;
    }
    
    int left = node*2;
    int right  = left+1;
    build_min_tree(left, a, (a+b)/2); // Init left child
    build_min_tree(right, 1+(a+b)/2, b); // Init right child
   
    treeMin[node] = min(treeMin[left], treeMin[right]); // Init root value
   
    if(treeMinInd[left]==-1)treeMinInd[node] = treeMinInd[right];
    else if(treeMinInd[right]==-1)treeMinInd[node] = treeMinInd[left];
    else{
        if(treeMin[left]<=treeMin[right]){
            treeMinInd[node] =treeMinInd[left]; 
        }
        else 
            treeMinInd[node] =treeMinInd[right];
    }

    
}


void update_min_tree(int node, int a, int b, int i, int j, int value) {
  
    if(lazyMin[node] != 0) { // This node needs to be updated
        treeMin[node] += lazyMin[node]; // Update it

        if(a != b) {
            lazyMin[node*2] += lazyMin[node]; // Mark child as lazyMin
                lazyMin[node*2+1] += lazyMin[node]; // Mark child as lazyMin
        }

        lazyMin[node] = 0; // Reset it
    }
  
    if(a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;
    
    if(a >= i && b <= j) { // Segment is fully within range
            treeMin[node] += value;

        if(a != b) { // Not leaf node
            lazyMin[node*2] += value;
            lazyMin[node*2+1] += value;
        }

            return;
    }
    int left = node*2;
    int right  = left+1;
    update_min_tree(left, a, (a+b)/2, i, j, value); // Updating left child
    update_min_tree(right, 1+(a+b)/2, b, i, j, value); // Updating right child

    treeMin[node] = min(treeMin[left], treeMin[right]); // Updating root with min value

    if(treeMinInd[left]==-1)treeMinInd[node] = treeMinInd[right];
    else if(treeMinInd[right]==-1)treeMinInd[node] = treeMinInd[left];
    else{
        if(treeMin[left]<=treeMin[right]){
            treeMinInd[node] =treeMinInd[left]; 
        }
        else 
            treeMinInd[node] =treeMinInd[right];
    }

    
}

pair<int,int>  query_min_tree(int node, int a, int b, int i, int j) {
    
    if(a > b || a > j || b < i) return {-1,-1}; // Out of range

    if(lazyMin[node] != 0) { // This node needs to be updated
        treeMin[node] += lazyMin[node]; // Update it

        if(a != b) {
            lazyMin[node*2] += lazyMin[node]; // Mark child as lazyMin
            lazyMin[node*2+1] += lazyMin[node]; // Mark child as lazyMin
        }

        lazyMin[node] = 0; // Reset it
    }

    if(a >= i && b <= j) // Current segment is totally within range [i, j]
        return {treeMinInd[node],treeMin[node]};

    pair<int,int>  q1 = query_min_tree(node*2, a, (a+b)/2, i, j); // Query left child
    pair<int,int>  q2 = query_min_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

    if(q1.first==-1)return q2;
    else if(q2.first==-1) return q1;
    else{
        if(q1.second<=q2.second){
            return q1;
        }
        else 
           return q2;
    }
}


void solve(int caseno){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }
    for(int i=0; i<n; i++) {
        ar[i]=v[i]+(i+1);
    }
    whatisArray(ar,n);
    int sz4 = n*4LL;
    for(int i=0; i<sz4; i++) {
        lazyMin[i]=0;
        lazyMax[i]=0;
        treeMinInd[i]=-1;
        treeMaxInd[i]=-1;
    }

    build_min_tree(1,0,n-1);
    build_max_tree(1,0,n-1);
    /*
        ll mn = query_tree(1, 0, n-1, y, n-1);
        update_tree(1, 0, n-1, y, n-1, -x);*/
    set<int,greater<int> >st;
    for(int i=0; i<n; i++) {
        auto [ind,val] = query_max_tree(1, 0, n-1, 0, n-1);
        whatis2(ind,val);
        if(st.find(val)==st.end()){
            st.emplace(val);
            update_max_tree(1, 0, n-1, ind+1, n-1, -1);
            update_min_tree(1, 0, n-1, ind+1, n-1, -1);

            update_max_tree(1, 0, n-1, ind, ind, INT_MIN);
            update_min_tree(1, 0, n-1, ind, ind, INT_MAX);
            continue;
        }
        auto [ind2,val2] = query_min_tree(1, 0, n-1, 0, n-1);
        
        st.emplace(val2);
        update_max_tree(1, 0, n-1, ind2+1, n-1, -1);
        update_min_tree(1, 0, n-1, ind2+1, n-1, -1);

        update_max_tree(1, 0, n-1, ind2, ind2, INT_MIN);
        update_min_tree(1, 0, n-1, ind2, ind2, INT_MAX);
        
    }

    for(auto it = st.begin(); it != st.end(); it++){
        cout<<*it<<' '; 
    }   
    cout<<'\n';
    
    return;
    
}
main()
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