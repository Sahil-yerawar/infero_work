/*
	SAHIL YERAWAR
	@thanos_01/thanos_03
*/

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define N 100010

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
typedef vector<int> vi;

const double PI = 2*acos(0.0);

#define rtn return
#define gc getchar
#define pb push_back
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define lp(i,b) for(ll i = ll(0); i<ll(b) ; i++)
#define lpit(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define mid(s,e) (s+(e-s)/2)
#define min3(a,b,c)	min(a,min(b,c))
#define max3(a,b,c)	max(a,max(b,c))

#define MAXN 1024000
#define MAXH 21

#define UP_SET 1
#define UP_CLR 2
#define UP_FLP 3

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


//void prime_sieve(){ for(ll i=2 ; i*i<=MAX ; i++){	if(!isPrime[i]){ for(ll j=i*i ; j<=MAX ; j+=i)	isPrime[j] = 1;} } 	}
/*void spf_sieve(){	for(ll i=2 ; i<MAX ; i++){ if(i&1) spf[i] = i; else spf[i] = 2;}
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

class SegmentTree{
  private:
    vi a;
    vi t;
    vi u;
    int left (int p) { return p << 1; } // same as binary heap operations
    int right(int p) { return (p << 1) + 1; }
    int n;
  public:
    SegmentTree(){
      a.resize(MAXN);
      t.resize(1<<MAXH);
      u.resize(1<<MAXH);
    }
    void init(vi a,int na){
      this->a = a;
      n = na;
      tree_init(1,0,n-1);
    }
    void tree_init(int a, int l, int r){
      u[a]=0;
      if(l==r){t[a]=this->a[l];return;}
      int lt = left(a),rt=right(a),mid=(l+r)/2;
      tree_init(lt,l,mid);
      tree_init(rt,mid+1  ,r);
      t[a]=t[lt]+t[rt];
    }

    void set(int i, int j){
      tree_set(i,j,1,0,n-1);
    }
    void tree_set(int i, int j, int x, int a, int b){
      propagate(x,a,b);
      if(j<a || i > b)return;
      if(a == b){t[x]=1;return;}
      int lt = left(x),rt=right(x),md=(a+b)/2;
      if(a>=i && b <= j){
        t[x]=b-a+1;
        u[lt]=u[rt]=UP_SET;
        return;
      }
      tree_set(i,j,lt,a,md);
      tree_set(i,j,rt,md+1,b);
      t[x]=t[lt]+t[rt];
    }
    int query(int i, int j){
      return tree_query(i,j,1,0,n-1);
    }
    int tree_query(int i, int j, int x, int a, int b){
      if(j<a || i > b)return -1;
      propagate(x,a,b);
      // if(a == b){t[x]=1;return;}
      if(a>=i && b <= j){
        return t[x];
      }
      int lt = left(x),rt=right(x),md=(a+b)/2;
      int q1=tree_query(i,j,lt,a,md);
      int q2=tree_query(i,j,rt,md+1,b);
      if(q1<0)return q2;
      if(q2<0)return q1;
      return q1+q2;
    }
    void clear(int i, int j){
      tree_clear(i,j,1,0,n-1);
    }
    void tree_clear(int i, int j, int x, int a, int b){
      propagate(x,a,b);
      if(j<a || i > b)return;
      if(a == b){t[x]=0;u[x]=0;return;}
      int lt = left(x),rt=right(x),md=(a+b)/2;
      if(a>=i && b <= j){
        t[x]=0;
        u[lt]=u[rt]=UP_CLR;
        return;
      }
      tree_clear(i,j,lt,a,md);
      tree_clear(i,j,rt,md+1,b);
      t[x]=t[lt]+t[rt];
    }

    void flip(int i, int j){
      tree_flip(i,j,1,0,n-1);
    }
    void tree_flip(int i, int j, int x, int a, int b){
      propagate(x,a,b);
      if(j<a || i > b)return;
      if(a == b){t[x]=t[x]==1 ? 0 : 1 ;return;}
      int lt = left(x),rt=right(x),md=(a+b)/2;
      if(a>=i && b <= j){
        t[x]=b-a+1-t[x];
        u[lt]=apply_flip(u[lt]);
        u[rt]=apply_flip(u[rt]);
        return;
      }
      tree_flip(i,j,lt,a,md);
      tree_flip(i,j,rt,md+1,b);
      t[x]=t[lt]+t[rt];
    }

    int apply_flip(int v){
      if(v==UP_SET)return UP_CLR;
      if(v==UP_CLR)return UP_SET;
      if(v==UP_FLP)return 0;
      return UP_FLP;
    }

    void propagate(int x, int a, int b){
      if(u[x]==0)return;
      if(u[x]==UP_SET)t[x] = b-a+1;
      else if(u[x]==UP_CLR)t[x]=0;
      else if(u[x]==UP_FLP)t[x]=b-a+1-t[x];

      if(a!=b){
        int lt = left(x),rt=right(x);
        if(u[x]==UP_SET||u[x]==UP_CLR){
          u[lt]=u[rt]=u[x];
        }
        else u[lt]=apply_flip(u[lt]),u[rt]=apply_flip(u[rt]);
      }
      u[x]=0;
    }

};
int t,m,a,b,l,r;
string s,ta;
char q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    int z = t;
    while(t--){
      s="";
      cin>>m;
      vi pirates;
      int size=0;
      while(m--){
        cin>>b;
        cin>>ta;
        size += b*ta.size();
        while(b--)s+=ta;
      }
      for(int i=0;i<s.size();i++){
        pirates.pb(s[i]-'0');
      }
      SegmentTree st;
      st.init(pirates,size);
      cin>>a;
      int w=a,k=0;
      cout<<"Case "<<z-t<<":"<<endl;
      while(a--){
        cin>>q>>l>>r;
        if(q=='F')st.set(l,r);
        else if(q=='E')st.clear(l,r);
        else if(q=='I')st.flip(l,r);
        else cout<<"Q"<<++k<<": "<<st.query(l,r)<<endl;
      }
    }
    return 0;
}