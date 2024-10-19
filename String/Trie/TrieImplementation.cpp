// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define whatArray2D(arr,m,n) cout<<#arr<<", Size: "<<m<<","<<n<<'\n';for(int mm=0;mm<m;mm++){for(int nn=0;nn<n;nn++)cout<<arr[mm][nn]<<" ";cout<<'\n';} 
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'
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

#define int long long

// try binary search,BIT,segment tree, dp, dfs, union find, set, priority queue, sorting, two pointer, gready.
class TrieNode{
public:
    TrieNode* next[30];
    bool end;
    TrieNode() {
        end = false;
        for(int i=0; i<30; i++) {
            next[i] = nullptr;
        } 
    }
};
class Trie {
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(int i=0; i<word.size(); i++) {
            int ch = word[i]-'a';
            if(cur->next[ch]==nullptr){
                TrieNode* tmp = new TrieNode();
                cur->next[ch] = tmp;
            }
            cur = cur->next[ch];
        }
        cur->end=true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(int i=0; i<word.size(); i++) {
            int ch = word[i]-'a';
            if(cur->next[ch]==nullptr){
                return false;
            }
            cur = cur->next[ch];
        }
        if(cur->end){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i=0; i<prefix.size(); i++) {
            int ch = prefix[i]-'a';
            if(cur->next[ch]==nullptr){
                return false;
            }
            cur = cur->next[ch];
        }
        return true;  
    }
};



void solve(int caseno){
    int q;cin>>q;
    Trie* obj = new Trie();
    while(q--){
        int type;string s;
        cin>>type>>s;
        if(type==1){
            obj->insert(s);
        }
        else if(type==2){
            bool ans = obj->search(s);
            cout<<ans<<'\n';    
        }
        else{
            bool ans = obj->startsWith(s);
            cout<<ans<<'\n';
        }
    }
    return;
    
}
main()
{
    ios::sync_with_stdio(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}               