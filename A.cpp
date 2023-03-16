// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define MAXX 1000006

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(true){
    	int n;
    	cin>>n;
    	if(n<=0)break;
    	int arr[n+100],temp;
    	deque<pair<int,int> > dq;
    	for(int i=0; i<n; i++) {
    		cin>>temp;
    		dq.push_front(make_pair(temp,i));
	    }
	    while(!dq.empty()&&dq.front().second>=0){
	    	int right = dq.front().first;
	    	if(right>=0){
	    		dq.push_back(make_pair(dq.front().first,-1));
	    		dq.pop_front();
	    	}
	    	else
	    	{
	    		pair<int,int> p = dq.front();
	    		dq.pop_front();
	    		pair<int,int> q = dq.front();
	    		dq.pop_front();
	    		q.first = q.first+p.first;
	    		dq.push_front(q);
	    		
	    	}	
	    }
	    while(!dq.empty()&&dq.front().first<0){

	    		pair<int,int> p = dq.front();
	    		dq.pop_front();
	    		pair<int,int> q = dq.front();
	    		dq.pop_front();
	    		q.first = q.first+p.first;
	    		dq.push_front(q);
	    		
	    	
	    }
	    cout<<dq.size()<<endl;

    }
    return 0;
}
/*
Rough:
3
0	1	2
11 12 13 14 1 2 3 4 5 6 	-5	1	1, -5	     		  = x

0 1 1 -5
11 12 13 14  
1	1	-1 = 1
1 	-1	1 = 1


 
*/