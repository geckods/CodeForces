#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//=

int main(){
	
    ll n,k;
    cin>>n>>k;

    cout<<"?"<<" ";
    for(int i=1;i<=k;i++){
    	cout<<i<<" ";
    	// if(i<k)cout<<" ";
    }
    cout<<endl;

    fflush(stdout);
	cout.flush();

    ll ogpos,ogval;
    cin>>ogpos>>ogval;

    if(k==1){
    	cout<<"!"<<" "<<1<<endl;
    	fflush(stdout);
	    cout.flush();
    	return 0;
    }

    ll currknowaboutnext=0;//0->don't know if less or greater, //1 equals def less, 2 equals def greater

    ll arr[k];
    memset(arr,0,sizeof(arr));

    for(int i=1;i<=k;i++){

    	//remove the ith one.
    	if(i==ogpos)continue;

    	cout<<"?"<<" ";
    	for(int j=1;j<=k;j++){
    		if(j==i)continue;
    		cout<<j<<" ";
    	}
    	cout<<k+1<<" "<<endl;
	    fflush(stdout);
	    cout.flush();

	    ll pos,val;
	    cin>>pos>>val;

	    if(currknowaboutnext==0){
	    	// we don't know if k+1 is greater or less
	    	if(val==ogval){
	    		//no new info
	    		// continue;
	    	}
	    	else{
	    		if (val<ogval){
	    		//old was greater, new is less
		    		currknowaboutnext=1;
		    		arr[i-1]=2;
		    	}
		    	else{
		    		//old was less, new is greater
		    		currknowaboutnext=2;
		    		arr[i-1]=1;
			    }
			    for(int z=1;z<i;z++){
			    	if(z==ogpos)continue;
			    	arr[z-1]=currknowaboutnext;
			    }
		    }
	    }
	    else{
	    	if(currknowaboutnext==1){
	    		if(val<ogval){
	    			arr[i-1]=2;
	    		}
	    		else{
	    			arr[i-1]=1;	    			
	    		}
	    	}
	    	else{
	    		if(val>ogval){
	    			arr[i-1]=1;
	    		}
	    		else{
	    			arr[i-1]=2;	    			
	    		}	    		
	    	}
	    }
    	// cerr<<i<<" "<<currknowaboutnext<<endl;
    }

    if(currknowaboutnext==0){
    	// cerr<<"HI"<<endl;
    	cout<<"?"<<" ";
    	for(int i=1;i<=k+1;i++){
    		if(i==ogpos)continue;
    		cout<<i<<" ";
	    	// if(i<=k)cout<<" ";
    	}
    	cout<<endl;
    	fflush(stdout);
	    cout.flush();

    	ll pos,val;
    	cin>>pos>>val;
    	if(val<ogval){
    		cout<<"!"<<" "<<k<<endl;
    	}
    	else{
    		cout<<"!"<<" "<<1<<endl;
    	}
    	fflush(stdout);
	    cout.flush();
    	return 0;
    }

    ll lessthan=0;
    for(int i=1;i<=k;i++){
    	if(i==ogpos)continue;
    	if(arr[i-1]==1)lessthan++;
    }

    cout<<"!"<<" "<<lessthan+1<<endl;
    fflush(stdout);
	cout.flush();
    return 0;
}