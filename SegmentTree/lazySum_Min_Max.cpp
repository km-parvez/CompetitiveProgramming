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
#define mod 1000000007

using namespace std;
using ll = long long;

#define MAX 200005
ll tree[MAX*4],treeMin[MAX*4],lazy[MAX*4], lazyMin[MAX*4];
ll ar[MAX];
/* Function to display elements of the Segment Tree and
   the Lazy tree level by level. */
void showSegTree(ll n)
{
  ll i, j, h = ceil(log2(n));
  cout<<"Segment Tree:"<<endl;
  for(i=0 ; i<=h ; ++i)
  {
    for(j=0 ; j<pow(2, i) ; ++j)
      cout<<tree[ll(pow(2, i)-1 + j)]<<' ';
    cout<<endl;
  }
  cout<<"Lazy Tree:"<<endl;
  for(i=0 ; i<=h ; ++i)
  {
    for(j=0 ; j<pow(2, i) ; ++j)
      cout<<lazy[ll(pow(2, i)-1 + j)]<<' ';
    cout<<endl;
  }
}
/* Function to construct the Segment Tree recursively.
   At each node, if it is not the leaf, two children are
   processed further. Otherwise, the leaf is assigned an
   array alement. strt and end are range in the array,
   idx is the index used in the segment tree */
ll constSegTree(ll strt, ll end, ll idx)
{
  // Initialize all lazy tree nodes with 0
  lazy[idx] = 0;
  // Saves tree[idx] = ar[strt] and then returns tree[idx]
  if(strt == end)
    return tree[idx] = ar[strt];
  ll mid = (strt + end) / 2;
  return tree[idx] = constSegTree(strt, mid, 2*idx+1) +
            constSegTree(mid+1, end, 2*idx+2);
}
void constSegTree(ll n)
{
  constSegTree(0, n-1, 0);
}
/* Function to get the sum of elements of array in the
   range [strt..end]. l & r are the range of current node.
   indx is the index of node in segment tree */

ll getSum(ll strt, ll end, ll l, ll r, ll idx)
{
  // If there's pending update, update the node first
  if(lazy[idx] != 0)
  {
    // Add the pending update to the current node
    // [l..r] contains l-r+1 nodes
    tree[idx] += (r-l+1)*lazy[idx];
    // If the node has children, postpone the updates
    // to the children by adding to the their lazy nodes
    if(l != r)
    {
      lazy[2*idx+1] += lazy[idx];
      lazy[2*idx+2] += lazy[idx];
    }
    // Reset the lazy node of current node
    lazy[idx] = 0;
  }
  // If completly outside the range, don't care
  if(end < l || r < strt || l > r)
    return 0;
  
  // If node is entirely within the range, return the node value
  if(strt <= l && r <= end)
    return tree[idx];
  
  // Enter its children and process further
  ll mid = (l + r) / 2;
  return getSum(strt, end, l, mid, 2*idx+1) +
      getSum(strt, end, mid+1, r, 2*idx+2);
}
ll getSum(ll n, ll strt, ll end)
{
  return getSum(strt, end, 0, n-1, 0);
}

/* Function to update a particular node of the array in
   Segment Tree. pos is the desired index in the array.
   val is the value to be added */
void updtSegTree(ll strt, ll end, ll val, ll l, ll r, ll idx)
{
  // If there's pending update, update the node first
  if(lazy[idx] != 0)
  {
    // Add the pending update to the current node
    // [l..r] contains l-r+1 nodes
    tree[idx] += (r-l+1)*lazy[idx];
    // If the node has children, postpone the updates
    // to the children by adding to the their lazy nodes
    if(l != r)
    {
      lazy[2*idx+1] += lazy[idx];
      lazy[2*idx+2] += lazy[idx];
    }
    // Reset the lazy node of current node
    lazy[idx] = 0;
  }
  // If completly outside the range, don't care
  if(end < l || r < strt || l > r)
    return;
  // If node is entirely within the range
  if(strt <= l && r <= end)
  {
    // Update the current node in Segment tree
    tree[idx] += (r-l+1)*val;
    // If the node has children, postpone the updates
    // of the children by adding to the their lazy nodes
    if(l != r)
    {
      lazy[2*idx+1] += val;
      lazy[2*idx+2] += val;
    }
  }
  else
  {
    // Enter its children and process further
    ll mid = (l + r) / 2;
    updtSegTree(strt, end, val, l, mid, 2*idx+1);
    updtSegTree(strt, end, val, mid+1, r, 2*idx+2);
    // Recalculate the itermediate nodes after updation
    tree[idx] = tree[2*idx+1] + tree[2*idx+2];  
  }
}
void updtSegTree(ll n, ll strt, ll end, ll val)
{
  updtSegTree(strt, end, val, 0, n-1, 0);
}

void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range
    
    if(a == b) { // Leaf node
            treeMin[node] = ar[a]; // Init value
        return;
    }
    
    build_tree(node*2, a, (a+b)/2); // Init left child
    build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
    
    treeMin[node] = min(treeMin[node*2], treeMin[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {
  
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

    update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

    treeMin[node] = min(treeMin[node*2], treeMin[node*2+1]); // Updating root with min value
}

/**
 * Query treeMin to get min element value within range [i, j]
 */
ll query_tree(int node, int a, int b, int i, int j) {
    
    if(a > b || a > j || b < i) return LLONG_MAX; // Out of range

    if(lazyMin[node] != 0) { // This node needs to be updated
        treeMin[node] += lazyMin[node]; // Update it

        if(a != b) {
            lazyMin[node*2] += lazyMin[node]; // Mark child as lazyMin
            lazyMin[node*2+1] += lazyMin[node]; // Mark child as lazyMin
        }

        lazyMin[node] = 0; // Reset it
    }

    if(a >= i && b <= j) // Current segment is totally within range [i, j]
        return treeMin[node];

    ll q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
    ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

    ll res = min(q1, q2); // Return final result
    
    return res;
}


//  Max Segment tree Find Max

void build_max_tree(int node, int a, int b) {
    if(a > b) {
    treeMaxInd[node]=-1;
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

/**
 * Increment elements within range [i, j] with value value
 */
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

/**
 * Query treeMax to get min element value within range [i, j]
 */
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



int main()
{
    ios::sync_with_stdio(0);

    ll n;
    cin>>n;
    vector<ll> v(n);
    vector< pair<ll,ll> > val;
    ll ans = 0;
    for(ll i=0;i<n;i++) {
        cin>>v[i];
        if(v[i]<0)val.emplace_back(-v[i],-i);
        else ans++;
    }
    ar[0]=0;
    for(ll i=0; i<n; i++) {
        if(i==0){
            ar[i]= max(v[i],0LL);
        }
        else{
            ar[i]= max(ar[i-1]+v[i],ar[i-1]);
        }
    }
  //  whatisaray(ar,n);
    memset(lazy,0,sizeof(lazy));
    constSegTree(n);
    build_tree(1, 0, n-1);
    memset(lazyMin, 0, sizeof lazyMin);

    ll ind = 0;
    sort(val.begin(),val.end());
    for(ll i=0; i<val.size(); i++) {
        ll x = val[i].first;
        ll y = -val[i].second;
        ll cur = getSum(n,y,y);
        ll mn = query_tree(1, 0, n-1, y, n-1);
       // whatis2(x,y);
       // whatis2(cur,mn);
        if(cur-x>=0 && mn-x>=0){
            updtSegTree(n,y,n-1,-x);
            update_tree(1, 0, n-1, y, n-1, -x);
            ans++;
        } 
        //showSegTree(n);
    }
  /*  for(ll i=0; i<n; i++) {
        cout<<getSum(n,i,i)<<' ';
    }cout<<'\n';*/
    cout<<ans<<'\n';


    
    
    return 0;
}