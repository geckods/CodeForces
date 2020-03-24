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

    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    double darr[n];
    for(int i=0;i<n;i++){
    	darr[i]=(double)(arr[i]);
    }

    //just need to minimize first element -> if second element can be made smaller, then it doesnt make sense
    double cumave[n];
    cumave[0]=darr[0];
    for(int i=1;i<n;i++){
    	cumave[i]=cumave[i-1]+darr[i];
    	// cerr<<i<<" "<<cumave[i]<<endl;
    }

    // for(int i=0;i<n;i++){
    // 	cumave[i]/=(i+1);
    // }

    int mintoright[n];
    double minave[n];
    double rightave=0;
    int currminind=n-1;
    minave[n-1]=darr[n-1];
    int elemcount[n];
    elemcount[n-1]=1;

    double temp;

    for(int i=n-2;i>=0;i--){
    	if(darr[i]<minave[i+1]){
    		minave[i]=darr[i];
    		elemcount[i]=1;
    	}
    	else{
    		temp=(minave[i+1]*elemcount[i+1]+darr[i]);
    		if(elemcount[i+1]+i+1<n && minave[i+1+elemcount[i+1]] < temp/(elemcount[i+1]+1)){
    			minave[i]=(darr[i]+minave[i+1+elemcount[i+1]]*elemcount[i+1+elemcount[i+1]] + minave[i+1]*elemcount[i+1]);
    			elemcount[i]=elemcount[i+1]+1+elemcount[i+1+elemcount[i+1]];
    			minave[i]/=elemcount[i];
    		}
    		else{
    			minave[i]=temp/(elemcount[i+1]+1);
    			elemcount[i]=elemcount[i+1]+1;
    		}
    	}
    	cerr<<i<<" "<<darr[i]<<" "<<minave[i]<<" "<<elemcount[i]<<endl;
    }

    int i=0;
    while(i<n){
    	if(minave[i]<darr[i]){
    		for(int j=0;j<elemcount[i];j++){
    			cout<<setprecision(10)<<minave[i]<<endl;
    		}
    		i+=elemcount[i];
    	}
    	else{
    		cout<<setprecision(10)<<darr[i]<<endl;
    		i++;
    	}
    }

}