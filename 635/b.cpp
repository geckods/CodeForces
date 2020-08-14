#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

ll mysq(ll x){
	return x*x;
}

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
    	// cerr<<t<<endl;
    	ll nr,ng,nb;
    	cin>>nr>>ng>>nb;
    	ll red[nr];
    	ll green[ng];
    	ll blue[nb];
    	for(int i=0;i<nr;i++){
    		cin>>red[i];
    	}

    	for(int i=0;i<ng;i++){
    		cin>>green[i];
    	}

    	for(int i=0;i<nb;i++){
    		cin>>blue[i];
    	}

    	sort(red,red+nr);
    	sort(green,green+ng);
    	sort(blue,blue+nb);

    	// for each combination, two pointers it, find best value of third
    	int rp=0;
    	int gp=0;
    	int bp=0;

    	ll ans=LLONG_MAX;



    	while(rp<nr || gp<ng){
    		ll mid=(red[rp]+green[gp])/2;
    		int currBlue=upper_bound(blue,blue+nb,mid)-blue;
    		// cerr<<currBlue<<endl;
    		if(currBlue<nb){
    			ans=min(ans,mysq(red[rp]-green[gp])+mysq(red[rp]-blue[currBlue])+mysq(blue[currBlue]-green[gp]));
    		}
    		if(currBlue>0){
    			currBlue--;
    			ans=min(ans,mysq(red[rp]-green[gp])+mysq(red[rp]-blue[currBlue])+mysq(blue[currBlue]-green[gp]));
    		}


	    	// cerr<<t<<" "<<rp<<" "<<gp<<" "<<ans<<endl;

    		if(gp==ng-1 && rp==nr-1)break;

    		if(rp<nr-1 && (gp==ng-1 || red[rp]<green[gp])){
    			// cerr<<"HI"<<" "<<nr-1<<endl;
    			rp++;
    		}
    		else if (rp==nr-1 || red[rp]>green[gp])gp++;
    		else{
    			// cerr<<"HI"<<endl;
    			if(red[rp+1]<green[gp+1])rp++;
    			else gp++;
    		}
    	}

    	// cerr<<t<<" "<<ans<<endl;


    	rp=0;
    	gp=0;
    	bp=0;

    	while(rp<nr || bp<nb){
    		ll mid=(red[rp]+blue[bp])/2;
    		int currGreen=upper_bound(green,green+ng,mid)-green;
    		if(currGreen<ng){
    			ans=min(ans,mysq(red[rp]-green[currGreen])+mysq(red[rp]-blue[bp])+mysq(blue[bp]-green[currGreen]));
    		}
    		if(currGreen>0){
    			currGreen--;
    			ans=min(ans,mysq(red[rp]-green[currGreen])+mysq(red[rp]-blue[bp])+mysq(blue[bp]-green[currGreen]));
    		}

    		if(rp==nr-1 && bp==nb-1)break;



    		if(rp<nr-1 && (bp==nb-1 || red[rp]<blue[bp]))rp++;
    		else if (rp==nr-1 || red[rp]>blue[bp])bp++;
    		else{
    			if(red[rp+1]<blue[bp+1])rp++;
    			else bp++;
    		}
    	}

    	rp=0;
    	gp=0;
    	bp=0;

    	while(gp<ng || bp<nb){
    		ll mid=(green[gp]+blue[bp])/2;
    		int currRed=upper_bound(red,red+nr,mid)-red;
    		if(currRed<nr){
    			ans=min(ans,mysq(red[currRed]-green[gp])+mysq(red[currRed]-blue[bp])+mysq(blue[bp]-green[gp]));
    		}
    		if(currRed>0){
    			currRed--;
    			ans=min(ans,mysq(red[currRed]-green[gp])+mysq(red[currRed]-blue[bp])+mysq(blue[bp]-green[gp]));
    		}

    		if(gp==ng-1 && bp==nb-1)break;


    		if(gp<ng-1 && (bp==nb-1 || green[gp]<blue[bp]))gp++;
    		else if (gp==ng-1 || green[gp]>blue[bp])bp++;
    		else{
    			if(green[gp+1]<blue[bp+1])gp++;
    			else bp++;
    		}
    	}
    	cout<<ans<<endl;
    }
}