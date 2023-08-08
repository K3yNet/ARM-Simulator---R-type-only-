# Simulador de Processador ARM para Instruções do Tipo R

![License](https://img.shields.io/badge/license-MIT-blue.svg

Bem-vindo ao Simulador de Processador ARM para Instruções do Tipo R! Este é um projeto que desenvolvi para simular o funcionamento de um processador baseado na arquitetura ARM, focando exclusivamente nas instruções do tipo R. Com esse simulador, você poderá entender melhor como funcionam e como são executadas as instruções do tipo R em processadores ARM.

##Visão Geral

O simulador foi implementado utilizando a linguagem c++ e tem como objetivo fornecer uma representação simples e funcional de um processador que suporte as instruções do tipo R da arquitetura ARM. As instruções do tipo R são aquelas que envolvem operações aritméticas e lógicas entre dois registradores.

##Funcionalidades

Implementação das principais instruções do tipo R: ADD, SUB, ZEROS, XOR, OR, PASSNOTA, AND, ASL, ASR, PASSA, LOAD, STORE, ADDI, SUBI, NAND, NOR, XNOR, HALT.
Suporte para carregar dados em registradores e executar operações aritméticas e lógicas.
Exibição do resultado das instruções fornecidas.

Como Usar

Clone este repositório em sua máquina local.
Abra o teste.txt e faça seu codigo ARM na seguinte formatação:
add R1, R2, R3
addi R1, R2, 20
Execute o simulador.
