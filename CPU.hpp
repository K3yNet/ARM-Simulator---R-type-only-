#include<bits/stdc++.h>
#include "interpreter.hpp"
#include "memory.hpp"
#include "IF.hpp"
#include "ID.hpp"
#include "EXE.hpp"
#include "WB.hpp"
using namespace std;

void CPU(vector<pair<int, bitset<32>>> instructions){

  Memory memory;

  memory.setInstruction(instructions);

  bitset<32> registerIfId;

  RegisterIdEx registerIdEx;

  pair<bitset<8>, bitset<32>> registerExWb;

  for (int i = 0; !registerIfId.all(); i++){
    registerIfId = instructionFetch(i, memory);
    registerIdEx = instructionDecoder(registerIfId, memory);
    registerExWb = execution(registerIdEx, memory);
    writeBack(registerExWb, memory);
  }

  memory.printAll();

}