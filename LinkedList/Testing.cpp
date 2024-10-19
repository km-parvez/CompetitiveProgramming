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
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void printList(ListNode *head){
    ListNode *cur = head;
    while(cur!=nullptr){
        cout<<cur->val<<'\n'; 
        cur= cur->next;
    }
    cout<<'\n';
    return;
}
ListNode *insertAtFirst(ListNode *head,int val){
    ListNode *nw = new ListNode();
    nw->val = val;
    nw->next = head;
    return nw;  
}
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1==nullptr)return list2;
    if(list2==nullptr)return list1;
    if(list1->val<=list2->val){
        list1->next = mergeTwoLists(list1->next,list2);
        return list1;
    }
    else{
        list2->next = mergeTwoLists(list1,list2->next);   
        return list2;
    }
}   
ListNode* deleteDuplicates(ListNode* head) {
    if(head==nullptr)return head;
    
    ListNode* cur  = head;
    while(cur->next!=nullptr){
        if(cur->val == cur->next->val){
            cur->next = cur->next->next;
        }
        else{
            cur= cur->next;
        }
    }   
    return head;
}
bool hasCycle(ListNode *head) {
    if(head==nullptr || head->next==nullptr){
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while(fast!=nullptr&&fast->next!=nullptr){
        if(slow==fast){
            return true;
        }
        slow= slow->next;
        fast = fast->next->next;
    }
    return false;
}
ListNode* removeElements(ListNode* head, int val) {
    if(head == nullptr)return head;
    ListNode* cur = new ListNode(-1);
    cur->next = head;
    ListNode* newHead = new ListNode();
    newHead = cur;
    while(cur!=nullptr && cur->next!=nullptr ){
        if(cur->next->val == val){
            cur->next = cur->next->next;
        }
        else{
            cur = cur->next;
        }
    }
    return newHead->next;
}



void solve(int caseno){
    int counter = 300;
    ListNode *a = new ListNode();
    ListNode *b = new ListNode();
    ListNode *c = new ListNode();
    a->val = 1;
    b->val = 2;
    c->val = 4;

    a->next = b;
    b->next = c;

    ListNode *x = new ListNode();
    ListNode *y = new ListNode();
    ListNode *z = new ListNode();
    x->val = 1;
    y->val = 3;
    z->val = 4;

    x->next = y;
    y->next = z;

    ListNode *prv = nullptr;
    ListNode *cur = a;
   // printList(a);
    a = insertAtFirst(a,1);
    printList(a);
    printList(x);
    ListNode* list3 = mergeTwoLists(a,x);
    printList(list3);
    ListNode* ans = removeElements(list3,1);
    printList(ans);
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