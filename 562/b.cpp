#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    int arr[m][2];

    int a,b;
    for(int i=0;i<m;i++){
    	cin>>a>>b;
    	arr[i][0]=min(a,b);
    	arr[i][1]=max(a,b);
    }


    if(m==1){
    	cout<<"YES"<<endl;
   		return 0;
    }


    // poss[2][2];

    // poss[0][0]=arr[0][0];
    // poss[0][1]=arr[0][1];
    // bool needsecond = false;

    // for(int i=1;i<m;i++){
    // 	if(arr[i][0]==possind[0][0] || arr[i][0]==poss[0][1] || arr[i][1]==poss[0][0]|| arr[i][1]==poss[0][1]){
    // 		continue;
    // 	}
    // 	else{

    // 	}
    // }

    int z=1;
    while(z<m && (arr[0][0]==arr[z][0] || arr[0][0]==arr[z][1] || arr[0][1]==arr[z][0] ||arr[0][1]==arr[z][1])) z++;

    if(z==m){
    	cout<<"YES"<<endl;
    	return 0;
    }

    int poss[4][2];
    poss[0][0]=arr[0][0];
    poss[0][1]=arr[z][0];
    poss[1][0]=arr[0][0];
    poss[1][1]=arr[z][1];
    poss[2][0]=arr[0][1];
    poss[2][1]=arr[z][0];
    poss[3][0]=arr[0][1];
    poss[3][1]=arr[z][1];

    set<int> possind;
    for(int i=0;i<4;i++){
    	possind.insert(i);
    }


    for(int i=0;i<m;i++){
    	set<int> removeind;
    	for(set<int>::iterator j=possind.begin();j!=possind.end();j++){
    		// cout<<i<<" "<<*j<<endl;
    		// cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<poss[*j][0]<<" "<<poss[*j][1]<<endl;
    		if(!(arr[i][0]==poss[*j][0] || arr[i][0]==poss[*j][1] || arr[i][1]==poss[*j][0] || arr[i][1]==poss[*j][1])){
    			removeind.insert(*j);
    		}
    	}

    	for(set<int>::iterator j=removeind.begin();j!=removeind.end();j++){
    		possind.erase(*j);
    	}

    	// cout<<i<<endl;
    	// for(set<int>::iterator j = possind.begin();j!=possind.end();j++){
    	// 	cout<<*j<<" ";
    	// }
    	// cout<<endl;

    	if(possind.empty()){
    		cout<<"NO"<<endl;
    		return 0;
    	}
    }
    cout<<"YES"<<endl;
}

    //deal with case where all numbers are the same
