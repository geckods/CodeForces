#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//=

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
    	int n,k1,k2;
    	cin>>n>>k1>>k2;

    	int onemax=0;
    	int twomax=0;
    	int x;
    	for(int i=0;i<k1;i++){
    		cin>>x;
    		onemax=max(onemax,x);
    	}

    	for(int i=0;i<k2;i++){
    		cin>>x;
    		twomax=max(twomax,x);    		
    	}

    	if(onemax<twomax){
    		cout<<"NO"<<endl;
    	}
    	else{
    		cout<<"YES"<<endl;
    	}
    }
}
