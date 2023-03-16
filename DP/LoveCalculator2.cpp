// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 62

using namespace std;
using ll = long long;


long long ncr[MAXX + 1][MAXX + 1];

void makeTriangle() {
    int i, j;

    // initialize the first row
    ncr[0][0] = 1; // C(0, 0) = 1

    for(i = 1; i < MAXX; i++) {
        ncr[i][0] = 1; // C(i, 0) = 1
        for(j = 1; j <= i; j++) {
            ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
        }
    }
}

string ch1,ch2;
ll len1,len2;
ll dp[MAXX][MAXX];
pair<int,int> track[MAXX][MAXX];
ll lcs(int pos1, int pos2){
  if(pos1>=len1) {track[pos1][pos2]= {-1,-1};return 0;}
  if(pos2>=len2) {track[pos1][pos2]= {-1,-1};return 0;}
  if(dp[pos1][pos2]!=-1)return dp[pos1][pos2];

  if(ch1[pos1]==ch2[pos2]){
        track[pos1][pos2] = {pos1+1,pos2+1};
    dp[pos1][pos2] = lcs(pos1+1,pos2+1)+1;
  }
  else{

         ll val1,val2;
     val2 = lcs(pos1,pos2+1);
         val1 = lcs(pos1+1,pos2);
         
     if(val1>=val2){
        dp[pos1][pos2] = val1;
        track[pos1][pos2] = {pos1+1,pos2};
     }
     else
     {
        dp[pos1][pos2] = val2;
        track[pos1][pos2] = {pos1,pos2+1};
     }
  }
  return dp[pos1][pos2];

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    makeTriangle();
     //whatis1(ncr[10][5]);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){

        cout<<"Case "<<++caseno<<": ";
        memset(dp,-1,sizeof dp);
        cin>>ch1>>ch2;
        len1= ch1.size();
        len2= ch2.size();
        int mxlcs = lcs(0,0);
        if(mxlcs==0){
            cout<<len1+len2<<" "<<ncr[len1+len2][len1]<<endl;
            continue;
        }
        
        string ansstr;
        vector<string> v; 
        int co = 0;
        queue<pair<pair <pair<int,int>, int >,string> > q;
        q.push({{{0,0},0},""});
        while(!q.empty()){
            pair<pair <pair<int,int>, int >,string> tmp = q.front();
            q.pop();
            int ind1= tmp.first.first.first;
            int ind2=tmp.first.first.second;
            int carry = tmp.first.second;
            string tmpstr = tmp.second; 

            if(carry==mxlcs){
                v.push_back(tmpstr);
            }
            if(carry>=mxlcs&&ind1>=len1&&ind2>=len2){

                continue;
            }
            
            int i,j;
            for(int z='A'; z<='Z'; z++) {
                bool found = false;
                for(i=ind1; i<len1; i++) {
                    if(ch1[i]==z){
                      for(j=ind2; j<len2; j++) {
                        if(ch2[j]==z&&carry+dp[i][j]==mxlcs){
                            ansstr+=ch1[i];
                            q.push({{{i+1,j+1},carry+1},tmpstr+ch1[i]}); 
                           found = true;    
                            break;
                        }
                      }   
                      if(found)break;
                    }
                    
                }
               
            }
        }

      ll ans=0LL;
      cout<<mxlcs<<endl;
     /* string str = ch1;
      bool visited[103];memset(visited,false,sizeof(visited));
      for(int k=0; k<v.size(); k++) {
          for(int i=0; i<v[i].size(); i++) {
            for(int j=i; j<len2; j++) {
                if(v[k][i]==ch2[j])visited[j]=true;
                break;

            }
          }
      }*/
        for(int k=0; k<v.size(); k++) {
            cout<<v[k]<<endl;
            ll prod = 1;
            int prv1=-1;
            int prv2=-1;
            int i=0,j=0;
            while(ch1[i]!=v[k][0])i++;
            while(ch2[j]!=v[k][0]) j++;
            
            int left1 = i-prv1-1;
            int left2 = j-prv2-1;
            prod = ncr[left1+left2][left1];

            for(int t=1; t<mxlcs; t++) {
              //whatis2(t,v[k][t]);

              int ii=i+1,jj=j+1;
              while(ch1[ii]!=v[k][t])ii++;
              while(ch2[jj]!=v[k][t])jj++;

              int left1 = i-prv1-1;
              int left2 = j-prv2-1;
              int right1 = ii-i-1;
              int right2 = jj-j-1;
              prod*=ncr[right1+right2][right1];
              int ni=i+1,nj=j+1;
              ll locsum = 0;
              while(ch1[ni]!=v[k][t]) {
                  if(ch1[ni]==v[k][t-1]){
                    int tmpi = i;
                    i = ni;
                    left1 = i-prv1-1;
                    left2 = j-prv2-1;
                    right1 = ii-i-1;
                    right2 = jj-j-1;
                    ll plus = ncr[left1+left2][left2]*ncr[right1+right2][right2];
                    ll minus =ncr[tmpi-prv1-1+left2][left2]*ncr[right1+right2][right2];
                    //whatis2(left1,left2);
                   // whatis2(right1,right2);

                   // whatis2(plus,minus);
                    locsum = locsum+plus-minus;
                   // whatis3(ni,t,locsum);

                  }
                  ni++;
              }
              while(ch2[nj]!=v[k][t]) {
                  if(ch2[nj]==v[k][t-1]){
                    int tmpj = j;
                    j = nj;
                    left1 = i-prv1-1;
                    left2 = j-prv2-1;
                    right1 = ii-i-1;
                    right2 = jj-j-1;
                    ll plus = ncr[left1+left2][left1]*ncr[right1+right2][right1];
                    ll minus =ncr[left1+tmpj-prv2-1][left1]*ncr[right1+right2][right1];
                    //whatis2(left1,left2);
                    //whatis2(right1,right2);

                    //whatis2(plus,minus);
                    locsum = locsum+plus-minus;
                    //whatis3(nj,t,locsum);
                  }
                  nj++;
              }

              //whatis3("prod",v[k][t],locsum);
              prod+=locsum;
              prv1= i;
              prv2= j;
              i = ii;
              j = jj;

            }
            {
              int ii=len1,jj=len2;

              int left1 = i-prv1-1;
              int left2 = j-prv2-1;
              int right1 = ii-i-1;
              int right2 = jj-j-1;
     

             prod*=ncr[right1+right2][right1];

              ll locsum=0;
             // whatis2("bTop",locsum);
              int ni=i+1,nj=j+1;
              while(ni<len1) {
                  if(ch1[ni]==v[k][mxlcs-1]){
                    int tmpi = i;
                    i = ni;
                    left1 = i-prv1-1;
                    left2 = j-prv2-1;
                    right1 = ii-i-1;
                    right2 = jj-j-1;
                    ll plus = ncr[left1+left2][left2]*ncr[right1+right2][right2];
                    ll minus =ncr[tmpi-prv1-1+left2][left2]*ncr[right1+right2][right2];
                   // whatis2(left1,left2);
                   // whatis2(right1,right2);
                   // whatis2(plus,minus);
                   //  whatis3(ni,i,locsum);
                    locsum = locsum+plus-minus;
                   // whatis3(ni,i,locsum);
                  }
                  ni++;
              }
              while(nj<len2) {
                  if(ch2[nj]==v[k][mxlcs-1]){
                    int tmpj = j;
                    j = nj;
                    left1 = i-prv1-1;
                    left2 = j-prv2-1;
                    right1 = ii-i-1;
                    right2 = jj-j-1;
                    ll plus = ncr[left1+left2][left1]*ncr[right1+right2][right1];
                    ll minus =ncr[left1+tmpj-prv2-1][left1]*ncr[right1+right2][right1];
                    //whatis2(left1,left2);
                    //whatis2(right1,right2);
                    //whatis2(plus,minus);
                     //whatis3(nj,j,locsum);
                    locsum = locsum+plus-minus;
                    //whatis3(nj,j,locsum);
                  }
                  nj++;
              }
              //whatis3("prod",v[k][mxlcs-1],locsum);
              prod+=locsum;
              prv1= i;
              prv2= j;
              i = ii;
              j = jj;
            }
            //whatis1(ans);
            //whatis1(prod);
            ans+=prod;
            
        }
        cout<<len1+len2-mxlcs<<" "<<ans<<endl;
    }
    return 0;
}