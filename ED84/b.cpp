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
        vector<vector<ll>> matching;
        for(int i=0;i<n;i++){
            matching.push_back(vector<ll>());
            ll k,x;
            cin>>k;
            while(k--){
                cin>>x;
                x--;
                matching[i].push_back(x);
            }
        }

        bool seenKingdom[n];
        memset(seenKingdom,false,sizeof(seenKingdom));

        ll unMatchedPrincess=-1;


        for(int i=0;i<n;i++){
            bool done=false;
            for(int j=0;j<matching[i].size();j++){
                if(!seenKingdom[matching[i][j]]){
                    seenKingdom[matching[i][j]]=true;
                    done=true;
                    break;
                }
            }

            if(!done){
                unMatchedPrincess=i;
            }
        }

        if(unMatchedPrincess==-1){
            cout<<"OPTIMAL"<<endl;
        }
        else{
            cout<<"IMPROVE"<<endl;
            int z=0;
            while(seenKingdom[z])z++;
            cout<<unMatchedPrincess+1<<" "<<z+1<<endl;
        }
    }
}