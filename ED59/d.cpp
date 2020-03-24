#include <bits/stdc++.h>
using namespace std;

/*
int primeFactors(int n, int arr[]){
    // Print the number of 2s that divide n 
    int i=0;
    while (n%2 == 0) 
    { 
        if(i==0)    arr[i++]=2;
        n = n/2; 
    } 
  
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
            if(i==0 || arr[i-1] != i)    arr[i++]=i;
            n = n/i; 
        } 
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2) if(i==0 || arr[i-1] != n)   arr[i++]=n;
    return i;
}
*/

int primeFactors(int n, int arr[]){
    // Print the number of 2s that divide n 
    int j=0;
    arr[j++]=1;
  
    for (int i = 2; i <= sqrt(n); i++) 
    { 
        // While i divides n, print i and divide n 
        if (n%i == 0) 
        { 
            arr[j++]=i;
            arr[j++]=n/i;
        } 
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2
    sort(arr, arr+j);
    return j;
}

const char* hex_char_to_bin(char c)
{
    // TODO handle default / error
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    int n,facno;
    cin>>n;
    int primefac[n];
    facno = primeFactors(n,primefac);

    int arr[n][n];
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        string bin;
        for(unsigned j = 0; j != n/4; ++j)
            bin += hex_char_to_bin(s[j]);
        for(int j=0;j<n;j++){
            arr[i][j]=((int)bin[j]-'0');
        }
    }
/*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
*/

    int factor,other;
    bool works;
    for(int i=0;i<=facno;i++){
        if(i==facno) factor = n;
        else factor = primefac[i];
        other = n/factor;
//        cout<<factor<<" "<<other<<endl;
        int miniarr[factor+1][factor+1];
        for(int a=0;a<=factor;a++){
            for(int b=0;b<=factor;b++){
                miniarr[a][b]=arr[factor+a][factor+b];
            }
        }
/*
            for(int i=0;i<factor;i++){
        for(int j=0;j<factor;j++){
            cout<<miniarr[i][j]<<" ";
        }
        cout<<endl;
    }
*/
        works = true;

        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                if(arr[a][b] != miniarr[(int)ceil(a/other)][(int)ceil(b/other)]){
                    works = false;
                    break;
                }
            }
            if(!works) break;
        }

        if(works){
            cout<<other<<endl;
            return 0;
        }

    }
/*
        for(int a=0;a<other;a++){
            for(int b=0;b<other;b++){
                if(a==1 && b==1) continue;
                for(int m=0;m<factor;m++){
                    for(int n=0;n<factor;n++){
                        if(arr[(int)ceil(a*factor+m)][(int)ceil(b*factor+n)] != miniarr[m][n]){
                            works = false;
                            break;
                        }
                    }
                    if(!works) break;
                }
                if(!works) break;
            }
            if(!works) break;
        }

        if(works){
            cout<<other<<endl;
            return 0;
        }
    }
*/
    cout<<1<<endl;
    return 0;
}
