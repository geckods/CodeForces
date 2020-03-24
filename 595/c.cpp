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

    int q;
    cin>>q;

    for(int quer=0;quer<q;quer++){
    	ll n;
    	cin>>n;

    	ll ogn=n;

    	vector<ll> decomp;

    	while(n>0){
    		decomp.push_back(n%3);
    		n/=3;
    	}

    	// for(int i=0;i<decomp.size();i++){
    	// 	cout<<decomp[i]<<" ";
    	// }
    	// cout<<endl;

    	reverse(decomp.begin(),decomp.end());

    	int i;
    	for(i=0;i<decomp.size();i++){
    		if(decomp[i]==2)break;
    	}

    	int j;

    	for(j=i-1;j>=0;j--){
    		if(decomp[j]==0)break;
    	}

    	// for(int z=0;z<decomp.size();z++){
    	// 	cout<<decomp[z]<<" ";
    	// }
    	// cout<<endl;

    	// cout<<ogn<<" "<<i<<" "<<j<<endl;
    	//j is the last 0 followed by ones followed by 2

    	if(i==decomp.size()){
    		cout<<ogn<<endl;
    		continue;
    	}


    	if(j==-1){
    		ll ans=1;
    		for(int i=0;i<decomp.size();i++){
    			ans*=3;
    		}
    		cout<<ans<<endl;
    	}
    	else{
    		ll ans=0;
    		for(int z=0;z<j;z++){
    			ans+=decomp[z]*pow(3ll,decomp.size()-z-1);
    		}
    		ans+=pow(3ll,decomp.size()-j-1);
    		cout<<ans<<endl;
    	}
    	// cout<<endl;

    }
}