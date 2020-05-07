//Author : Sukarna Paul

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define pi acos(-1)
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;


string bin(ll x){
    string s="";
    for(int i=0;i<64;i++){
        if(x%2==0){
            s+='0';
        }
        else{
            s+='1';
        }
        x/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}


int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){
        ll x,y;cin>>x>>y;
        string a = bin(x);
        string b = bin(y);
        //cout<<a<<"\n"<<b<<"\n";
        bool bl=false;
        string ansOR="";
        string ansAND="";
        for(int i=0;i<a.length();i++){
            if(bl==false){
                if(a[i]!=b[i]){
                    ansOR+='1';
                    ansAND+='0';
                    bl=true;
                    continue;
                }
                ansOR+=a[i];
                ansAND+=a[i];
            }
            else{
                ansOR+='1';
                ansAND+='0';
            }
        }
        reverse(ansOR.begin(),ansOR.end());
        reverse(ansAND.begin(),ansAND.end());
        //cout<<ansOR<<"\n"<<ansAND<<"\n";
        ll ans1 = 0;
        ll ans2 = 0;
        ll p=1LL;
        for(int i=0;i<ansOR.length();i++){
            if(ansOR[i]=='1')ans1+=p;
            if(ansAND[i]=='1')ans2+=p;
            p*=2LL;
        }
        cout<<"Case "<<tt+1<<": "<<ans1<<" "<<ans2<<"\n";
    }
}

