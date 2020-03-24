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
    	ll n;
    	cin>>n;

    	ll narr[n];
    	ll on=0;
    	ll om=0;
    	ll en=0;
    	ll em=0;
    	for(int i=0;i<n;i++){
    		cin>>narr[i];
    		if(narr[i]%2==0){
    			en++;
    		}
    		else{
    			on++;
    		}
    	}

    	ll m;
    	cin>>m;

    	ll arr[m];
    	for(int i=0;i<m;i++){
    		cin>>arr[i];
    		if(arr[i]%2==0){
    			em++;
    		}
    		else{
    			om++;
    		}
    	}

    	cout<<en*em+on*om<<endl;


    }
}
