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
#define MAXX 17

using namespace std;
using ll = long long;
void setBit(int &mask,int pos){
	mask=mask|(1<<pos);
}
bool isOn(int mask,int pos){
	return (mask>>pos)&1;
}
bool isAll(int mask,int n){
	return mask==(1<<n)-1;
}

vector<int> lines[MAXX];
pair<int,int> arr[MAXX];

bool collinear(int x1, int y1, int x2,int y2, int x3, int y3)
{
	return (y3 - y2) * (x2 - x1) == (y2 - y1) * (x3 - x2));
}
int makeLine(int prv,int cur){
	int mask = 0;
	setBit(mask,prv);
	setBit(mask,cur);
	for(int i=0; i<n; i++) {
		if(!isOn(mask)){
			if(collinear(arr[prv].first,arr[prv].second,arr[cur].first,arr[cur].second,arr[i].first,arr[i].second))
				setBit(mask,i);
		}
	}
	lines[] = mask;
}

int func(int prv,int cur){

}

void solve(int caseno){
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
    	int x,y;
    	cin>>x>>y;
    	arr[i]={x,y};
    }
    for(int i=0; i<n; i++) {
    	for(int j=i; j<n; j++) {
    		makeLine(i,j);
    	}
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