#include "arvore.h"
#include <iostream>

/*Implementacao dos metodos da classe TipoItem*/
TipoItem::TipoItem()
{
    chave = -1; //indica item vazio
}
TipoItem::TipoItem(TipoChave c)
{
    chave = c;
}
void TipoItem::SetChave(std::string c)
{
    chave = c;
}
TipoChave TipoItem::GetChave()
{
    return chave;
}
void TipoItem::Imprime()
{
    std::cout << " " << chave;
}

/*Implementacao dos metodos da classe TipoNo*/
TipoNo::TipoNo()
{
    item.SetChave("");
    esq = NULL;
    dir = NULL;
}

/*Implementacao dos metodos da classe ArvoreBinaria*/
ArvoreBinaria::ArvoreBinaria()
{
    raiz = NULL;
}
ArvoreBinaria::~ArvoreBinaria()
{
    ApagaRecursivo(raiz);
    raiz = NULL;
}
void ArvoreBinaria::ApagaRecursivo(TipoNo *p)
{
    if(p != NULL)
    {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}
void ArvoreBinaria::Insere(TipoItem item)
{
    InsereRecursivo(raiz,item);
}
void ArvoreBinaria::InsereRecursivo(TipoNo* &p, TipoItem item)
{
    if(p == NULL)
    {
        p = new TipoNo();
        p->item = item;
    }
    else
    {
        if(item.GetChave() < p->item.GetChave())
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}
void ArvoreBinaria::Remove(TipoChave chave) 
{
    return RemoveRecursivo(raiz, chave);
}
void ArvoreBinaria::Antecessor(TipoNo *q, TipoNo* &r)
{
    if(r->dir != NULL)
    {
        Antecessor(q, r->dir);
        return;
    }
    q->item = r->item;
    q = r;
    r = r->esq;
    free(q);
}
void ArvoreBinaria::RemoveRecursivo(TipoNo* &no, TipoChave chave)
{
    TipoNo *aux;
    if(no == NULL)
    {
        throw("Item nao está presente");
    }
    if(chave < no->item.GetChave())
        return RemoveRecursivo(no->esq, chave);
    else if(chave>no->item.GetChave())
        return RemoveRecursivo(no->dir, chave);
    else
    {
        if(no->dir == NULL)
        {
            aux = no;
            no = no->esq;
            free(aux);
        }
        else if(no->esq == NULL)
        {
            aux = no;
            no = no->dir;
            free(aux);
        }
        else
            Antecessor(no, no->esq);
    }
}
//Metodos diferentes dos vistos em aulas para atender as especificacoes do trabalho prático
void ArvoreBinaria::PreOrdemEncripta(TipoNo *p, int &codigo ,TipoChave *palavras, int *codigos, int quant)
{
    //Caminhamento pre-ordem modoficado
    if(p != NULL)
    {
        //Para cada elemento da arvore verifica se a palavra atual eh uma das palavras a ser encriptada,
        //caso seja, o codigo da mesma eh armazenado no vetor de codigos respeitando a ordem de encriptacao
        for(int i = 0; i < quant; i++)
            if(p->item.GetChave() == palavras[i])
                codigos[i] = codigo;
        codigo++;
        PreOrdemEncripta(p->esq, codigo, palavras, codigos, quant);
        PreOrdemEncripta(p->dir, codigo, palavras, codigos, quant);
    }
}
void ArvoreBinaria::PreOrdemDesencripta(TipoNo *p, int &codigo ,TipoChave *palavras, int *codigos, int quant)
{
    //Caminhamento pre-ordem modoficado
    if(p != NULL)
    {
        //Para cada elemento da arvore verifica se o codigo da palavra atual eh um dos codigos a ser
        //desencriptado, caso seja, a respectiva palavra eh armazenada no vetor de palavras respeitando
        //a ordem de desencriptacao
        for(int i = 0; i < quant; i++)
            if(codigo == codigos[i])
                palavras[i] = p->item.GetChave();
        codigo++;
        PreOrdemDesencripta(p->esq, codigo, palavras, codigos, quant);
        PreOrdemDesencripta(p->dir, codigo, palavras, codigos, quant);
    }
}
void ArvoreBinaria::Encripta(TipoChave palavras[], int tam)
{
    //Cria um vetor de codigos para que ao caminhar pela arvore a ordem de encriptacao sera a mesma
    //da informada pela linha de entrada
    int codigos[20];
    int codigo = 1;
    PreOrdemEncripta(raiz, codigo, palavras, codigos, tam);
    //Imprime os codigos da mensagem informada
    for(int i = 0; i < tam; i++)
        std::cout << codigos[i] << " ";
    std::cout << std::endl;
}
void ArvoreBinaria::Desencripta(int codigos[], int tam)
{
    //Cria um vetor de palavras para que ao caminhar pela arvore a ordem de encriptacao sera a mesma
    //da informada pela linha de entrada
    TipoChave palavras[20];
    int codigo = 1;
    PreOrdemDesencripta(raiz, codigo, palavras, codigos, tam);
    //Imprime as palavras da mensagem informada
    for(int i = 0; i < tam; i++)
        std::cout << palavras[i] << " ";
    std::cout << std::endl;
}