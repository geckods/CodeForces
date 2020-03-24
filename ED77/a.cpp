#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    ll c[n];
    ll s[n];
    for(int i=0;i<n;i++){
    	cin>>c[i]>>s[i];
    }

    for(int i=0;i<n;i++){
    	if(c[i]>=s[i]){
    		cout<<s[i]<<endl;
    	}
    	else{
    		//s>c
//    		s/c radiators will have s/c sections
//    		one radiator will 
    		ll min=s[i]/c[i];
    		//there are s%c extra
    		cout<<(c[i]-s[i]%c[i])*min*min+(s[i]%c[i])*(min+1)*(min+1)<<endl;
    	}
    }

}
