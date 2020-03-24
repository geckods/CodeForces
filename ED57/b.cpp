#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    string s;
    cin>>s;

    char first=s[0];
    char last=s[n-1];

    ll ans=0;

    ll firstnonfirst=-1;
    for(int i=0;i<n;i++){
    	if(s[i]!=first){
    		firstnonfirst=i;
    		break;
    	}
    }

    ll lastnonfirst=-1;

    for(int i=n-1;i>=0;i--){
    	if(s[i]!=first){
    		lastnonfirst=i;
    		break;
    	}
    }

    ll lastnonlast=-1;

    for(int i=n-1;i>=0;i--){
    	if(s[i]!=last){
    		lastnonlast=i;
    		break;
    	}
    }



    if(last==first){
    	ans=(firstnonfirst+1)*(n-lastnonfirst);
    }
    else{
    	ans+=(firstnonfirst)+(n-lastnonlast);
    }

    cout<<ans%MOD<<endl;
}