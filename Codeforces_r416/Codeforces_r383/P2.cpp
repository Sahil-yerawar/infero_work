#include<iostream>
using namespace std;
typedef long long int lli;

int main(){
  lli n,x;
  lli pair = 0;
  cin >> n >> x;
  lli array[n];
  for(lli i = 0; i < n; i++){
    cin >> array[i];
  }
  if(x == 0){
    cout << n << endl;
    return 0;
  }
  for(lli i = 0; i < n-1; i++){
    for(lli j = i+1; j < n; j++){
      lli u = array[i]^array[j];
      if(u == x){
        pair+=1;
      }
    }
  }
 
  cout << pair << endl;
  return 0;
}
