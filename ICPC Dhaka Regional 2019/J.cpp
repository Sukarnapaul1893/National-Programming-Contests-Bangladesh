#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,n;
    cin>>a>>n;
    int mx;
    for(int i=0;i<=n;i++){
        if(i==0){
            mx = __gcd(a,i);
            continue;
        }
        mx = max(__gcd(a,i),mx);
    }
    cout<<mx<<"\n";
}
