#include "CPU.cpp"
#include "reader.cpp"

int main(){

  vector<string> instructionList = readFile();

  cout << "arquivo lido com sucesso" << endl;

  vector<pair<int, bitset<32>>> instructions = interpreter(instructionList);

  cout << "vetor de instruções criado" << endl;

  CPU(instructions);

  cout << "programa executado com sucesso" << endl;
  
  return 0;

}