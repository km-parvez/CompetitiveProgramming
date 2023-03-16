// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 30

using namespace std;
using ll = long long;
int INF = 1000000007;

int fx[]={0,0,0,0,-1,1};
int fy[]={0,0,-1,1,0,0};
int fz[]={-1,1,0,0,0,0};

struct node
{
	int a,b,c;
	node(int x,int y,int z){
		a=x;
		b=y;
		c=z;
	}
};
int level[MAXX][MAXX][MAXX];


void bfs(int a,int b,int c,int x,int y,int z){
	level[a][b][c]=0;
	queue< node > q;
	q.push(node(a,b,c));
	while(!q.empty()){
		node cur = q.front();
		q.pop();
		if(cur.a==x&&cur.b==y&&cur.c==z){
			return ;
		}
		//adj 
		for(int i=0; i<6; i++) {
			int na = cur.a+fx[i];
			int nb = cur.b+fy[i];
			int nc = cur.c+fz[i];
			if(na==26)na=0;
			if(nb==26)nb=0;
			if(nc==26)nc=0;
			if(na==-1)na=25;
			if(nb==-1)nb=25;
			if(nc==-1)nc=25;
			
			if(level[na][nb][nc]==INF){
				//db3(a,b,c);
				//db3(na,nb,nc);
				q.push(node(na,nb,nc));
				level[na][nb][nc]= level[cur.a][cur.b][cur.c]+1;
			}
		}
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
    	for(int i=0; i<MAXX; i++) {
    		for(int j=0; j<MAXX; j++) {
    			for(int k=0; k<MAXX; k++) {
    				level[i][j][k]=INF;
    			}
    		}
    	}
    	char s[4],e[4];
    	cin>>s>>e;
        int n;
        cin>>n;
        int ans = INF;
        if(s[0]==e[0]&&s[1]==e[1]&&s[2]==e[2])
        	ans = 0;
        for(int i=0;i<n;i++){
        	string x1,x2,x3;
        	cin>>x1>>x2>>x3;
    		for(int i1=0; i1<x1.size(); i1++) {
    			for(int i2=0; i2<x2.size(); i2++) {
    				for(int i3=0; i3<x3.size(); i3++) {
    					if(x1[i1]==s[0] &&x2[i2]==s[1]&&x3[i3]==s[2])
    						ans = -1;
    					if(x1[i1]==e[0] &&x2[i2]==e[1]&&x3[i3]==e[2])
    						ans = -1;
    					level[x1[i1]-'a'][x2[i2]-'a'][x3[i3]-'a'] = -1;
    				}
    			}
    		}
        }
        if(ans!=INF){
        	caseprint(caseno,ans);
        	continue;
        }
        bfs(s[0]-'a',s[1]-'a',s[2]-'a',e[0]-'a',e[1]-'a',e[2]-'a');
        if(level[e[0]-'a'][e[1]-'a'][e[2]-'a']==INF)
        ans = -1;
        else
        ans = level[e[0]-'a'][e[1]-'a'][e[2]-'a'];
        caseprint(caseno,ans);    
    	
    }
    return 0;
}