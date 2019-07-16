//https://open.kattis.com/problems/grassseed

#include <iostream>
#include <vector>
#include <algorithm>

#define PB push_back
#define PF push_front
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define se second
#define fi first

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;
typedef vector<ll> VLL;
typedef vector<int> VI;

const ll inf = 1e9+7;

int main()
{
    db c, l;

    cin >> c >> l;

    db cost;

    for (int i = 0; i < l; i++) {
        db wi, li;
        cin >> wi >> li;

        cost += wi*li;
    }

    cout << c*cost;
    
    return 0;
}
