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

  	int t;
  	cin>>t;
  	for(int test=0;test<t;test++){
  		int n;
  		cin>>n;
  		string s;
  		cin>>s;

  		int earl=-1;
  		int lat=-1;
  		for(int i=0;i<n;i++){
  			if(s[i]=='1'){
  				earl=i;
  				break;
  			}
  		}

  		for(int i=n-1;i>=0;i--){
  			if(s[i]=='1'){
  				lat=i;
  				break;
  			}
  		}

  		// cout<<earl<<" "<<lat<<endl;

  		if(earl==lat&&lat==-1){
  			int ans=n;
  			cout<<ans<<endl;
  			continue;
  		}

  		int ans=n;
  		ans=max(ans,(lat-earl+1)*2);
  		ans=max(ans,(lat+1)*2);
  		ans=max(ans,(n-earl)*2);
  		cout<<ans<<endl;
  	}
}