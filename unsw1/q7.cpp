#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pair;
typedef long long LL;
const int MAX_V  = 100;
const int MAX_E = 1e4+10;
const int maxn = 1e5+10;
unordered_map<LL,int> mp;
#define max(a, b) (a > b) ? a : b
#define min(a, b) (a < b) ? a : b

int a[maxn];

int main(int argc, char const *argv[]) {
  LL n,k;
  cin>>n>>k;
  for(int i=0 ; i<n ; ++i)cin>>a[i];


//kadane
    LL h_overall = 0, h_here = 0;
    LL l_overall = 0, l_here = 0;
    for (int i = 0; i < n; i++){
        h_here = max(h_here + a[i], 0);
        l_here = min(l_here + a[i], 0);

        h_overall = max(h_here, h_overall);
        l_overall = min(l_here, l_overall);
    }
    // printf("high is %lld, low is %lld", h_overall, l_overall);
    // find range of power
    LL limit = max(h_overall, abs(l_overall));




  LL ans =0;
  LL power = 1;
  int t =0;
  while (abs(power) <= limit && abs(power)<=1e15) {
    mp.clear();
    mp[0]++;
    LL s =0;
    for(int i=0 ; i<n ; ++i){
      s+=a[i];
      ans+=mp[s-power];
      mp[s]++;
    }
    power*=k;
    if( power == 1)break;
  }
  std::cout << ans << '\n';

    return 0;
}
