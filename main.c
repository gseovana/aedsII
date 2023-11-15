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

    else {

        criar_base_dvd(arq, 600);
        int opcao = -1;

        while (opcao != 0) {
            system("clear");
            printf("\n****************** LOCADORA TAGEO FILMES *******************");
            printf("\n1. Cadastrar DVD \n2. Buscar DVD \n3. Excluir DVD \n4. Imprimir todos os DVDs \n-----------------------------\n"
                   "5. Cadastrar cliente \n6. Buscar cliente \n7. Excluir cliente \n8. Imprimir todos os clientes \n-----------------------------"
                   "\n9. Novo funcionário \n10. Imprimir todos os funcionários \n---------------------------"
                   "\n11. Nova transação\n12. Imprimir todas as transações \n0. Sair\n\nEscolha uma opção: ");
            scanf("%d", &opcao);
            //fflush(arq);

            switch (opcao) {
                case 1:
                    system("clear");
                    printf("\n********** CADASTRAR DVD **********\n");

                    TDvd *dvd = (TDvd *) malloc(sizeof(TDvd));

                    // Limpar o buffer, consumindo o caractere de nova linha remanescente
                    while (getchar() != '\n');

                    printf("Título: ");
                    fgets(dvd->nome_dvd, 51, stdin);

                    printf("Ano lançamento: ");
                    scanf("%d", &dvd->ano_lancamento);

                    printf("Diretor: ");
                    fgets(dvd->diretor, 51, stdin);

                    while (getchar() != '\n');

                    printf("Gênero: ");
                    fgets(dvd->genero, 51, stdin);

                    dvd->disponivel = true;

                    salvar_dvd(dvd, arq);
                    printf("\nDVD salvo com sucesso!");
                    opcao = -1;

                    free(dvd);
                    break;
                case 2:
                    printf("\n********** BUSCAR DVD **********\n");

                    int id_dvd;

                    printf("Informe o codigo: ");
                    scanf("%d", &id_dvd);

                    dvd = busca_sequencial_dvd(id_dvd, arq);
                    if(dvd != NULL) {
                        imprimir_dvd(dvd);
                    }

                    free(dvd);
                    break;
                case 3:
                    printf("\n********** EXCLUIR DVD **********\n");

                    printf("Informe o codigo: ");
                    scanf("%d", &id_dvd);

                    excluir_dvd(id_dvd, arq);

                    free(dvd);

                    break;
                case 4:
                    printf("\n********** IMPRIMIR BASE DE DADOS DE DVDs **********\n");
                    imprimir_base_dvd(arq);
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
            }

            //imprimir_base_dvd(arq);
            //system("pause");
            //f = buscaSequencial(10, arq);
            //imprime(f);
            //f = busca_binaria(10, arq, 0, tamanho_arquivo(arq)-1);
            //imprime(f);
            //free(f);
        }
    }
}
