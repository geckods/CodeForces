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

    int q;
    cin>>q;

    for(int test=0;test<q;test++){
    	int arr[3];
    	cin>>arr[0]>>arr[1]>>arr[2];
    	sort(arr,arr+3);
    	cout<<max(2*(arr[2]-arr[0])-4,0)<<endl;
    }

}
