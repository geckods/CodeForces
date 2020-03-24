#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void rat_approx(double f, ll md, ll *num, ll *denom)
{
    /*  a: continued fraction coefficients. */
    ll a, h[3] = { 0, 1, 0 }, k[3] = { 1, 0, 0 };
    ll x, d, n = 1;
    int i, neg = 0;

    if (md <= 1) { *denom = 1; *num = (ll) f; return; }

    if (f < 0) { neg = 1; f = -f; }

    while (f != floor(f)) { n <<= 1; f *= 2; }
    d = f;

    /* continued fraction and check denominator each step */
    for (i = 0; i < 64; i++) {
        a = n ? d / n : 0;
        if (i && !a) break;

        x = d; d = n; n = x % n;

        x = a;
        if (k[1] * a + k[0] >= md) {
            x = (md - k[0]) / k[1];
            if (x * 2 >= a || k[1] >= md)
                i = 65;
            else
                break;
        }

        h[2] = x * h[1] + h[0]; h[0] = h[1]; h[1] = h[2];
        k[2] = x * k[1] + k[0]; k[0] = k[1]; k[1] = k[2];
    }
    *denom = k[1];
    *num = neg ? -h[1] : h[1];
}
int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    bool likes[n];
    int a;
    for(int i=0;i<n;i++){
    	cin>>a;
    	if(a){
    		likes[i]=true;
    	}
    	else{
    		likes[i]=false;
    	}
    }

    int weights[n];

    int weightsum=0;
    for(int i=0;i<n;i++){
    	cin>>weights[i];
    	weightsum+=weights[i];
    }

    ll weightsums[n];
    for(int i=0;i<n;i++){
    	weightsums[i]=0;
    }

    int simulation;
    srand(time(0));
    for(simulation=0;simulation<1000000;simulation++){
    	int weightcopy[n];
    	int weightsumcopy=weightsum;
    	for(int i=0;i<n;i++){
    		weightcopy[i]=weights[i];
    	}

    	for(int i=0;i<m;i++){
    		int currweight=0;
    		int z;

    		int random = rand()%weightsumcopy;
    		for(z=0;z<n;z++){
    			currweight+=weightcopy[z];
    			if(currweight>random){
    				break;
    			}
    		}

    		// cout<<z<<endl;

    		if(likes[z]){ 
    			weightcopy[z]++;
    			weightsumcopy++;
    		}
    		else{ 
    			weightcopy[z]--;
    			weightsumcopy--;
    		}
    	}

    	for(int i=0;i<n;i++){
    		weightsums[i]+=weightcopy[i];
    	}
    }

    for(int i=0;i<n;i++){
    	cout<<(double)weightsums[i]/simulation<<endl;
    	ll a,b;
    	rat_approx((double)weightsums[i]/simulation,1e5,&a,&b);
    	cout<<a<<" "<<b<<endl;
    }
}