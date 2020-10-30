#ifndef ARVORE_H
#define ARVORE_H
#include <string>

typedef std::string TipoChave; //TipoChave é uma std::string

/*Assinatura dos atributos e metodos da classe TipoItem*/
class TipoItem
{
    public:
        TipoItem();
        TipoItem(TipoChave c);
        void SetChave(std::string c);
        TipoChave GetChave();
        void Imprime();
    
    private:
        TipoChave chave;
        //outrosmembros
};

/*Assinatura dos atributos e metodos da classe TipoNo*/
class TipoNo
{
    public:
        TipoNo();
    
    private:
        TipoItem item;
        TipoNo *esq;
        TipoNo *dir;
        friend class ArvoreBinaria;
};

/*Assinatura dos atributos e metodos da classe ArvoreBinaria*/
class ArvoreBinaria
{
    public:
        ArvoreBinaria();
        ~ArvoreBinaria();
        void Insere(TipoItem item);
        void Remove(TipoChave chave);
        void Encripta(TipoChave palavras[], int tam);
        void Desencripta(int codigos[], int tam);
    
    private:
        void ApagaRecursivo(TipoNo* p);
        void InsereRecursivo(TipoNo* &p, TipoItem item);
        void Antecessor(TipoNo* q, TipoNo* &r);
        void RemoveRecursivo(TipoNo* &p, TipoChave chave);
        void PreOrdemEncripta(TipoNo *p, int &codigo, TipoChave *palavras, int *codigos, int quant);
        void PreOrdemDesencripta(TipoNo *p, int &codigo, TipoChave *palavras, int *codigos, int quant);
        TipoNo *raiz;
};

#endif /* ARVORE_H */