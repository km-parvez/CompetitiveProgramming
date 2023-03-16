// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define MAXX 105

using namespace std;
using ll = long long;


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
            cout<<":("<<endl;
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
         //  db3(ind1,ind2,carry);
          // db1(tmpstr);
            if(carry==mxlcs){
                v.push_back(tmpstr);
            }
            if(carry>=mxlcs&&ind1>=len1&&ind2>=len2){
               // db1("continue");
               // db3(ind1,ind2,carry);

                continue;
            }

          //  db3(ind1,ind2,carry);
            
            int i,j;
            for(int z='a'; z<='z'; z++) {
                bool found = false;
                for(i=ind1; i<len1; i++) {
                    if(ch1[i]==z){
                      for(j=ind2; j<len2; j++) {
                        if(ch2[j]==z&&carry+dp[i][j]==mxlcs){
                            ansstr+=ch1[i];

                           // v[carry].push_back(ch1[i]);
                            q.push({{{i+1,j+1},carry+1},tmpstr+ch1[i]}); 
                           // ind2=j+1;  
                           found = true;    
                            break;
                        }
                      }   
                      if(found)break;
                    }
                    
                }
               
            }
        }
      //  ansstr[mxlcs]='\0';

    	//db1(cnt);
    	cout<<mxlcs<<endl;
        for(int i=0; i<v.size(); i++) {
            cout<<v[i]<<endl;
            
        }
      //  cout<<ansstr<<endl;
    }
    return 0;
}