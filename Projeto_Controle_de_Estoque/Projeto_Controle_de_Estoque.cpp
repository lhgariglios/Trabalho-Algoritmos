/*Projeto Algotitmo Controle de Estoque - Luiz Henrique Gariglio dos Santos - 2022*/
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct Produto
{
    char Nome[30];
    char Codigo[10];
    float Quantidade = 0;
    float Custo = 0;
    float Preco = 0;
};

struct celula
{
    struct celula* proximo;
    struct Produto produto;
};

struct Fila_Estoque
{
    struct celula* inicio;
    struct celula* fim;
    int quantidade;
};

/*Iniciando Funções*/

void Inicio();

void IniciarEstoque(struct Fila_Estoque* e);

void Operacoes_Produtos(struct Fila_Estoque* e);
    void Registro_Produtos(struct Fila_Estoque* e);
    void Alterar_Produto(struct Fila_Estoque* e);

void Consultar_Estoque(struct Fila_Estoque* e);
    void Mostrar_Estoque(struct Fila_Estoque* e);
    void Buscar_Produto(struct Fila_Estoque* e);
    void Alterar_Estoque(struct Fila_Estoque* e);



int main()
{
    int acao = 0;
    struct Fila_Estoque* Estoque;
    Estoque = (Fila_Estoque*)malloc(sizeof(Fila_Estoque));
    IniciarEstoque(Estoque);

    while (acao != 4)
    {
        Inicio();
        cin >> acao;
        if (acao == 1)
        {
            Operacoes_Produtos(Estoque);

        }
        else if (acao == 2)
        {
            Alterar_Estoque(Estoque);

        }
        else if (acao == 3)
        {

            Consultar_Estoque(Estoque);

        }
        else if (acao == 4)
        {
            cout << "\n\tSaindo ...";
        }
        else {
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
    cout << "\n\t1 - Produto;";
    cout << "\n\t2 - Movimentacoes de Estoque;";
    cout << "\n\t3 - Consultar estoque;";
    cout << "\n\t4 - Sair.\n\n\t";
}

void IniciarEstoque(struct Fila_Estoque* e)
{
    e->inicio = NULL;
    e->fim = NULL;
    e->quantidade = 0;
}

void Operacoes_Produtos(struct Fila_Estoque* e)
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
            Registro_Produtos(e);
        }
        else if (acao_P == 2)
        {
            Alterar_Produto(e);
        }
        else if (acao_P == 3)
        {
            cout << "\n\tSaindo ...";
        }
    }
}

void Registro_Produtos(struct Fila_Estoque* e)
{
    struct celula* novo;
    struct Produto novop;
    novo = (struct celula*)malloc(sizeof(struct celula));

    system("clear || cls");
    cout << "\n\tDigite o nome do produto: ";
    cin >> novop.Nome;
    cout << "\n\tDigite o codigo do produto: ";
    cin >> novop.Codigo;
    cout << "\n\tDigite a quantidade: ";
    cin >> novop.Quantidade;
    cout << "\n\tDigite o custo do produto: ";
    cin >> novop.Custo;
    cout << "\n\tDigite o preco do produto: ";
    cin >> novop.Preco;

    novo->proximo = NULL;
    novo->produto = novop;

    if (e->quantidade > 0)
    {
        e->fim->proximo = novo;
        e->fim = novo;
        e->quantidade++;
    }
    else
    {
        e->inicio = novo;
        e->fim = novo;
        e->quantidade++;
    }

}

void Alterar_Produto(struct Fila_Estoque* e)
{
    struct celula* aux;
    aux = e->inicio;
    char nome[30];
    int sair_AP = 0;
    system("clear || cls");

    if (e->quantidade == 0)
    {
        cout << "\n\tNao ha produtos registrados!";
    }
    else
    {
        cout << "\n\tDigite o nome ou o codigo do produto que deseja alterar: ";
        cin >> nome;

        while (aux != NULL && strcmp(aux->produto.Nome, nome) != 0 && strcmp(aux->produto.Codigo, nome))
        {
            aux = aux->proximo;
        }

        if (aux == NULL)
        {
            cout << "\n\tProduto nao encontrado!";
            cout << "\n\tPressione 1 para sair.\n\t";
            cin >> sair_AP;
            if (sair_AP == 1)
            {
                cout << "\n\tSaindo...";
            }
        }
        else
        {
            //mostra produto antigo
            cout << "\n\t Nome: " << aux->produto.Nome;
            cout << "\n\t Codigo: " << aux->produto.Codigo;
            cout << "\n\t Quantidade no estoque: " << aux->produto.Quantidade;
            cout << "\n\t Custo do produto: " << aux->produto.Custo;
            cout << "\n\t Preco de venda: " << aux->produto.Preco;
            cout << endl;

            //insere e realiza as alterações
            cout << "\n\n\tDigite as alteracoes";
            cout << "\n\tDigite o nome do produto: ";
            cin >> aux->produto.Nome;
            cout << "\n\tDigite o codigo do produto: ";
            cin >> aux->produto.Codigo;
            cout << "\n\tDigite o custo do produto: ";
            cin >> aux->produto.Custo;
            cout << "\n\tDigite o preco do produto: ";
            cin >> aux->produto.Preco;

            cout << "\n\tAlteracao realizada com sucesso!";
            cout << "\n\tPressione 1 para sair.\n\t";
            cin >> sair_AP;
            if (sair_AP == 1)
            {
                cout << "\n\tSaindo...";
            }
        }
    }
}

void Consultar_Estoque(struct Fila_Estoque* e)
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
            Mostrar_Estoque(e);
        }
        else if (acao_E == 2)
        {
            Buscar_Produto(e);
        }
        else if (acao_E == 3)
        {
            cout << "\n\tSaindo ...";
        }
    }
}

void Mostrar_Estoque(struct Fila_Estoque* e)
{
    int sair_E = 0;
    struct celula* aux = e->inicio;
    system("clear || cls");

    if (e->quantidade == 0)
    {
        cout << "\n\tNao ha produtos registrados!";
    }
    else
    {
        do
        {
            cout << "\n\t Nome: " << aux->produto.Nome;
            cout << "\n\t Codigo: " << aux->produto.Codigo;
            cout << "\n\t Quantidade no estoque: " << aux->produto.Quantidade;
            cout << "\n\t Custo do produto: " << aux->produto.Custo;
            cout << "\n\t Preco de venda: " << aux->produto.Preco;
            cout << endl;

            aux = aux->proximo;


        } while (aux != NULL);

        cout << "\n\tPressione 1 para sair.\n\t";
        cin >> sair_E;
        if (sair_E == 1)
        {
            cout << "\n\tSaindo...";
        }
    }
}

void Buscar_Produto(struct Fila_Estoque* e)
{
    system("clear || cls");
    char nome[30];
    int sair_E = 0;
    struct celula* aux;
    aux = e->inicio;

    if (e->quantidade == 0)
    {
        cout << "\n\tNao ha produtos registrados!";
    }
    else
    {
        cout << "\n\tDigite o nome ou o codigo do produto que deseja buscar: ";
        cin >> nome;

        while (aux != NULL && strcmp(aux->produto.Nome, nome) != 0 && strcmp(aux->produto.Codigo, nome) != 0)
        {
            aux = aux->proximo;
        }
        if (aux == NULL)
        {
            cout << "\n\tProduto não encontrado!";
        }
        else
        {
            cout << "\n\t Nome: " << aux->produto.Nome;
            cout << "\n\t Codigo: " << aux->produto.Codigo;
            cout << "\n\t Quantidade no estoque: " << aux->produto.Quantidade;
            cout << "\n\t Custo do produto: " << aux->produto.Custo;
            cout << "\n\t Preco de venda: " << aux->produto.Preco;
            cout << endl;
        }
        cout << "\n\tPressione 1 para sair.\n\t";
        cin >> sair_E;
        if (sair_E == 1)
        {
            cout << "\n\tSaindo...";
        }
    }
}

void Alterar_Estoque(struct Fila_Estoque* e)
{
    int movimentacao = 0, quantidade = 0;

    system("clear || cls");
    char nome[30];
    int sair_E = 0;
    struct celula* aux;
    aux = e->inicio;

    if (e->quantidade == 0)
    {
        cout << "\n\tNao ha produtos registrados!";
    }
    else
    {
        cout << "\n\tDigite o nome ou o codigo do produto que deseja alterar: ";
        cin >> nome;

        while (aux != NULL && strcmp(aux->produto.Nome, nome) != 0 && strcmp(aux->produto.Codigo, nome) != 0)
        {
            aux = aux->proximo;
        }
        if (aux == NULL)
        {
            cout << "\n\tProduto não encontrado!";
        }
        else
        {
            while (movimentacao != 1 && movimentacao != 2)
            {
                cout << "\n\tSelecione:\n\t1-Entrada\n\t2-Retirada\n\t";
                cin >> movimentacao;

                if (movimentacao == 1)
                {
                    cout << "\n\tRealizar entrada em " << aux->produto.Nome;
                    cout << "\n\tDigite a quantidade: ";
                    cin >> quantidade;
                    aux->produto.Quantidade = aux->produto.Quantidade + quantidade;
                    cout << "\n\tAlteracao realizada com sucesso!";
                }
                else if (movimentacao == 2)
                {
                    cout << "\n\tRealizar retirada em " << aux->produto.Nome;
                    cout << "\n\tDigite a quantidade: ";
                    cin >> quantidade;
                    aux->produto.Quantidade = aux->produto.Quantidade - quantidade;
                    cout << "\n\tAlteracao realizada com sucesso!";
                }
                else
                {
                    cout << "\n\tDigite uma entrada valida!";
                }
            }
        }

        cout << "\n\tPressione 1 para sair.\n\t";
        cin >> sair_E;
        if (sair_E == 1)
        {
            cout << "\n\tSaindo...";
        }
    }

}