#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);

  	ll n,p,w,d;
  	cin>>n>>p>>w>>d;

  	ll x0,y0,g;

  	ll a=w;
  	ll b=d;

  	if(!find_any_solution(a,b,p,x0,y0,g)){
  		cout<<-1<<endl;
  		return 0;
  	}

  	// cout<<x0<<" "<<y0<<" "<<g<<endl;

  	ll k2;

  	if(x0<0){
  		k2=(abs(x0)*g)/b;
  		if(b*k2 < g*abs(x0))k2++;
  		x0=x0+k2*(b/g);
  		y0=y0-k2*(a/g);

  		if(y0<0){
  			cout<<-1<<endl;
  			return 0;
  		}
  	}
  	else if (y0<0){
  		k2=(abs(y0)*g)/a;
  		if(a*k2 < g*abs(y0))k2++;
  		y0=y0+k2*(a/g);
  		x0=x0-k2*(b/g);

  		if(x0<0){
  			cout<<-1<<endl;
  			return 0;
  		}
  	}

  	// cout<<x0<<" "<<y0<<" "<<g<<endl;


  	ll newx,newy;
  	ll k;

  	k = (y0*g)/a;
  	newx=x0+k*(b/g);
  	newy=y0-k*(a/g);

  	if(newx+newy<=n){
  		cout<<newx<<" "<<newy<<" "<<n-(newx+newy)<<endl;
  	}
  	else{
  		cout<<-1<<endl;
  	}
}