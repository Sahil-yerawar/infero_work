#include <bits/stdc++.h>
/* TRIE IMPLEMENTATION USED HERE*/  #include <iostream>

int main(){
	/* code */
	return 0;
}
#define ll long long int
#define llu long long int unsigned
#define vi vector <int>
#define vl vector <ll>

#define sz(n) (auto)n.size()
#define all(n) n.begin(), n.end()

#define rep(i,j,k) for(auto i=j; i<=k; i++)
#define repd(i,j,k) for(auto i=j; i>=k; i--)
#define iter(it, s) for(auto it=s.begin(); it!=s.end(); it++)
#define printv(a) cout << endl;iter(it , a){ cout << *it << " , ";}cout << endl;

using namespace std;

typedef struct node{
  struct node* child[26];
}node;

void insert(node* r, string a){
  int len = a.size();
  for(int i = 0;i< len;i++){
    if(r->child[a[i]-97] == NULL){
      node* temp = new node;
      for(int j = 0;j<26;j++){
        temp->child[j] = NULL;
      }
      r->child[a[i]-97] = temp;
    }
    r = r->child[a[i]-97];
  }

}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  std::vector<string> v;
  string a;
  char t;
  node* root = new node;
  for (int j = 0; j < 26; ++j)
      root->child[j] = NULL;

  for (int i = 0; i < n; ++i)
  {
      cin >> t;
      cin >> a;
      if (t == '+')
          insert(root , a);
      else
          v.push_back(a);//list of blocked sites
  }
  set <string> ans;
  node* x = root;
  int i , len;
  for(vector<string>::iterator it = v.begin();it != v.end();++it){
    string p = *it;
    int len = p.size();
    x = root;
    string a = "";
    for(i =0;i<len;i++){
      if(x->child[p[i]-97] == NULL){
        a += p[i];
        break;
      }
      a += p[i];
      x = x->child[p[i]-97];
    }
    if(i == len){
      cout << -1 << endl;
      return 0;
    }
    ans.insert(a);
  }
  cout << ans.size() << endl;
  for(set<string>::iterator it = ans.begin();it != ans.end();++it){
    cout << *it << endl;
  }
  return 0;
}