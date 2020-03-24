#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll setBitNumber(ll n) 
{ 
    n |= n >> 1; 
  
    n |= n >> 2; 
  
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
  
    n = n + 1; 
    return (n >> 1); 
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
    	ll n;
    	cin>>n;
    	ll p[n];
    	for(int i=0;i<n;i++){
    		cin>>p[i];
    		p[i]--;
    	}

    	ll c[n];
    	for(int i=0;i<n;i++){
    		cin>>c[i];
    	}


    	bool checked[n];
    	memset(checked,false,sizeof(checked));

    	ll ans=n;
    	for(int i=0;i<n;i++){
    		// if(checked[i])continue;
    		vector<ll> temp;
    		temp.push_back(i);
    		ll curr=p[i];
    		while(curr!=i){
    			temp.push_back(curr);
    			checked[curr]=true;
    			curr=p[curr];
    		}
    		ans=min(ans,(ll)temp.size());
    	}
    	// 	if(temp.size()==1){
    	// 		ans=1;
    	// 		break;
    	// 	}

    	// 	// cerr<<i<<" "<<temp.size()<<endl;
    	// 	// for(int i=0;i<temp.size();i++){
    	// 	// 	cerr<<temp[i]<<endl;
    	// 	// }

    	// 	for(ll z=1;z<temp.size();z++){
    	// 		if(temp.size()%z!=0)continue;
	    // 		bool works=true;

    	// 		for(ll zz=0;zz<z;zz++){
    	// 			works=true;
    	// 			ll zzs=zz;
	    // 			while(zzs<temp.size()){
	    // 				if(c[temp[zzs]]==c[temp[zz]]){
		   //  				zzs+=z;
	    // 				}
	    // 				else{
	    // 					works=false;
	    // 					break;
	    // 				}
	    // 			}
	    // 			if(works)break;				
    	// 		}

    	// 		if(works){
    	// 			ans=min(ans,z);
    	// 		}
    	// 	}
    	// }
    	// cout<<ans<<endl;


    	//build binary lifting array
    	ll child[n][32]; //j represents the 2^jth child
    	for(int i=0;i<n;i++){
    		child[i][0]=p[i];
    	}

    	for(int i=1;i<32;i++){
    		for(int j=0;j<n;j++){
	    		child[j][i]=child[child[j][i-1]][i-1];
    		}
    	}

    	// for(int i=0;i<n;i++){
    	// 	cerr<<i<<" "<<child[i][1]<<endl;
    	// }

    	//setup binsearch
    	ll bmin=1;
    	ll bmax=n;
    	while(bmin<=n/2 && bmin<ans){

    		ll bmid=bmin;
    		//get the array
    		ll buildArray[n];
    		for(int i=0;i<n;i++){buildArray[i]=i;}
    		ll bmidc=bmid;
    		while(bmidc){
    			ll theSetBit=setBitNumber(bmidc);
    			ll theSetBitc=theSetBit;
    			int z=0;
    			while(!(theSetBit&1)){
    				z++;
    				theSetBit=theSetBit>>1;
    			}
    			// cerr<<z<<endl;
    			for(int i=0;i<n;i++){
    				buildArray[i]=child[buildArray[i]][z];
    			}
    			bmidc-=(theSetBitc);
    		}

    		// for(int i=0;i<n;i++){
    		// 	cerr<<i<<" "<<buildArray[i]<<endl;
    		// }


    		// return 0;
    		//have the array, check if it has a sequence

    		ll terminated[n];
    		memset(terminated,-1,sizeof(terminated));
    		bool works=false;
    		for(int i=0;i<n;i++){
    			int curr=buildArray[i];
    			while(c[curr]==c[i] && i!=curr){
    				if(terminated[curr]!=-1){
    					curr=terminated[curr];
    					break;
    				}
    				curr=buildArray[curr];
    			}
    			if(i==curr){
    				works=true;
    				break;
    			}
    			else{
    				ll theend=curr;
    				curr=i;
    				while(curr!=theend){
    					terminated[curr]=theend;
    					curr=buildArray[curr];
    				}
    			}
    		}

    		// cout<<bmid<<" "<<works<<endl;
    		// return 0;
    		if(works){
    			ans=min(ans,bmid);
    			break;
    		}
    		else{
    			bmin++;
    		}
    	}

    	cout<<ans<<endl;
    }
}