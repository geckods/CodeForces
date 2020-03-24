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

    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    ll trianglecount=0;
    ll unpairedcount=0;

    for(int i=0;i<n;i++){
    	ll curr = arr[i];

    	// trianglecount+=(curr/3);
    	// curr%=3;

    	// if(curr==2 && unpairedcount>0){
    	// 	unpairedcount--;
    	// 	trianglecount++;
    	// }
    	// else{
    	// 	unpairedcount+=curr;
    	// }

    	ll isocount = min(curr/2,unpairedcount);
    	trianglecount+=isocount;
    	unpairedcount-=isocount;

    	curr-=isocount*2;

    	trianglecount+=curr/3;
    	curr%=3;

    	unpairedcount+=curr;
    }

    cout<<trianglecount<<endl;
}