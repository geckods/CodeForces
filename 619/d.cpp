#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string,int> moveobj;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,k;

    cin>>n>>m>>k;

    vector<moveobj> ansVec;

    if(k>4*n*m-2*n-2*m){
    	cout<<"NO"<<endl;
    	return 0;
    }
    else{
    	cout<<"YES"<<endl;
    	ll currcount=0;
    	if(n==1||m==1){
    		if(n==1){
    			if(currcount+m-1<=k){
    				ansVec.push_back({"R",m-1});
    				currcount+=m-1;
    			}
    			else{
    				ansVec.push_back({"R",k-currcount});
    				currcount=k; 				
    			}

    			if(currcount<k){
    				ansVec.push_back({"L",k-currcount});    				
    			}
    		}
    		else if (m==1){
    			if(currcount+n-1<=k){
    				ansVec.push_back({"D",n-1});
    				currcount+=n-1;
    			}
    			else{
    				ansVec.push_back({"D",k-currcount});
    				currcount=k; 				
    			}

    			if(currcount<k){
    				ansVec.push_back({"U",k-currcount});    				
    			}
    		}
    	}
    	else{
    		//first, go all the way right
    		if(currcount+m-1>=k){
	    		ansVec.push_back({"R",k-currcount});
	    		currcount=k;
    		}
    		else{
	    		ansVec.push_back({"R",m-1});
	    		currcount+=m-1;
    		}

    		bool left=true;
    		for(int i=0;i<n-1;i++){
    			if(currcount==k)break;
    			if(left){
    				if(currcount<k){
	    				ansVec.push_back({"D",1});
	    				currcount++;
    				}

    				if(currcount+3*(m-1)<=k){
	    				ansVec.push_back({"LUD",m-1});
	    				currcount+=3*(m-1);
    				}
    				else{
    					//FILL IN
    					if(currcount==k)break;
    					if(k-currcount>=3){
		    				ansVec.push_back({"LUD",(k-currcount)/3});
		    				currcount+=((k-currcount)/3)*3;    						
    					}
	    				if(k-currcount==1){
		    				ansVec.push_back({"L",1});
	    					currcount++;
	    				}
	    				else if (k-currcount==2){
		    				ansVec.push_back({"LU",1});
	    					currcount++;
	    					currcount++;
	    				} 		
	    				break;			
    				}

    				left=false;
    			}
    			else{
    				if(currcount<k){
    					ansVec.push_back({"D",1});
    					currcount++;
	    			}
    				if(currcount+3*(m-1)<=k){
	    				ansVec.push_back({"RUD",m-1});
	    				currcount+=3*(m-1);
    				}
    				else{
    					if(currcount==k)break;
    					if(k-currcount>=3){
		    				ansVec.push_back({"RUD",(k-currcount)/3});
		    				currcount+=((k-currcount)/3)*3;    						
    					}
	    				if(k-currcount==1){
		    				ansVec.push_back({"R",1});
	    					currcount++;
	    				}
	    				else if (k-currcount==2){
		    				ansVec.push_back({"RU",1});
	    					currcount++;
	    					currcount++;
	    				} 		
	    				// cerr<<"HI"<<endl;
	    				break;			
    					//FILL IN
    				}
    				left=true;
    			}
    		}


    		for(int i=0;i<n-1;i++){
    			if(currcount==k)break;
    			if(left){
    				if(currcount+m-1<=k){
    					ansVec.push_back({"L",m-1});
    					currcount+=m-1;
    				}
    				else{
    					if(currcount==k)break;
	    		// cerr<<"HI"<<endl;
    					ansVec.push_back({"L",k-currcount});
    					currcount=k;
    					break;
    					//FILL IN
    				}

    				if(currcount<k){
	    				ansVec.push_back({"U",1});    				
	    				currcount++;
    				}
    				left=false;
    			}
    			else{
    				if(currcount+m-1<=k){
    					ansVec.push_back({"R",m-1});
    					currcount+=m-1;
    				}
    				else{
    					if(currcount==k)break;
    					ansVec.push_back({"R",k-currcount});
    					currcount=k;
    					break;
    					//FILL IN
    				}

    				if(currcount<k){
	    				ansVec.push_back({"U",1});    				
	    				currcount++;
    				}
    				left=true;
				}
    		}

    		if(currcount<k)
		    	ansVec.push_back({"L",k-currcount});
    	}
    }

    vector<moveobj> newAnsVec;
    for(int i=0;i<ansVec.size();i++){
    	if(ansVec[i].second>0){
    		newAnsVec.push_back(ansVec[i]);
    	}
    }

    cout<<newAnsVec.size()<<endl;
    for(int i=0;i<newAnsVec.size();i++){
    	cout<<newAnsVec[i].second<<" "<<newAnsVec[i].first<<endl;
    }

}