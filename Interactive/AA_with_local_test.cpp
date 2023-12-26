// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define MX 200005

using namespace std;
using ll = long long;
int testarr[MX],testn,testk;
void extraInputToTest(){
    int output = 0;
    for(int i=1; i<=testn; i++) {
        cin>>testarr[i];
        output^=testarr[i];
    }
    whatis1(output);
}
int askToTest(int arg){
    int rep=0;
    for(int i=arg; i<arg+testk; i++) {
        rep^=testarr[i];
    }
    reverse(testarr+arg,testarr+arg+testk);
    return rep;
}

int ask(int arg){
    cout<<"? "<<arg<<'\n';
    int rep;cin>>rep;
    return rep;
}
int main()
{
    // Instructions: 
    // 1. extraInputToTest(): we may need extra input to make jury's reply.
    //    most of the time it is jury's array.
    // 2. askToTest(int arg) should reply as jury's reply. 
    //    ask(int arg) is to receive jury's reply.  
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
    int n,k;
    cin>>n>>k;
    // Start test
        testn = n;testk = k;
        extraInputToTest();
    // End test
    int xr  = 0,tmp=0;
    int st = k+(n%k)+1;
    for(int i=st; i<=n; i+=k) {
        tmp = askToTest(i);
        xr^=tmp;
    }
    tmp = askToTest(1);
    xr^=tmp;
    int rem = n%k;
    int nw = 2;
    for(int i=0; i<rem; i++) {
        tmp = askToTest(nw);
        xr^=tmp;
        nw++;
    }

    cout<<"! "<<xr<<'\n';
    fflush(stdout);
    }
    return 0;
}