/** 
* Author : GreatC0der
* 2025-09-16 13:28:55 
**/
#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve(){
    int n ;
    cin >> n;
    int a , b ,g ;
    int g1 = 0;
    int g2 = 0;
    int g3 = 0 ;
    int tracker_1 = 1; // assuming shell 1 has the pebble initially  
    int tracker_2 = 2 ; // assuming shell 2  has the pebble initially
    int tracker_3 = 3 ; // assuming shell 3 has the pebble initially
    
    for(int i = 0 ;i < n ; i ++ ){
        cin >> a >> b >> g;
        
        if (a == tracker_1 || b == tracker_1 || g == tracker_1){
            if (a ==  tracker_1){tracker_1 = b;}
            else if (b == tracker_1){tracker_1 = a;}
            if (g == tracker_1){g1 ++ ;}

        
        }
        if (a == tracker_2 || b == tracker_2  || g == tracker_2){
            if (a ==  tracker_2){tracker_2 = b;}
            else if (b == tracker_2){tracker_2 = a;}
            if (g == tracker_2){g2 ++ ;}
        
        }
        if (a == tracker_3  ||  b == tracker_3 || g == tracker_3){
            if (a ==  tracker_3){tracker_3 = b;}
            else if (b == tracker_3){tracker_3 = a;}
            if (g == tracker_3){g3 ++ ;}
        }
      
    }
    cout << max({g1, g2, g3});
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("shell.in", "r",stdin);
    freopen(   "shell.out", "w",stdout);
    long long t = 1;
    //cin>>t;
    while(t -- ){
        solve();
    }
    return 0;
}
