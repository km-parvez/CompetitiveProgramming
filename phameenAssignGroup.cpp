// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'

#define MAXX  1000006
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   	int cls = 10; 
    int t = 6;
    //cout<<"Class "<<cls<<" :"<<endl;
    while(t--){
        char section;
        while(cin>>section){
        	if(section>='A' && section<='Z')break;
        }
     //   cout<<"Section "<<section<<" : "<<endl;
        vector<int> v;
        while(true){
        	int roll;char ch;
        	cin>>roll>>ch;
        	v.push_back(roll);
        //	cout<<roll<<" ";
        	if(ch=='.')break;
        	
        }
    //    cout<<endl<<"Total Science in Section '"<<section<<"' = "<<v.size()<<endl<<endl;
        for(int i=0; i<v.size(); i++) {
            cout<<"UPDATE tbstudent SET groupName = 'Science' WHERE rollNo = '"<<v[i]<<"' AND class = 'D"<<cls<<section<<"' AND session = '2021' ;"<<endl;
        }
    }
    
    return 0;
}