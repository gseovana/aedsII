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
    char telefone_funcionario[11];
    double salario;
} TFuncionario;

typedef struct cliente_est {
    int id_cliente;
    char nome_cliente[100];
    char cpf_cliente[15];
    char data_nascimentoC[100];
    char telefone_cliente[11];
} TCliente;

typedef struct transacao_est {
    int id_transacao;
    TCliente cliente;
    TDvd dvd;
    TFuncionario funcionario;
    char data_locacao[11];
    char data_devolucao[11];
    double valor;
    double multa;
} TTransacao;

TDvd *criar_DVD(int id_dvd, char *nome_dvd, int ano_lancamento, char *diretor, char *genero, int estoque);
TFuncionario *criar_funcionario(int id_funcionario, char *nome_funcionario, char *cpf_funcionario, char *data_nascimentoF, char *telefone_funcionario, double salario);
TDvd *criar_cliente(int id_cliente, char *nome_cliente, char *cpf_cliente, char *data_nascimentoC, char *telefone_cliente);
TDvd *criar_transacao(int id_transacao, TCliente cliente, TDvd dvd, TFuncionario funcionario, char *data_locacao, char *data_devolucao, double multa);

void desordenar(int *vet,int MAX,int MIN);

void salvar_dvd(TDvd *dvd, FILE *out);
void salvar_funcionario(TDvd *dvd, FILE *out);
void salvar_cliente(TDvd *dvd, FILE *out);
void salvar_transacao(TDvd *dvd, FILE *out);


#endif //LOCADORA_LOCADORA_H
