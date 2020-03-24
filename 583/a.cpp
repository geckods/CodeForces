#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);      
} 


int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll n,d,e;
    cin>>n>>d>>e;

    ll ans=n;
    for(int i=0;i*d<=n;i++){
    	ans=min(ans,(n-d*i)%(5*e));
    }

    cout<<ans<<endl;
}
