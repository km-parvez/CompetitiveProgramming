// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


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
constexpr ll mod = 1'000'000'007;
constexpr int MX = 200005;
#define pbds                                               \
    tree<pair<int, int>, null_type, less<pair<int, int> >, \
         rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;

// strickly less than And strickly greater than
// first=small,second = big;
vector<pair<int,int> >  countSmallerBiggerLeft(int arr[], int n)
{
    pbds s;
    map<int,int> mp;
    vector<pair<int,int> > ans;
    for (int i = 0; i < n; i++) {
        if (i == 0) { 
                          
            ans.emplace_back(0,0);
        }
        else { 
            int sml= s.order_of_key({ arr[i], i });
            int big = i-sml;
            if(mp.find(arr[i])!=mp.end()){
                sml-=mp[arr[i]];
            }
            ans.emplace_back(sml,big);
        }
        s.insert({ arr[i], i });
        mp[arr[i]]++;

    }
 
   return ans;
}
 
void solve(int caseno){
    int n;
    cin>>n;
    int v[n];
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }

    vector ans = countSmallerBiggerLeft(v, n);
    ll res = 0;
    for(int i=0; i<n; i++) {
        ll s = ans[i].first;
        ll b = ans[i].second;
       // whatis2(s,b);
        if(s<b){
            res+=s;
        }
        else{
            res+=b;
        }
    }
    cout<<res<<'\n';
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