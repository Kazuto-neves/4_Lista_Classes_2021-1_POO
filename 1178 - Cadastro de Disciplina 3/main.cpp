#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class Disciplina {
    private:
        string nome, Nprof;
        int Codigo, Creditos, Ano, Semestre;
        double Nota1, Nota2;
    public:
        void ler();
        void mostrar();
        
};

class Historico {
    private:
        Disciplina v[100];
        int qtd;
    public:
        void inicializarHistorico(Historico &h);
        void inserirDisciplina(Disciplina d, Historico &h);
        void listarHistorico();
};

void Disciplina::ler(){
    cin >> Codigo;
    cin.ignore(1);
    getline(cin, nome);
    getline(cin, Nprof);
    cin >> Creditos >> Ano >> Semestre >> Nota1 >> Nota2;
}

void Disciplina::mostrar(){
    cout << setprecision(2) << fixed;
    cout << setfill('0') << setw(4) << Codigo << " ";
    cout << setfill(' ') << setw(54) << left << nome;
    cout << right << Creditos << " " << right << Ano << "/" << Semestre << " ";
    cout << setfill('0') << setw(5) << (Nota1 + 2.0*Nota2)/3.0 << endl;
}


void Historico::inicializarHistorico(Historico &h){h.qtd = 0;}

void Historico::inserirDisciplina(Disciplina d, Historico &h){
    h.v[h.qtd] = d;
    h.qtd++;
}

void Historico::listarHistorico(){
    int i;
    cout << "Cod. Nome                                               Cred  Ano/S Media" << endl;
    for (i = 0; i < qtd; i++)v[i].mostrar();
}

int menu(){
    int opc;
    do{
        cout << "1 - inicializar" << endl;
        cout << "2 - inserir nova disciplina" << endl;
        cout << "3 - listar historico" << endl;
        cout << "4 - sair" << endl;
        cout << "Entre com a sua opcao:" << endl;
        cin >> opc;
    }while (opc < 1 || opc > 4);

    return opc;
}

int main(){
    Disciplina d;
    Historico h;
    bool end = false;
    string ok;
    h.inicializarHistorico(h);
    while(!end){
        switch (menu()){
        case 1:
            h.inicializarHistorico(h);
            cout << "Historico inicializado com sucesso!" << endl;
            break;
        case 2:
            d.ler();
            h.inserirDisciplina(d, h);
            cout << "Disciplina inserida com sucesso!" << endl;
            break;
        case 3:
            h.listarHistorico();
            cin >> ok;
            while(ok != "Ok"){
                ok = " ";
                cin >> ok;
            }
            break;
        case 4:
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