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
   		int b,w;
   		cin>>b>>w;

   		bool lesswhites=false;
   		if(w<b)lesswhites=true;

   		if((lesswhites && b>(4+3*(w-1))) || (!(lesswhites) && w>(4+3*(b-1)))){
   			cout<<"NO"<<endl;
   			continue;
   		}
   		cout<<"YES"<<endl;

   		if(lesswhites){
   			for(int i=0;i<w;i++){
   				cout<<4<<" "<<2*i+2<<endl;
   			}
   			int j=0;
   			while(b>0 && 2*j<=w*2){
   				cout<<4<<" "<<2*j+1<<endl;
   				b--;
   				j++;
   			}
   			j=0;
   			while(b>0 && 2*j+2<=w*2){
   				cout<<3<<" "<<2*j+2<<endl;
   				b--;
   				j++;
   			}
   			j=0;
			while(b>0 && 2*j+2<=w*2){
   				cout<<5<<" "<<2*j+2<<endl;
   				b--;
   				j++;
   			}   			
   		}
   		else{
   			for(int i=0;i<b;i++){
   				cout<<3<<" "<<2*i+2<<endl;
   			}
   			int j=0;
   			while(w>0 && 2*j<=b*2){
   				cout<<3<<" "<<2*j+1<<endl;
   				w--;
   				j++;
   			}
   			j=0;
   			while(w>0 && 2*j+2<=b*2){
   				cout<<2<<" "<<2*j+2<<endl;
   				w--;
   				j++;
   			}
   			j=0;
			while(w>0 && 2*j+2<=b*2){
   				cout<<4<<" "<<2*j+2<<endl;
   				w--;
   				j++;
   			}
   		}
   	}
}