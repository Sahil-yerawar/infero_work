/*
	SAHIL YERAWAR
	@thanos_01/thanos_03
*/

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
// #define N 100010

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

const double PI = 2*acos(0.0);
const int N = 512345;
#define rtn return
#define gc getchar
#define pb push_back
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define lp(i,b) for(ll i = ll(0); i<ll(b) ; ++i)
#define lpit(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define mid(s,e) (s+(e-s)/2)
#define min3(a,b,c)	min(a,min(b,c))
#define max3(a,b,c)	max(a,max(b,c))
#define debug(X) cout << "--> " << #X << " = " << X << endl

ll ip(){
	ll x = 0; bool isNeg = false; char c;
	c = gc();
	if(c == '-')	isNeg = true , c = gc();
	for( ; c >= '0'  && c <= '9' ; c = gc()); x = (x << 1) + (x << 3) + c - '0';
	if(isNeg)	x *= -1;	return x;
}
//////////////////////////////////////////// CONTAINERS FOR FUNCTIONS MENTIONED IN TEMPLATE ///////////////////////////////////
#define MAX 100005
//bool isPrime[MAX];
//int spf[MAX];
//////////////////////////////////////////// FUNCTIONS THAT NEED COMMENTED OUT CONTAINERS ////////////////////////////////////


//void prime_sieve(){ for(ll i=2 ; i*i<=MAX ; ++i){	if(!isPrime[i]){ for(ll j=i*i ; j<=MAX ; j+=i)	isPrime[j] = 1;} } 	}
/*void spf_sieve(){	for(ll i=2 ; i<MAX ; ++i){ if(i&1) spf[i] = i; else spf[i] = 2;}
	for(ll i=3 ; i<MAX ; i+=2){	if(spf[i]==i){  for(ll j=i*i ; j<=MAX ; j+=i){ if(spf[j]==j) spf[j] = i; } } }
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
inline ll ncr(ll n,ll r){ ll ans = 1 ; if(r > n-r) r = n-r; lp(i,r+1){ans*=(n-i) ; ans/=(i+1); } rtn ans; }
inline ll gcd(ll a,ll b){if(!a) rtn b; rtn gcd(b%a,a); }
inline ll fme(ll x,ll n){ll ans=1;x%=MOD;while(n>0){if(n&1){ ans*=x;ans%=MOD;} x*=x;x%=MOD;n>>=1;}rtn ans%MOD;}
inline bool isPalin(string &s){	int len = s.size()-1;lp(i,(len/2)+2){if(!(s[i]==s[len-i]))	rtn false;} rtn true;}
inline ll lcm(ll a,ll b){rtn (a*b)/gcd(a,b); }
inline ll fmm(ll a,ll b) {ll r=0;a%=MOD;b%=MOD;while(b>0){if(b&1){r+=a;r%=MOD;}a+=a;a%=MOD;b>>=1;}rtn r%MOD;}
inline ll sfme(ll a,ll b) {ll r=1;a%=MOD;while(b>0){if(b&1)r=fmm(r,a);a=fmm(a,a);b>>=1;}rtn r%MOD;}
inline int in(){ int NR=0; register char c=gc(); while( c < 48 || c > 57 ){c=gc();}
	while(c>47 && c< 58){	NR = (NR << 3) + (NR << 1) + (c - 48); c=gc();} return NR;
}

ll dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//
map<int, vector<int> > s, e;
map<int, vector<pii> > q;
map<int, int> c;
int bit[N];
void update(int i, int v)
{
	while(i < N)
	{
		bit[i] += v;
		i += (i & (-i));
	}
}
int query(int i)
{
	int ret = 0;
	while(i > 0)
	{
		ret += bit[i];
		i -= (i & (-i));
	}
	return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll ans;
    ans = 0;
    // debug(ans);
    vector<pair< int, pii> > v,h;
    vector<int> X,Y;
    int x1,y1,x2,y2;
    scanf("%lld",&n);
    while(n--){
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      if(x1==x2){
        if(y1>y2)swap(y1,y2);
        v.pb(mp(x1,mp(y1,y2)));
        X.pb(x1),Y.pb(y1),Y.pb(y2);
      }
      else{
        if(x1>x2)swap(x1,x2);
        h.pb(mp(y1,mp(x1,x2)));
        Y.pb(y1),X.pb(x1),X.pb(x2);
      }
    }
    sort(all(h));
    sort(all(v));
    sort(all(X));
    sort(all(Y));

    for(int i=0;i<v.size();++i){
			// debug(v[i].ss.ss);
      // debug(v[i].ss.ff);
			int last=v.size(),x=v[i].ff;
      for(int j=i;j<v.size();++j){
        if(v[j].ff!=v[i].ff){
          last = j;
          break;
        }
      }
      pii cur = v[i].ss;
      for(int j=i+1;j<last;++j){
				// debug(v[j].ss.ff);
				// debug(v[j].ss.ss);
        if(cur.ss<v[j].ss.ff){
          ans += cur.ss-cur.ff+1;
          q[x].pb(cur);
          cur = v[j].ss;
        }
        else if(v[j].ss.ss<= cur.ss){}
        else cur.ss = v[j].ss.ss;
        // debug(ans);
      }
      ans += cur.ss-cur.ff+1;
      // debug(cur.ff);
      // debug(cur.ss);
      q[x].pb(cur);
      i = last-1;
    }
    for(int i = 0;i<h.size();++i){
      int last = h.size(),y = h[i].ff;
      for(int j=i;j<h.size();++j){
        if(h[j].ff!=h[i].ff){
          last = j;
          break;
        }
      }
      pii cur = h[i].ss;
      for(int j=i;j<last;++j){
        if(cur.ss<h[j].ss.ff){
          s[cur.ff].pb(y);
          e[cur.ss].pb(y);
          ans += cur.ss-cur.ff+1;
          cur = h[j].ss;
          // debug(ans);
        }
        else if(h[j].ss.ss<= cur.ss){}
        else cur.ss = h[j].ss.ss;
      }
      ans += cur.ss-cur.ff+1;
      // debug(ans);
      s[cur.ff].pb(y);
      e[cur.ss].pb(y);
      i = last-1;
    }
    int ct = 1;
    for(int i = 0;i<Y.size();++i){
      if(i==0||Y[i]>Y[i-1])c[Y[i]] = ++ct;
    }
        // debug(ans);
    for(int r = 0;r<X.size();++r){
      if(r == 0 || X[r]> X[r-1]){
        int x = X[r];
        for(int i = 0;i<s[x].size();++i){
          int y = s[x][i];
          update(c[y],1);
        }
        for(int i = 0;i<q[x].size();++i){
          int y = q[x][i].ff,yy= q[x][i].ss;
          ans -= query(c[yy])-query(c[y]-1);
        }
        for(int i = 0;i<e[x].size();++i){
          int y = e[x][i];
          update(c[y],-1);
        }
      }
    }
    printf("%lld\n", ans);
    return 0;
}