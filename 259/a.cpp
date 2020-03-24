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

    int n;
    cin>>n;
    for(int i=0;i<n/2;i++){
    	for(int j=0;j<n/2-i;j++){
    		cout<<"*";
    	}
    	for(int j=0;j<2*i+1;j++){
    		cout<<"D";
    	}
    	for(int j=0;j<n/2-i;j++){
    		cout<<"*";
    	}
    	cout<<endl;
    }

    for(int j=0;j<n;j++){
    	cout<<"D";
    }
    cout<<endl;

    for(int i=1;i<=n/2;i++){
    	for(int j=0;j<i;j++){
    		cout<<"*";
    	}
    	for(int j=0;j<2*((n/2)-i)+1;j++){
    		cout<<"D";
    	}
    	for(int j=0;j<i;j++){
    		cout<<"*";
    	}
    	cout<<endl;
    }


}
