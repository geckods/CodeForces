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
        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        bool done=false;
        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1])>=2){
                done=true;
                cout<<"YES"<<endl;
                cout<<i<<" "<<i+1<<endl;
                break;
            }
        }

        if(!done){
            cout<<"NO"<<endl;
        }

    }
}