#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll func(ll finalx,ll initx, ll cyclex, ll finaly, ll inity, ll cycley, ll c){
	return abs(finalx-(initx+cyclex*c))+abs(finaly-(inity+cycley*c));
}

int binsearch(ll finalx,ll initx, ll cyclex, ll finaly, ll inity, ll cycley, ll l, ll r,ll prevmid){
	ll mid=l+(r-l)/2;
	if(mid==prevmid){
		return mid;
	}
	ll leftval = func(finalx,initx,cyclex,finaly,inity,cycley,mid-1);
	ll midval = func(finalx,initx,cyclex,finaly,inity,cycley,mid);
	ll rightval = func(finalx,initx,cyclex,finaly,inity,cycley,mid+1);
//	cout<<mid<<" "<<leftval<<" "<<midval<<" "<<rightval<<endl;
	if(midval<=leftval && midval<=rightval){
		return mid;
	}
	else if (midval<=leftval){
		return binsearch(finalx,initx,cyclex,finaly,inity,cycley,mid,r,mid);
	}
	else{
		return binsearch(finalx,initx,cyclex,finaly,inity,cycley,l,mid-1,mid);		
	}
}

ll func2(ll finalx,ll initx, ll cyclex, ll finaly, ll inity, ll cycley, ll c,ll n){
	if(c==-1){
		return 0;
	}
	if(abs(finalx-(initx+cyclex*c))+abs(finaly-(inity+cycley*c)) > c*n)
			return 0;
	else
		return 1;
}

ll binsearch2(ll finalx,ll initx, ll cyclex, ll finaly, ll inity, ll cycley, ll l, ll r,ll prevmid,ll n){
	ll mid=l+(r-l)/2;
	if(mid==prevmid){
		return mid;
	}
	ll leftval = func2(finalx,initx,cyclex,finaly,inity,cycley,mid-1,n);
	ll midval = func2(finalx,initx,cyclex,finaly,inity,cycley,mid,n);
//	cout<<mid<<" "<<leftval<<" "<<midval<<" "<<rightval<<endl;
	if(midval==1 && leftval==0){
		return mid;
	}
	else if (midval==0){
		return binsearch2(finalx,initx,cyclex,finaly,inity,cycley,mid+1,r,mid,n);
	}
	else{
		return binsearch2(finalx,initx,cyclex,finaly,inity,cycley,l,mid,mid,n);
	}
}


int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    ll x,y,targx,targy;
    cin>>x>>y;
    cin>>targx>>targy;

    ll n;
    cin>>n;

    string s;
    cin>>s;

    char ch;
    ll dist;
    ll initx=x,inity=y;
    ll initdist=abs(targy-y)+abs(targx-x);
    ll i=0,j=0;

    while(1){
    	i=j%n;
    	if(j%n==0 && j>0){
    		break;
/*
    		if(dist>=initdist+j){
    			cout<<-1<<endl;
    			return 0;
    		}
*/
    	}
    	ch=s[i];
    	if(ch=='U'){
    		y++;
    	}
    	if(ch=='L'){
    		x--;
    	}
    	if(ch=='R'){
    		x++;
    	}
    	if(ch=='D'){
    		y--;
    	}
    	dist=abs(targy-y)+abs(targx-x);
//    	cout<<j<<" "<<x<<" "<<y<<" "<<dist<<endl;
    	if(dist==j){
    		cout<<j+1<<endl;
    		return 0;
    	}
    	else if (dist==j-1){
    	    cout<<j<<endl;
    		return 0;	
    	}
    	j++;
    }
/*
    int onlyoneupdown=0,onlyonerightleft=0;
    if((hasu&&!hasd)||(hasd&&!hasu)||(!hasu&&!hasd))
    	onlyoneupdown = 1;
    if((hasr&&!hasl)||(hasl&&!hasr)||(!hasl&&!hasr))
    	onlyonerightleft = 1;

    int nofree=min(hasu,hasd)+min(hasl,hasr);
*/



    if(initdist+n==dist){
    	cout<<-1<<endl;
    	return 0;
    }
    else{
    	ll cyclex = x-initx;
    	ll cycley = y-inity;

//    	for(int i=0;i<10;i++){
//    		cout<<func(targx,initx,cyclex,targy,inity,cycley,i)<<" ";
//    	}
    	ll noofcycles = binsearch2(targx,initx,cyclex,targy,inity,cycley,-1,100000000000,-1,n)-1;
//    	cout<<noofcycles<<endl;
    	x = initx+cyclex*noofcycles;
    	y = inity+cycley*noofcycles;
    	ll count =  noofcycles*n;
    	j=0;

    	if(targy==1000000000 && targx == 1000000000){
//    		cout<<noofcycles<<" "<<cyclex<<" "<<cycley<<" "<<x<<" "<<y<<endl;
    	}
//    	cout<<initx<<inity<<cyclex<<cycley<<endl;
//    	cout<<x<<y<<endl;
    	while(1){
    		i=j%n;
	    	if(j==2*n){
	    		cout<<-1<<endl;
    			return 0;
	    	}
    		ch=s[i];
    		if(ch=='U'){
	    		y++;
    		}
   		 	if(ch=='L'){
    			x--;
    		}
    		if(ch=='R'){
    			x++;
    		}
    		if(ch=='D'){
    			y--;
    		}
    		dist=abs(targy-y)+abs(targx-x);
//    		cout<<j<<" "<<x<<" "<<y<<" "<<dist<<" "<<j+count<<endl;
		 	if(dist==j+count+1){
    			cout<<count+j+1<<endl;
    			return 0;
    		}
	    	else if (dist==count+j){
   		 	    cout<<count+j+1<<endl;
    			return 0;
    		}
	    	j++;
    	}
    	//need to run the cycle until it reaches, then read the string backwards
    }
}