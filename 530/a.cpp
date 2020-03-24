#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w,h;
    int u1,d1;
    int u2,d2;
    cin>>w>>h;
    cin>>u1>>d1;
    cin>>u2>>d2;
    

    for(int height=h;height>0;height--){
    	w+=height;
    	if(height==d1){
    		w-=u1;
    		w=max(w,0);
    	}
    	if(height==d2){
    		w-=u2;
    		w=max(w,0);
    	}
    }

    cout<<w<<endl;
}
