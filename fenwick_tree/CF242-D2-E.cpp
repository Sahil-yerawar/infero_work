/*
	SAHIL YERAWAR
	@thanos_01/thanos_03
*/

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define N 100005
// #define N 100010

typedef double lf;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef set<int> sint;
typedef vector<int> vint;
typedef map<string,int> msl;
typedef pair<int,int> pii;
typedef pair<int,int> ii;
typedef vector<ii > vpint;
typedef map<int,int> mint;
typedef vector<vint > matrix;
typedef list<int> intl;
typedef vector<intl > vintl;
typedef pair<int,ii> iii;

const double PI = 2*acos(0.0);

#define rtn return
#define gc getchar
#define pb push_back
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define aint(a) a.begin(),a.end()
#define aintr(a) a.rbegin(),a.rend()
#define lp(i,b) for(int i = int(0); i<int(b) ; i++)
#define lpit(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define mid(s,e) (s+(e-s)/2)
#define min3(a,b,c)	min(a,min(b,c))
#define max3(a,b,c)	max(a,max(b,c))

int ip(){
	int x = 0; bool isNeg = false; char c;
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


//void prime_sieve(){ for(int i=2 ; i*i<=MAX ; i++){	if(!isPrime[i]){ for(int j=i*i ; j<=MAX ; j+=i)	isPrime[j] = 1;} } 	}
/*void spf_sieve(){	for(int i=2 ; i<MAX ; i++){ if(i&1) spf[i] = i; else spf[i] = 2;}
	for(int i=3 ; i<MAX ; i+=2){	if(spf[i]==i){  for(int j=i*i ; j<=MAX ; j+=i){ if(spf[j]==j) spf[j] = i; } } }
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
inline int ncr(int n,int r){ int ans = 1 ; if(r > n-r) r = n-r; lp(i,r+1){ans*=(n-i) ; ans/=(i+1); } rtn ans; }
inline int gcd(int a,int b){if(!a) rtn b; rtn gcd(b%a,a); }
inline int fme(int x,int n){int ans=1;x%=MOD;while(n>0){if(n&1){ ans*=x;ans%=MOD;} x*=x;x%=MOD;n>>=1;}rtn ans%MOD;}
inline bool isPalin(string &s){	int len = s.size()-1;lp(i,(len/2)+2){if(!(s[i]==s[len-i]))	rtn false;} rtn true;}
inline int lcm(int a,int b){rtn (a*b)/gcd(a,b); }
inline int fmm(int a,int b) {int r=0;a%=MOD;b%=MOD;while(b>0){if(b&1){r+=a;r%=MOD;}a+=a;a%=MOD;b>>=1;}rtn r%MOD;}
inline int sfme(int a,int b) {int r=1;a%=MOD;while(b>0){if(b&1)r=fmm(r,a);a=fmm(a,a);b>>=1;}rtn r%MOD;}
inline int in(){ int NR=0; register char c=gc(); while( c < 48 || c > 57 ){c=gc();}
	while(c>47 && c< 58){	NR = (NR << 3) + (NR << 1) + (c - 48); c=gc();} return NR;
}

int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//
int a[N];
int tree[21][4*N];
int lazy[21][4*N];
int n,m,x,y,z,w;

void build(int node, int l, int r, int no){
	if(l==r){
		tree[no][node] = 0;
		if(a[l] & (1<<no)){
			tree[no][node] = 1;
		}
		return;
	}
	int mid = (l + r)>>1;
	build(node*2,l,mid,no);
	build((node*2)+1,mid+1,r,no);
	tree[no][node] = tree[no][node*2]+tree[no][(node*2)+1];
	return;
}

void update(int node, int l, int r, int no, int i, int j){
	if(lazy[no][node]){
		tree[no][node] = (r-l+1)-(tree[no][node]);
		if(l!=r){
			lazy[no][node*2] ^= 1;
			lazy[no][node*2+1] ^= 1;
		}
		lazy[no][node] = 0;
		// return;
	}
	if(l>j || i > r)return;
	if(l >=i && r <=j){
		tree[no][node] = (r-l+1)-(tree[no][node]);
		if(l!=r){
			lazy[no][node*2] ^= 1;
			lazy[no][node*2+1] ^= 1;
		}
		lazy[no][node] = 0;
		return;
	}
	int mid = (l+r)>>1;
	update(node*2,l,mid,no,i,j);
	update(node*2+1,mid+1,r,no,i,j);
	tree[no][node] = tree[no][node*2]+tree[no][node*2+1];
	return;
}

int query(int node, int l, int r, int no, int i, int j){
	if(lazy[no][node]){
		tree[no][node] = (r-l+1)-(tree[no][node]);
		if(l!=r){
			lazy[no][node*2] ^= 1;
			lazy[no][node*2+1] ^= 1;
		}
		lazy[no][node] = 0;
		// return;
	}
	if(l>j||r<i)return 0;
	if(l >=i && r <=j){
		return tree[no][node];
	}
	int mid = (l+r)>>1;
	return query(node*2,l,mid,no,i,j)+query(node*2+1,mid+1,r,no,i,j);
}
// int sum(int b){
//   int ans = 0;
//   for(;b;b -= (b&(-b)))ans += a[b];
//   return ans;
// }
//
// int sum(int a, int b){
//   return sum(b)-(a==1?0:sum(a-1));
// }
//
// void update(int i, int v){
//   for(;i<n;i+=i&(-i))a[i] ^= v;
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0;i<n;i++){
      cin>>a[i];
      // if(i!=1)a[i] += a[i-1];
    }
		for(int i = 0;i<20;i++){
			build(1,0,n-1,i);
			// for(int j = 0;j<n;j++){
			// 	cout<<tree[i][j]<<" ";
			// }
			// cout<<endl;
		}
    cin >> m;
    while(m--){
      cin >> x ;
      if(x == 1){
				cin >> y >> z;
				ll sum = 0;
        for(int i = 0;i<20;i++){
					// cout<<(query(1,0,n-1,i,y-1,z-1)*(1LL<<i))<<endl;
					sum += (query(1,0,n-1,i,y-1,z-1)*(1LL<<i));
				}
				cout<<sum<<endl;
      }
      else{
        cin>> y >> z>> w;
        for(int i = 0;i<20;i++){
        	if(w & (1<<i))update(1,0,n-1,i,y-1,z-1);
        }
      }
    }
    return 0;
}