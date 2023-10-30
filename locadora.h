//
// Created by geovana on 10/30/23.
//

#ifndef LOCADORA_LOCADORA_H
#define LOCADORA_LOCADORA_H

typedef struct dvd_est {
    int id_dvd;
    char nome_dvd[100];
    int ano_lancamento;
    char diretor[50];
    char genero[100];
    int estoque;
} TDvd;

typedef struct funcionario_est {
    int id_funcionario;
    char nome_funcionario[100];
    char cpf_funcionario[15];
    char data_nascimentoF[100];
    double salario;
} TFuncionario;

typedef struct cliente_est {
    int id_cliente;
    char nome_cliente[100];
    char cpf_cliente[15];
    char data_nascimentoC[100];
} TCliente;

typedef struct transacao {
    int id_transacao;
    TCliente cliente;
    TDvd dvd;
    TFuncionario funcionario;
    char data_locacao[11];
    char data_devolucao[11];
    float multa;
} TTransacao;

TFuncionario *criar_funcionario(int id_funcionario, char *nome_funcionario, char *cpf_funcionario, char *data_nascimentoF, double salario);
TDvd *criar_DVD(int id_dvd, char *nome_dvd, int ano_lancamento, char *diretor, char *genero, int estoque);
TDvd *criar_cliente(int id_cliente, char *nome_cliente, char *cpf_cliente, char *data_nascimentoC);
TDvd *criar_transacao(int id_transacao, TCliente cliente, TDvd dvd, TFuncionario funcionario, char *data_locacao, char *data_devolucao, double multa);

#endif //LOCADORA_LOCADORA_H
