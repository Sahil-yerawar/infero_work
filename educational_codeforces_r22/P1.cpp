#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define LL "%I64d"
typedef long long int  lli;

using namespace std;

int main(){
  int m,n,x,y,count =0;
  vector<int> a;
  vector< vector<int> > b;
  cin >> n;
  for(int i = 0;i<n;i++){
    cin >> x;
    a.push_back(x);
    count += x;
  }
  cin >> m;
  for(int i = 0;i<m;i++){
    vector<int>row;
    cin >> x >> y;
    row.push_back(x);
    row.push_back(y);
    b.push_back(row);
  }
  if(b[m-1][1]-b[0][0]+1 < count){
    cout << -1 << endl;
  }
  else{
    for(int i = 0;i<m;i++){
      if (b[i][0] <= count-b[0][0]+1 and b[i][1] >= count-b[0][0]+1){
        cout << count << endl;
      }
      else if(b[i][0] >= count-b[0][0]+1 and b[i][1] >= count-b[0][0]+1){
        cout << b[i][0]<<endl;
      }
    }
  }
  return 0;
}