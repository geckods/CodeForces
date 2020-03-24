#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,d;
    cin>>n>>m>>d;

    vector<ll> myVec;
    ll x;
    ll totplat;
    for(int i=0;i<myVec.size();i++){
    	cin>>x;
    	totplat+=x;
    	myVec.push_back(x);
    }

    //total jumpable distance = (m+1)*d + sigma platformlen - m >= n+1

    if((m+1)*d+totplat-x>=n+1){
    	cout<<"YES"<<endl;
    }
    else{
    	cout<<"NO"<<endl;
    }
}