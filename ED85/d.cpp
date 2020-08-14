#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

int main(){

	// =
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t--){
        ll n,l,r;
        cin>>n>>l>>r;

        ll currRunner=1;
        ll nextSub=2*(n-currRunner);

        // cerr<<" "<<n<<" "<<l<<" "<<r<<" "<<currRunner<<" "<<nextSub<<endl;

        while(l>nextSub && currRunner<=n){
            // cerr<<t<<" "<<l<<" "<<r<<" "<<currRunner<<" "<<n<<endl;
            l-=nextSub;
            r-=nextSub;
            currRunner++;
            nextSub=2*(n-currRunner);
        }

        // cerr<<l<<" "<<r<<" "<<currRunner<<" "<<nextSub<<endl;
        if(currRunner==n+1){
            cout<<1<<endl;
        }
        else{
            while(r>nextSub && currRunner<n){
                // cerr<<l<<" "<<r<<" "<<currRunner<<" "<<nextSub<<" "<<n<<endl;
                ll curr=0;
                for(int i=0;i<nextSub;i++){
                    if(i%2==0)curr=currRunner;
                    else curr=currRunner+(i+1)/2;
                    if(l-1<=i)cout<<curr<<" ";
                }
                l-=nextSub;
                r-=nextSub;
                currRunner++;
                nextSub=2*(n-currRunner);
            }
            // in the next space

            // in the same space

            if(currRunner==n){
                cout<<1;
            }
            else{
                ll curr=0;
                for(int i=0;i<nextSub;i++){
                    if(i%2==0)curr=currRunner;
                    else curr=currRunner+(i+1)/2;
                    if(l-1<=i && r-1>=i)cout<<curr<<" ";
                }                
            }
            cout<<endl;
        }

    }
}