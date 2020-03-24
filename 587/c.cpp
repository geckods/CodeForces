#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	ll x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6;
   	cin>>x1>>y1>>x2>>y2;
   	cin>>x3>>y3>>x4>>y4;
   	cin>>x5>>y5>>x6>>y6;

   	//one of them covers completely

   	if(x3<=x1 && y3<=y1 && x4>= x2 && y4>=y2){
   		cout<<"NO"<<endl;
   	}
   	else if (x5<=x1 && y5<=y1 && x6>= x2 && y6>=y2){
   		cout<<"NO"<<endl;
   	}
   	else if (y3<=y1 && y4>=y2 && y5<=y1 && y6>=y2){
   		//they both cover y
   		if((x3<=x1 && x4>=x5 && x6>=x2) || (x5<=x1 && x6>=x3 && x4>=x2)){
   			cout<<"NO"<<endl;
   		}
   		else{
   			cout<<"YES"<<endl;
   		}
   	}
   	else if (x3<=x1 && x4>=x2 && x5<=x1 && x6>=x2){
   		if((y3<=y1 && y4>=y5 && y6>=y2) || (y5<=y1 && y6>=y3 && y4>=y2)){
   			cout<<"NO"<<endl;
   		}
   		else{
   			cout<<"YES"<<endl;
   		}
   	}
   	else{
   		//it can be seen
   		cout<<"YES"<<endl;
   	}
   	//they both cover one dimension completely and they together cover the other dimention
}