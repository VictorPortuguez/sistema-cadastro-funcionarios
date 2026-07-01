# Sistema de Cadastro de Funcionários

## 📖 Sobre o projeto

Este projeto foi desenvolvido em linguagem C com o objetivo de praticar conceitos fundamentais da programação, principalmente o uso de estruturas (`struct`), manipulação de arquivos e organização de código.

O sistema realiza um cadastro simples de funcionários, armazenando as informações em um arquivo de texto, permitindo que os dados permaneçam salvos mesmo após o encerramento do programa.

## 🚀 Funcionalidades

* Cadastrar funcionários
* Listar funcionários cadastrados
* Buscar funcionário por ID
* Alterar informações de um funcionário
* Excluir funcionários
* Armazenamento dos dados em arquivo `.txt`

## 🛠️ Tecnologias utilizadas

* Linguagem C
* Manipulação de arquivos (`FILE`)
* Structs
* Ponteiros
* Funções
* Biblioteca padrão da linguagem C

## 📂 Estrutura dos dados

Os funcionários são armazenados em um arquivo texto utilizando o seguinte formato:

```text
id;nome;salario
```

Exemplo:

```text
1;João Silva;2500.00
2;Maria Souza;3200.50
```

## ▶️ Como executar

1. Clone este repositório.
2. Compile o programa utilizando um compilador C, como GCC.

```bash
gcc main.c -o programa
```

3. Execute o programa.

No Windows:

```bash
programa.exe
```

No Linux:

```bash
./programa
```

## 📚 Objetivo

Este projeto foi desenvolvido para fins de estudo durante minha graduação em Ciência da Computação.

O principal objetivo foi praticar conceitos como:

* Manipulação de arquivos
* Organização de código em funções
* Estruturas de dados (`struct`)
* Entrada e saída de dados
* Busca, alteração e remoção de registros

## 🔮 Melhorias futuras

* Interface mais organizada no terminal
* Validação de dados de entrada
* Ordenação dos registros
* Exportação dos dados
* Separação do projeto em múltiplos arquivos (`.h` e `.c`)
* Utilização de arquivos binários

## 👨‍💻 Autor

Desenvolvido como parte dos meus estudos em programação na linguagem C.
