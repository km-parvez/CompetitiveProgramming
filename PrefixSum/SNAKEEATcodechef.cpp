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
#define MAXX 100005

using namespace std;
using ll = long long;

void solve(int caseno){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll prefix[n+2];
    prefix[0]=v[0];
   for(int i=1; i<n; i++) {
   	prefix[i]= prefix[i-1]+v[i];
   }
 	//whatisArray(v,n);
   	//whatisArray(prefix,n);
    while(q--){
    	ll k;cin>>k;
    	int end = lower_bound(v.begin(), v.end(), k)-v.begin();
    	int ans = n-end;
    	//whatis2(ans,end);
    	end--;
    	int low = 0,high=end;
    	int res = 0;
    	while(low<=high){
	    	int mid = (low+high)/2;
	    	ll need = (ll)(end-mid+1)*k-(prefix[end]-(mid>0?prefix[mid-1]:0));
	    	ll has = mid;
	    	//whatis3(mid,need,has);
	    	if(has>=need){
	    		res = end-mid+1;
	    		high = mid-1;
	    	}
	    	else{
	    		low=mid+1;
	    	}
    	}
    	//whatis1(res);
    	cout<<ans+res<<'\n';
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