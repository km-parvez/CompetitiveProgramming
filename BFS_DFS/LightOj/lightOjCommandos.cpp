#include<bits/stdc++.h>
using namespace std;
#define SIZE 10004
vector< int >v[SIZE];
int pr_of[SIZE];
int visited1[SIZE];
int visited2[SIZE];
int level1[SIZE];
int level2[SIZE];
int mxl;

void bfs1(int s,int *level)
{

    queue<int>q;
    visited1[s] = 1;
    level[s] = 0;
    q.push(s);
    while(!q.empty())
    {

        int top = q.front();
        q.pop();
        for(int i=0;i<v[top].size();i++)
        {

            if(visited1[v[top][i]]!=1)
            {
                visited1[v[top][i]]=1;
                q.push(v[top][i]);
              level[v[top][i]] = level[top]+1;
            }
        }
    }
}


int main()
{
    int cases,caseno =0;
    scanf("%d",&cases);
    while(cases--)
    {
        int n,s,d,r;
        scanf("%d %d",&n,&r);

        for(int i=0;i<n;i++)
        {
            level1[i] = 0;
            level2[i] = 0;

            visited1[i]= 0;
            visited2[i]= 0;
            v[i].clear();


        }
        for(int i=0;i<r;i++)
        {
                int x,y;
                scanf("%d %d",&x,&y);
                v[x].push_back(y);
                v[y].push_back(x);
        }

        scanf("%d %d",&s,&d);
        bfs1(s,level1);
         for(int i=0;i<n;i++)
        {
        visited1[i]=0;
        }
        bfs1(d,level2);
        int maxx = 0;
        for(int i=0;i<n;i++)
        {
            if((level1[i]+level2[i])>maxx)
            maxx =level1[i]+level2[i];
        }

        printf("Case %d: %d\n",++caseno,maxx);

    }
    return 0;
}
