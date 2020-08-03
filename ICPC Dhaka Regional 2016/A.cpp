#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define all(a) a.begin(), a.end()
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




int main(){
    IOS
    //freopen("output.txt","w",stdout);
    map<int,int>mp;

    mp[1]++;
    mp[64]++;
    mp[729]++;
    mp[4096]++;
    mp[15625]++;
    mp[46656]++;
    mp[117649]++;
    mp[262144]++;
    mp[531441]++;
    mp[1000000]++;
    mp[1771561]++;
    mp[2985984]++;
    mp[4826809]++;
    mp[7529536]++;
    mp[11390625]++;
    mp[16777216]++;
    mp[24137569]++;
    mp[34012224]++;
    mp[47045881]++;
    mp[64000000]++;
    mp[85766121]++;
    ll n;
    while(cin>>n){
        if(n==0)break;
        if(mp[n]>0){
            cout<<"Special\n";
        }
        else{
            cout<<"Ordinary\n";
        }
    }

}
