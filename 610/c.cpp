#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll,ll> intpair;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin>>m;

    while(m--){
        ll n,t,a,b;
        cin>>n>>t>>a>>b;
        vector<intpair> problem;

        ll hard[n];
        ll time[n];

        ll toteasycount=0;
        ll tothardcount=0;
        for(int i=0;i<n;i++){
            cin>>hard[i];
            toteasycount+=1;
            toteasycount-=hard[i];
            tothardcount+=hard[i];
        }

        for(int i=0;i<n;i++){
            cin>>time[i];
        }

        for(int i=0;i<n;i++){
            problem.push_back({time[i],hard[i]});
        }

        sort(problem.begin(),problem.end());



        ll ans=0;
        ll easycount=0;
        ll hardcount=0;
        // cerr<<m<<endl;
        ll minians=0;
        for(int i=0;i<n;i++){
            //considering i+1th problem
            // cerr<<i<<" "<<easycount<<" "<<hardcount<<endl;
            if(problem[i].first-1-easycount*a >= hardcount*b){
                minians=i;
                minians+=max(min((problem[i].first-1-easycount*a-hardcount*b)/a,toteasycount-easycount),min((problem[i].first-1-easycount*a-hardcount*b)/b,tothardcount-hardcount));
                ans=max(ans,(ll)minians);
            }
            if(problem[i].second==0){
                easycount++;
            }
            else{
                hardcount++;
            }
        }

        if(t>=easycount*a+hardcount*b){
            ans=n;
        }

        cout<<ans<<endl;

    }
}