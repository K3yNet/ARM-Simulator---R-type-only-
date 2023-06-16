#ifndef _TYPES_H
#include "types.hpp"
#endif
#include "interpreter.cpp"
#include "IF.cpp"
#include "ID.cpp"
#include "EXE.cpp"
#include "WB.cpp"

void CPU(vector<pair<int, bitset<32>>> instructions){

  Memory memory;

  cout << "memoria criada" << endl;

  memory.setInstruction(instructions);

  cout << "memoria de instruções setada" << endl;

  bitset<32> registerIfId;

  RegisterIdEx registerIdEx;

  pair<bitset<8>, bitset<32>> registerExWb;

  for (int i = 0; registerIfId.all(); i++){
    registerIfId = instructionFetch(i, memory);
    cout << "ID" << endl;
    registerIdEx = instructionDecoder(registerIfId, memory);
    cout << "IF" << endl;
    registerExWb = execution(registerIdEx, memory);
    cout << "EXEC" << endl;
    writeBack(registerExWb, memory);
    cout << "WB" << endl;
  }

  memory.printAll();

}