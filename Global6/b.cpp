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

    for(int test=0;test<t;test++){
        ll x;
        cin>>x;

        if(x<15){
            cout<<"NO"<<endl;
            continue;
        }

        bool works=false;
        for(int a=15;a<=20;a++){
            if((x-a)%14==0){
                works=true;
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
