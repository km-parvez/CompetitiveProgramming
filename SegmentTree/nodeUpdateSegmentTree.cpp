#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
//function to build the segment tree
void buildTree(int *tree,int *a,int index,int s,int e)
{
    //base case
    if(s>e)
        return;
    //reached leaf node
    if(s==e)
    {
        tree[index]=0;
        a[s]=0;
        return ;
    }
    //now build the segment tree in bottom up manner
    int m = (s+e)/2;
    buildTree(tree,a,2*index,s,m);
    buildTree(tree,a,2*index+1,m+1,e);
    tree[index]= tree[2*index]+tree[2*index+1];
    return;
}
 
//function to query the segment tree for RSQ
int query(int *tree,int index,int s,int e,int qs,int qe)
{
    //base case: if query range is outside the node range
    if(qs>e || s>qe)
        return 0;
    //complete overlap
    if(s>=qs && e<=qe)
        return tree[index];
    //now partial overlap case is executed
    int m = (s+e)/2;
    int left_ans = query(tree,2*index,s,m,qs,qe);
    int right_ans = query(tree,2*index+1,m+1,e,qs,qe);
    return left_ans+right_ans;
}
 
void updateNode(int *tree,int *a,int index,int s,int e,int pos,int val)
{
    if(pos<s || pos>e)
        return ;
    if(s==e)
    {
        a[s]+=val;
        tree[index] = a[s]>0;
        return ;
    }
    int m = (s+e)/2;
    updateNode(tree,a,2*index,s,m,pos,val);
    updateNode(tree,a,2*index+1,m+1,e,pos,val);
    tree[index] = tree[2*index]+tree[2*index+1];
    return;
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    int a[n+2]={0};                                                       //size of input array
    int b[n+2]={0};                                                       //size of input array
    int *tree = new int[4*n+1];                                    //array to store the segment tree
    int *tree2 = new int[4*n+1];                                    //array to store the segment tree
    int index = 1;                                                  //index of 1st node
    int s =0,e=n-1;
   // buildTree(tree,a,index,s,e);                                    //now tree has been built
    //buildTree(tree2,b,index,s,e);   
    while(q--){
    int t;
    cin>>t;
    if(t==1){
        int x,y;
        cin>>x>>y;
        x--;y--;
        updateNode(tree,a,index,s,e,x,1);
        updateNode(tree2,b,index,s,e,y,1);
    }
    else if(t==2)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        updateNode(tree,a,index,s,e,x,-1);
        updateNode(tree2,b,index,s,e,y,-1);
    }
    else {
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        x1--;y1--;x2--;y2--;
        int rows = query(tree,index,s,e,x1,x2);
        int cols = query(tree2,index,s,e,y1,y2);
        if(rows==x2-x1+1||cols==y2-y1+1){
            cout<<"YES"<<'\n';
        }
        else
            cout<<"NO"<<'\n';
    }
 
    }
    //updateNode(tree,index,s,e,4,-11);
    return 0;
}