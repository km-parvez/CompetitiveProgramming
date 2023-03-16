// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    deque< pair<int,int> > dq;
    int n,m,arr[1004];
    cin>>n>>m;
    for(int i=0; i<n; i++) {
    	cin>>arr[i];
    }
    string ans = "";
    for(int i=0; i<n; i++) {
    	while(!dq.empty() && dq.back().first>=arr[i])
    		dq.pop_back();
    	dq.push_back(make_pair(arr[i],i));
    	while(!dq.empty()&&dq.front().second<i-m+1)
    		dq.pop_front();
    	if(i>=m-1){
    		for(int j=i-m+1; j<=i; j++) {
    			cout<<arr[j]<<" ";
    		}
    		cout<<" : "<<dq.front().first<<endl;
    		//ans=ans+", "+ dq.front().first+"";
    	}
    }

cout<<ans<<endl;
        
    return 0;
}