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

struct Node {
    int value;  // Minimum value in the range
    int indx;  // Index of the minimum value
};

void buildMinSegTree(vector<int>& arr, vector<Node>& tree, int start, int end, int treeNode) {
    if (start == end) {
        // Leaf node
        tree[treeNode].value = arr[start];
        tree[treeNode].indx = start;
        return;
    }

    int mid = (start + end) / 2;
    buildMinSegTree(arr, tree, start, mid, 2 * treeNode);
    buildMinSegTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode].value = min(tree[2 * treeNode].value, tree[2 * treeNode + 1].value);
    tree[treeNode].indx = (tree[2 * treeNode].value < tree[2 * treeNode + 1].value) ? tree[2 * treeNode].indx : tree[2 * treeNode + 1].indx;
}

pair<int, int> queryMinSegTree(vector<Node>& tree, int start, int end, int treeNode, int left, int right) {
    if (start > right || end < left) {
        return make_pair(INT_MAX, -1);
    }

    if (start >= left && end <= right) {
        return make_pair(tree[treeNode].value, tree[treeNode].indx);
    }

    int mid = (start + end) / 2;
    pair<int, int> leftResult = queryMinSegTree(tree, start, mid, 2 * treeNode, left, right);
    pair<int, int> rightResult = queryMinSegTree(tree, mid + 1, end, 2 * treeNode + 1, left, right);

    if (leftResult.first < rightResult.first)
        return leftResult;
    else
        return rightResult;
}

void updateMinSegTree(vector<Node>& tree, int start, int end, int treeNode, int idx, int value) {
    if (start == end) {
        // Leaf node
        tree[treeNode].value = value;
        tree[treeNode].indx = idx;
        return;
    }

    int mid = (start + end) / 2;

    if (idx <= mid) {
        // Update left subtree
        updateMinSegTree(tree, start, mid, 2 * treeNode, idx, value);
    } else {
        // Update right subtree
        updateMinSegTree(tree, mid + 1, end, 2 * treeNode + 1, idx, value);
    }

    // Update the parent node
    tree[treeNode].value = min(tree[2 * treeNode].value, tree[2 * treeNode + 1].value);
    tree[treeNode].indx = (tree[2 * treeNode].value < tree[2 * treeNode + 1].value) ? tree[2 * treeNode].indx : tree[2 * treeNode + 1].indx;
}


void buildMaxSegTree(vector<int>& arr, vector<Node>& tree, int start, int end, int treeNode) {
    if (start == end) {
        // Leaf node
        tree[treeNode].value = arr[start];
        tree[treeNode].indx = start;
        return;
    }

    int mid = (start + end) / 2;
    buildMaxSegTree(arr, tree, start, mid, 2 * treeNode);
    buildMaxSegTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode].value = max(tree[2 * treeNode].value, tree[2 * treeNode + 1].value);
    tree[treeNode].indx = (tree[2 * treeNode].value > tree[2 * treeNode + 1].value) ? tree[2 * treeNode].indx : tree[2 * treeNode + 1].indx;
}

pair<int, int> queryMaxSegTree(vector<Node>& tree, int start, int end, int treeNode, int left, int right) {
    if (start > right || end < left) {
        return make_pair(0, -1);
    }

    if (start >= left && end <= right) {
        return make_pair(tree[treeNode].value, tree[treeNode].indx);
    }

    int mid = (start + end) / 2;
    pair<int, int> leftResult = queryMaxSegTree(tree, start, mid, 2 * treeNode, left, right);
    pair<int, int> rightResult = queryMaxSegTree(tree, mid + 1, end, 2 * treeNode + 1, left, right);

    if (leftResult.first > rightResult.first)
        return leftResult;
    else
        return rightResult;
}

void updateMaxSegTree(vector<Node>& tree, int start, int end, int treeNode, int idx, int value) {
    if (start == end) {
        // Leaf node
        tree[treeNode].value = value;
        tree[treeNode].indx = idx;
        return;
    }

    int mid = (start + end) / 2;

    if (idx <= mid) {
        // Update left subtree
        updateMaxSegTree(tree, start, mid, 2 * treeNode, idx, value);
    } else {
        // Update right subtree
        updateMaxSegTree(tree, mid + 1, end, 2 * treeNode + 1, idx, value);
    }

    // Update the parent node
    tree[treeNode].value = max(tree[2 * treeNode].value, tree[2 * treeNode + 1].value);
    tree[treeNode].indx = (tree[2 * treeNode].value > tree[2 * treeNode + 1].value) ? tree[2 * treeNode].indx : tree[2 * treeNode + 1].indx;


}
void solve(int caseno){
    int n;
    cin>>n;
    vector<int> v(n);
    vector<Node> tree(4*n+5);
    vector<Node> tree2(4*n+5);
    int one ;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        if(v[i]==1){
            one=i;
        }
    }

    if(n==1){
        cout<<0<<'\n';return;
    }
    if(n==2){
        cout<<1<<'\n';return;
    }
    // Build the segment tree
    buildMinSegTree(v, tree, 0, n - 1, 1);
    buildMaxSegTree(v, tree2, 0, n - 1, 1);
       
    
    int i=one-1;
    int co = 0;
    int ans = 0;
    while(i>=0){
        if(co%2==0){
            int left = 0;
            int right = i;
            pair<int, int> result = queryMaxSegTree(tree2, 0, n - 1, 1, left, right);
            i = result.second-1;
        }
        else{
            int left = 0;
            int right = i;
            pair<int, int> result = queryMinSegTree(tree, 0, n - 1, 1, left, right);
            i = result.second-1;
        }
        co++;
        ans++;
    }
    i=one+1;
    co = 0;
    while(i<n){
        if(co%2==0){
            int left = i;
            int right = n-1;
            pair<int, int> result = queryMaxSegTree(tree2, 0, n - 1, 1, left, right);
            i = result.second+1;
        }
        else{
            int left = i;
            int right = n-1;
            pair<int, int> result = queryMinSegTree(tree, 0, n - 1, 1, left, right);
            i = result.second+1;
        }
        co++;
        ans++;
    }
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