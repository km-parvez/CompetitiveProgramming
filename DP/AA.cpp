// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define MAXX 1000006

using namespace std;
using ll = long long;

void solve(){
   int n;
   cin>>n;
   int arr[n+1],arr1[n+1],arr2[n+1];
   for(int i=0; i<n; i++) {
    cin>>arr[i];
    arr1[i] = arr[i];
   }

   if(n==1){cout<<"YES"<<endl; return;}
   if(n==2){
    if(arr[0]>arr[1])
    {
      cout<<"NO"<<endl; return;
    }
    if(arr[1]-arr[0]==1||arr[1]-arr[0]==2||arr[1]-arr[0]==3)
      {cout<<"YES"<<endl; return;}
    else
      {
      cout<<"NO"<<endl; return;
     }
   }

   int co = 0;
    for(int i=1; i<n; i++) {

      if(arr[i-1]>arr[i]||(arr[i]-arr[i-1])>2)
      {        co++; break;
      }
      else if(arr[i-1]==arr[i]){
        arr[i]+=1;
      }
      else if(arr[i-1]+2==arr[i])
        arr[i]-=1;
    }


    for(int i=0; i<n; i++) {
      arr[i] =arr1[i];
    }
    arr[0]+=1;
    for(int i=1; i<n; i++) {

      if(arr[i-1]>arr[i]||(arr[i]-arr[i-1])>2)
      {
        co++;break;
      }
      else if(arr[i-1]==arr[i]){
        arr[i]+=1;
      }
      else if(arr[i-1]+2==arr[i])
        arr[i]-=1;
    }

    for(int i=0; i<n; i++) {
      arr[i] =arr1[i];
    }
    arr[0]-=1;
    for(int i=1; i<n; i++) {

      if(arr[i-1]>arr[i]||(arr[i]-arr[i-1])>2)
      {
        co++;
        break;
      }
      else if(arr[i-1]==arr[i]){
        arr[i]+=1;
      }
      else if(arr[i-1]+2==arr[i])
        arr[i]-=1;
    }

   // whatis1(co);
    if(co==3)
    cout<<"NO"<<'\n';
  else
    cout<<"YES"<<endl;

    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve();
    }
    return 0;
}