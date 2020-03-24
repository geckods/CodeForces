#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool works(ll arr[], ll n, ll k, ll x, ll y, ll a, ll b, ll g){

    ll xs=0;
    ll ys=0;
    ll twos=0;  

    ll fa=a-1;
    ll fb=b-1;

    ll curr;
    while(min(fa,fb)<=g){
        curr=min(fa,fb);
        if(curr==fa){
            if(curr==fb){
                twos++;
                fa+=a;
                fb+=b;
            }
            else{
                xs++;
                fa+=a;
            }
        }
        if(curr==fb){
            ys++;
            fb+=b;
        }
    }

    curr=0;
    for(int i=0;i<twos;i++){
        curr+=(arr[i]/100)*(x+y);
    }
    if(x>y){
        for(int i=twos;i<twos+xs;i++){
            curr+=(arr[i]/100)*(x);
        }
        for(int i=twos+xs;i<twos+xs+ys;i++){
            curr+=(arr[i]/100)*(y);
        }
    }
    else{
        for(int i=twos;i<twos+ys;i++){
            curr+=(arr[i]/100)*(y);
        }
        for(int i=twos+ys;i<twos+xs+ys;i++){
            curr+=(arr[i]/100)*(x);
        }        
    }

    // cerr<<"CURR"<<curr<<" "<<k<<endl;
    if(curr>=k){
        return true;
    }
    else{
        return false;
    }
}


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

    for(int quer=0;quer<q;quer++){
        ll n;
        cin>>n;
        ll p[n];
        for(int i=0;i<n;i++){
            cin>>p[i];
        }

        sort(p,p+n);
        reverse(p,p+n);

        ll x,a,y,b;
        cin>>x>>a;
        cin>>y>>b;
        ll k;
        cin>>k;

        ll bmin=0;
        ll bmax=n-1;
        ll bmid;
        while(bmin<bmax){
            bmid=(bmin+bmax)/2;
            // cerr<<bmin<<" "<<bmax<<" "<<bmid<<endl;
            // cerr<<bmid<<" "<<works(p,n,k,x,y,a,b,bmid)<<endl;
            if(works(p,n,k,x,y,a,b,bmid)){
                bmax=bmid;
            }
            else{
                bmin=bmid+1;
            }
        }

        if(bmin==n-1){
            if(works(p,n,k,x,y,a,b,n-1)){
                cout<<n<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
        else{
            cout<<bmin+1<<endl;
        }

    }
}