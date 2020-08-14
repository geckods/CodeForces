#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// THINGS TO REMEMBER
// ENDL is slow, '\n' is fast
// Clear everything (including graphs) between test cases
// use anti-anti-hash: https://codeforces.com/blog/entry/62393
// pb-ds: https://codeforces.com/blog/entry/11080
// check when to use LLONG_MAX/LLONG_MIN vs INT_MAX or INT_MIN
// You frequently suffer from confirmation bias - you trust your initial solution and miss simple things. 
// When you hit a roadblock, remember to rethink the solution ground up, not just try hacky fixes

int main(){
	
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
        ll n,m;
        cin>>n>>m;

        ll arr[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }

        ll ans=LLONG_MAX;

        ll c1,c2,toBe;

        for(int fixi=0;fixi<n;fixi++){
            for(int fixj=0;fixj<m;fixj++){
                ll minians=0;

                ll tldp[n][m];
                ll tltb[n][m];

                tldp[fixi][fixj]=0;
                tltb[fixi][fixj]=arr[fixi][fixj];

                ll brdp[n][m];
                ll brtb[n][m];

                brdp[fixi][fixj]=0;
                brtb[fixi][fixj]=arr[fixi][fixj];

                for(int ipj=fixi+fixj-1;ipj>=0;ipj--){
                    for(int i=0;i<=fixi;i++){
                        // can constant improve here
                        int j=ipj-i;
                        if(j>fixj||j<0)continue;

                        toBe=arr[fixi][fixj]-(fixi+fixj-ipj);

                        if(arr[i][j]<toBe){
                            tldp[i][j]=LLONG_MAX;
                            continue;
                        }

                        if(i==fixi){
                            if(tldp[i][j+1]==LLONG_MAX)tldp[i][j]=LLONG_MAX;
                            else tldp[i][j]=tldp[i][j+1]+arr[i][j]-toBe;
                        }
                        else if (j==fixj){
                            if(tldp[i+1][j]==LLONG_MAX)tldp[i][j]=LLONG_MAX;
                            else tldp[i][j]=tldp[i+1][j]+arr[i][j]-toBe;
                        }
                        else{
                            c1=tldp[i][j+1];
                            c2=tldp[i+1][j];
                            if(c1<c2){
                                if(tldp[i][j+1]==LLONG_MAX)tldp[i][j]=LLONG_MAX;
                                else tldp[i][j]=tldp[i][j+1]+arr[i][j]-toBe;
                            }
                            else{
                                if(tldp[i+1][j]==LLONG_MAX)tldp[i][j]=LLONG_MAX;
                                else tldp[i][j]=tldp[i+1][j]+arr[i][j]-toBe;
                            }
                        }
                        // cerr<<fixi<<" "<<fixj<<" "<<i<<" "<<j<<" "<<tldp[i][j]<<endl;

                    }
                }


                for(int ipj=fixi+fixj+1;ipj<=n+m-2;ipj++){
                    for(int i=fixi;i<n;i++){
                        // can constant improve here
                        int j=ipj-i;
                        if(j<fixj||j>=m)continue;

                        toBe=arr[fixi][fixj]+(ipj-fixi-fixj);

                        if(arr[i][j]<toBe){
                            brdp[i][j]=LLONG_MAX;
                            continue;
                        }

                        if(i==fixi){
                            if(brdp[i][j-1]==LLONG_MAX)brdp[i][j]=LLONG_MAX;
                            else brdp[i][j]=brdp[i][j-1]+arr[i][j]-toBe;
                        }
                        else if (j==fixj){
                            if(brdp[i-1][j]==LLONG_MAX)brdp[i][j]=LLONG_MAX;
                            else brdp[i][j]=brdp[i-1][j]+arr[i][j]-toBe;
                        }
                        else{
                            c1=brdp[i][j-1];
                            c2=brdp[i-1][j];
                            if(c1<c2){
                                if(brdp[i][j-1]==LLONG_MAX)brdp[i][j]=LLONG_MAX;
                                else brdp[i][j]=brdp[i][j-1]+arr[i][j]-toBe;
                            }
                            else{
                                if(brdp[i-1][j]==LLONG_MAX)brdp[i][j]=LLONG_MAX;
                                else brdp[i][j]=brdp[i-1][j]+arr[i][j]-toBe;
                            }
                        }

                    }
                }

                if(tldp[0][0]==LLONG_MAX || brdp[n-1][m-1]==LLONG_MAX){
                    continue;
                }
                // cerr<<fixi<<" "<<fixj<<" "<<tldp[0][0]<<" "<<brdp[n-1][m-1]<<endl;
                ans=min(ans,tldp[0][0]+brdp[n-1][m-1]);



            }
        }

        cout<<ans<<endl;


    }
}