// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define MAXX  1003
using namespace std;
using ll = long long;

int rep[MAXX];
int arr[MAXX];
int sum[MAXX];
int members[MAXX];
int find(int x){
	if(rep[x]==x){
		return x;
	}
	else{
		rep[x] = find(rep[x]);
		return rep[x];
	}
}
void join(int a,int b){
	int ra= find(a);
	int rb= find(b);
	if(ra!=rb){
		rep[rb]=ra;
	}
}
void makeset(int n){
	for(int i=1; i<=n; i++) {
		rep[i]=i;
		sum[i]=0;
		members[i]=0;
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases,caseno = 0;
    cin>>cases;
    while(cases--){
        int n,m;
        cin>>n>>m;
        makeset(n);
        int amounts[n+5];
        int tot = 0;
        int avg = -1;
        for(int i=1;i<=n;i++){
        	cin>>amounts[i];
        	tot+=amounts[i];
        }
        if(tot==0){
        	for(int i=0; i<m; i++){
	        	int x;
	     		cin>>x>>x;
	     	}
        	caseprint(caseno,"Yes");
        	continue;
        }
        if(tot%n!=0){
        	for(int i=0; i<m; i++){
	        	int x;
	     		cin>>x>>x;
	     	}
			caseprint(caseno,"No");
        	continue;
        }
        else{
        	avg = tot/n;
        }

     	for(int i=0; i<m; i++) {
     		int x,y;
     		cin>>x>>y;
     		join(x,y);
     	}
     	for(int i=1; i<=n; i++) {
     		int r = find(i);
     		sum[r]+=amounts[i];
     		members[r]++;
     	}
     	bool flag = false;
     	for(int i=1; i<=n; i++) {
     		if(rep[i]==i&&members[i]!=0){
     			if(sum[i]%members[i]!=0||sum[i]/members[i]!=avg){
     				flag=true;
     				break;
     			}
     		}
     	}
     	if(flag)
        	caseprint(caseno,"No");
     	else 
        	caseprint(caseno,"Yes");

    }
    return 0;
}