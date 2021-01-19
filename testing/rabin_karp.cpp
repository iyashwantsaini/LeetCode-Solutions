#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void rabin_(string t,string p){
    int n=t.length();
    int m=p.length();
    ll pcurr=0;
    ll tcurr=0;
    // preprocess for initial window
    for(int i=0,j=m-1;i<m||j>=0;i++,j--){
        tcurr+=((t[i]-96)*pow(10,j));
        pcurr+=((p[i]-96)*pow(10,j));
    }
    cout<<pcurr<<" "<<tcurr<<"\n";
    int pw=pow(10,m-1);
    // for subsequent windows
    for(int i=m;i<n;i++){
        // if found!
        if(pcurr==tcurr){
            // check for array elements as well
            int flag=1;
            for(int j=i-1,x=m-1;j>=i-m||x>=0;j--,x--){
                if(t[j]!=p[x]){
                    flag=0;
                }
            }
            if(flag==1){
                cout<<"found! => "<<i-m<<"\n";
            }
        }
        // continue to search
        tcurr=(((tcurr-(t[i-m]-96)*pw)%mod)*10+(t[i]-96));
        cout<<pcurr<<" "<<tcurr<<"\n";
    }
}

int main(){
    string t="abcabaabcabac";//text
    string p="abaa";//pattern
    rabin_(t,p);
    return 0;
}