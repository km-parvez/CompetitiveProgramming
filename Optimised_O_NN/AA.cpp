#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int MX=100005;
int a[MX];
 
int main()
{
    int t;
    scanf("%d",&t);  
    while(t--){
        int n;
        ll ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%1d",&a[i]);
            a[i]+=a[i-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                ans+=(ll)(a[j]-a[i-1]==j-i+1);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}