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
#define MX 1000006

using namespace std;
using ll = long long;

void solve(int caseno){
    int n;
    string s;
    cin>>s;
    n=s.size();
    cout<<"Case "<<caseno<<": ";
    char binary[n];
    for(int i=0; i<n; i++) {
    	if(s[i]=='?')binary[i] = s[i];
    	else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
    		binary[i] = '0';
    	else binary[i]='1';
    }
    bool bad = true;
    for(int i=0; i<=n-3; i++) {
    	bad = true;
    	for(int j=0; j<3; j++) {
    		if(binary[i+j]!='0'){bad=false;break;}
    	}
    	if(bad){
    		cout<<"BAD"<<'\n';return ;
    	}
    }
    bad = true;
    for(int i=0; i<=n-5; i++) {
    	bad = true;
    	for(int j=0; j<5; j++) {
    		if(binary[i+j]!='1'){bad=false;break;}
    	}
    	if(bad){
    		cout<<"BAD"<<'\n';return ;
    	}
    }
    for(int i=0; i<=n-3; i++) {
    	if(binary[i]=='0'&&binary[i+1]=='0'&&binary[i+2]=='?'){
    		binary[i+2]='1';
    	}
    	else if(i+4<=n-1&& binary[i]=='1'&&binary[i+1]=='1'&&binary[i+2]=='1'&&binary[i+3]=='1'&&binary[i+4]=='?'){
    		binary[i+4] = '0';
    	}
    }
     bad = true;
    for(int i=0; i<=n-3; i++) {
    	bad = true;
    	for(int j=0; j<3; j++) {
    		if(binary[i+j]!='0'){bad=false;break;}
    	}
    	if(bad){
    		cout<<"BAD"<<'\n';return ;
    	}
    }
    bad = true;
    for(int i=0; i<=n-5; i++) {
    	bad = true;
    	for(int j=0; j<5; j++) {
    		if(binary[i+j]!='1'){bad=false;break;}
    	}
    	if(bad){
    		cout<<"BAD"<<'\n';return ;
    	}
    }
    for(int i=0; i<n; i++) {
    	if(s[i]=='?')binary[i]='0';
    }
	bad = true;
    for(int i=0; i<=n-3; i++) {
    	bad = true;
    	for(int j=0; j<3; j++) {
    		if(binary[i+j]!='0'){bad=false;break;}
    	}
    	if(bad){
    		cout<<"MIXED"<<'\n';return ;
    	}
    }
    for(int i=0; i<n; i++) {
    	if(s[i]=='?')binary[i]='1';
    }
    bad = true;
    for(int i=0; i<=n-5; i++) {
    	bad = true;
    	for(int j=0; j<5; j++) {
    		if(binary[i+j]!='1'){bad=false;break;}
    	}
    	if(bad){
    		cout<<"MIXED"<<'\n';return ;
    	}
    }
    cout<<"GOOD"<<'\n';

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