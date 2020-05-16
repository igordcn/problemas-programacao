#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

void convertToTex(string line, bool& abrirAspas, bool ultimaLinha) {
  string texText = "";
  for(string::iterator it = line.begin(); it != line.end(); it++) {
    if(*it == '"') {
      if(abrirAspas){
        texText.push_back('`');
        texText.push_back('`');
      } else {
        texText.push_back(39);
        texText.push_back(39);
      }
      abrirAspas = !abrirAspas;
    } else {
      texText.push_back(*it);
    }
  }
  printf("%s", texText.c_str());
  if(!ultimaLinha) printf("\n");
}

int main() {
  string line;
  string texText = "";
  bool abrirAspas = true;
  while(!getline(cin, line).eof()) {
    convertToTex(line, abrirAspas, false);
  }
  convertToTex(line, abrirAspas, true);
  return 0;
}