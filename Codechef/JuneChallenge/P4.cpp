#include<bits/stdc++.h>
using namespace std;

typedef double lf;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef set<ll> sll;
typedef vector<ll> vll;
typedef map<string,ll> msl;
typedef pair<int,int> pii;
typedef pair<ll,ll> ii;
typedef vector<ii > vpll;
typedef map<ll,ll> mll;
typedef vector<vll > matrix;
typedef list<ll> lll;
typedef vector<lll > vlll;
typedef pair<ll,ii> iii;


#define MOD 1000000007
#define N 100010
#define all(a) a.begin(),a.end()
#define pb push_back
#define lp(i,b) for(ll i = ll(0); i<ll(b) ; i++)
#define lpit(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t,n,k,b;
  cin >> t;
  while(t--){
    cin >> n >> k;
    int x,a,g=0;
    vll v[n];
    lp(i,n){
			cin >> a;
			lp(j,a){
				cin >> b;
				v[i].pb(b);
			}
		}
    ll ans = 0;
    for(ll i = 0;i<n;i++){
      for(ll j = i+1;j<n;j++){
        if(v[i].size()+v[j].size()<k)continue;
        ll cnt = v[i].size()+v[j].size();
        if(v[i].size() < v[j].size()){
          sort(all(v[i]));
          ll sz = 0;
          lpit(it,v[j]){
            if( binary_search( all(v[i]), *it) )
							sz++;
          }
          cnt -= sz;
          if( cnt == k )	ans++;
        }
        else{
          sort(all(v[j]));
					ll sz = 0;
					lpit(it,v[i]){
						if( binary_search( all(v[j]), *it) )
							sz++;
					}
					cnt -= sz;
					if( cnt == k )	ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}