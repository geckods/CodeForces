#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pref[200][200001];

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
        int maxval=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            maxval=max(maxval,arr[i]);
            arr[i]--;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<maxval;j++){
                pref[j][i]=0;
            }
        }

        pref[arr[0]][0]++;

        for(int i=1;i<n;i++){
            for(int j=0;j<maxval;j++){
                pref[j][i]=pref[j][i-1];
            }
            pref[arr[i]][i]++;
        }



        // for(int i=0;i<n;i++){
        //     for(int j=0;j<3;j++){
        //         cerr<<i<<" "<<j<<" "<<pref[i][j]<<endl;
        //     }
        // }

        int ans=1;

        for(int i=0;i<maxval;i++){
            ans=max(ans,pref[i][n-1]);
            int curr=0;
            int back;
            for(int j=0;j<n;j++){
                if(pref[i][j]==curr)continue;
                // cerr<<j<<" "<<i<<" "<<curr<<endl;
                curr=pref[i][j];
                // starting index
                back=upper_bound(pref[i],pref[i]+n,pref[i][n-1]-curr)-pref[i];
                // cerr<<i<<" "<<curr<<" "<<j<<" "<<back<<endl;
                if(back<=j){
                    break;
                }
                int minians=0;
                for(int k=0;k<maxval;k++){
                    int temp=pref[k][back-1]-pref[k][j];
                    minians=max(minians,temp);
                }
                // cerr<<i<<" "<<j<<" "<<2*curr+minians<<endl;
                ans=max(ans,2*curr+minians);
            }
        }
        cout<<ans<<endl;
    }
}