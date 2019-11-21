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
    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){
        int n;
        cin>>n;
        ll arr[n];
        int bam[n];
        int dan[n];
        memset(bam,0,sizeof bam);
        memset(dan,0,sizeof dan);
        for(int i=0;i<n;i++)cin>>arr[i];
        bool bl=false;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                bl=true;
                break;
            }
        }
        if(bl==false){
            cout<<"Case "<<tt+1<<": "<<n<<"\n";
            continue;
        }
        ll cur=0;
        int cnt=0;
        int running=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0 and cur==0)continue;

            if(arr[i]==0){
                bam[running]=++cnt;
            }
            else if(arr[i]!=cur){
                cur=arr[i];
                for(int j=running+1;j<i;j++){
                    bam[j]=--cnt;
                }
                running =i;
                cnt=0;
                bam[running]=++cnt;
            }

            else{
                cur=arr[i];
                bam[running]=++cnt;

            }
            if(i==n-1){
                for(int j=running+1;j<i;j++){
                    bam[j]=--cnt;
                }
            }

        }
        running = n-1;
        cur=0;
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(arr[i]==0 and cur==0)continue;
            if(arr[i]==0){
                dan[running]=++cnt;
            }
            else if(arr[i]!=cur){
                cur=arr[i];
                for(int j=running-1;j>i;j--){
                    dan[j]=--cnt;
                }
                running =i;
                cnt=0;
                dan[running]=++cnt;
            }

            else{
                cur=arr[i];
                dan[running]=++cnt;

            }
            if(i==0){
                for(int j=running-1;j>i;j--){
                    dan[j]=--cnt;

                }
            }

        }

        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,bam[i]+dan[i]-1);
            //cout<<bam[i]<<" "<<dan[i]<<"\n";
        }

        cout<<"Case "<<tt+1<<": "<<mx<<"\n";
    }
}
