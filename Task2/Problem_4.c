#include <stdio.h>

void print(int n) {
  if (n == 1){
    printf("1\n");
    return;
  }
  else {
    print(n - 1);
    printf("%d\n",n--);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  print(n);
}

//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/312258779