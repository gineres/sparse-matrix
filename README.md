[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7997462&assignment_repo_type=AssignmentRepo)
# Lista de Exercícios 2 — Unidade 2

Está atividade é individual e corresponde à metade da nota da segunda unidade.

Implemente uma aplicação em C++ para representação de uma matriz esparsa, isto é, uma matriz em que a maioria das posições armazena o valor zero. Para isso, siga os seguintes passos:

(Peso 0.5) Crie uma classe para representar objetos que possui dois atributos inteiros, um índice e um valor, e um construtor atribuindo o valor inicial desses atributos;

(Peso 0.5) Crie uma classe para representar uma linha da matriz. Uma linha deve ter um campo indicando a sua posição na matriz e também deve armazenar todos os elementos presentes, isto é, os zeros não devem ser armazenados na matriz. Observe que cada elemento deve ser representado pelo seu índice e valor utilizando objetos da classe criada no item anterior;

(Peso 1) Crie uma classe para representar a matriz. Ela deve ter informações sobre as suas dimensões e também deve armazenar somente as linhas que possuam ao menos um elemento. Observe que isso deve ser feito utilizando objetos da classe criada no item anterior;

(Peso 3) Além disso, a matriz deve ter métodos para:
1. Inserir um elemento na matriz dada uma posição e valor;
2. Remover um elemento da matriz dado uma posição;
3. Busca um valor armazenado numa posição informada;
4. Verificar a existência de um valor na matriz. Deve ser retornado verdadeiro ou falso indicando a existência do valor e, além disso, a posição deve ser retornada por passagem por referência.

(Peso 2) Modifique os métodos do item anterior para utilizar busca binária sempre que for necessário acessar uma posição da matriz;

(Peso 1) Crie um método para gravar a matriz num arquivo. Somente os elementos existentes devem ser armazenados;

(Peso 1) Crie um método para recuperar os dados da matriz a partir de um arquivo.

(Peso 1) Além disso, você deve criar testes para verificar se cada método faz o que deveria fazer. Para isso, crie um arquivo de código-fonte com uma função para verificar cada um dos métodos criados, incluindo os construtores (também destrutores, caso existam). É opcional o uso de algum framework para execução de testes, por exemplos:

[https://github.com/catchorg/Catch2]

[https://google.github.io/googletest/]

[https://cpptest.sourceforge.io/]
