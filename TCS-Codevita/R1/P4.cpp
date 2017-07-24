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
#define DEBUG(var) cerr<<"-->"<<#var<<"= "<var<<endl;

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
inline int gcd(int a,int b){if(!a) rtn b; rtn gcd(b%a,a); }
ll dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//
/*
  SPACE FOR GLOBAL DECLARATIONS
*/
int rank1[201][201];
int cnt = 0;
bool e = true;
vector<float> used;
int toNum(string h){
  ll x=0;
  for(size_t i=0;i<h.size();i++){
    x += (h[i]-'0')*(int)pow(10,h.size()-i-1);
  }
  return x;
}
void fill(int a,int y){
  if(a == 1){
    cnt += 1;
    rank1[1][1] = cnt;
  used.pb((float)1);}
  else{
    for(size_t i = 1;i<(size_t)a+1;i++){
        if(e){
          float r = (float)(a+1-i)/(float)(i);
          if(find(all(used),r)==used.end()){
            cnt++;
            rank1[i][a+1-i] = cnt;
            used.pb(r);
          }
        }
        else{
          float r = (float)(i)/(float)(a+1-i);
          if(find(all(used),r)==used.end()){
            cnt++;
            rank1[a+1-i][i] = cnt;
            used.pb(r);
          }
      }
    }
  }
  // }
  if(a != 2*y-1){e = !e;return fill(a+1,y);}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s,p="",q="";
    cin >> s;
    size_t i;
    for(i=0;i<s.size();i++){
      if(s[i]=='/')break;
      else p +=s[i];
    }
    int a = toNum(p);
    i++;
    for(;i<s.size();i++){
      q += s[i];
    }
    int b = toNum(q);
    // cout<<a << " "<<b<<endl;
    int c = gcd(a,b);
    a /= c;
    b /= c;
    int g = max(a,b);
    fill(1,g);
    // for(int i = 1;i<=2*g-1;i++){
    //   for(int j = 1;j<=2*g-1;j++){
    //       cout<<rank1[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
    cout << rank1[a][b]<<endl;
    return 0;

}