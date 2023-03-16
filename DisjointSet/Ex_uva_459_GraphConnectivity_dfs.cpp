// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define MAXX 256

using namespace std;
using ll = long long;
vector<char> g[MAXX];
bool visited[MAXX];

void dfs(char u){
    visited[u] = true;
    for(int i=0; i<g[u].size(); i++) {
        char v = g[u][i] ;
        if(!visited[v])dfs(v);
    }
}
int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    bool flag = true;
    int t;
    cin>>t;
    char line[10];
   gets(line);
	while(t--){
        if(flag)
                gets(line);
            flag = false;
                char mx ;
            //    cout<<"test : "<<t<<endl;  
            while(gets(line)){
        		
                if(strlen(line)==1){

                 
                   // cout<<line<<" 1"<<endl;
                    mx = line[0];
                //    cout<<line[0]<<endl;
                    for(char i = 'A';i<=mx;i++){
                    g[i].clear();
                    visited[i] = false;
                    }
                }
                else if(strlen(line)==2){
               //     cout<<line<<" 2"<<endl;
                    char u = line[0];
                    char v = line[1];
                    g[u].push_back(v);
                    g[v].push_back(u);
                }
                else if(strlen(line)==0)
                {
             //       cout<<line<<" 0"<<endl;
                int ans = 0;
                for(char i = 'A';i<=mx;i++){
                    if(!visited[i]){
                        dfs(i);
                        ans++;
                    }
                }
                printf("%d\n\n",ans );
                break;
                }
            }
            if(t==0){
             int ans = 0;
                for(char i = 'A';i<=mx;i++){
                    if(!visited[i]){
                            dfs(i);
                            ans++;
                        }
                }
                printf("%d\n",ans );
        	}


    }
    return 0;
}