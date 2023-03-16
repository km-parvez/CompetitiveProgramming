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
constexpr ll MX = 200005;
constexpr ll inf = 1e18;
struct Node {
    ll maxPrefixSum;
    ll maxSuffixSum;
    ll totalSum;
    ll maxSubarraySum;
    Node()
    {
        maxPrefixSum = maxSuffixSum = maxSubarraySum = -inf;
        totalSum = -inf;
    }
};

Node merge(Node leftChild, Node rightChild)
{
    Node parentNode;
    parentNode.maxPrefixSum = max(leftChild.maxPrefixSum,
                                  leftChild.totalSum +
                                  rightChild.maxPrefixSum);
  
    parentNode.maxSuffixSum = max(rightChild.maxSuffixSum,
                                  rightChild.totalSum +
                                  leftChild.maxSuffixSum);
  
    parentNode.totalSum = leftChild.totalSum +
                          rightChild.totalSum;
  
    parentNode.maxSubarraySum = max({leftChild.maxSubarraySum,
                                     rightChild.maxSubarraySum,
                                     leftChild.maxSuffixSum +
                                     rightChild.maxPrefixSum});
  
    return parentNode;
}
  
void constructTreeUtil(Node* tree, ll arr[], int start,
                                    int end, int index)
{
  
    if (start == end) {
        tree[index].totalSum = arr[start];
        tree[index].maxSuffixSum = arr[start];
        tree[index].maxPrefixSum = arr[start];
        tree[index].maxSubarraySum = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    constructTreeUtil(tree, arr, start, mid, 2 * index);
    constructTreeUtil(tree, arr, mid + 1, end, 2 * index + 1);
    tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
}
Node* constructTree(ll arr[], int n)
{
    int max_size = 4 * n;
    Node* tree = new Node[max_size];
    constructTreeUtil(tree, arr, 0, n - 1, 1);
    return tree;
}

Node queryUtil(Node* tree, int ss, int se, int qs,
                               int qe, int index)
{
    if (ss > qe || se < qs) {
        Node nullNode;
        return nullNode;
    }

    if (ss >= qs && se <= qe) {
        return tree[index];
    }
  
    int mid = (ss + se) / 2;
    Node left = queryUtil(tree, ss, mid, qs, qe,
                                     2 * index);
    Node right = queryUtil(tree, mid + 1, se, qs,
                              qe, 2 * index + 1);
    Node res = merge(left, right);
    return res;
}

ll query(Node* tree, int start, int end, int n)
{
    Node res = queryUtil(tree, 0, n - 1, start, end, 1);
    return res.maxSubarraySum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 0 index
    ll arr[] = { 1, 3, -4, 5, -2 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    // Construct Segment Tree
    Node* Tree = constructTree(arr, n);
    int start, end;
    ll maxSubarraySum;
  
    // Answering query 1:
    start = 0;
    end = 4;
    maxSubarraySum = query(Tree, start, end, n);
    cout << "Maximum Sub-Array Sum between "
         << start << " and " << end
         << " = " << maxSubarraySum << "\n";
  
    // Answering query 2:
    start = 0;
    end = 2;
    maxSubarraySum = query(Tree, start, end, n);
    cout << "Maximum Sub-Array Sum between "
         << start << " and " << end
         << " = " << maxSubarraySum << "\n";
    
    
    return 0;
}   