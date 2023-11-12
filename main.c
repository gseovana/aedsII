#include <stdio.h>
#include <stdlib.h>
#include "locadora.h"

/*
2. (10 pontos) Realize buscas sequencias por entidades nas bases. Considere bases de
diferentes tamanhos. Realizar a marcação de tempo e contagem de comparações realizadas
em cada busca, salvando os dados em um arquivo de log.

4. (10 pontos) Com as bases ordenadas, realize buscas binária por entidades nas bases.
Considere bases de diferentes tamanhos. Realizar a marcação de tempo e contagem de
comparações realizadas em cada busca, salvando os dados em um arquivo de log.

5. (10 pontos) Implemente operações que exemplique interações entre as entidades da
aplicação.

6. (2 pontos) Com base nos testes realizados, elaborar um pequeno relatório destacando as
principais diferenças observadas entre os métodos*/

int main() {

    //CRIA UM PONTEIRO PARA TIPO FILE (ARQUIVO)
    FILE *arq;

    //CONDICIONAL DE TENTATIVA ABERTURA DO ARQUIVO
    if ((arq = fopen("locadora.dat", "w+b")) == NULL) {
        printf("Algo deu errado. Não foi possível abrir o arquivo.\n");
        exit(1);
    }

    else{

        criar_base_dvd(arq, 600);
        int opcao = 0;

        printf("\n****************** LOCADORA TAGEO FILMES *******************");
        printf("\n1. Cadastrar DVD \n2. Buscar DVD \n3. Excluir DVD \n-----------------------------\n"
               "4. Cadastrar cliente \n5. Buscar cliente \n6. Excluir cliente \n------------------------------"
               "\n7. Nova transação \n8. Sair\n\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                system("clear");
                printf("********** CADASTRAR DVD **********\n");
                //printf("Nome: ");
                //fgets()
                //criar_dvd();
                break;
            case 2: break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                printf("Saindo...");
                break;
            default:
                printf("Opcão inválida. Saindo...");
                break;
        }

        imprimir_base_dvd(arq);
        //system("pause");
        //f = buscaSequencial(10, arq);
        //imprime(f);
        //f = busca_binaria(10, arq, 0, tamanho_arquivo(arq)-1);
        //imprime(f);
        //free(f);
    }

}
