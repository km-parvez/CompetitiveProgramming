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
constexpr int MX = 500000;

void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}

#define int long long

// try binary search,BIT,segment tree, dp, dfs, union find, set, priority queue, sorting, two pointer, gready.
class myNode
{
public:
    int val,ind;
public:    
    myNode(){
        val= 0;ind=0;
    }
    myNode(int tval,int tind){
        val= tval;
        ind=tind;
    }
    void print(){
        cout<<val<<" "<<ind<<'\n';
    }
};

class SegmentTree {
private:
    vector<myNode> tree;
    vector<int> nums;
    myNode marge(myNode left,myNode right){
        if(left.val<right.val){
            return left;
        }
        else{
           return right; 
        }  
    }
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = myNode(nums[start],start);
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = marge(tree[2 * node] , tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int index, int newValue) {
        if (start == end) {
            nums[index] = newValue;
            tree[node] = myNode(nums[index],index);
        } else {
            int mid = (start + end) / 2;
            if (start <= index && index <= mid) {
                update(2 * node, start, mid, index, newValue);
            } else {
                update(2 * node + 1, mid + 1, end, index, newValue);
            }
            tree[node] = marge(tree[2 * node] , tree[2 * node + 1]);
        }
    }

public:
    SegmentTree() {
    }
    SegmentTree(vector<int>& arr) {
        int n = arr.size();
        nums = arr;
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    myNode query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return myNode(INT_MAX,-1);
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        myNode leftSum = query(2 * node, start, mid, l, r);
        myNode rightSum = query(2 * node + 1, mid + 1, end, l, r);
        return marge(leftSum,rightSum);
    }

    myNode rangeQuery(int left, int right) {
        return query(1, 0, nums.size() - 1, left, right);
    }

    void updateElement(int index, int newValue) {
        if (index < 0 || index >= nums.size()) {
            return; // Index out of bounds
        }
        update(1, 0, nums.size() - 1, index, newValue);
    }
};

SegmentTree st;

int ans[MX];
bool chooseFxleft[MX]={0};
int func(vector<int> &arr,int b,int e,int n){
    if(b>e)return 0;
    if(b==e)return arr[b];
    auto [val,ind] = st.rangeQuery(b, e);
    int left = func(arr,b,ind-1,n);
    int right = func(arr,ind+1,e,n);
    int rfixed = left+val*(e-ind+1);
    int lfixed = right+ val*(ind-b+1);
    if(lfixed>rfixed){
        chooseFxleft[ind] = true;
    }
    return max(rfixed,lfixed);
}
void makearray(vector<int> &arr,int b,int e,int n){
    if(b>e)return ;
    if(b==e)return ;
    auto [val,ind] = st.rangeQuery(b, e);
    if(chooseFxleft[ind]){
        for(int i=b; i<=ind; i++) {
            ans[i] = val;
        }
        makearray(arr,ind+1,e,n);
    }
    else{
        for(int i=ind; i<=e; i++) {
            ans[i] = val;
        }
        makearray(arr,b,ind-1,n);
    }
    
    return ;
}
 
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        ans[i] = arr[i];
    }
    st = SegmentTree(arr);
    func(arr,0,n-1,n);
    makearray(arr,0,n-1,n);
 
    for(int i=0; i<n; i++) {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
 
 
    return 0;
}       
