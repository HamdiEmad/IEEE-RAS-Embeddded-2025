#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void wonderful(long long n);

int main() {
  long long n;
  scanf("%lld", &n);
  wonderful(n);
}


void wonderful(long long n) {
  if (n % 2 == 0) {
    printf("NO");
    return;
  }
  char binary[32] = "";
  while(n) {
    if (n % 2 == 0) strcat(binary, "0");
    else strcat(binary, "1");
    n /= 2;
  }
  for (int i = 0; i < strlen(binary) / 2; i++) {
    if (binary[i] != binary[strlen(binary) - i - 1]) {
      printf("NO");
      return ;
    } 
  }
  printf("YES");
  return ;
}

//https://codeforces.com/group/MWSDmqGsZm/contest/223205/submission/312258430