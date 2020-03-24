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

	int t;
	cin>>t;

	while(t--){
		string a,b,c;
		cin>>a>>b>>c;

		bool works=true;
		for(int i=0;i<a.length();i++){
			if(b[i]==c[i]||c[i]==a[i]){

			}
			else{
				works=false;
				break;
			}
		}

		if(works){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}

	} 

}
