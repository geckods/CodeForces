#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif

    int n,m;

    cin>>n>>m;

    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    int range[m][2];
    for(int i=0;i<m;i++){
    	cin>>range[i][0]>>range[i][1];
    	range[i][0]--;
    	range[i][1]--;
    }

    map<int, vector<int> > myMap;

    for(int i=0;i<n;i++){
    	myMap[i]=vector<int>();
    	for(int j=0;j<m;j++){
    		if(i>=range[j][0] && i<= range[j][1]){
    			myMap[i].push_back(j);
    		}
    	}
    }

    // for(vector<int>::iterator j = myMap[1].begin();j!=myMap[1].end();j++){
    // 	cout<<*j<<" ";
    // }
    // cout<<endl;


    int cumularr[n];
    int cumul=0;

    // for(int i=0;i<n;i++){
    // 	cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    cumularr[0]=arr[0];
    for(int i=0;i<n;i++){
    	cumularr[i]=arr[i]-arr[i-1];
//    	cout<<cumularr[i]<<" ";
    }
//    cout<<endl;

    int greatestdiff=INT_MIN;
    int greatestdiffind=-1;

    for(int i=0;i<n;i++){
    	int newcumularr[n];
    	for(int j=0;j<n;j++){
    		newcumularr[j]=cumularr[j];
    	}

    	// for(int j=0;j<n;j++){
    	// 	cout<<newcumularr[j]<<" ";
    	// }
    	// cout<<endl;

    	for(vector<int>::iterator j = myMap[i].begin();j!=myMap[i].end();j++){
    		newcumularr[range[*j][0]]--;
    		if(range[*j][1] < n-1)
	    		newcumularr[range[*j][1]+1]++;
    	}

    	// for(int j=0;j<n;j++){
    	// 	cout<<newcumularr[j]<<" ";
    	// }
    	// cout<<endl;


    	int newarr[n];
    	int cumul=0;
    	for(int j=0;j<n;j++){
    		cumul+=newcumularr[j];
    		newarr[j]=cumul;
    	}

    	// for(int j=0;j<n;j++){
    	// 	cout<<newarr[j]<<" ";
    	// }
    	// cout<<endl;


    	int mymax=INT_MIN;
    	int mymin=INT_MAX;

    	for(int j=0;j<n;j++){
    		if(newarr[j]>mymax) mymax=newarr[j];
    		if(newarr[j]<mymin) mymin=newarr[j];
    	}

//    	cout<<i<<" "<<mymax-mymin<<endl<<endl;

    	if(mymax-mymin>greatestdiff){
    		greatestdiff=mymax-mymin;
    		greatestdiffind=i;
    	}
    }

    cout<<greatestdiff<<endl;
    cout<<myMap[greatestdiffind].size()<<endl;
    for(vector<int>::iterator i = myMap[greatestdiffind].begin(); i!=myMap[greatestdiffind].end();i++){
    	cout<<*i+1<<" ";
    }
} 