#include<bits/stdc++.h>
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
      cout << i << " " << registerBank[i].to_ulong() << endl;
    }
    cout << endl << endl;

    cout << "L1 de dados" << endl;
    for (int i = 0; i < (64 * 1024); i++){
      if(!L1DataCache[i].none()){
        cout << i << " " << L1DataCache[i].to_ulong() << endl;
      }
    }

    cout << "L1 de instrucoes" << endl;
    for (int i = 0; i < (64 * 1024); i++){
      if(!L1InstructionCache[i].none()){
        cout << i << " " << L1InstructionCache[i].to_ulong() << endl;
      }
    }
    
  }

};