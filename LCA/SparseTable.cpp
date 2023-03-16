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
vector<int> g[MX];
int parent[MX];
int level[MX];
int parseTable[MX][32];
void dfs(int par,int u){
    for(int i=0; i<g[u].size(); i++) {
        int v= g[u][i];
        if(v!=par){
            level[v]=level[u]+1;
            parent[v]=u;
            dfs(u,v);
        }
    }
}

void solve(int caseno){
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++) {
        int x,y;
        cin>>x>>y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    level[0]=0;
    parent[0]=-1;
    dfs(-1,0);
    memset(parseTable,-1,sizeof(parseTable));
    for(int i=0; i<n; i++) {
        parseTable[i][0]=parent[i];
    }
    int lgn = log2(n);
    for(int j=1;j<lgn; j++) {
        for(int i=0; i<n; i++) {
            if(parseTable[i][j-1]!=-1)
            parseTable[i][j] = parseTable[parseTable[i][j-1]][j-1];
        }
    }
    for(int i=0; i<n; i++) {
        cout<<i<<" : ";
        for(int j=0; j<lgn+1; j++) {
            cout<<parseTable[i][j]<<' ';
        }
        cout<<'\n';
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