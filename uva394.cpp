#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

struct Array
{
  char nome[10];
  int base;
  int elemsize;
  int boundslen;
  int lbounds[10];
  int ubounds[10];
} arrays[10];

int arrayslen, numArray;
int indexes[10];


int getArrayIndex(char nome[]) {
  for(int i = 0; i < arrayslen; i++) {
    if(strcmp(nome, arrays[i].nome) == 0) {
      return i;
    }
  }
  return 0;
}

int calcAddress() {
  Array array = arrays[numArray];
  int len = array.boundslen;
  int c[len];
  c[len-1] = array.elemsize;
  int c0 = array.base - c[len-1]*array.lbounds[len-1];
  int result = c[len-1]*indexes[len-1];
  for(int i = len-2; i >= 0; i--) {
    c[i] = c[i+1]*(array.ubounds[i+1]-array.lbounds[i+1]+1);
    result += c[i]*indexes[i];
    c0 -= c[i]*array.lbounds[i];
  }
  result += c0;
  return result;
}

void printResult(int result) {
  Array array = arrays[numArray];
  printf("%s[", array.nome);
  for(int i = 0; i < array.boundslen; i++) {
    printf("%d", indexes[i]);
    if(i < array.boundslen-1) printf(", ");
  }
  printf("] = %d\n", result);
}

int main() {
  int checkCount, result;

  char arrayName[10];

  scanf("%d %d", &arrayslen, &checkCount);
  for(int i = 0; i < arrayslen; i++) {
    scanf("%s %d %d %d", arrays[i].nome, &arrays[i].base, &arrays[i].elemsize, &arrays[i].boundslen);
    for(int j = 0; j < arrays[i].boundslen; j++) {
      scanf("%d %d", &arrays[i].lbounds[j], &arrays[i].ubounds[j]);
    }
  }

  for(int i = 0; i < checkCount; i++) {
    scanf("%s", arrayName);
    numArray = getArrayIndex(arrayName);
    for(int j = 0; j < arrays[numArray].boundslen; j++) {
      scanf("%d", &indexes[j]);
    }
    result = calcAddress();
    printResult(result);
  }
  return 0;
}