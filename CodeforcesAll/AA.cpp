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
#define mod 1000000007
#define MX 200005

using namespace std;
using ll = long long;
int n,m;
char ch[201][201];
vector<pair<int,int> > ans;
bool solve3(int i,int j){
    int cnt = 0;
    for(int x=0; x<2; x++) {
        for(int y=0; y<2; y++) {
            if(ch[i+x][j+y]=='1')cnt++;
        }
    }
    if(cnt==3){
        for(int x=0; x<2; x++) {
            for(int y=0; y<2; y++) {
                if(ch[i+x][j+y]=='1'){
                     ch[i+x][j+y]='0';
                     ans.push_back({i+x,j+y});
                }
            
            }
        }
        return true;
    }
    return false;
}
bool solve2(int i,int j){
    int cnt = 0;
    for(int x=0; x<2; x++) {
        for(int y=0; y<2; y++) {
            if(ch[i+x][j+y]=='1')cnt++;
        }
    }
    if(cnt==2){
        bool flag = true;
        for(int x=0; x<2; x++) {
            for(int y=0; y<2; y++) {
                if(flag&&ch[i+x][j+y]=='1'){
                    flag = false;
                }
                else{
                    ch[i+x][j+y]='0'+(ch[i+x][j+y]=='0');
                    ans.push_back({i+x,j+y});
                }
            
            }
        }
       // solve3(i,j);
        return true;
    }
    return false;
}
bool solve1(int i,int j){
    int cnt = 0;
    for(int x=0; x<2; x++) {
        for(int y=0; y<2; y++) {
            if(ch[i+x][j+y]=='1')cnt++;
        }
    }
    if(cnt==1){
        bool flag = true;
        for(int x=0; x<2; x++) {
            for(int y=0; y<2; y++) {
                if(flag&&ch[i+x][j+y]=='0'){
                    flag = false;
                }
                else{
                    ch[i+x][j+y]='0'+(ch[i+x][j+y]=='0');
                    ans.push_back({i+x,j+y});
                }
            
            }
        }
        return true;
      //  solve2(i,j);
    }
    return false;
}
bool solve4(int i,int j){
    int cnt = 0;
    for(int x=0; x<2; x++) {
        for(int y=0; y<2; y++) {
            if(ch[i+x][j+y]=='1')cnt++;
        }
    }
    if(cnt==4){
        bool flag = true;
        for(int x=0; x<2; x++) {
            for(int y=0; y<2; y++) {
                if(flag&&ch[i+x][j+y]=='1'){
                    flag = false;
                }
                else{
                    ch[i+x][j+y]='0'+(ch[i+x][j+y]=='0');
                    ans.push_back({i+x,j+y});
                }
            
            }
        }
      //  solve1(i,j);
        return true;
    }
    return false;
}

void solve(int caseno){
    ans.clear();
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>ch[i][j];
        }
    }
    if(m%2==1){
        for(int i=n-2; i>=0; i-=2) {
            int co=0;
            if(ch[i+1][m-1]=='1'){
                ch[i+1][m-1]='0';
                ans.push_back({i+1,m-1});
                co++;
            }
            if(ch[i][m-1]=='1'){
                ch[i][m-1]='0';
                ans.push_back({i,m-1});
                co++;
            }
            if(co>0){
                ans.push_back({i+1,m-2});
                ch[i+1][m-2]='0'+(ch[i+1][m-2]=='0');
            }
            if(co==1){
                ans.push_back({i,m-2});
                ch[i][m-2]='0'+(ch[i][m-2]=='0');
                co--;
            }
        }
        int i=0;
        if(ch[i][m-1]=='1'){
            int co=0;
            if(ch[i+1][m-1]=='1'){
                ch[i+1][m-1]='0';
                ans.push_back({i+1,m-1});
                co++;
            }
            if(ch[i][m-1]=='1'){
                ch[i][m-1]='0';
                ans.push_back({i,m-1});
                co++;
            }
            if(co>0){
                ans.push_back({i+1,m-2});
                ch[i+1][m-2]='0'+(ch[i+1][m-2]=='0');
            }
            if(co==1){
                ans.push_back({i,m-2});
                ch[i][m-2]='0'+(ch[i][m-2]=='0');
                co--;
            }
        }
    }
 //   whatArray2D(ch,n,m);
    if(n%2==1){
        int save_m = m;
        if(m%2==1)m--;;
        for(int i=m-2; i>=0; i-=2) {
            int co=0;
            if(ch[n-1][i+1]=='1'){
                ch[n-1][i+1]='0';
                ans.push_back({n-1,i+1});
                co++;
            }
            if(ch[n-1][i]=='1'){
                ch[n-1][i]='0';
                ans.push_back({n-1,i});
                co++;
            }
            if(co>0){
                ans.push_back({n-2,i+1});
                ch[n-2][i+1]='0'+(ch[n-2][i+1]=='0');
            }
            if(co==1){
                ans.push_back({n-2,i});
                ch[n-2][i]='0'+(ch[n-2][i]=='0');
                co--;
            }
        }
        int i=0;
        if(ch[n-1][i]=='1'){
            assert(n%2==0);
            int co=0;
            if(ch[n-1][i+1]=='1'){
                ch[n-1][i+1]='0';
                ans.push_back({n-1,i+1});
                co++;
            }
            if(ch[n-1][i]=='1'){
                ch[n-1][i]='0';
                ans.push_back({n-1,i});
                co++;
            }
            if(co>0){
                ans.push_back({n-2,i+1});
                ch[n-2][i+1]='0'+(ch[n-2][i+1]=='0');
            }
            if(co==1){
                ans.push_back({n-2,i});
                ch[n-2][i]='0'+(ch[n-2][i]=='0');
                co--;
            }
        }
        m = save_m;
    }
  //  whatArray2D(ch,n,m);

    for(int i=0; i<n-1; i+=2) {
        for(int j=0; j<m-1; j+=2) {
            solve4(i,j);solve1(i,j);solve2(i,j);solve3(i,j);
        }
    }
    assert((ans.size()/3)<=n*m);
  // if(ans.size()%3!=0){cout<<"WRONG"<<'\n';}
    cout<<ans.size()/3<<'\n';
    for(int i=0; i<ans.size(); i++) {
        if(i!=0 &&(i%3)==0){cout<<'\n';}
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<' ';
    }
    cout<<'\n';
 //  whatArray2D(ch,n,m);
    
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}