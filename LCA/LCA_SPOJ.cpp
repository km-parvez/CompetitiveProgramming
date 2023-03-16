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
#define MX 10004

using namespace std;
using ll = long long;
vector<pair<int,int> > g[MX];
int parent[MX];
int level[MX];
int dist[MX];
int parseTable[MX][16];
int n;
void dfs(int par,int u){
    for(int i=0; i<g[u].size(); i++) {
        int v= g[u][i].first;
        if(v!=par){
            level[v]=level[u]+1;
            dist[v]=dist[u]+g[u][i].second;
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
    int lgn = log2(p)+1;
    for(int i=lgn; i>=0; i--) {
        if(level[p]-(1<<i)>=level[q]){
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

    cin>>n;
    for(int i=0; i<MX; i++) {
        g[i].clear();
    }
    for(int i=0; i<n-1; i++) {
        int x,y,w;
        cin>>x>>y>>w;
        g[x].emplace_back(y,w);
        g[y].emplace_back(x,w);
    }
    dist[1]=0;
    level[1]=0;
    parent[1]=-1;
    dfs(-1,1);
    createParseTable();
    /*for(int i=1; i<=n; i++) {
        cout<<i<<" : ";
        for(int j=0; j<lgn; j++) {
            cout<<parseTable[i][j]<<' ';
        }
        cout<<'\n';
    }*/
    string ques;
    while(cin>>ques){
        if(ques=="DIST"){
            int p,q;
            cin>>p>>q;
           // whatis2(p,q);
            int lca = query(p,q);
            ll ans = dist[p]+dist[q]-2*dist[lca];
            //whatis3(lca,dist[p],dist[q]);
            cout<<ans<<'\n';
        }
        else if(ques=="KTH"){
            int p,q,k;
            cin>>p>>q>>k;
            k--;
            int lca = query(p,q);
            if((level[p]-level[lca])<k){
                k=(level[q]-level[lca])-(k-(level[p]-level[lca]));
                p=q;
            }
          //  whatis2(p,k);
            int pow = 0;
            while(k>0){
                if(k&1){
                    p=parseTable[p][pow];
                    //whatis1(p);
                }
                k=k/2;
                pow++;
            }
            cout<<p<<'\n';
        }
        else if(ques=="DONE")break;
        

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
        cout<<'\n';
    }
    return 0;
}