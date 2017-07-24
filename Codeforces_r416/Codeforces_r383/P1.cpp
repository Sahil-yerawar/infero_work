#include<iostream>
using namespace std;
typedef long long int lli;
int main(){
  lli n;
  cin >> n;
  if(n == 0){
    cout << 1 << endl;
    return 0;
  }
  lli u = n%4;
  if(u == 1)cout << 8 << endl;
  else if(u == 2)cout << 4 << endl;
  else if(u == 3)cout << 2 << endl;
  else if(u == 0)cout << 6 << endl;

  return 0;
}
