#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int array[n],mint[n];
  for(int i =0; i < n; i++){
    cin >> array[n];
    mint[n]=0;
  }

  for(int i = 0; i < n;i++){
    if(i == array[i])mint[i]=-1;
    else{
      int j = i,k=array[i];
      while(j != k){
        k = array[k];
        mint[j]++;
      }

    }
  }int min=1000;
  for(int i=0;i <n;i++){
    if(mint[i] > 0 && mint[i]< min){
      min = mint[i];
    }
  }
  cout << min << endl;
  return 0;
}
