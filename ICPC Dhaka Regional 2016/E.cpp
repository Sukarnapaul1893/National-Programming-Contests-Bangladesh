#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
int n;
vector<int>vec;
unordered_map<int,int>mark;
void input();

void solve(){
    if(n&1){
        cout<<"invalid\n";
        return;
    }
    string ans = "";
    int cur = 0;

    for(int i=0;i<n;i++){
        if(mark[cur+1]!=0){
            mark[cur+1]--;
            ans+="(";
            cur++;
            continue;
        }
        else if(mark[cur-1]!=0){
            mark[cur-1]--;
            ans+=")";
            cur--;
            continue;
        }
        else{
            cout<<"invalid\n";
            return;
        }
    }
    cout<<ans<<"\n";
}

void Clear(){
    vec.clear();
    mark.clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    for(int tt=1;tt<=t;tt++){
        cout<<"Case "<<tt<<": ";
        input();
        solve();
        Clear();
    }
}

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        int  a;
        cin>>a;
        mark[a]++;
        vec.pb(a);
    }
}
