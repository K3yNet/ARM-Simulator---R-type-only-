#include<bits/stdc++.h>

#define _TYPES_H

using namespace std;

struct Memory{

  bitset<16> L1DataCache[64 * 1024];
  bitset<32> L1InstructionCache[64 * 1024];
  bitset<32> registerBank[32];

  void setData(int address, bitset<16> data){
    L1DataCache[address] = data;
  }

  bitset<16> getData(int address){
    return L1DataCache[address];
  }

  void setInstruction(vector<pair<int, bitset<32>>> instructionList){
    
    for (auto it: instructionList){
      L1InstructionCache[it.first] = it.second;
    }
    
  }

  bitset<32> getInstruction(int address){
    return L1InstructionCache[address];
  }

  void setRegister(int registerNum, bitset<32> data){
    
    if(registerNum == 0){
      cout << "!!! Tentativa de escrita no registrador 0 !!!" << endl;
      return;
    }
    else
      registerBank[registerNum] = data;
    
  }

  bitset<32> getRegister(int registerNum){
    return registerBank[registerNum];
  }

  void printAll(){
    cout << "Banco de registradores" << endl;
    for (int i = 0; i < 32; i++){
      cout << i << " " << registerBank[i] << endl;
    }
    cout << endl;

    cout << "L1 de dados" << endl;
    for (int i = 0; i < (64 * 1024); i++){
      if(!L1DataCache[i].none()){
        cout << i << " " << L1DataCache[i] << endl;
      }
    }

    cout << "L1 de instrucoes" << endl;
    for (int i = 0; i < (64 * 1024); i++){
      if(!L1InstructionCache[i].none()){
        cout << i << " " << L1InstructionCache[i] << endl;
      }
    }
    
  }

};

struct RegisterIdEx{
  
  bitset<8> opcode;
  bitset<8> regWrite;

  bitset<32> registerAData;
  bitset<32> registerBData;
  bitset<32> registerCData;

  bitset<8> imediate;

};

map<string, string> mapOpcode = {
    {"add", "00000001"}, // 3
    {"sub", "00000010"}, // 3
    {"zeros", "00000011"}, // 1
    {"xor", "00000100"}, // 3
    {"or", "00000101"}, // 3
    {"passnota", "00000110"}, // 2
    {"and", "00000111"}, // 3
    {"asl", "00001000"}, // 3
    {"asr", "00001001"}, // 3
    {"passa", "00001100"}, // 2
    {"load", "00001111"}, // 3*
    {"store", "00010000"}, // 3*
    {"addi", "00010001"}, // 3
    {"subi", "00010010"}, // 3
    {"nand", "00010011"}, // 3
    {"nor", "00010100"}, // 3
    {"xnor", "00010101"}, // 3
    {"halt", "11111111"}
};