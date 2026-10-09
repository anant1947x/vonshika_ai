#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long int
#define all(x) (x).begin(),(x).end()

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> mset;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;

const int MOD=1e9+7;

// 8 16
// dbcadabc

void solve(){
     int n,k; cin>>n>>k;
     string s; cin>>s;
     int l=0,r=1;
     string neww="";
     neww.push_back(s[0]);
     while(r<(int)s.size()){
        if (s[r]<s[l]){
            neww.push_back(s[r]);
            r++; 
        }
        else if (s[r]==s[l]){
            // dusra loop 
            bool find=0;
            l++;  string temp=""; 
            temp.push_back(s[r]);
            r++;
            while(r<(int)s.size() and find==0){
                temp.push_back(s[r]);
                if (s[r]<s[l]) find=1;
                else if (s[r]>s[l]) break;
                r++; l++;
            }
            if (find==0) break;
            else {
                l=0;
                for (auto &i:temp) neww.push_back(i);
            }
        }
        else break;
     }
     string outt="";
     int times=k/(int)neww.size();
      outt="";
     for (int i=0; i<times; ++i){
        for (auto &j:neww) outt.push_back(j);
     }
     for (int i=0; i<(k%(int)neww.size()); ++i){
        outt.push_back(neww[i]);
     }
    cout<<outt<<endl;
}

signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1; 
    auto start=chrono::high_resolution_clock::now();
    while(t--){
        solve();
    }
    auto end=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(end-start);
    cerr<<"Time taken: "<<duration.count()/1000.0<<" ms"<<endl;
    return 0;
}