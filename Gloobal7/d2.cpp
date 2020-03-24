#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;

    	int n=s.length();

		vector<int> d1(n);
		for (int i = 0, l = 0, r = -1; i < n; i++) {
		    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
		        k++;
		    }
		    d1[i] = k--;
		    if (i + k > r) {
		        l = i - k;
		        r = i + k;
		    }
		}

		vector<int> d2(n);
		for (int i = 0, l = 0, r = -1; i < n; i++) {
		    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
		        k++;
		    }
		    d2[i] = k--;
		    if (i + k > r) {
		        l = i - k - 1;
		        r = i + k ;
		    }
		}


    	ll a=0;
    	ll b=s.length()-1;

    	while(s[a]==s[b]){
    		a++;
    		b--;
    		if(a>=b){
    			break;
    		}
    	}

    	a--;
    	b++;

    	if(a>=b){
    		cout<<s<<endl;
    		continue;
    	}

    	int c=b-1;
    	while(c>=a+1){
    		//check if a+1 to c is a palindrome
    		if((c-(a+1))%2==0){
    			//odd length palindrome
    			// cerr<<c<<" "<<(c+a+1)/2<<endl;
    			if(d1[(c+a+1)/2]>=(c-(c+a+1)/2 + 1)){
    				break;
    			}
    		}
    		else{
    			if(d2[(c+a+1)/2 +1 ]>=(c-(c+a+1)/2)){
    				break;
    			}
    		}
    		c--;
    	}


    	int d=a+1;
    	while(d<=b-1){
    		if((b-1-d)%2==0){
	    		// cerr<<d<<" "<<b<<endl;
    			//odd length palindrome
    			if(d1[(b+d-1)/2]>=(b-(b+d-1)/2 )){
    				break;
    			}
    		}
    		else{
    			// cerr<<d<<" "<<b<<" "<<d2[(b+d-1)/2+1]<<endl;
    			if(d2[(b+d-1)/2+1]>=(b-(b+d-1)/2-1)){
    				break;
    			}
    		}
    		d++;
    	}

		for(int i=0;i<=a;i++){
			cout<<s[i];
		}

    	if(c-a>b-d){
    		for(int i=a+1;i<=c;i++){
    			cout<<s[i];
    		}
    	}
    	else{
    		for(int i=d;i<=b-1;i++){
    			cout<<s[i];
    		}
    	}

		for(int i=b;i<s.length();i++){
			cout<<s[i];
		}
		cout<<endl;

	}
}