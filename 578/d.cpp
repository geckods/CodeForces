#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 2000

char arr[MAXN][MAXN];
int rowmin[MAXN];
int colmin[MAXN];
int rowmax[MAXN];
int colmax[MAXN];

int rowcan[MAXN][MAXN];
int colcan[MAXN][MAXN];



int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n,k;
   	cin>>n>>k;

   	// store min and max for each row/col
   	// put a 1 in a location if that row/col can be converted by a size k eraser
   	//cumul that arr


   	for(int i=0;i<n;i++){
   		rowmax[i]=colmax[i]=INT_MIN;
   		rowmin[i]=colmin[i]=INT_MAX;
   	}

   	for(int i=0;i<n;i++){
   		for(int j=0;j<n;j++){
   			cin>>arr[i][j];
   			if(arr[i][j]=='B'){
   				rowmin[i]=min(rowmin[i],j);
   				colmin[j]=min(colmin[j],i);
   				rowmax[i]=max(rowmax[i],j);
   				colmax[j]=max(colmax[j],i);
   			}
   		}
   	}

   	int freerows=0;
   	for(int i=0;i<n;i++){
   		// cout<<i<<" "<<rowmin[i]<<" "<<rowmax[i]<<" "<<colmin[i]<<" "<<colmax[i]<<endl;
   		if(rowmax[i]==INT_MIN)freerows++;
   		if(colmax[i]==INT_MIN)freerows++;
   	}


   	for(int i=0;i<n;i++){
   		for(int j=0;j<n;j++){
   			rowcan[i][j]=colcan[i][j]=0;
   			if((j<=rowmin[i] && rowmax[i]-j<k) && rowmax[i]!=INT_MIN){
   				rowcan[i][j]=1;
   			}

   			if((i<=colmin[j] && colmax[j]-i<k)&& colmax[j]!=INT_MIN){
   				colcan[i][j]=1;
   			}
   		}
   	}

   	// for(int i=0;i<n;i++){
   	// 	for(int j=0;j<n;j++){
   	// 		cout<<rowcan[i][j]<<" ";
   	// 	}
   	// 	cout<<endl;
   	// }

   	// cout<<endl;
   	// for(int i=0;i<n;i++){
   	// 	for(int j=0;j<n;j++){
   	// 		cout<<colcan[i][j]<<" ";
   	// 	}
   	// 	cout<<endl;
   	// }



   	for(int j=0;j<n;j++){
   		int asd=rowcan[0][j];
   		for(int i=1;i<n;i++){
	   		asd+=rowcan[i][j];
	   		rowcan[i][j]=asd;   			
   		}
   	}

   	for(int i=0;i<n;i++){
   		int asd=colcan[i][0];
   		for(int j=1;j<n;j++){
   			asd+=colcan[i][j];
   			colcan[i][j]=asd;
   		}
   	}

   	int ans=0;

   	for(int i=0;i<n;i++){
   		for(int j=0;j<n;j++){
   			int minians=0;
   			minians+=colcan[i][min(j+k-1,n-1)];
   			if(j>0){
   				minians-=colcan[i][j-1];
   			}

   			minians+=rowcan[min(i+k-1,n-1)][j];

   			if(i>0){
   				minians-=rowcan[i-1][j];
   			}

   			ans=max(ans,minians);
   		}
   	}
   	cout<<ans+freerows<<endl;
}