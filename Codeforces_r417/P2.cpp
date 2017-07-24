#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
using namespace std;
#define LL "%I64d"
typedef long long int  lli;
using namespace std;
int main(){
  int m,n;
  string x;
  cin >> n >> m;
  vector<string> v;
  int rightmost[n],leftmost[n];
  for(int i = 0;i<n;i++){
    rightmost[i] = 0;
    leftmost[i] = m+1;
  }
  int maxFloor = -1;
  for(int i = n-1;i>=0;i--){
    cin >> x;
    for(int j=0;j<m+2;j++){
      if(x[j] == '1'){
        rightmost[i] = j;
        if (maxFloor == -1)maxFloor = i;
      }
    }
    // cout << rightmost[i]<<" "<<leftmost[i]<<endl;
    for(int j = m+1;j>=0;j--){
      if(x[j] == '1')leftmost[i] = j;
    }
    // cout << rightmost[i]<<" "<<leftmost[i]<<endl;
  }

  int answer = 100000;
  for(int stairs =0;stairs < (1<<n-1);++stairs){
    int current = 0;int room =0;int floof = 0;
    while(floof <= maxFloor){
      if(room == 0){
        current += rightmost[floof] -room;
        room = rightmost[floof];
      }
      else{
        current += room - leftmost[floof];
        room = leftmost[floof];
      }
      if(floof == maxFloor)break;
      int nxt = (stairs & (1<<floof)) == 0 ? 0:m+1;
      current += abs(nxt-room)+1;
      room = nxt;
      ++floof;
    }
    answer = min(answer,current);
    // cout << answer <<endl;
  }
  cout << answer << endl;
  return   0;
}