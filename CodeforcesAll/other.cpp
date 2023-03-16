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

void solve(int caseno){
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        v[i]=i+1;
    }
    do{
        bool ok = true;
        for(int i=1; i<n-1; i++) {
            if(v[i]%(i+1)!=0){
               // whatis2(v[i],(i+1));
                ok = false;
                break;
            }
        }
       // whatis1(ok);
        if(ok){
            whatisArray(v,v.size());
        }

    }while(next_permutation(all(v)));
    

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