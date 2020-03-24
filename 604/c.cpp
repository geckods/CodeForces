#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define m 998244353

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
ll modexp(ll x, ll n) 
{ 
    if (n == 0) { 
        return 1; 
    } 
    else if (n % 2 == 0) { 
        return modexp((x * x) % m, n / 2); 
    } 
    else { 
        return (x * modexp((x * x) % m, (n - 1) / 2) % m); 
    } 
} 
  
// Function to return the fraction modulo mod 
ll getFractionModulo(ll a, ll b) 
{ 
    ll c = gcd(a, b); 
  
    a = a / c; 
    b = b / c; 
  
    // (b ^ m-2) % m 
    ll d = modexp(b, m - 2); 
  
    // Final answer 
    ll ans = ((a % m) * (d % m)) % m; 
  
    return ans; 
} 

int main(){
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
        freopen("error", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q;
    cin>>n>>q;

    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    ll prefixmult[n][2];
    prefixmult[0][0]=arr[0];
    prefixmult[0][1]=100;

    for(int i=1;i<n;i++){
        prefixmult[i][0]=(arr[i]*prefixmult[i-1][0])%m;
        prefixmult[i][1]=(100*prefixmult[i-1][1])%m;
    }

    

}


}


