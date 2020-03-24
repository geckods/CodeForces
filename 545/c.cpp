/*I solved this perfectly, but there was a for loop index that was supposed to be n, not m. That bug was manifesting in very weird ways.
I caught that bug only 30 seconds before the end, didn't get time to submit.
I also got fast IO TLEd in this question (after the contest), so I've now added the fast IO line to my start script
*/

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

    int arr[n][m];
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>arr[i][j];
    	}
    }

    int sortedrows[n][m];
	
	for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		sortedrows[i][j]=arr[i][j];
    	}
    }

    for(int i=0;i<n;i++){
    	sort(sortedrows[i],sortedrows[i]+m);
    }

	int sortedcols[m][n];
	
	for(int j=0;j<m;j++){
    	for(int i=0;i<n;i++){
    		sortedcols[j][i]=arr[i][j];
    	}
    }

    for(int j=0;j<m;j++){
    	sort(sortedcols[j],sortedcols[j]+n);
    }

    int uniqbeforerows[n][m];
    int curr;
    for(int i=0;i<n;i++){
    	int the=0;
    	set<int> myset;
    	for(int j=0;j<m;j++){
    		curr=sortedrows[i][j];
    		if(myset.find(curr)!=myset.end() && !myset.empty()){
    			uniqbeforerows[i][j]=the;
    		}
    		else{
    			the++;
    			uniqbeforerows[i][j]=the;
    			myset.insert(curr);
    		}
    	}
    }

//    cout<<uniqbeforerows[0][0]<<endl;
    int uniqbeforecols[m][n];
    
    for(int j=0;j<m;j++){
    	int the=0;
    	set<int> myset;
    	for(int i=0;i<n;i++){
    		curr=sortedcols[j][i];
    		if(myset.find(curr)!=myset.end()&& !myset.empty()){
    			uniqbeforecols[j][i]=the;
    		}
    		else{
    			the++;
    			uniqbeforecols[j][i]=the;
    			myset.insert(curr);
    		}
    	}
    }


    int rowind;
    int colind;

    int rowindupper;
    int colindupper;

    int rowans;

    int colans;
    int atleast;
    int atmost;
    int offset;
/*
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cout<<uniqbeforerows[i][j]<<" ";
    	}
    	cout<<endl;
    }
*/
//    cout<<uniqbeforerows[0][0]<<endl;

    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		rowind=lower_bound(sortedrows[i],sortedrows[i]+m,arr[i][j])-sortedrows[i];
    		colind=lower_bound(sortedcols[j],sortedcols[j]+n,arr[i][j])-sortedcols[j];

    		rowindupper=upper_bound(sortedrows[i],sortedrows[i]+m,arr[i][j])-sortedrows[i]-1;
    		colindupper=upper_bound(sortedcols[j],sortedcols[j]+n,arr[i][j])-sortedcols[j]-1;


    		//the largest number has rowind n-1
    		atleast=max(rowind-(rowind+1-uniqbeforerows[i][rowind]),colind-(colind+1-uniqbeforecols[j][colind]));
    		atmost=max(m-rowindupper - (m-uniqbeforerows[i][m-1] - (rowindupper+1-uniqbeforerows[i][rowindupper])),n-colindupper-(n-uniqbeforecols[j][n-1]-(colindupper+1-uniqbeforecols[j][colindupper])));

//    		atleast = max(rowind-(j+1-uniqbeforerows[i][j]),colind-(i+1-uniqbeforecols[j][i]));

//    		rowind-(j+1-uniqbeforerows[i][rowind]);

//    		atmost= max(n-rowind-(m-(uniqbeforerows[i][m-1]-uniqbeforerows[i][j])),m-colind-(n-(uniqbeforecols[j][n-1]-uniqbeforecols[j][i])));
    		cout<<atleast+atmost<<" ";
//    		cout<<i<<" "<<j<<" "<<atleast<<" "<<atmost<<" "<<rowind<<" "<<colind<<endl;
    	}
    	cout<<endl;
    }

}