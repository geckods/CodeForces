#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

#define endl '\n'

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
        ll n;
        cin>>n;

        // when you come into play
        // you have one round of 01ull 1ull0 1ull1ull
        // then you alternate 00,00,00 , 01ull,1ull0,1ull1ull, 1ull0,1ull1ull,01ull , 1ull1ull,01ull,1ull0

        ll x=1ull;
        ll y=0;

        while(n>=x){
            y++;
            x=x<<2ull;
        }

        ll ans=0;
        for(ll i=0;i<y;i++){
            // 0th set is last 2ull bits
            ll numsInPlay=n-(1ull<<(2ull*i));
            ll firstPart=(1ull<<(2ull*i+2ull))-(1ull<<(2ull*i));

            // cerr<<i<<" "<<numsInPlay<<" "<<firstPart<<endl;
            ll temp=0;
            if(numsInPlay<firstPart){
                switch(numsInPlay%3ull){
                    case(0):
                        temp=1ull;
                        break;
                    case(1ull):
                        temp=2ull;
                        break;
                    case(2ull):
                        temp=3ull;
                        break;
                }
            }
            else{
                numsInPlay-=firstPart;
                switch((numsInPlay/firstPart)%4){
                    case(0):
                        temp=0;
                        break;
                    case(1ull):
                        switch(numsInPlay%3ull){
                            case(0):
                                temp=1ull;
                                break;
                            case(1ull):
                                temp=2ull;
                                break;
                            case(2ull):
                                temp=3ull;
                                break;
                        }
                        break;
                    case(2ull):
                        switch(numsInPlay%3ull){
                            case(0):
                                temp=2ull;
                                break;
                            case(1ull):
                                temp=3ull;
                                break;
                            case(2ull):
                                temp=1ull;
                                break;
                        }
                        break;
                    case(3ull):
                        switch(numsInPlay%3ull){
                            case(0):
                                temp=3ull;
                                break;
                            case(1ull):
                                temp=1ull;
                                break;
                            case(2ull):
                                temp=2ull;
                                break;
                        }
                        break;
                }
            }

            ans|=temp<<(2ull*i);
            // 0->3ull
            // 1ull->1ull2ull
        }
        cout<<ans<<endl;
    }
}