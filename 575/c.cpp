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

   	int q;
   	cin>>q;

   	for(int quer=0;quer<q;quer++){
   		int n;
   		cin>>n;

   		int top,bottom,left,right;
   		top=1e5;
   		bottom=-(1e5);
   		left=-(1e5);
   		right=1e5;

   		for(int i=0;i<n;i++){
   			int x,y,f1,f2,f3,f4;
   			cin>>x>>y>>f1>>f2>>f3>>f4;

   			if(f1==0){
   				left=max(left,x);
   			}
   			if(f2==0){
   				top=min(top,y);
   			}
   			if(f3==0){
   				right=min(right,x);
   			}
   			if(f4==0){
   				bottom=max(bottom,y);
   			}
   		}

   		if(top<bottom || right<left){
   			cout<<0<<endl;
   		}
   		else{
   			cout<<1<<" "<<left<<" "<<bottom<<endl;
   		}
   	}
}