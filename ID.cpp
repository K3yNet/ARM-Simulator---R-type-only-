#ifndef _TYPES_H
#include "types.hpp"
#endif

RegisterIdEx instructionDecoder(bitset<32> registerIfId, Memory memory){
  
  RegisterIdEx reg;
  bitset<8> opcode;
  bitset<8> numRegisterA;
  bitset<8> numRegisterB;
  bitset<8> numRegisterC;
  int j = 31;

  for (int i = 7; i >= 0; i--){
    opcode[i] = registerIfId[j];
    j--;
  }

  if(opcode == 0b00000001){ // ADD
    
    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
      numRegisterB[i] = registerIfId[i + 8];
      numRegisterA[i] = registerIfId[i + 16];
    }
    reg.registerAData = memory.getRegister(numRegisterA.to_ulong());
    reg.registerBData = memory.getRegister(numRegisterB.to_ulong());
    reg.regWrite = numRegisterC;
    
  }
  else if (opcode == 0b00000010){ // SUB
    
    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
      numRegisterB[i] = registerIfId[i + 8];
      numRegisterA[i] = registerIfId[i + 16];
    }
    reg.registerAData = memory.getRegister(numRegisterA.to_ulong());
    reg.registerBData = memory.getRegister(numRegisterB.to_ulong());
    reg.regWrite = numRegisterC;

  }
  else if (opcode == 0b00000011){ // ZEROS
    
    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
    }
    reg.regWrite = numRegisterC;
    
  }
  else if (opcode == 0b00000100){ // XOR
    
    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
      numRegisterB[i] = registerIfId[i + 8];
      numRegisterA[i] = registerIfId[i + 16];
    }
    reg.registerAData = memory.getRegister(numRegisterA.to_ulong());
    reg.registerBData = memory.getRegister(numRegisterB.to_ulong());
    reg.regWrite = numRegisterC;

  }
  else if (opcode == 0b00000101){ // OR
    
    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
      numRegisterB[i] = registerIfId[i + 8];
      numRegisterA[i] = registerIfId[i + 16];
    }
    reg.registerAData = memory.getRegister(numRegisterA.to_ulong());
    reg.registerBData = memory.getRegister(numRegisterB.to_ulong());
    reg.regWrite = numRegisterC;

  }
  else if (opcode == 0b00000110){ // PASSNOTA
    
    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
      numRegisterA[i] = registerIfId[i + 16];
    }
    reg.registerAData = memory.getRegister(numRegisterA.to_ulong());
    reg.regWrite = numRegisterC;
  
  }
  else if (opcode == 0b00000111){ // AND
    
    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
      numRegisterB[i] = registerIfId[i + 8];
      numRegisterA[i] = registerIfId[i + 16];
    }
    reg.registerAData = memory.getRegister(numRegisterA.to_ulong());
    reg.registerBData = memory.getRegister(numRegisterB.to_ulong());
    reg.regWrite = numRegisterC;

  }
  else if (opcode == 0b00001000){ // ASL
    
    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
      numRegisterB[i] = registerIfId[i + 8];
      numRegisterA[i] = registerIfId[i + 16];
    }
    reg.registerAData = memory.getRegister(numRegisterA.to_ulong());
    reg.registerBData = memory.getRegister(numRegisterB.to_ulong());
    reg.regWrite = numRegisterC;

  }
  else if (opcode == 0b00001001){ // ASR

    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
      numRegisterB[i] = registerIfId[i + 8];
      numRegisterA[i] = registerIfId[i + 16];
    }
    reg.registerAData = memory.getRegister(numRegisterA.to_ulong());
    reg.registerBData = memory.getRegister(numRegisterB.to_ulong());
    reg.regWrite = numRegisterC;

  }
  else if (opcode == 0b00001100){ // PASSA
    
    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
      numRegisterA[i] = registerIfId[i + 16];
    }
    reg.registerAData = memory.getRegister(numRegisterA.to_ulong());
    reg.regWrite = numRegisterC;

  }
  else if (opcode == 0b00001111){ // LOAD
    
    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
      numRegisterA[i] = registerIfId[i + 16];
    }
    reg.registerAData = memory.getRegister(numRegisterA.to_ulong());
    reg.regWrite = numRegisterC;

  }
  else if (opcode == 0b00010000){ // STORE
    
    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
      numRegisterA[i] = registerIfId[i + 16];
    }
    reg.registerAData = memory.getRegister(numRegisterA.to_ulong());
    reg.registerCData = memory.getRegister(numRegisterC.to_ulong());

  }
  else if (opcode == 0b00010001){ // ADDI
    
    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
      numRegisterB[i] = registerIfId[i + 8];
      numRegisterA[i] = registerIfId[i + 16];
    }
    reg.registerAData = memory.getRegister(numRegisterA.to_ulong());
    reg.imediate = numRegisterB;
    reg.regWrite = numRegisterC;

  }
  else if (opcode == 0b00010010){ // SUBI
    
    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
      numRegisterB[i] = registerIfId[i + 8];
      numRegisterA[i] = registerIfId[i + 16];
    }
    reg.registerAData = memory.getRegister(numRegisterA.to_ulong());
    reg.imediate = numRegisterB;
    reg.regWrite = numRegisterC;

  }
  else if (opcode == 0b00010011){ // NAND
    
    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
      numRegisterB[i] = registerIfId[i + 8];
      numRegisterA[i] = registerIfId[i + 16];
    }
    reg.registerAData = memory.getRegister(numRegisterA.to_ulong());
    reg.registerBData = memory.getRegister(numRegisterB.to_ulong());
    reg.regWrite = numRegisterC;

  }
  else if (opcode == 0b00010100){ // NOR
    
    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
      numRegisterB[i] = registerIfId[i + 8];
      numRegisterA[i] = registerIfId[i + 16];
    }
    reg.registerAData = memory.getRegister(numRegisterA.to_ulong());
    reg.registerBData = memory.getRegister(numRegisterB.to_ulong());
    reg.regWrite = numRegisterC;

  }
  else if (opcode == 0b00010101){ // XNOR
    
    for (int i = 7; i >= 0; i--){
      numRegisterC[i] = registerIfId[i];
      numRegisterB[i] = registerIfId[i + 8];
      numRegisterA[i] = registerIfId[i + 16];
    }
    reg.registerAData = memory.getRegister(numRegisterA.to_ulong());
    reg.registerBData = memory.getRegister(numRegisterB.to_ulong());
    reg.regWrite = numRegisterC;

  }
  else if (opcode == 0b11111111){ // HALT
    bitset<8> op (0xff);
    reg.opcode = op;
  }

  return reg;
  
}