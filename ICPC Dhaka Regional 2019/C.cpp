#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

void input();
int cs;
ll n,m;

void solve(){
    ll ev = 1;
    ll mod = 1e9+7;
    //probability of not choosing ith color out of n colors
    ll p = ((n-1LL)*modinverse(n,mod))%mod;
    //probability of not choosing ith for any of m layers
    ev = bigmod(p,m,mod);
    //probability of choosing ith color
    ev = 1-(ev);
    ev += mod;
    ev %=mod;
    ev*=n;
    ev%=mod;
    cout<<"Case "<<cs<<": "<<ev<<"\n";
}

void Clear(){
    cs++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cs=1;
    int t;
    cin>>t;
    while(t--){
        input();
        solve();
        Clear();
    }
}

void input(){
    cin>>n>>m;
}
