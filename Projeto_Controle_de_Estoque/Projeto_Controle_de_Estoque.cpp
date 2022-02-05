/*Projeto Algotitmo Controle de Estoque - Luiz Henrique Gariglio dos Santos - 2022*/
#include <iostream>
#include <stdlib.h>
#include <list>

using namespace std;

struct Produto
{
    string Nome;
    string Codigo;
    float Quantidade = 0;
    float Custo = 0;
    float Preco = 0;
};

/*Iniciando Funções*/

void Inicio();

void Operacoes_Produtos(list <Produto>& Estoque);

struct Produto Registro_Produtos();

void Alterar_Produto(list <Produto>& Estoque);

void Alterar_Estoque(list <Produto>& Estoque);

void Consultar_Estoque(list <Produto> Estoque);

void Mostrar_Estoque(list <Produto> Estoque);

void Buscar_Produto(list <Produto> Estoque);




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
            Operacoes_Produtos(Estoque);

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
    cout << "\n\t1 - Produtos;";
    cout << "\n\t2 - Movimentacoes de Estoque;";
    cout << "\n\t3 - Consultar estoque;";
    cout << "\n\t4 - Sair.\n\n\t";
}

void Operacoes_Produtos(list <Produto> &Estoque)
{
    int acao_P = 0;

    while (acao_P != 3)
    {
        system("clear || cls");
        cout << "\n\tProdutos\n";
        cout << "\n\tDigite o que deseja fazer:\n";
        cout << "\n\t1 - Registrar Produto;";
        cout << "\n\t2 - Alterar Produto;";
        cout << "\n\t3 - Sair.\n\n\t";
        cin >> acao_P;

        if (acao_P == 1)
        {
            Estoque.push_back(Registro_Produtos());
            cout << "\n\tProduto Registrado!";
        }
        else if (acao_P == 2)
        {
            Alterar_Produto(Estoque);
        }
        else if (acao_P == 3)
        {
            cout << "\n\tSaindo ...";
        }
    }
}

void Alterar_Produto(list <Produto>& Estoque)
{
    list <Produto>::iterator it;
    string nome, nome_novo;
    float info;
    int sair_AP = 0;
    system("clear || cls");
    cout << "\n\tDigite o nome ou o codigo do produto que deseja alterar: ";
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

    for (it = Estoque.begin(); it != Estoque.end(); ++it)
    {
        if (nome == it->Nome || nome == it->Codigo)
        {
            cout << "\n\n\tDigite as alteracoes";
            cout << "\n\tDigite o nome do produto: ";
            cin >> nome_novo;
            it->Nome = nome_novo;
            cout << "\n\tDigite o codigo do produto: ";
            cin >> nome_novo;
            it->Codigo = nome_novo;
            cout << "\n\tDigite o custo do produto: ";
            cin >> info;
            it->Custo = info;
            cout << "\n\tDigite o preco do produto: ";
            cin >> info;
            it->Preco = info;
        }
    }
    
    cout << "\n\tAlteracao realizada com sucesso!";
    cout << "\n\tPressione 1 para sair.";
    cin >> sair_AP;
    if (sair_AP == 1)
    {
        cout << "\n\tSaindo...";
    }
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

void Alterar_Estoque(list <Produto>& Estoque)
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
                    cout << "\n\tAlteracao realizada com sucesso!";
                }
                else if (movimentacao == 2)
                {
                    cout << "\n\tDigite a quantidade: ";
                    cin >> quantidade;
                    it->Quantidade = it->Quantidade - quantidade;
                    cout << "\n\tAlteracao realizada com sucesso!";
                }
                else
                {
                    cout << "\n\tDigite uma entrada valida!";
                }
            }
        }
    }
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