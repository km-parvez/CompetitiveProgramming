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
#define MX 200005

using namespace std;
using ll = long long;
vector<int> g[MX];
int parent[MX];
int level[MX];
int parseTable[MX][20];
int n;
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
void createParseTable(){

    memset(parseTable,-1,sizeof(parseTable));
    for(int i=1; i<=n; i++) {
        parseTable[i][0]=parent[i];
    }
    int lgn = log2(n)+1;
    for(int j=1;j<lgn; j++) {
        for(int i=1; i<=n; i++) {
            if(parseTable[i][j-1]!=-1)
            parseTable[i][j] = parseTable[parseTable[i][j-1]][j-1];
        }
    }
}
int query(int p,int q){
    if(level[p]<level[q])swap(p,q);
// p should has a bigger level
    int lgn = log2(n)+1;
    for(int i=lgn; i>=0; i--) {
        if((level[p]-(1<<i))>=level[q]){
            p=parseTable[p][i];
        }
    }
    if(p==q)return p;

    for(int i=lgn; i>=0; i--) {
        if(parseTable[p][i]!=-1&&parseTable[p][i]!=parseTable[q][i]){
            p = parseTable[p][i];
            q = parseTable[q][i];
        }
    }
    return parent[p];

}

void solve(int caseno){
    int q;
    cin>>n>>q;
    for(int i=0; i<n-1; i++) {
        int x,y;
        cin>>x>>y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    level[1]=0;
    memset(parent,-1,sizeof(parent));
    parent[1]=-1;
    dfs(-1,1);
    //whatisArray(level,n+1);
    createParseTable();
/*    for(int i=1; i<=n; i++) {
        cout<<i<<" : ";
        for(int j=0; j<20; j++) {
            cout<<parseTable[i][j]<<' ';
        }
        cout<<'\n';
    }*/
    while(q--){
        int k;cin>>k;
        vector<int> val(k);
        int mxlvl = -1; int nod; 
        for(int i=0; i<k; i++) {
            cin>>val[i];
            if(level[val[i]]>mxlvl){
                mxlvl = level[val[i]];
                nod = val[i];
            }
        }
        bool ok = true;
        for(int i=0; i<k; i++) {
            int lca = query(val[i],nod);
           // whatis3(common,val[i],nod);
            if(lca!=val[i]&&parent[val[i]]!=lca){
                ok = false;
                break;
            }
        }
        if(ok)
            cout<<"YES"<<'\n'; 
        else 
            cout<<"NO"<<'\n';          
    }

    

    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    int cases,caseno=0;
    cases=1;
    while(cases--){
        solve(++caseno);
        cout<<'\n';
    }
    return 0;
}