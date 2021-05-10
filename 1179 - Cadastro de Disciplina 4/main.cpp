#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class Disciplina {
    private:
        string nome, Nprof;
        int Codigo, Creditos, Ano, Semestre;
        double nota1, nota2;
    public:
        void ler();
        void mostrar();

        int getCodigo() {return Codigo;}
        string getNome() {return nome;} 
        string getNprof() {return Nprof;}
        int getCreditos() {return Creditos;}
        int getAno() {return Ano;}
        int getSemestre() {return Semestre;}
        double getNota1() {return nota1;}
        double getNota2() {return nota2;}
};

class Historico {
    private:
        Disciplina v[100];
        int qtd;
    public:
        double coeficienteRendimento ();
        void inicializarHistorico(Historico &h);
        void inserirDisciplina(Disciplina d, Historico &h);
        int obterIndice(Historico h, int &id);
        void listar();
        void disciplinasAnoSemestre(int &a, int &b);
        void disciplinasNomeProfessor(string s);
        int excluir(Historico &h, int &id);
        void alterar(Historico &h, int &id, Disciplina d);
        void TodasDiciplinas();
        void historicoM();
};

void Disciplina::ler(){
    cin >> Codigo;
    cin.ignore(1);
    getline(cin, nome);
    getline(cin, Nprof);
    cin >> Creditos >> Ano >> Semestre >> nota1 >> nota2;
}

void Disciplina::mostrar(){
    cout << setfill('0') << setw(4) << Codigo << " ";
    cout << setfill(' ') << setw(54) << left << nome;
    cout << right << Creditos << " " << right << Ano << "/" << Semestre << " ";
    cout << setfill('0') << setw(5) << (nota1 + 2.0*nota2)/3.0 << endl;
}

int Historico::obterIndice(Historico h, int &id){
    int i = 0;
    bool achou = 0;
    while (!achou && i<h.qtd){
        id == v[i].getCodigo() ? achou = 1 : i++;
    }
    return achou ? i : -1;
}

int Historico::excluir(Historico &h, int &id){
   int pos = obterIndice(h, id);
   if (pos>-1){
       h.v[pos] = h.v[h.qtd-1];
       h.qtd--;
       return 1;
   }else return 0;
}

void Historico::alterar(Historico &h, int &id, Disciplina d){
   int pos = obterIndice(h, id);
   h.v[pos] = d;
}

void Historico::inicializarHistorico(Historico &h){h.qtd = 0;}

void Historico::inserirDisciplina(Disciplina d, Historico &h){
    h.v[h.qtd] = d;
    h.qtd++;
}

void Historico::listar(){cout << "Cod. Nome                                               Cred  Ano/S Media" << endl;}

void Historico::disciplinasAnoSemestre(int &a,int &b){
    int i;
    listar();
    for(i = 0; i<qtd; i++)
        if ((v[i].getAno() == a) && (v[i].getSemestre() == b))v[i].mostrar();
}

void Historico::disciplinasNomeProfessor(string s){
    int i, posN = 0, posP = 0;
    listar();
    for(i = 0; i<qtd; i++){
        posN = v[i].getNome().find(s);
        posP = v[i].getNprof().find(s);
        if (posN > -1 || posP > -1)v[i].mostrar();
    }
}

void Historico::TodasDiciplinas(){
    int i;
    listar();
    for (i = 0; i < qtd; i++)v[i].mostrar();
}

double Historico::coeficienteRendimento (){
    int i;
    double credtotal = 0 ,soma = 0,cr = 0;
    for ( i = 0 ; i < qtd ; i++ ){
        soma+=( ((v[i].getNota1() + 2.0*v[i].getNota2())/3.0) * v[i].getCreditos() );
        credtotal+=v[i].getCreditos();
    }
    if (qtd != 0)cr=soma/credtotal;
    return cr;
}

void Historico::historicoM(){
    int i;
    cout << setprecision(2) << fixed;
    h.TodasDiciplinas();
    cout << "Coeficiente de Rendimento                                           " << setfill('0') << setw(5) << right << coeficienteRendimento()<< endl;
    }

int menu(){
    int opc;
    do{
        cout << "1 - inserir nova disciplina" << endl;
        cout << "2 - remover disciplina pelo codigo" << endl;
        cout << "3 - alterar disciplina pelo codigo" << endl;
        cout << "4 - listar todas as disciplinas" << endl;
        cout << "5 - listar disciplinas de um ano/semestre" << endl;
        cout << "6 - listar disciplinas pelo nome/professor" << endl;
        cout << "7 - Historico" << endl;
        cout << "8 - sair" << endl;
        cout << "Entre com a sua opcao:" << endl;
        cin >> opc;
    }while (opc < 1 || opc > 8);
    return opc;
}
int main(){
    Disciplina d;
    Historico h;
    bool end = false;
    string ok,s;
    int i,j,k;
    string confirma, busca;
    int buscar, buscarano, buscarsemestre;
    h.inicializarHistorico(h);
    cout << setprecision(2) << fixed;
    while(!end){
        switch (menu()){
            case 1:
                d.ler();
                h.inserirDisciplina(d, h);
                cout << "Disciplina inserida com sucesso!" << endl;
                break;
            case 2:
                cin >> i;
                if(h.excluir(h,i))cout << "Disciplina removida com sucesso!" << endl;
                else cout << "Disciplina nao encontrada!" << endl;
                break;
            case 3:
                cin >> i;
                if(h.obterIndice(h, i) > -1){
                    d.ler();
                    h.alterar(h, i, d);
                    cout << "Disciplina alterada com sucesso!" << endl;
                }else cout << "Disciplina nao encontrada!" << endl;
                break;
            case 4:
                h.TodasDiciplinas();
                cin >> ok;
                while(ok != "Ok"){
                    ok = " ";
                    cin >> ok;
                }
                break;
            case 5:
                cin >> i >> j;
                h.disciplinasAnoSemestre(i,j);
                cin >> ok;
                while(ok != "Ok"){
                    ok = " ";
                    cin >> ok;
                }
                break;
            case 6:
                cin.ignore(1);
                getline(cin, s);
                h.disciplinasNomeProfessor(s);
                cin >> ok;
                while(ok != "Ok"){
                    ok = " ";
                    cin >> ok;
                }
                break;
            case 7:
                h.historicoM();
                cin >> ok;
                while(ok != "Ok"){
                    ok = " ";
                    cin >> ok;
                }
                break; 
            case 8:
                cout << "Obrigado por utilizar o programa de cadastro, volte sempre!" << endl;
                end = true;
                break;
            default:
                menu();
                break;
            }
        }
    return 0;
}
