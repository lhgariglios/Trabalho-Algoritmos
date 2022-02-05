/*Projeto Algotitmo Controle de Estoque - Luiz Henrique Gariglio dos Santos - 2022*/
#include <iostream>
#include <stdlib.h>
#include <list>

using namespace std;

struct Produto
{
    string Nome;
    float Quantidade = 0;
    float Custo = 0;
    float Preco = 0;
    string Codigo;
};

/*Iniciando Funções*/

void Inicio();
struct Produto Registro_Produtos();
void Consultar_Estoque(list <Produto> Estoque);
void Mostrar_Estoque(list <Produto> Estoque);
void Buscar_Produto(list <Produto> Estoque);
void Alterar_Estoque(list <Produto> &Estoque);


int main()
{
    int acao = 0;
    list<Produto> Estoque;
    list<Produto>::iterator it = Estoque.begin();

    while (acao != 4)
    {
        Inicio();
        cin >> acao;
        if (acao == 1)
        {           
            Estoque.push_back(Registro_Produtos());
            cout << Estoque.size();

        }else if(acao == 2)
        {
            Alterar_Estoque(Estoque);

        }else if (acao == 3) 
        {
            Consultar_Estoque(Estoque);
            
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
    system("clear || cls");
    cout << "\n\tPrograma Controle de Estoque - Luiz Henrique Gariglio dos Santos\n";
    cout << "\n\tDigite o que deseja fazer:\n";
    cout << "\n\t1 - Registro de Produtos;";
    cout << "\n\t2 - Movimentacoes de Estoque;";
    cout << "\n\t3 - Consultar estoque;";
    cout << "\n\t4 - Sair.\n\n\t";
}

struct Produto Registro_Produtos()
{
    Produto produto;

    system("clear || cls");
    cout << "\n\tDigite o nome do produto: ";
    cin >> produto.Nome;
    cout << "\n\tDigite o codigo do produto: ";
    cin >> produto.Codigo;
    cout << "\n\tDigite a quantidade: ";
    cin >> produto.Quantidade;
    cout << "\n\tDigite o custo do produto: ";
    cin >> produto.Custo;
    cout << "\n\tDigite o preco do produto: ";
    cin >> produto.Preco;
    
    return produto;
}

void Consultar_Estoque(list <Produto> Estoque) 
{
    int acao_E = 0;
    
    while (acao_E != 3)
    {
        system("clear || cls");
        cout << "\n\tEstoque\n";
        cout << "\n\tDigite o que deseja fazer:\n";
        cout << "\n\t1 - Mostrar estoque;";
        cout << "\n\t2 - Buscar Produto;";
        cout << "\n\t3 - Sair.\n\n\t";
        cin >> acao_E;

        if (acao_E == 1)
        {
            Mostrar_Estoque(Estoque);
        }
        else if (acao_E == 2)
        {
            Buscar_Produto(Estoque);

        }
        else if (acao_E == 3)
        {
            cout << "\n\tSaindo ...";
        }
    }
}

void Mostrar_Estoque (list <Produto> Estoque)
{
    list<Produto>::iterator it;
    int sair_E = 0;

    system("clear || cls");
    for (it = Estoque.begin(); it != Estoque.end(); ++it)
    {
        cout << "\n\t Nome: " << it->Nome;
        cout << "\n\t Codigo: " << it->Codigo;
        cout << "\n\t Quantidade no estoque: " << it->Quantidade;
        cout << "\n\t Custo do produto: " << it->Custo;
        cout << "\n\t Preco de venda: " << it->Preco;
        cout << endl;
    }

    cout << "\n\tPressione 1 para sair.";
    cin >> sair_E;
    if (sair_E == 1)
    {
        cout << "\n\tSaindo...";
    }
}

void Alterar_Estoque (list <Produto> &Estoque)
{
    list<Produto>::iterator it;
    string nome;
    int movimentacao = 0, quantidade = 0;
    system("clear || cls");
    cout << "\n\tDigite o nome ou o codigo do produto que deseja alterar: ";
    cin >> nome;

    for (it = Estoque.begin(); it != Estoque.end(); ++it)
    {
        if (nome == it->Nome || nome == it->Codigo)
        {
            while (movimentacao != 1 && movimentacao != 2)
            {
                cout << "\n\tSelecione:\n\t1-Entrada\n\t2-Retirada\n\t";
                cin >> movimentacao;

                if (movimentacao == 1)
                {
                    cout << "\n\tDigite a quantidade: ";
                    cin >> quantidade;
                    it->Quantidade = it->Quantidade + quantidade;
                }
                else if (movimentacao == 2)
                {
                    cout << "\n\tDigite a quantidade: ";
                    cin >> quantidade;
                    it->Quantidade = it->Quantidade - quantidade;
                }
                else
                {
                    cout << "\n\tDigite uma entrada valida!";
                }
            }
        }
    }
}

void Buscar_Produto (list <Produto> Estoque)
{
    list<Produto>::iterator it;
    string nome;
    int sair_E = 0;
    system("clear || cls");
    cout << "\n\tDigite o nome ou o codigo do produto que deseja buscar: ";
    cin >> nome;

    for (it = Estoque.begin(); it != Estoque.end(); ++it)
    {
        if (nome == it->Nome || nome == it->Codigo)
        {
            cout << "\n\t Nome: " << it->Nome;
            cout << "\n\t Codigo: " << it->Codigo;
            cout << "\n\t Quantidade no estoque: " << it->Quantidade;
            cout << "\n\t Custo do produto: " << it->Custo;
            cout << "\n\t Preco de venda: " << it->Preco;
            cout << endl;
        }
    }
    cout << "\n\tPressione 1 para sair.";
    cin >> sair_E;
    if (sair_E == 1)
    {
        cout << "\n\tSaindo...";
    }
}