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

    while(t--){
        ll n,m;
        cin>>n>>m;
        ll arr[m];
        ll bits[64] = {0};

        for(int i=0;i<m;i++){
            cin>>arr[i];
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<64;j++){
                if((arr[i]>>j)&1){
                    bits[j]++;
                    break;
                }
            }
        }


        bool works=true;
        ll ans=0;
        ll req;

        for(int i=0;i<64;i++){
            if((n>>i)&1){
                int j=i;
                bool miniworks=false;
                req=1;
                for(j=i;j>=0;j--){
                    if(bits[j]>=req){
                        miniworks=true;
                        break;
                    }
                    else{
                        req-=bits[j];
                    }
                    req*=2;
                }

                if(miniworks){
                    req=1;
                    for(int k=i;k>=j;k--){
                        if(bits[k]>=req){
                            bits[k]-=req;
                            break;
                        }
                        else{
                            req-=bits[k];
                            bits[k]=0;
                        }
                        req*=2;
                    }
                    continue;
                }

                //can't go down, must go up.
                for(j=i;j<64;j++){
                    if(bits[j])break;
                }

                if(j==64){
                    works=false;
                    break;
                }

                for(int k=j;k>i;k--){
                    bits[k]--;
                    bits[k-1]+=2;
                    ans++;
                }

                bits[i]--;
            }
        }
        // cerr<<endl;

        if(!works){
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }

    }
}    