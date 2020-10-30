#include "headers/arvore.h"
#include <iostream>
#include <string>

int main()
{
    int quant, codigo;
    char operacao;
    int desencriptadas[20];
    TipoChave palavra;
    TipoChave encriptadas[20];
    ArvoreBinaria idioma;
    TipoItem item;

    //Laco de leitura da operacao a ser executada ate o fim da entrada
    while(scanf("%c", &operacao) != EOF)
    {
        switch(operacao)
        {
            //Operacao para inserir a palavra informada na arvore
            case 'i':
                std:: cin >> palavra;
                item.SetChave(palavra);
                idioma.Insere(item);
                break;
            
            //Operacao para encriptar uma mensagem, le uma quantidade de palavras da entrada
            //e imprime os codigos correspondente ao caminhamento pre-ordem da arvore
            case 'e':
                std::cin >> quant;
                for(int i = 0; i < quant; i++)
                {
                    std::cin >> palavra;
                    encriptadas[i] =  palavra;
                }
                idioma.Encripta(encriptadas, quant);
                break;
            
            //Operacao para desencriptar uma mensagem, le uma quantidade de codigos da entrada
            //e imprime as palavras correspondente ao caminhamento pre-ordem da arvore
            case 'd':
                std::cin >> quant;
                for(int i = 0; i < quant; i++)
                {
                    std::cin >> codigo;
                    desencriptadas[i] =  codigo;
                }
                idioma.Desencripta(desencriptadas, quant);
                break;
            //Operacao para substituir uma palavra, remove uma palavra da arvore e em seguida 
            //insere outra palavra respeitando as propriedades de arvores binarias
            case 's':
                std:: cin >> palavra;
                idioma.Remove(palavra);
                std:: cin >> palavra;
                item.SetChave(palavra);
                idioma.Insere(item);
                break;
            //Mensagem de erro quando uma operacao nao eh valida
            default:
                std::cout << std::endl << "Instrucao invalida.\n";
                break;
        }
        //Limpa a entrada e pula uma linha para evitar lixo na leitura da proxima instrucao
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    return 0;
}