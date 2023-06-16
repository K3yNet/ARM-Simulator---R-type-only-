#ifndef _TYPES_H
#include "types.hpp"
#endif

vector<string> split(string instruction){

  string aux;
  vector<string> result;

  istringstream spliter(instruction);

  while (spliter >> aux){
    
    for (int i = 0; i < int(aux.size()); i++){
      if(aux[i] == 'R' or aux[i] == ',')
        aux.erase(next(aux.begin(), i));
    }
    
    result.push_back(aux);

  }
  
  return result;
  
}

bitset<32> binaryGen(vector<string> instruction){
  
  int rc, ra, rb;
  
  if(mapOpcode.find(instruction[0]) == mapOpcode.end()){
    throw "Instrução não encontrada";
  }

  string opcode = mapOpcode[instruction[0]];

  if(opcode == "00000001"){ // ADD
    rc = stoi(instruction[1]);
    ra = stoi(instruction[2]);
    rb = stoi(instruction[3]);
  }
  else if (opcode == "00000010"){ // SUB
    rc = stoi(instruction[1]);
    ra = stoi(instruction[2]);
    rb = stoi(instruction[3]);
  }
  else if (opcode == "00000011"){ // ZEROS
    rc = stoi(instruction[1]);
    ra = rb = 0;
  }
  else if (opcode == "00000100"){ // XOR
    rc = stoi(instruction[1]);
    ra = stoi(instruction[2]);
    rb = stoi(instruction[3]);
  }
  else if (opcode == "00000101"){ // OR
    rc = stoi(instruction[1]);
    ra = stoi(instruction[2]);
    rb = stoi(instruction[3]);
  }
  else if (opcode == "00000110"){ // PASSNOTA
    rc = stoi(instruction[1]);
    ra = stoi(instruction[2]);
    rb = 0;
  }
  else if (opcode == "00000111"){ // AND
    rc = stoi(instruction[1]);
    ra = stoi(instruction[2]);
    rb = stoi(instruction[3]);
  }
  else if (opcode == "00001000"){ // ASL
    rc = stoi(instruction[1]);
    ra = stoi(instruction[2]);
    rb = stoi(instruction[3]);
  }
  else if (opcode == "00001001"){ // ASR
    rc = stoi(instruction[1]);
    ra = stoi(instruction[2]);
    rb = stoi(instruction[3]);
  }
  else if (opcode == "00001100"){ // PASSA
    rc = stoi(instruction[1]);
    ra = stoi(instruction[2]);
    rb = 0;
  }
  else if (opcode == "00001111"){ // LOAD
    rc = stoi(instruction[1]);
    ra = stoi(instruction[2]);
    rb = 0;
  }
  else if (opcode == "00010000"){ // STORE
    rc = stoi(instruction[1]);
    ra = stoi(instruction[2]);
    rb = 0;
  }
  else if (opcode == "00010001"){ // ADDI
    rc = stoi(instruction[1]);
    ra = stoi(instruction[2]);
    rb = stoi(instruction[3]);
  }
  else if (opcode == "00010010"){ // SUBI
    rc = stoi(instruction[1]);
    ra = stoi(instruction[2]);
    rb = stoi(instruction[3]);
  }
  else if (opcode == "00010011"){ // NAND
    rc = stoi(instruction[1]);
    ra = stoi(instruction[2]);
    rb = stoi(instruction[3]);
  }
  else if (opcode == "00010100"){ // NOR
    rc = stoi(instruction[1]);
    ra = stoi(instruction[2]);
    rb = stoi(instruction[3]);
  }
  else if (opcode == "00010101"){ // XNOR
    rc = stoi(instruction[1]);
    ra = stoi(instruction[2]);
    rb = stoi(instruction[3]);
  }
  else if (opcode == "11111111"){ // HALT
    rc = ra = rb = 0b11111111;
  }

  bitset<8> opcodeBin (opcode);
  bitset<8> registerA (ra);
  bitset<8> registerB (rb);
  bitset<8> registerC (rc);

  bitset<32> result;

  for (int i = 7; i >= 0; i--){
    result[i + 24] = opcodeBin[i];
    result[i + 16] = registerA[i];
    result[i + 8] = registerB[i];
    result[i] = registerC[i];
  }
  
  return result;

}

//int = endereço na memoria
//string = instrução em binario
vector<pair<int, bitset<32>>> interpreter(vector<string> instructionList){

  vector<pair<int, bitset<32>>> result;
  vector<string> aux;
  
  for (int i = 0; i < int(instructionList.size()); i++){
    aux = split(instructionList[i]);

    result.push_back({i, binaryGen(aux)});
    
  }

  return result;
  
}