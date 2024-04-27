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
constexpr ll INF = 1000000007;
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
    int mx,mxcnt=0;
    int secondmx,secondcnt=0;
public:    
    myNode(){
        mx=-INF;mxcnt=0;
        secondmx=-INF;secondcnt=0;
    }
    myNode(ll tmx, ll tmxcnt,ll tsecondmx,ll tsecondcnt){
        mx=tmx;mxcnt=tmxcnt;
        secondmx=tsecondmx;secondcnt=tsecondcnt;
    }
    void print(){
        cout<<mx<<" "<<mxcnt<<' ';
        cout<<secondmx<<" "<<secondcnt<<'\n';
    }
};

class SegmentTree {
private:
    vector<myNode> tree;
    vector<int> nums;
    myNode marge(myNode left,myNode right){
        vector<pair<int,int> > tmp;
        tmp.emplace_back(left.mx,left.mxcnt);
        tmp.emplace_back(right.mx,right.mxcnt);
        tmp.emplace_back(left.secondmx,left.secondcnt);
        tmp.emplace_back(right.secondmx,right.secondcnt);
        sort(tmp.begin(),tmp.end(),greater<pair<int,int> >());  
        int tmpmx = tmp[0].first;
        int tmpmxcnt = tmp[0].second;
        int ind = 0;
        for(int i=1; i<4; i++) {
            if(tmp[i].first==tmpmx){
                tmpmxcnt+=tmp[i].second;
                ind=i;
            }
            else break; 
        }
        ind++;
        int smx = -INF;
        int scnt = 0;
        if(ind<4){
            smx = tmp[ind].first;
            scnt = tmp[ind].second;
            for(int i=ind+1; i<4; i++) {
                if(tmp[i].first==smx){
                    scnt+=tmp[i].second;
                }
                else break;
            }
        }

        return myNode(tmpmx,tmpmxcnt,smx,scnt); 
    }
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = myNode(nums[start],1,-INF,0);
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
            tree[node] = myNode(nums[index],1,-INF,0);
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
            return myNode(-INF,0,-INF,0);
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
void solve(int caseno){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    st = SegmentTree(v);
    while(q--){
        int type;cin>>type;
        int l,r;cin>>l>>r;
        l--;
        if(type==1){
            st.updateElement(l,r);
        }
        else{
            r--;
            //get_max(int v, int tl, int tr, int l, int r) {
            myNode ans = st.rangeQuery(l,r);
            cout<<ans.secondcnt<<'\n';
        }
    }
    
    return;
    
}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases,caseno=0;
    //cin>>cases;
    cases=1;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}
