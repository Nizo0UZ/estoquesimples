#include <iostream>
#include <stdlib.h>

using namespace std;

class Produto{
    private:
    string nomeP;
    int quant;
    float preco;

    public:
    //construtor
    Produto(string nomeP, int quant, float preco){
        this->nomeP = nomeP;
        this->quant = quant;
        this->preco = preco;
    }
    int getquant(){
        return quant;
    }
    void addQuantidade(int q){
        quant += q;
    }
    void removeQuantidade(int q){
        if(quant>=q){
            cout << q << " foram removidas de " << quant << endl;
            quant -= q;
        }else{
            cout << "Quantidade Insuficiente" << endl;
        }
    }
    void ExibicaoProduto(){
        cout << "Produto: " << nomeP << " /" << " Estoque: " << quant << " /" << " Preco: RS" << preco << endl;
    }
};

class Funcionario{
    private:
    string nomeF;
    string funcao;

    public:
    //Construtor
    Funcionario(string nomeF, string funcao){
        this->nomeF = nomeF;
        this->funcao = funcao;
    }
    //Exibir dados do funcionario
    void exibirFuncionario(){
        cout << "Funcionario: " << nomeF << " /" << " Cargo: " << funcao << endl;
    }
};


int main(){

    Produto produto1("Cerveja", 20, 2.99);
    Produto produto2("Picanha", 10, 1.99);
    Funcionario fun1("Lucas", "Caixa");
    Funcionario fun2("Willen", "Estoquista");

    int select;
    bool sair=false;

    while(!sair){
        cout << "\nMenu de Gerenciamento de Estoque:" << endl;
        cout << "[1] Adicionar produto ao estoque." << endl;
        cout << "[2] Remover produto do estoque." << endl;
        cout << "[3] Exibir Produto." << endl;
        cout << "[4] Lista de Funcionarios." << endl;
        cout << "[5] SAIR" << endl;
        cout << "Escolha alguma das opcoes:";
        cin >> select;
        system("cls");

        switch (select){
            case 1:{
                //add o produto ao estoque
                int quantidadeadd;
                int opcao;
                cout << "Adicionar para [1] Cerveja ou [2] Picanha?\n";
                cin >> opcao;
                if(opcao==1){
                    cout << "Quantas quantidades adicionar?\n";
                    cin >> quantidadeadd;
                    produto1.addQuantidade(quantidadeadd);
                    cout << quantidadeadd << " unidades de " << produto1.getquant() << " adicionadas ao estoque.\n" << endl;
                } else if(opcao==2){
                    cout << "Quantas quantidades adicionar?\n";
                    cin >> quantidadeadd;
                    produto2.addQuantidade(quantidadeadd);
                    cout << quantidadeadd << " unidades de " << produto2.getquant() << " adicionadas ao estoque.\n" << endl;
                }else{
                    cout << "ERRO";
                }
                break;
            }
            case 2:{
                //Remover produto
                int quantidadermv;
                int opcao;
                cout << "Remover para [1] Cerveja ou [2] Picanha?\n";
                cin >> opcao;
                if(opcao==1){
                    cout << "Quantas quantidades remover?\n";
                    cin >> quantidadermv;
                    produto1.removeQuantidade(quantidadermv);
                } else if(opcao==2){
                    cout << "Quantas quantidades remover?\n";
                    cin >> quantidadermv;
                    produto2.removeQuantidade(quantidadermv);
                }else{
                    cout << "ERRO";
                }
                break;
            }
            case 3:{
                //info dos produtos
                produto1.ExibicaoProduto();
                produto2.ExibicaoProduto();
                break;
            }
            case 4:{
                //info funcionarios
                fun1.exibirFuncionario();
                fun2.exibirFuncionario();
                break;
            }
            case 5: {
                //saida
                cout << "Saindo do Sistema de Gerenciamento de Estoque..." << endl;
                sair = true;
                break;
            }
            default: 
                cout << "Opcao invalida! Tente novamente." << endl;
        }
    }

    return 0;
}
// Para add novos funcionarios ou produtos é atraves do int main
// Se for add mais talvez tenha q criar um switch dentro do switch ou continuar com if e else