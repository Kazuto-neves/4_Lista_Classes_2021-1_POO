# Cadastro de Disciplina 3

Fazer um programa para gerenciar  o seu  historico de disciplinas. O programa deve mostrar um menu de op��es com 4 opcoes: inicializar, inserir nova disciplina, listar historico e sair.  Ao Iniciar o programa o historico deve iniciar vazio.Os dados da disciplina s�o: codigo: inteiro, Nome:string, Professor: string, Creditos: inteiro, Ano: Inteiro, Semestre: inteiro, Nota1: double e Nota 2: double.a m�dia � calculada usando a nota1 e a nota2, nota 1 com peso 1 e nota 2 com peso 2.  

*Calculo da media = (nota1 + 2.0 \* nota2)/3.0*

**Obs: pode usar struck para representar a disciplina**   

Exemplo de Struct C#
~~~C#
class xyz{
  public struct Pessoa{
    public string nome;
    public double peso,altura;
    public int idade;
  }

  public static void Main()
  {
       .....
  }
}
~~~

# Entrada

A entrada de dados contem os valores que o usu�rio digitaria, desta forma para inserir eles digita 2 e depois os dados da disciplina na seguinte ordem: Codigo, Nome, Nome do Professor, Creditos, Ano, Semestre,Nota1 e Nota2. Para listar ele digitaria 3, as disciplinas seriam apresentadas e depois digita "Ok" para voltar ao menu. Finalmente para sair ele apertaria 4 e o programa se encerra escrevendo na tela "obrigado por utilizar o programa.". A qualquer momento ele pode digitar 1, para remover todas as disciplinas e ficar com o historico vazio.

# Sa�da

Voc� pode clicar aqui para digitar a descri��o da entrada do seu problema usando multiplos par�grafos se necess�rio.

Primeiro mostra-se o menu, e depois depende da op��o que o usu�rio escolher

## Menu

mostra o menu de op��es: "1 - inicializar", "inserir nova disciplina", "" e "4 - sair".OBS: Caso seja digitado um numero inv�lido, menor que 1 ou maior que 3, o menu dever� ser apresentado novamente.

1 - inicializar  
2 - inserir nova disciplina  
3 - listar historico  
4 - sair  
Entre com a sua opcao:

## Inicializar

nesta o op��o todas as disciplinas j� cadastras ser�o removidas e o hist�rico deve ficar vazio. Ao escolher essa op��o o historico � zerado, e o sistema deve apresentar a mensagem "Historico inicializado com sucesso!"

## Inserir nova disciplina

nesta op��o o usu�rio deve digitar os dados da disciplina na ordem, nada � escrito na tela, ap�s a digita��o o programa deve inserir a disciplina no historico e apresentar a mensagem "Disciplina inserida com sucesso!"

## Listar historico

Nesta op��o o programa dever� listar todas as disciplinas do hist�rico  no seguinte formato: codigo com 4 digitos e preenchido com zero a esquerda, nome com 50 caracteres e alinhado a esquerda, Creditos com 4 caractres e alinhado a direita, Ano/Semestre, ano com 4 digitos e semestre com 1 digito, media com 5 caracteres e 2 de precis�o. N�o esquecer de colocar o cabe�alho. Ap�s a listagem, o programa deve ficar esperando o usuario digitar "Ok" para voltar ao menu principal. Conforme mostrado abaixo:

~~~
Cod. Nome                                               Cred  Ano/S Media
9876 Calculo I                                             6 2020/1 07.03
0001 Ingles Tecnico                                        3 2020/1 06.67
1001 Programacao Orientada a Objetos                       3 2020/1 07.30
1010 Programacao em Java                                   3 2020/1 10.00
~~~

## Sair

Nesta op��o o programa deve escrever a mensagem "Obrigado por utilizar o programa de cadastro, volte sempre!" e encerra a aplica��o