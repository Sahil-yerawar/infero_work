#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;
vector<int>maxArray1(int a, int b, vector<int> array){
  vector<int> list2;
  if(a <= b){
    int count = 0;
    for(int i = 0 ;i<a; i++){
        if(array[i] == 1){
            count += 1;}
    }
    list2.push_back(count);
    return list2;
  }
  else{
    int n = array.size();
  for(int i = 0; i< n;i++){
    int x = array[i];
    list2.push_back(x);
  }
  for(int i = 0; i< n;i++){
    array.push_back(list2[i]);
  }
  array.erase(array.begin());
  vector<int> list1,list3;
  for(int i = array.size()-1; i>=0;i--){
    list1.push_back(array[i]);
  }
  int count = 0;
  for(int i = 0 ;i<b; i++){
      if(list1[i] == 1){
          count += 1;}
  }
  list3.push_back(count);

  for (int i = b;i<list1.size();i++){
    if (list1[i-b] == 1)
        count -= 1;
    if (list1[i] == 1)
        count += 1;
    list3.push_back(count);
  }
  return list3;
  }
}
vector<int> setMax(int a, int b, vector<int> array){
  vector<int>sliding_max;
  if (a > b){int n = array.size(),k = a-b+1;
  int leftmin[n],rightmin[n];
  leftmin[0] = array[0];
  rightmin[n-1] = array[n-1];
  for(int i = 1;i < n;i++){
    leftmin[i] = (i%k == 0) ? array[i]:max(leftmin[i-1],array[i]);
    int j = n-i-1;
    rightmin[j] = (j%k == 0) ? array[j]:max(rightmin[j+1],array[j]);
  }
  for(int i = 0,j=0;i+k <= n; i++){
    sliding_max.push_back(max(rightmin[i],leftmin[i+k-1]));
  }
  }
  else{

    sliding_max.push_back(array[0]);
  }
  return sliding_max;
}

void SATreq1(int a,int b,int c,vector<int> list1,string req){
  vector<int> list2 = maxArray1(a,b,list1);
  vector<int> list3 = setMax(a,b,list2);

  int count = 0;
  for(int i = 0; i<c; i++){
      if (req[i] == '!'){
        if(count == a-1)
          count = 0;
        else
          count++;
      }
      else{
        if(a <= b)cout << list3[0] << endl;
        else cout << list3[count] << endl;
      }
  }
}

int main(){
  int n,k,p,a;
  vector<int> list;
  string req;
  cin >> n >> k >> p;
  for(int i = 0;i < n;i++){
    cin >> a;
    list.push_back(a);
  }
  cin >> req;
  SATreq1(n,k,p,list,req);
  return 0;
}