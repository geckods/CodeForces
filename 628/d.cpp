#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll u,v;
    cin>>u>>v;

    if(u>v){
    	cout<<-1<<endl;
    	return 0;
    }

    //at the right most, sum cannot be 0 when xor is 1


    //with msb, build higher part
    //if sum is even in that position,

    //it should always be at max 3

    ll reqcount[63];
    memset(reqcount,0,sizeof(reqcount));
    bool sendCarry=false;
    for(int i=0;i<63;i++){
    	bool hasX=(u>>i)&1;
    	bool hasS=(v>>i)&1;
    	// cerr<<i<<" "<<hasS<<" "<<hasX<<" "<<sendCarry<<endl;
    	if(sendCarry){
    		if(hasS){
    			if(hasX){
    				reqcount[i]++;
    				reqcount[i-1]+=2;
    				sendCarry=true;
    			}
    			else{
    				sendCarry=false;
    			}
    		}
    		else{
    			if(hasX){
    				reqcount[i]++;
    				sendCarry=true;    				
    			}
    			else{
    				reqcount[i-1]+=2;
    				sendCarry=true;
    			}    			
    		}

    	}
    	else{
    		if(hasS){
    			if(hasX){
    				reqcount[i]++;
    				sendCarry=false;
    			}
    			else{
    				if(i==0){
    					cout<<-1<<endl;
    					return 0;
    				}
    				reqcount[i-1]+=2;
    				sendCarry=false;
    			}
    		}
    		else{
    			if(hasX){
    				reqcount[i]++;
    				if(i==0){
    					cout<<-1<<endl;
    					return 0;
    				}
    				reqcount[i-1]+=2;
    				sendCarry=true;
    			}
    			else{
    				sendCarry=false;    				//do nothing
    			}    			
    		}
    	}
    }

    if(sendCarry){
    	cout<<-1<<endl;
    	return 0;
    }

    ll maxBits=0;
	for(int i=0;i<63;i++){
		maxBits=max(maxBits,reqcount[i]);
	}
	cout<<maxBits<<endl;

    vector<ll> ansVec;
    while(1){
    	maxBits=0;
    	ll temp=0;
    	for(int i=0;i<63;i++){
    		maxBits=max(maxBits,reqcount[i]);
    	}
    	if(maxBits==0)break;
    	for(int i=0;i<63;i++){
    		if(reqcount[i]>0){
    			reqcount[i]--;
    			temp|=(1ll<<i);
    			// cerr<<i<<" "<<(1<<i)<<endl;
    		}
    	}
    	// cerr<<temp<<endl;

    	ansVec.push_back(temp);
    }

    for(int i=0;i<ansVec.size();i++){
    	cout<<ansVec[i]<<" ";
    }
    cout<<endl;
}