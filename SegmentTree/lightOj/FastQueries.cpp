// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define MX 100005

using namespace std;
using ll = long long;
int arr[MX];
vector<int> emptyvector;
vector<int> tree[4*MX];
vector<int> marge(vector<int> a,vector<int> b){
	vector<int> tmp;
	int ca=0,cb=0;
	while(ca<a.size()&&cb<b.size()){
		if(a[ca]==b[cb]){
			tmp.push_back(a[ca]);ca++;cb++;
		}
		else if(a[ca]<b[cb]) tmp.push_back(a[ca++]);
		else tmp.push_back(b[cb++]);
	}
	for(int i=ca; i<a.size(); i++)tmp.push_back(a[i]);
	for(int i=cb; i<b.size(); i++)tmp.push_back(b[i]);
	return tmp;
} 
void init(int node,int b,int e){
	if(b>e)return;
	if(b==e){tree[node].push_back(arr[b]);return;};
	int mid = (b+e)/2;
	int left = node*2;
	int right = left+1;
	init(left,b,mid);
	init(right,mid+1,e);
	tree[node] = marge(tree[left],tree[right]);
	return;
}
vector<int> query(int node,int b,int e,int i,int j){
	 if(i>e || b>j)
        return emptyvector;
    if(b>=i && e<=j)
        return tree[node];
    int mid = (b+e)/2;
    int left = node*2;
    int right=left+1;
    return marge(query(left,b,mid,i,j),query(right,mid+1,e,i,j));
}
void solve(int caseno){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    for(int i=0; i<n*4+2; i++) {
    	tree[i].clear();
    }
    init(1,0,n-1);
   /* for(int i=1; i<n; i++) {
    	whatisArray(tree[i],tree[i].size());
    }*/
    cout<<"Case "<<caseno<<":"<<endl;
    while(q--){
    	int i,j;cin>>i>>j;
    	i--;j--;
    	vector<int> ans = query(1,0,n-1,i,j);
    	cout<<ans.size()<<'\n';
    }
    
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}