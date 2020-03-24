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

      ll n;
      cin>>n;

      ll arr[n];
      for(int i=0;i<n;i++){
         cin>>arr[i];
      }

      if(n%2==0){
         for(int i=0;i<n;i++){
            if(arr[i]>=0){
               arr[i]=(-1*arr[i])-1;
            }
         }
      }
      else{

         for(int i=0;i<n;i++){
            if(arr[i]>=0){
               arr[i]+=1;
               arr[i]*=(-1);
            }
         }

         ll max=abs(arr[0]);
         ll maxind=0;

         for(int i=0;i<n;i++){
            if(abs(arr[i])>max){
               max=abs(arr[i]);
               maxind=i;
            }
         }

         // for(int i=0;i<n;i++){
         //    if((arr[i]>=0 && i!=maxind)||(arr[i]<0 && i==maxind)){
         //       arr[i]=(-1*arr[i])-1;
         //    }
         // }

         arr[maxind]*=(-1);
         arr[maxind]-=1;
      }

      for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
      }
      cout<<endl;
}