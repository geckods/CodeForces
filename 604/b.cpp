#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//stupid mistake, didn't consider some edge cases, failed in contest

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int oga,ogb,ogc,ogd;
    cin>>oga>>ogb>>ogc>>ogd;

    int a,b,c,d;
    a=oga;
    b=ogb;
    c=ogc;
    d=ogd;

    vector<int> ans1;
    bool ans1works=true;

    while(a>0){
    	if(!ans1works)break;
    	ans1.push_back(0);
    	a--;
    	if(b>0){
    		ans1.push_back(1);
    		b--;
    	}
    	else{
    		if(a>0 || c+d>0){
    			ans1works=false;
    			break;
    		}
    	}
    }

    while(b>0){
    	if(!ans1works)break;
    	b--;
    	if(c>0){
    		ans1.push_back(2);
 	   		ans1.push_back(1);
    		c--;
    	}
    	else{
 	   		if(ans1.size()>0 && ans1[ans1.size()-1]==1){
 		   		ans1.insert(ans1.begin(), 1);
 	   		}
 	   		else{
 		   		ans1.push_back(1);
 		   	}

    		if(b>0 || d>0){
    			ans1works=false;
    			break;
    		}
    	}
    }

    while(c>0){
    	if(!ans1works)break;
		ans1.push_back(2);
		c--;
		if(d>0){
			ans1.push_back(3);
			d--;
		}    	
		else{
			if(c>0){
				ans1works=false;
				break;
			}
		}
    }

    if(d>0){
    	ans1works=false;
    }

    if(ans1works){
    	cout<<"YES"<<endl;
    	for(int i=0;i<oga+ogb+ogc+ogd;i++){
    		cout<<ans1[i]<<" ";
    	}
    	cout<<endl;
    	return 0;
    }


    a=oga;
    b=ogb;
    c=ogc;
    d=ogd;

    vector<int> ans2;
    bool ans2works=true;

    while(d>0){
    	if(!ans2works)break;
    	ans2.push_back(3);
    	d--;
    	if(c>0){
    		ans2.push_back(2);
    		c--;
    	}
    	else{
    		if(d>0 || a+b>0){
    			ans2works=false;
    			break;
    		}
    	}
    }

    while(c>0){
    	if(!ans2works)break;
    	c--;
    	if(b>0){
    		ans2.push_back(1);
	    	ans2.push_back(2);
    		b--;
    	}
    	else{
    		if(ans2.size()>0 && ans2[ans2.size()-1]==2){
    			ans2.insert(ans2.begin(), 2);
    		}
    		else{
		    	ans2.push_back(2);
    		}
    		if(c>0 || a>0){
    			ans2works=false;
    			break;
    		}
    	}
    }

    while(b>0){
    	if(!ans2works)break;
		ans2.push_back(1);
		b--;
		if(a>0){
			ans2.push_back(0);
			a--;
		}    	
		else{
			if(b>0){
				ans2works=false;
				break;
			}
		}
    }


    if(a>0){
    	ans2works=false;
    }

    if(ans2works){
    	cout<<"YES"<<endl;
    	for(int i=0;i<oga+ogb+ogc+ogd;i++){
    		cout<<ans2[i]<<" ";
    	}
    	cout<<endl;
    	return 0;
    }


    cout<<"NO"<<endl;


}