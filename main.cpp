#include<bits/stdc++.h>
#include "CPU.hpp"
#include "reader.hpp"
#include "interpreter.hpp"

using namespace std;


int main(){

  vector<string> instructionList = readFile();

  vector<pair<int, bitset<32>>> instructions = interpreter(instructionList);

  CPU(instructions);
  
  return 0;

}