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

    int h,w;
    cin>>h>>w;

    char arr[h][w];

    for(int i=0;i<h;i++){
    	for(int j=0;j<w;j++){
    		cin>>arr[i][j];
    	}
    }

    int rowcount[h];
    int colcount[w];
    for(int i=0;i<h;i++){
    	rowcount[i]=0;
    }

    for(int i=0;i<w;i++){
    	colcount[i]=0;
    }


    int centeri,centerj;

    int hasanscount=0;
    for(int i=0;i<h;i++){
    	for(int j=0;j<w;j++){
    		if(arr[i][j]=='*'){
    			rowcount[i]++;
    			colcount[j]++;
    		}
    	}
    }

    for(int i=0;i<h;i++){
    	for(int j=0;j<w;j++){
    		if(arr[i][j]=='*' &&i>0 && arr[i-1][j]=='*'&&i<h-1&&arr[i+1][j]=='*'&&j>0&&arr[i][j-1]=='*'&&j<w-1&&arr[i][j+1]=='*'){
    			hasanscount++;
    			centeri=i;
    			centerj=j;

   				int a=i;
   				int b=i;
   				while(a>=0 && arr[a][j]=='*')a--;
   				if(a<0 || arr[a][j]!='*')a++;
   				
   				while(b<h && arr[b][j]=='*')b++;
   				if(b>=h || arr[b][j]!='*')b--;

   				for(int k=0;k<a;k++){
   					if(rowcount[k]>0){
   						cout<<"NO"<<endl;
   						return 0;
   					}
   				}

   				for(int k=b+1;k<h;k++){
   					if(rowcount[k]>0){
   						cout<<"NO"<<endl;
   						return 0;
   					}
   				}

   				a=j;
   				b=j;
   				while(a>=0 && arr[i][a]=='*')a--;
   				if(a<0 || arr[i][a]!='*')a++;
   				
   				while(b<w && arr[i][b]=='*')b++;
   				if(b>=w || arr[i][b]!='*')b--;

   				for(int k=0;k<a;k++){
   					if(colcount[k]>0){
   						cout<<"NO"<<endl;
   						return 0;
   					}
   				}

   				for(int k=b+1;k<w;k++){
   					if(colcount[k]>0){
   						cout<<"NO"<<endl;
   						return 0;
   					}
   				}
    		}
    	}
    }

    int greateronerowcount=0;
    int greateronecolcount=0;

    for(int i=0;i<h;i++){
    	if(rowcount[i]>1)greateronerowcount++;
    }

    for(int j=0;j<w;j++){
    	if(colcount[j]>1)greateronecolcount++;
    }

    if(greateronerowcount>1 || greateronecolcount>1 || hasanscount!=1){
    	cout<<"NO"<<endl;
    	return 0;
    }
    cout<<"YES"<<endl;
}