#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

int salvarCycleLength(vector<int> &valores, map<int,int> &cycleLength, int cycleLengthFound) {
  int maxCycleLength = valores.size() + cycleLengthFound;
  for(int i = 0; i < valores.size(); i++) {
    cycleLength[valores[i]] = maxCycleLength - i;
  }
  return maxCycleLength;
}

int executarAlgoritmo(int valor, map<int, int> &cycleLength) {
  vector<int> valores;
  int cycleLengthFound = 1;
  while(valor != 1) {
    if(cycleLength.find(valor) != cycleLength.end()) {
      cycleLengthFound = cycleLength[valor];
      break;
    }
    valores.push_back(valor);
    if(valor % 2 != 0) {
      valor = 3*valor +1;
    } else {
      valor = valor/2;
    }
  }

  return salvarCycleLength(valores, cycleLength, cycleLengthFound);
}

int main() {

  map<int, int> cycleLength;
  cycleLength[1] = 1;

  int input1, input2, limiteMin, limiteMax, valorTemp, maxValor;

  while(scanf("%d %d", &input1, &input2) != EOF) {
    maxValor =0;
    if(input1 > input2) {
      limiteMin = input2;
      limiteMax = input1;
    } else {
      limiteMin = input1;
      limiteMax = input2;
    }
    for(int i = limiteMin; i <= limiteMax; i++) {
      valorTemp = executarAlgoritmo(i, cycleLength);
      if(valorTemp > maxValor) {
        maxValor = valorTemp;
      }
    }
    printf("%d %d %d\n", input1, input2, maxValor);
  } 
  return 0;
}