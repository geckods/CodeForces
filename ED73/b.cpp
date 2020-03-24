#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if((i+j)%2==0){
    			cout<<"W";
    		}
    		else{
    			cout<<"B";
    		}
    	}
    	cout<<endl;
    }
}