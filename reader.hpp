#include<bits/stdc++.h>
using namespace std;

// add, Rd, Rs, Rt
// sub, 

vector<string> readFile(){

  string aux;

  vector<string> instructionList;

  ifstream file("teste.txt");
  if(file){
    while (getline(file, aux)){

      if(aux.size() == 0){
        continue;
      }

      instructionList.push_back(aux);

    }
  }
  else{
    cout << "Erro na leitura do file" << endl;
  }

  return instructionList;

}