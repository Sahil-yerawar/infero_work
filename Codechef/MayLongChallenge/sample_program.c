#include <stdio.h>

int main() {
  int t = 0;
  int a[11];
  for(int i = 0;i<10;i++){
    // t++;
    //
    // if(i*2<15)break;
  }
  // if(i == 4)break;
  for(int i = 0; i<10;i++){
    t++;
    if(i*2<15){t+=2;t-=1;break;}
    else{
      t += 2;

    }
    t -= 1;
  }
  return 0;
}
