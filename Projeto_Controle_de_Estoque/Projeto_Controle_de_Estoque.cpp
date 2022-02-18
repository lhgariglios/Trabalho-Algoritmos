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

struct produto_venda
{
    char Nome[30];
    char Codigo[10];
    float Quantidade = 0;
    float Preco = 0;
    float total = 0;
};

struct celula_venda {
    struct celula_venda* proximo;
    struct produto_venda item;
};

struct Pilha_Venda {
    struct celula_venda* topo;
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

void IniciarVenda(struct Pilha_Venda* v);

float Realizar_Venda(struct Pilha_Venda* v, struct Fila_Estoque* e);
float Insere_Produto_Venda(struct Pilha_Venda* v, struct Fila_Estoque* e, float total_venda);
float Remove_Produto_Venda(struct Pilha_Venda* v, float total_venda);
void Mostrar_Venda(struct Pilha_Venda* v, float total_venda);
void Remove_Venda_Estoque(struct Pilha_Venda* v, struct Fila_Estoque* e);

void Fazer_Backup(struct Fila_Estoque* e, struct Fila_Estoque* b);

int main()
{
    int acao = 0, sair = 0;
    float Saldo = 0;
    struct Fila_Estoque* Estoque;
    Estoque = (Fila_Estoque*)malloc(sizeof(Fila_Estoque));
    IniciarEstoque(Estoque);

    struct Fila_Estoque* Backup;
    Backup = (Fila_Estoque*)malloc(sizeof(Fila_Estoque));

    struct Pilha_Venda* Venda;
    Venda = (Pilha_Venda*)malloc(sizeof(Pilha_Venda));
    IniciarVenda(Venda);

    while (acao != 8)
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
            Saldo = Saldo + Realizar_Venda(Venda, Estoque);
            Remove_Venda_Estoque(Venda, Estoque);
            IniciarVenda(Venda);
        }
        else if (acao == 5)
        {
            Fazer_Backup(Estoque, Backup);
        }
        else if (acao == 6)
        {
            Mostrar_Estoque(Backup);
        }
        else if (acao == 7)
        {
            cout << "\n\tO Saldo e de: " << Saldo << " reais.";
            cout << "\n\tPressione 1 para sair.\n\t";
            cin >> sair;
            cout << "\n\tSaindo...";

        }
        else if (acao == 8)
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

/* Funções para iniciar o programa, pilhas e filas */
void Inicio()
{
    system("clear || cls");
    cout << "\n\tPrograma Controle de Estoque - Luiz Henrique Gariglio dos Santos\n";
    cout << "\n\tDigite o que deseja fazer:\n";
    cout << "\n\t1 - Produto;";
    cout << "\n\t2 - Movimentacoes de Estoque;";
    cout << "\n\t3 - Consultar estoque;";
    cout << "\n\t4 - Realizar venda;";
    cout << "\n\t5 - Realizar backup;";
    cout << "\n\t6 - Mostrar backup;";
    cout << "\n\t7 - Mostrar saldo;";
    cout << "\n\t8 - Sair.\n\n\t";
}

void IniciarVenda(struct Pilha_Venda* v)
{
    v->topo = NULL;
    v->quantidade = 0;
}

void IniciarEstoque(struct Fila_Estoque* e)
{
    e->inicio = NULL;
    e->fim = NULL;
    e->quantidade = 0;
}

/* Funções para inserir e alterar produtos */

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

/* Funções para buscar e mostrar produtos no estoque e alterar quantidade no estoque */

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
    int i = 0;
    struct celula* aux = e->inicio;
    system("clear || cls");

    if (e->quantidade == 0)
    {
        cout << "\n\tNao ha produtos registrados!";
    }
    else
    {
        while(i < e->quantidade)
        {
            cout << "\n\t Nome: " << aux->produto.Nome;
            cout << "\n\t Codigo: " << aux->produto.Codigo;
            cout << "\n\t Quantidade no estoque: " << aux->produto.Quantidade;
            cout << "\n\t Custo do produto: " << aux->produto.Custo;
            cout << "\n\t Preco de venda: " << aux->produto.Preco;
            cout << endl;

            aux = aux->proximo;
            i++;

        } 

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

/* Funções para etapa de venda */

float Realizar_Venda(struct Pilha_Venda* v, struct Fila_Estoque* e)
{
    system("clear || cls");
    cout << "\n\tNova venda";

    int acao = 0;
    float total_venda = 0;

    while (acao != 2)
    {

        if (v->quantidade != 0)
        {
            Mostrar_Venda(v, total_venda);
        }

        cout << "\n\t1-Novo Produto\n\t2-Finalizar venda\n\t3-Excluir ultimo produto\n\t";
        cin >> acao;

        if (acao == 1)
        {
            total_venda = Insere_Produto_Venda(v, e, total_venda);
        }
        else if (acao == 2)
        {
            cout << "\n\tSaindo ...";
        }
        else if (acao == 3)
        {
            total_venda = Remove_Produto_Venda(v, total_venda);
        }
        else {
            cout << "\n\tDigite uma entrada valida!";
        }

    }

    return total_venda;
}

float Insere_Produto_Venda(struct Pilha_Venda* v, struct Fila_Estoque* e, float total_venda)
{
    struct celula_venda* novo = NULL;
    novo = (struct celula_venda*)malloc(sizeof(struct celula_venda));

    struct celula* aux;
    aux = e->inicio;

    char nome[30];

    cout << "\n\tDigite o nome ou codigo do protudo:";
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
        strcpy_s(novo->item.Nome, aux->produto.Nome);
        strcpy_s(novo->item.Codigo, aux->produto.Codigo);
        cout << "\n\tDigite a Quantidade: ";
        cin >> novo->item.Quantidade;
        novo->item.Preco = aux->produto.Preco;
        novo->item.total = novo->item.Quantidade * novo->item.Preco;
        novo->proximo = NULL;
        total_venda = total_venda + novo->item.total;

        v->quantidade++;

        if (v->quantidade == 0)
        {
            novo->proximo = NULL;
            v->topo = novo;
        }
        else
        {
            novo->proximo = v->topo;
            v->topo = novo;
        }
    }
    return total_venda;
}

float Remove_Produto_Venda(struct Pilha_Venda* v, float total_venda)
{
    struct celula_venda* aux;
    aux = v->topo;
    cout << aux->item.total;
    total_venda = total_venda - aux->item.total;
    v->topo = v->topo->proximo;
    free(aux);
    v->quantidade--;
    return total_venda;
}

void Mostrar_Venda(struct Pilha_Venda* v, float total_venda)
{
    system("clear || cls");
    cout << "\n\n\t***** Produtos *****";

    //struct Pilha_Venda* p_aux = NULL;
    //p_aux = (struct Pilha_Venda*)malloc(sizeof(struct Pilha_Venda));
    //IniciarVenda(p_aux);

    struct celula_venda* aux;
    aux = v->topo;
    int i = 0;

    while (i < v->quantidade)
    {
        i++;
        cout << "\n\t" << i << " - Nome: " << aux->item.Nome;
        cout << "\t|\tQuantidade: " << aux->item.Quantidade;
        cout << "\t|\tPreco: " << aux->item.Preco;
        cout << "\t|\tValor: " << aux->item.total;

        aux = aux->proximo;
    }

    cout << "\n\n\t\t Total venda: " << total_venda << endl;
}

void Remove_Venda_Estoque(struct Pilha_Venda* v, struct Fila_Estoque* e)
{
    int i = 0;
    cout << v->quantidade;
    if (v->quantidade != 0)
    {
        struct celula* aux;
        aux = (struct celula*)malloc(sizeof(struct celula));
        
        struct celula_venda* aux2;
        aux2 = (struct celula_venda*)malloc(sizeof(struct celula_venda));
        aux2 = v->topo;
        int i = 0;
        while (i < v->quantidade)
        {
            aux = e->inicio;
            while (strcmp(aux->produto.Nome, aux2->item.Nome) != 0)
            {
                aux = aux->proximo;
            }
            aux->produto.Quantidade = aux->produto.Quantidade - aux2->item.Quantidade;
            aux2 = aux2->proximo;
            i++;
        } 
    }
}

void Fazer_Backup(struct Fila_Estoque* e, struct Fila_Estoque* b )
{
    int i = 0;
    struct Produto p;
    struct celula* aux;
    aux = (struct celula*)malloc(sizeof(struct celula));
    aux = e->inicio;
    
    IniciarEstoque(b);
    
    while (i < e->quantidade)
    {
        struct celula* aux2;
        aux2 = (struct celula*)malloc(sizeof(struct celula));

        strcpy_s(p.Nome,aux->produto.Nome);
        strcpy_s(p.Codigo, aux->produto.Codigo);
        p.Custo = aux->produto.Custo;
        p.Preco = aux->produto.Preco;
        p.Quantidade = aux->produto.Quantidade;

        aux2->produto = p;
        aux2->proximo = NULL;
        
        if (b->quantidade > 0)
        {
            b->fim->proximo = aux2;
            b->fim = aux2;
            b->quantidade++;
        }
        else
        {
            b->inicio = aux2;
            b->fim = aux2;
            b->quantidade++;
        }
        aux = aux->proximo;
        i++;        
    } 
}