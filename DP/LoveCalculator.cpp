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
#define MAXX 15
template<size_t N>
using namespace std;
using ll = long long;
int arr[15];
int cnt[15];
int distict = 0;
int d,n;
bool isOn(int mask,int pos){
    return (mask>>pos)&1;
}
void setOn(int &mask,int pos){
    return mask=mask|(1<<pos);
} 
ll func(int pos,int mask){
    if(pos>=n) return 0;

    for(int i=0; i<distict; i++) {
        if(!isOn(mask,i)){
            setOn(mask,i);
            if(num%d==0)
            {

            }
            else
            func(pos+1,mask);
        }
    }
}
void solve(int caseno){
    ll d,n;
    string str;
    cin>>str>>d;
    n = str.size();

   memset(cnt,1,sizeof(cnt));
    distict = 0;
    for(int i=0; i<n; i++) {
        if(cnt[str[i]-'0']==0){
            arr[distict++] = str[i]-'0';
            cnt[str[i]-'0']++;
        }
        else{
            cnt[str[i]-'0']++;   
        }

    }
    sort(arr,arr+distict);
    
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