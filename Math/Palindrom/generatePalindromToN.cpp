// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define MX 100005

using namespace std;
using ll = long long;
ll A[MX];
ll createPalindrome(ll input, ll b, bool isOdd)
{
    ll n = input;
    ll palin = input;
 
    // checks if number of digits is odd or even
    // if odd then neglect the last digit of input in
    // finding reverse as in case of odd number of
    // digits middle element occur once
    if (isOdd)
        n /= b;
 
    // Creates palindrome by just appending reverse
    // of number to itself
    while (n > 0)
    {
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}
 
// Function to print decimal palindromic number
void generatePalindromes(int count)
{
    ll number;
 
    // Run two times for odd and even length palindromes
    for (int j = 1; j < 2; j++)
    {
        // Creates palindrome numbers with first half as i.
        // Value of j decided whether we need an odd length
        // of even length palindrome.
        int i = 1;
        while ( i< count)
        {
        	number = createPalindrome(i, 10, j % 2);
        	A[i]=number;
            i++;
        }
    }
}
int powMod(ll b,ll p){
	ll res = 1;
	while(p>0){
		if(p&1)
		{
			res = (res*b)%mod;
		}
		b = (b*b)%mod;
		p=p>>1;
	}
	return res;
}
void solve(int caseno){
    ll l,r;
    cin>>l>>r;
    ll al = A[l]-A[l-1];
    ll pw = A[r]-A[l];
    ll ans = powMod(al,pw);
    cout<<ans%mod<<'\n';
   
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    A[0] = 0;
    generatePalindromes(MX);
  //  sort(A,A+MX);
    for(int i=1; i<MX; i++) {
    	A[i] += A[i-1];
    }
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}