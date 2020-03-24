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

    int onecount=0;

    int a;
    for(int i=0;i<n;i++){
    	cin>>a;
    	if(a==1) onecount++;
    }

    int twocount = n-onecount;

    if(twocount > 0){
    	twocount--;
    	cout<<2<<" ";
    }
    if(onecount > 0){
    	onecount--;
    	cout<<1<<" ";
    }
    while(twocount > 0){
    	twocount--;
    	cout<<2<<" ";
    }
    while(onecount>0){
    	onecount--;
    	cout<<1<<" ";
    }
}
