/*Projeto Algotitmo Controle de Estoque - Luiz Henrique Gariglio dos Santos - 2022*/
#include <iostream>
#include <list>

using namespace std;

struct Produto
{
    string Nome;
    float Quantidade = 0;
    float Custo = 0;
    float Preco = 0;
    int Codigo = 0;
};

/*Iniciando Funções*/

void Inicio();
// struct Produto Registro_Produtos(struct Produto Estoque);

int main()
{
    int acao = 0;
    string nome;
    Produto produto;
    list<Produto> Estoque;
    list<Produto>::iterator it = Estoque.begin();
    

    while (acao != 4)
    {
        Inicio();
        cin >> acao;
        if (acao == 1)
        {
            //Registro_Produtos(Estoque);
            cout << "\n\tDigite o nome do produto: ";
            cin >> produto.Nome;            
            cout << "\n\tDigite a quantidade: ";
            cin >> produto.Quantidade;
            cout << "\n\tDigite o custo do produto: ";
            cin >> produto.Custo;
            cout << "\n\tDigite o preco do produto: ";
            cin >> produto.Preco;
            cout << "\n\tDigite o codigo do produto: ";
            cin >> produto.Codigo;

            Estoque.push_back(produto);
            cout << Estoque.size();



        }else if(acao == 2)
        {

        }else if (acao == 3) 
        {
            for (it = Estoque.begin(); it != Estoque.end(); ++it)
            {
                cout << it->Nome;
                cout << it->Quantidade;
                cout << it->Custo;
                cout << it->Preco;
                cout << it->Codigo;
                
            }
            
        }else if (acao == 4) 
        {
            cout << "\n\tSaindo ...";
        }else{
            cout << "\n\tDigite uma entrada valida!";
        }

    }
    return 0;
}

/*Funções*/
void Inicio()
{
    cout << "\n\tPrograma Controle de Estoque - Luiz Henrique Gariglio dos Santos\n";
    cout << "\n\tDigite o que deseja fazer:\n";
    cout << "\n\t1 - Registro de Produtos;";
    cout << "\n\t2 - Movimentacoes de Estoque;";
    cout << "\n\t3 - Estoque;";
    cout << "\n\t4 - Sair.\n\n\t";
}

/*
struct Produto Registro_Produtos(struct Produto Estoque)
{
    cout << "\n\tDigite o nome do produto: ";
    cin >> Estoque.Nome;
    cout << "\n\tDigite a quantidade: ";
    cin >> Estoque.Quantidade;
    cout << "\n\tDigite o custo do produto: ";
    cin >> Estoque.Custo;
    cout << "\n\tDigite o preco do produto: ";
    cin >> Estoque.Preco;
    cout << "\n\tDigite o codigo do produto: ";
    cin >> Estoque.Codigo;
    return Estoque;
}
*/