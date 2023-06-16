#ifndef _TYPES_H
#include "types.hpp"
#endif
#include "interpreter.cpp"
#include "IF.cpp"
#include "ID.cpp"
#include "EXE.cpp"
#include "WB.cpp"

void CPU(vector<pair<int, bitset<32>>> instructions){

  Memory *memory = new Memory();

  memory->setInstruction(instructions);

  bitset<32> registerIfId;

  RegisterIdEx registerIdEx;

  pair<bitset<8>, bitset<32>> registerExWb;

  for (int i = 0;; i++){
    registerIfId = instructionFetch(i, memory);
    if (registerIfId.all() or registerIfId.none())
      break;
    registerIdEx = instructionDecoder(registerIfId, memory);
    registerExWb = execution(registerIdEx, memory);
    writeBack(registerExWb, memory);
  }

  memory->printAll();

}