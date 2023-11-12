//
// Created by geovana on 10/30/23.
//

#include "locadora.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <bits/types/FILE.h>
#include <stdio.h>

TDvd *ler_dvd(FILE *in);

// ******************************** CRIA UM "OBJETO" FUNCIONARIO ************************************

TFuncionario *criar_funcionario(int id_funcionario, char *nome_funcionario, char *cpf_funcionario, char *data_nascimentoF, char *telefone_funcionario, double salario) {
    //CRIA UM PONTEIRO PARA TIPO TRANSAÇÃO E ALOCA O ESPAÇO DE MEMORIA PRA ESSE PONTEIRO
    TFuncionario *funcionario = (TFuncionario *) malloc(sizeof(TFuncionario));

    //INICIALIZA ESPACO DE MEMORIA COM ZERO (TIRA O LIXO)
    if (funcionario) memset(funcionario, 0, sizeof(TFuncionario));

    //COLOCA OS VALORES QUE VIERAM POR PARAMETRO DENTRO DOS ATRIBUTOS
    funcionario->id_funcionario = id_funcionario;
    strcpy(funcionario->nome_funcionario, nome_funcionario);
    strcpy(funcionario->cpf_funcionario, cpf_funcionario);
    strcpy(funcionario->data_nascimentoF, data_nascimentoF);
    strcpy(funcionario->telefone_funcionario, telefone_funcionario);
    funcionario->salario = salario;

    return funcionario;
}
// ******************************* CRIA UM "OBJETO" DVD ****************************************

TDvd *criar_dvd(int id_dvd, char *nome_dvd, int ano_lancamento, char *diretor, char *genero, bool disponivel) {
    TDvd *dvd = (TDvd *) malloc(sizeof(TDvd));

    if (dvd) memset(dvd, 0, sizeof(TDvd));

    dvd->id_dvd = id_dvd;
    strcpy(dvd->nome_dvd, nome_dvd);
    dvd->ano_lancamento = ano_lancamento;
    strcpy(dvd->diretor, diretor);
    strcpy(dvd->genero, genero);
    dvd->disponivel = disponivel;

    return dvd;
}
// ******************************** CRIA UM "OBJETO" CLIENTE *******************************************

TCliente *criar_cliente(int id_cliente, char *nome_cliente, char *cpf_cliente, char *data_nascimentoC, char *telefone_cliente) {
    TCliente *cliente = (TCliente *) malloc(sizeof(TCliente));

    if (cliente) memset(cliente, 0, sizeof(TCliente));

    cliente->id_cliente = id_cliente;
    strcpy(cliente->nome_cliente, nome_cliente);
    strcpy(cliente->cpf_cliente, cpf_cliente);
    strcpy(cliente->data_nascimentoC, data_nascimentoC);
    strcpy(cliente->telefone_cliente, telefone_cliente);

    return cliente;
}

//****************************** CRIA UM "OBJETO" TRANSACAO ************************************

TTransacao *criar_transacao(int id_transacao, TCliente cliente, TDvd dvd, TFuncionario funcionario, char *data_locacao, char *data_devolucao, double multa) {
    TTransacao *transacao = (TTransacao *) malloc(sizeof(TTransacao));

    if (transacao) memset(transacao, 0, sizeof(TTransacao));

    transacao->id_transacao = id_transacao;
    transacao->cliente = cliente;
    transacao->dvd = dvd;
    transacao->funcionario = funcionario;
    strcpy(transacao->data_locacao, data_locacao);
    strcpy(transacao->data_devolucao, data_devolucao);

    return transacao;
}

// ***************************** SALVA DVD NO ARQUIVO *******************************

void salvar_dvd(TDvd *dvd, FILE *out) {
    fwrite(&dvd->id_dvd, sizeof(int), 1, out);
    fwrite(&dvd->ano_lancamento, sizeof(int), 1, out);
    fwrite(dvd->diretor, sizeof(char), sizeof(dvd->diretor), out);
    fwrite(dvd->genero, sizeof(char), sizeof(dvd->genero), out);
    fwrite(&dvd->disponivel, sizeof(bool), 1, out);
}

// ***************************** SALVA FUNCIONARIO NO ARQUIVO *******************************

void salvar_funcionario(TFuncionario *funcionario, FILE *out) {
    fwrite(&funcionario->id_funcionario, sizeof(int), 1, out);
    fwrite(funcionario->nome_funcionario, sizeof(char), sizeof(funcionario->nome_funcionario), out);
    fwrite(funcionario->cpf_funcionario, sizeof(char), sizeof(funcionario->cpf_funcionario), out);
    fwrite(funcionario->data_nascimentoF, sizeof(char), sizeof(funcionario->data_nascimentoF), out);
    fwrite(funcionario->telefone_funcionario, sizeof(char), sizeof(funcionario->telefone_funcionario), out);
    fwrite(&funcionario->salario, sizeof(double), 1, out);
}

// ***************************** SALVA CLIENTE NO ARQUIVO *******************************

void salvar_cliente(TCliente *cliente, FILE *out) {
    fwrite(&cliente->id_cliente, sizeof(int), 1, out);
    fwrite(cliente->nome_cliente, sizeof(char), sizeof(cliente->nome_cliente), out);
    fwrite(cliente->cpf_cliente, sizeof(char), sizeof(cliente->cpf_cliente), out);
    fwrite(cliente->data_nascimentoC, sizeof(char), sizeof(cliente->data_nascimentoC), out);
    fwrite(cliente->telefone_cliente, sizeof(char), sizeof(cliente->telefone_cliente), out);
}

// ***************************** SALVA TRANSACAO NO ARQUIVO *******************************

void salvar_transacao(TTransacao *transacao, FILE *out) {
    fwrite(&transacao->id_transacao, sizeof(int), 1, out);
    fwrite(&transacao->dvd, sizeof(char), sizeof(transacao->dvd), out);
    fwrite(&transacao->funcionario, sizeof(char), sizeof(transacao->funcionario), out);
    fwrite(transacao->data_locacao, sizeof(char), sizeof(transacao->data_locacao), out);
    fwrite(transacao->data_devolucao, sizeof(char), sizeof(transacao->data_devolucao), out);
    fwrite(&transacao->valor, sizeof(double), 1, out);
    fwrite(&transacao->multa, sizeof(double), 1, out);
}


// ************************************ EMBARALHA IDs ******************************************

void desordenar(int *vet,int MAX,int MIN) {
    srand(time(NULL));
    for (int i = MAX - MIN - 1; i > 0; i--) {
        int j = rand() % (i);
        int tmp = vet[j];
        vet[j] = vet[i];
        vet[i] = tmp;
    }
}

// ***************************** CRIA A BASE DE DADOS DE DVDs ******************************

void criar_base_dvd(FILE *out, int tamanho){

    //CRIA UM VETOR DE TAMANHO 'TAMANHO'
    int vetor_dvd[tamanho];
    TDvd *dvd;
    bool disponibilidade;

    //CRIA UM VETOR QUE VAI DE 1 ATÉ O TAMANHO (SERÁ USADO PARA EMBARALHAR OS IDs)
    for(int i=0;i<tamanho;i++)
        vetor_dvd[i] = i+1;

    //DESORDENA O VETOR CRIADO
    desordenar(vetor_dvd, tamanho, (tamanho*10)/100);

    printf("\nGerando a base de dados de DVDs...\n");

     /* O id de cada "objeto" dvd vem do vetor_dvd que está com os números embaralhados. Assim os "objetos"
     estarão fora de ordem no arquivo.*/

    // PERCORRE O VETOR DVD CRIANDO ENTIDADES DE DVD E SALVANDO NELE
    for (int i=0;i<tamanho;i++){
        if(i%2==0) {
            disponibilidade = false;
        } else{
            disponibilidade = true;
        }
        dvd = criar_dvd(vetor_dvd[i], "As aventuras de Geovana e Talia", i+2000, "Diretor Fulano", "Genero Y", disponibilidade);
        salvar_dvd(dvd, out);
    }

    free(dvd);

}

// ***************************** CRIA A BASE DE DADOS DE FUNCIONARIOS *******************************
void criar_base_funcionario(FILE *out, int tamanho){

    int vetor_funcionario[tamanho];
    TFuncionario *funcionario;

    for(int i=0;i<tamanho;i++)
        vetor_funcionario[i] = i+1;

    desordenar(vetor_funcionario, tamanho, (tamanho*10)/100);

    printf("\nGerando a base de dados de funcionários...\n");

    for (int i=0;i<tamanho;i++){
        funcionario = criar_funcionario(vetor_funcionario[i], "Funcionario A", "000.000.000-11", "22/12/2009", "98528-3250", 3000+2*i);
        salvar_funcionario(funcionario, out);
    }

    free(funcionario);

}

// ***************************** CRIA A BASE DE DADOS DE CLIENTES *******************************
void criar_base_cliente(FILE *out, int tamanho){

    int vetor_cliente[tamanho];
    TCliente *cliente;

    for(int i=0;i<tamanho;i++)
        vetor_cliente[i] = i+1;

    desordenar(vetor_cliente, tamanho, (tamanho*10)/100);

    printf("\nGerando a base de dados de clientes...\n");

    for (int i=0;i<tamanho;i++){
        cliente = criar_cliente(vetor_cliente[i], "Nome", "000.000.000-11", "22/12/2009","31985884789");
        salvar_cliente(cliente, out);
    }

    free(cliente);

}

// ***************************** CRIA A BASE DE DADOS DE TRANSACOES *******************************
void criar_base_transacao(FILE *out, int tamanho, TFuncionario funcionario, TDvd dvd, TCliente cliente) {

    int vetor_transacao[tamanho];
    TTransacao *transacao;

    //O VETOR TRANSAÇÃO NÃO SERÁ DESORDENADO PRA ATENDER AO REQUISITO DE CRIAR UMA BASE DE DADOS ORDENADA

    printf("\nGerando a base de dados de transações...\n");

    for (int i = 0; i < tamanho; i++) {
        transacao = criar_transacao(vetor_transacao[i], cliente, dvd, funcionario, "22/12/2019", "19/01/2020", 41.7);
        salvar_transacao(transacao, out);
    }

    free(transacao);

}

// ***************************** IMPRIME CADA DVD *******************************
void imprimir_dvd(TDvd *dvd) {
    printf("**********************************************");
    printf("\nID DVD: ");
    printf("%d", dvd->id_dvd);
    printf("\nTítulo: ");
    printf("%s", dvd->nome_dvd);
    printf("\nDiretor: ");
    printf("%s", dvd->diretor);
    printf("\nGênero: ");
    printf("%s", dvd->genero);
    printf("\nDisponível: ");
    if(dvd->disponivel == true) {
        printf("Sim");
    }else
        printf("Não");
    printf("\n**********************************************");
}

// ***************************** IMPRIME BASE DE DADOS DE DVD *******************************
void imprimir_base_dvd(FILE *out){

    printf("\Imprimindo base de dados...\n");

    rewind(out);
    TDvd *dvd;

    while ((dvd = ler_dvd(out)) != NULL)
        imprimir_dvd(dvd);

    free(dvd);

}

/* Le um dvd do arquivo "in" na posicao atual do cursor e retorna um ponteiro para funcionario lido do arquivo */

TDvd *ler_dvd(FILE *in) {
    TDvd *dvd = (TDvd *) malloc(sizeof(TDvd));
    if (0 >= fread(&dvd->id_dvd, sizeof(int), 1, in)) {
        free(dvd);
        return NULL;
    }
    fread(dvd->nome_dvd, sizeof(char), sizeof(dvd->nome_dvd), in);
    fread(&dvd->ano_lancamento, sizeof(int), 1, in);
    fread(dvd->diretor, sizeof(char), sizeof(dvd->diretor), in);
    fread(dvd->genero, sizeof(char), sizeof(dvd->genero), in);
    fread(&dvd->disponivel, sizeof(bool), 1, in);
    return dvd;
}

