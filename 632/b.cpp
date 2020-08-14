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

    // =

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll b[n];
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        bool hasPos=false;
        bool hasMin=false;

        bool works=true;
        for(int i=0;i<n;i++){
            if(a[i]==b[i]){

            }
            else if(a[i]<b[i] && !hasPos){
                works=false;
                break;
            }
            else if(a[i]>b[i] && !hasMin){
                works=false;
                break;
            }
            if(a[i]>0)hasPos=true;
            if(a[i]<0)hasMin=true;
        }
        if(works){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}