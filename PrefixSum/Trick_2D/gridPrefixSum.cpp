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
    int n,m;
    cin>>n>>m;
    int arr[n+5][m+5];    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];
        }
    }
    int ans = 1;
    int low = 1,hi= n;
    while( low <= hi){
        int mid = (hi+low)/2;
        bool res = false;
        
        int brr[n+5][m+5];
        memset(brr,0,sizeof(brr));  
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                brr[i][j] = (arr[i][j]>=mid);
                if(j>0){
                    brr[i][j]+=brr[i][j-1];
                }
            }
        }
        for(int j=0; j<m; j++) {
            for(int i=0; i<n; i++) {
                if(i>0){
                    brr[i][j]+=brr[i-1][j];
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ll tot = brr[i][j];
                if((j-mid)>=0)tot-=brr[i][j-mid];
                if((i-mid)>=0){
                    tot-=brr[i-mid][j];
                    if((j-mid)>=0)tot+=brr[i-mid][j-mid];
                }
                if(tot==(mid*mid)){
                    res = true;
                    break;
                }
            }
            if(res)break;
        }   
        if(res){
            ans = mid;
            low = mid+1;
        }
        else{
            hi = mid-1;
        }
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
