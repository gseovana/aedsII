//
// Created by geovana on 10/30/23.
//

#include "locadora.h"
#include <stdlib.h>
#include <string.h>

TFuncionario *criar_funcionario(int id_funcionario, char *nome_funcionario, char *cpf_funcionario, char *data_nascimentoF, double salario) {
    TFuncionario *funcionario = (TFuncionario *) malloc(sizeof(TFuncionario));

    //INICIALIZA ESPACO DE MEMORIA COM ZERO
    if (funcionario) memset(funcionario, 0, sizeof(TFuncionario));

    //ATRIBUI AS VARIÁVEIS DO PARAMETRO A ENTIDADE
    funcionario->id_funcionario = id_funcionario;
    strcpy(funcionario->nome_funcionario, nome_funcionario);
    strcpy(funcionario->cpf_funcionario, cpf_funcionario);
    strcpy(funcionario->data_nascimentoF, data_nascimentoF);
    funcionario->salario = salario;

    return funcionario;
}

TDvd *criar_DVD(int id_dvd, char *nome_dvd, int ano_lancamento, char *diretor, char *genero, int estoque) {
    TDvd *dvd = (TDvd *) malloc(sizeof(TDvd));

    //INICIALIZA ESPACO DE MEMORIA COM ZERO
    if (dvd) memset(dvd, 0, sizeof(TDvd));

    //ATRIBUI AS VARIÁVEIS DO PARAMETRO A ENTIDADE
    dvd->id_dvd = id_dvd;
    strcpy(dvd->nome_dvd, nome_dvd);
    dvd->ano_lancamento = ano_lancamento;
    strcpy(dvd->diretor, diretor);
    strcpy(dvd->genero, genero);
    dvd->estoque = estoque;

    return dvd;
}

TDvd *criar_cliente(int id_cliente, char *nome_cliente, char *cpf_cliente, char *data_nascimentoC) {
    TCliente *cliente = (TCliente *) malloc(sizeof(TCliente));

    //inicializa espaco de memoria com ZEROS
    if (cliente) memset(cliente, 0, sizeof(TCliente));

    cliente->id_cliente = id_cliente;
    strcpy(cliente->nome_cliente, nome_cliente);
    strcpy(cliente->cpf_cliente, cpf_cliente);
    strcpy(cliente->data_nascimentoC, data_nascimentoC);

    return cliente;
}

TDvd *criar_transacao(int id_transacao, TCliente cliente, TDvd dvd, TFuncionario funcionario, char *data_locacao, char *data_devolucao, double multa) {
    TTransacao *transacao = (TTransacao *) malloc(sizeof(TTransacao));

    //INICIALIZA ESPACO DE MEMORIA COM ZERO
    if (transacao) memset(transacao, 0, sizeof(TTransacao));

    transacao->id_transacao = id_transacao;
    transacao->cliente = cliente;
    transacao->dvd = dvd;
    transacao->funcionario = funcionario;
    strcpy(transacao->data_locacao, data_locacao);
    strcpy(transacao->data_devolucao, data_devolucao);

    return transacao;
}




