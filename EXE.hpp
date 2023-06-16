#include<bits/stdc++.h>
#include "memory.hpp"
#include "ID.hpp"
using namespace std;

bitset<32> bitAdder(char type, bitset<32> a, bitset<32> b){

  bitset<32> result;

  if (type == '+'){

    bool carry = false;

    for (int i = 0; i < 32; ++i){
      bool bit_a = a[i];
      bool bit_b = b[i];

      // Soma dos bits
      result[i] = bit_a ^ bit_b ^ carry;

      // Verifica se há carry
      carry = (bit_a & bit_b) || (bit_a & carry) || (bit_b & carry);
    }

  }
  else if (type == '-'){
    b.flip();
    result = bitAdder('+', a, bitAdder('+', b, 0b1));
  }
  
  return result;

}

pair<bitset<8>, bitset<32>> execution(RegisterIdEx reg, Memory memory){

  pair<bitset<8>, bitset<32>> result;
  
  if(reg.opcode == 0b00000001){ // ADD
    result.second = bitAdder('+', reg.registerAData, reg.registerBData);
    result.first = reg.regWrite;
  }
  else if (reg.opcode == 0b00000010){ // SUB
    result.second = bitAdder('-', reg.registerAData, reg.registerBData);
    result.first = reg.regWrite;
  }
  else if (reg.opcode == 0b00000011){ // ZEROS
    result.first = reg.regWrite;
    result.second = 0b0;
  }
  else if (reg.opcode == 0b00000100){ // XOR
    result.first = reg.regWrite;
    result.second = reg.registerAData ^ reg.registerBData;
  }
  else if (reg.opcode == 0b00000101){ // OR
    result.first = reg.regWrite;
    result.second = reg.registerAData | reg.registerBData;
  }
  else if (reg.opcode == 0b00000110){ // PASSNOTA
    result.first = reg.regWrite;
    result.second = ~reg.registerAData;
  }
  else if (reg.opcode == 0b00000111){ // AND
    result.first = reg.regWrite;
    result.second = reg.registerAData & reg.registerBData;
  }
  else if (reg.opcode == 0b00001000){ // ASL
    result.first = reg.regWrite;
    result.second = reg.registerAData << reg.registerBData.to_ulong();
  }
  else if (reg.opcode == 0b00001001){ // ASR
    result.first = reg.regWrite;
    result.second = reg.registerAData >> reg.registerBData.to_ulong();
  }
  else if (reg.opcode == 0b00001100){ // PASSA
    result.first = reg.regWrite;
    result.second = reg.registerAData;
  }
  else if (reg.opcode == 0b00001111){ // LOAD
    result.first = reg.regWrite;
    bitset<32> data (memory.getData(reg.registerAData.to_ulong()).to_ulong());
    result.second = data;
  }
  else if (reg.opcode == 0b00010000){ // STORE
    result.first = 0b0;
    bitset<16> data (reg.registerAData.to_ulong());
    memory.setData(reg.registerCData.to_ulong(), data);
  }
  else if (reg.opcode == 0b00010001){ // ADDI
    bitset<32> constant (reg.imediate.to_ulong());
    result.second = bitAdder('+', reg.registerAData, constant);
    result.first = reg.regWrite;
  }
  else if (reg.opcode == 0b00010010){ // SUBI
    bitset<32> constant (reg.imediate.to_ulong());
    result.second = bitAdder('-', reg.registerAData, constant);
    result.first = reg.regWrite;
  }
  else if (reg.opcode == 0b00010011){ // NAND
    result.first = reg.regWrite;
    result.second = ~(reg.registerAData & reg.registerBData);
  }
  else if (reg.opcode == 0b00010100){ // NOR
    result.first = reg.regWrite;
    result.second = ~(reg.registerAData | reg.registerBData);
  }
  else if (reg.opcode == 0b00010101){ // XNOR
    result.first = reg.regWrite;
    result.second = ~(reg.registerAData ^ reg.registerBData);
  }
  else{
    result.first = 0xff;
    result.second = 0xffffffff;
  }

  return result;

}