// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++) cout<<arr[m]<<" ";cout<<'\n';
#define whatArray2D(arr,m,n) cout<<#arr<<", Size: "<<m<<","<<n<<'\n';for(int mm=0;mm<m;mm++){for(int nn=0;nn<n;nn++)cout<<arr[mm][nn]<<" ";cout<<'\n';} 
#define caseprint(caseno,ans) cout<<"Case "<<++caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
constexpr ll mod = 1000000007;
constexpr int MX = 200005;

void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}


// try binary search,BIT,segment tree, dp, dfs, union find, set, priority queue, sorting, two pointer, gready.

struct Query {
    int L, R, idx;
};

bool compare(Query &q1, Query &q2) {
    int block_size = sqrt(q1.R - q1.L + 1);
    if (q1.L / block_size != q2.L / block_size)
        return q1.L / block_size < q2.L / block_size;
    return q1.R < q2.R;
}

class RangeModeQuery {
private:
    vector<int> arr;
    vector<int> result;
    int currentMode;
    map<int, int> freq;
    map<int, int> freqCount;

    void add(int element) {
        int prevFreq = freq[element];
        freq[element]++;
        int newFreq = freq[element];

        if (newFreq > currentMode) {
            currentMode = newFreq;
        }
        
        freqCount[prevFreq]--;
        freqCount[newFreq]++;
    }

    void remove(int element) {
        int prevFreq = freq[element];
        freq[element]--;
        int newFreq = freq[element];

        freqCount[prevFreq]--;
        if (newFreq > 0) freqCount[newFreq]++;

        if (freqCount[currentMode] == 0) {
            currentMode--;
        }
    }

public:
    RangeModeQuery(vector<int> &inputArr) : arr(inputArr) {}

    vector<int> processQueries(vector<Query> &queries) {
        int n = arr.size();
        int q = queries.size();
        result.resize(q);
        currentMode = 0;
        freq.clear();
        freqCount.clear();
        freqCount[0] = n;

        sort(queries.begin(), queries.end(), compare);

        int L = 0, R = -1;

        for (const auto &query : queries) {
            while (R < query.R) add(arr[++R]);
            while (R > query.R) remove(arr[R--]);
            while (L < query.L) remove(arr[L++]);
            while (L > query.L) add(arr[--L]);

            result[query.idx] = currentMode;
        }

        return result;
    }
};

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<Query> queries(q);
    int left[n],right[n];
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].L >> queries[i].R;
        queries[i].L--;queries[i].R--;
        left[i] = queries[i].L;
        right[i] = queries[i].R;
        queries[i].idx = i;
    }

    RangeModeQuery rmq(arr);
    vector<int> answers = rmq.processQueries(queries);
   
    int i =0;
    for (int mx : answers){
        int len = right[i]-left[i]+1;
        int ans = 0;
        int should = (len+1)/2;
        //whatis2(should,mx);
        if(should>=mx){
            cout<<1<<'\n';
            i++;
            continue;
        }
        int can = (len-mx)*2LL;
        if(can<mx){
            ans+=(len-mx);
            ans+=(mx - can);
            cout<<ans<<'\n';
            i++;
            continue;
        }
        int has = (len-mx)+1;
        ans = mx - has;
        cout<<ans+1<<'\n';

        i++;
    }
    
    return 0;
}   