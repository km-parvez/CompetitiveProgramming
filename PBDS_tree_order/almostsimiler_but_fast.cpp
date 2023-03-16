#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ara[1000001],tree[4000001];
ll les[1000001],great[1000001];
vector <ll>temp;
map<ll,ll> onto;
void update(ll node,ll l,ll r,ll pos,ll u)
{
     if(l==r){
        tree[node]=u;
        return ;
     }
     ll mid=(l+r)/2;
     if(pos<=mid)
        update(2*node,l,mid,pos,u);
     else
        update(2*node+1,mid+1,r,pos,u);
     tree[node]=tree[2*node]+tree[2*node+1];
}
ll query(ll node,ll l,ll r,ll ql,ll qr)
{
    if(ql>r || qr<l)
        return 0;
    if(ql<=l && qr>=r)
        return tree[node];
    ll mid=(l+r)/2;
    return query(2*node,l,mid,ql,qr)+query(2*node+1,mid+1,r,ql,qr);
}
int main()
{
    ll i,j,k;
    ll n,res=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&ara[i]);
        temp.push_back(ara[i]);
    }
    sort(temp.begin(),temp.end());
    for(i=0;i<n;i++)
        onto[temp[i]]=i;
    for(i=0;i<n;i++)
        ara[i]=onto[ara[i]];
    for(i=0;i<n;i++){
        if(ara[i]==0)
            great[i]=i;
        else
            great[i]=query(1,0,1000000,ara[i]+1,1000000);
        update(1,0,1000000,ara[i],1);
    }
    memset(tree,0,sizeof tree);
    for(i=n-1;i>=0;i--){
        if(ara[i]==0)
            les[i]=0;
        else
            les[i]=query(1,0,1000000,0,ara[i]-1);
        update(1,0,1000000,ara[i],1);
    }
    for(i=0;i<n;i++)
        res+=(les[i]*great[i]);
    printf("%lld",res);
}