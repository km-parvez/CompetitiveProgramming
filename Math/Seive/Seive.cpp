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
constexpr ll mod = 1'000'000'007;
constexpr int MX = 32004;
vector<int> prm;
void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])prm.push_back(p);
}
void solve(int caseno){
    int a,b,c,k;
    cin>>a>>b>>k;
    c= __gcd(a,b);
    int sa=a,sb=b,sc=c;
    int aa = 0,bb=0,cc=0;
    for(int i=0; i<prm.size()&&prm[i]*prm[i]<=a; i++) {
        while(a>1&&a%prm[i]==0){
            aa++;
            a/=prm[i];
        }
    }
    if(a>1)aa++;
    for(int i=0; i<prm.size()&&prm[i]*prm[i]<=b; i++) {
        while(b>1&&b%prm[i]==0){
            bb++;
            b/=prm[i];
        }
    }

    if(b>1)bb++;

    for(int i=0; i<prm.size()&&prm[i]*prm[i]<=c; i++) {
        while(c>1&&c%prm[i]==0){
            cc++;
            c/=prm[i];
        }
    }

    if(cc>1)cc++;
    int mx = aa+bb;
    if(k==1){
        if((sa==sc || sb==sc)&&(sa!=sb) ){
            cout<<"YES"<<'\n';
        }
        else cout<<"NO"<<'\n';
        return;
    }
    if(k<=mx){
        cout<<"YES"<<'\n';
    }
    else cout<<"NO"<<'\n';
 
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases,caseno=0;
    SieveOfEratosthenes(MX);
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}