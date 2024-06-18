#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Declarando estruturas de dados necessárias
typedef struct {
    int codigocli;
    char enderecocli[30], nomecli[30], telcli[15];
} cliente;

typedef struct {
    int codigofunc;
    char nomefunc[30], cargo[15], telfunc[15];
    float salario;
} funcionario;

typedef struct {
    int codigoest;
    char dentrada[20], dsaida[20];
    int qtddiarias, codcliente, numquarto;
} estadia;

typedef struct quarto {
    int nquarto, qtdhospedes;
    float valordiaria;
    char status[10];
} quarto;

// Declaração de variáveis globais
cliente clientes[100];
int totcli = 0;

funcionario funcionarios[100];
int totalfunc = 0;

estadia estadias[100];
int totestadias = 0;

quarto quartos[100];
int totquartos = 0;

// Função de cadastro de clientes
void cadastrocli() {
    int cod;
    char endereco[30], nome[30], tel[15];
    printf("\nInsira o código do novo cliente: ");
    scanf("%d", &cod);
    // Verifica se o código está disponível
    for (int i = 0; i < totcli; i++) {
        if (clientes[i].codigocli == cod) {
            printf("\nO código já está cadastrado!");
            return;
        }
    }

    printf("\nDigite o nome do cliente: ");
    scanf(" %[^\n]", nome);
    printf("\nDigite o endereço do cliente: ");
    scanf(" %[^\n]", endereco);
    printf("\nDigite o telefone do cliente: ");
    scanf(" %[^\n]", tel);

    cliente novocliente;
    novocliente.codigocli = cod;
    strcpy(novocliente.nomecli, nome);
    strcpy(novocliente.enderecocli, endereco);
    strcpy(novocliente.telcli, tel);

    clientes[totcli] = novocliente;
    totcli++;
    printf("\nCliente cadastrado com sucesso");
}

// Função de cadastro de funcionários
void cadastrofunc() {
    int cod;
    char nomef[30], cargo[15], telf[15];
    float salario;

    printf("\nInsira o código do novo funcionário: ");
    scanf("%d", &cod);
    // Verifica se o código está disponível
    for (int i = 0; i < totalfunc; i++) {
        if (funcionarios[i].codigofunc == cod) {
            printf("\nO código já está cadastrado!");
            return;
        }
    }

    printf("\nDigite o nome do funcionário: ");
    scanf(" %[^\n]", nomef);
    printf("\nDigite o cargo do funcionário: ");
    scanf(" %[^\n]", cargo);
    printf("\nDigite o telefone do funcionário: ");
    scanf(" %[^\n]", telf);
    printf("\nDigite o salário do funcionário: ");
    scanf("%f", &salario);

    funcionario novofuncionario;
    novofuncionario.codigofunc = cod;
    strcpy(novofuncionario.nomefunc, nomef);
    strcpy(novofuncionario.cargo, cargo);
    strcpy(novofuncionario.telfunc, telf);
    novofuncionario.salario = salario;

    funcionarios[totalfunc] = novofuncionario;
    totalfunc++;
    printf("\nFuncionário cadastrado com sucesso");
}

// Função para calcular a quantidade de diárias
int calcular_diarias(const char* dataentrada, const char* datasaida) {
//const usado para nao modificar o valor da variavel dentro da função e utilização de ponteiros
    int d1, m1, a1, d2, m2, a2;
    sscanf(dataentrada, "%d/%d/%d", &d1, &m1, &a1);
    sscanf(datasaida, "%d/%d/%d", &d2, &m2, &a2);

    // Converte as datas para dias absolutos
    int dias_entrada = a1 * 365 + m1 * 30 + d1;
    int dias_saida = a2 * 365 + m2 * 30 + d2;

    return dias_saida - dias_entrada;
}

// Função de cadastro de estadia
void cadastroestadia() {
    int cod, codcli, qtdhosp, qtddiarias, clientexiste = 0, quartodesocupado = 0, numquarto;
    char dataentrada[20], datasaida[20];

    printf("\nInsira o código da estadia: ");
    scanf("%d", &cod);

    // Verifica se o código está disponível
    for (int i = 0; i < totestadias; i++) {
        if (estadias[i].codigoest == cod) {
            printf("\nO código já está cadastrado!");
            return;
        }
    }

    printf("\nDigite o código do cliente: ");
    scanf("%d", &codcli);

    // Verifica se cliente está cadastrado
    for (int i = 0; i < totcli; i++) {
        if (clientes[i].codigocli == codcli) {
            clientexiste = 1;
            break;
        }
    }
    if (clientexiste != 1) {
        printf("\nO cliente não está cadastrado.");
        return;
    }

    printf("\nDigite a quantidade de hóspedes: ");
    scanf("%d", &qtdhosp);

    // Verifica se existe quarto disponível com essa descrição
    for (int i = 0; i < totquartos; i++) {
        if (quartos[i].qtdhospedes >= qtdhosp && strcmp(quartos[i].status, "desocupado") == 0) {
            numquarto = quartos[i].nquarto;
            quartodesocupado = 1;
            break;
        }
    }
    if (quartodesocupado != 1) {
        printf("\nNão tem quarto disponível com essa descrição!");
        return;
    }

    printf("\nDigite a data de entrada (dd/mm/aaaa): ");
    scanf(" %[^\n]", dataentrada);
    printf("\nDigite a data de saída (dd/mm/aaaa): ");
    scanf(" %[^\n]", datasaida);

    // Calcula a quantidade de diárias
    qtddiarias = calcular_diarias(dataentrada, datasaida);

    // Cria a nova estadia e atribui os valores
    estadia novaestadia;
    novaestadia.codigoest = cod;
    strcpy(novaestadia.dentrada, dataentrada);
    strcpy(novaestadia.dsaida, datasaida);
    novaestadia.qtddiarias = qtddiarias;
    novaestadia.codcliente = codcli;
    novaestadia.numquarto = numquarto;

    // Adiciona a nova estadia ao array e incrementa a contagem
    estadias[totestadias] = novaestadia;
    totestadias++;

    // Atualiza o status do quarto para ocupado
    for (int i = 0; i < totquartos; i++) {
        if (quartos[i].nquarto == numquarto) {
            strcpy(quartos[i].status, "ocupado");
            break;
        }
    }

    printf("\nEstadia cadastrada com sucesso");
}

// Função para cadastrar quarto
void cadastroquarto() {
    int num, qtdhospedes;
    float vdiaria;
    char status[10];

    printf("\nInsira o número do quarto: ");
    scanf("%d", &num);
    // Verifica se o número do quarto está disponível
    for (int i = 0; i < totquartos; i++) {
        if (quartos[i].nquarto == num) {
            printf("\nO número do quarto já está cadastrado!");
            return;
        }
    }

    printf("\nDigite a quantidade de hóspedes: ");
    scanf("%d", &qtdhospedes);
    printf("\nDigite o valor da diária: ");
    scanf("%f", &vdiaria);
    printf("\nDigite o status do quarto (ocupado/desocupado): ");
    scanf("%s", status);

    quarto novoquarto;
    novoquarto.nquarto = num;
    novoquarto.qtdhospedes = qtdhospedes;
    novoquarto.valordiaria = vdiaria;
    strcpy(novoquarto.status, status);

    quartos[totquartos] = novoquarto;
    totquartos++;
    printf("\nQuarto cadastrado com sucesso");
}

// Função para dar baixa na estadia e calcular valor total a ser pago
void baixarestadia() {
    int cod, numero;
    float vtotal = 0.0;
    printf("\nDigite o código da estadia: ");
    scanf("%d", &cod);
    for (int i = 0; i < totestadias; i++) {
        if (estadias[i].codigoest == cod) {
            // Calcula valor total
            numero = estadias[i].numquarto;
            for (int j = 0; j < totquartos; j++) {
                if (quartos[j].nquarto == numero) {
                    vtotal = quartos[j].valordiaria * estadias[i].qtddiarias;
                    // Atualiza status do quarto para desocupado
                    strcpy(quartos[j].status, "desocupado");
                    break;
                }
            }
            printf("\nO valor total é R$%.2f", vtotal);
            return;
        }
    }
    printf("\nEstadia não encontrada.");
}

// Função para pesquisar funcionário
void pesquisafunc(){
    int cod, opcao, resultado;
    char nome[30];

    printf("\nDeseja pesquisar por nome ou código? 1 - código || 2 - nome\n");
    scanf("%d", &opcao);

    if(opcao == 1) {
        printf("\nInsira o código do funcionário: ");
        scanf("%d", &cod);
        for(int i = 0; i < totalfunc; i++) {
            if(funcionarios[i].codigofunc == cod) {
                printf("\nO nome é %s", funcionarios[i].nomefunc);
                printf("\nO cargo é %s", funcionarios[i].cargo);
                printf("\nO telefone é %s", funcionarios[i].telfunc);
                printf("\nO salário é %.2f\n", funcionarios[i].salario);
                return;
            }
        }
        printf("\nCódigo de funcionário inexistente.\n");
    }
    else if(opcao == 2) {
        printf("\nInsira o nome do funcionário: ");
        scanf(" %[^\n]", nome);
        for(int j = 0; j < totalfunc; j++) {
            resultado = strcmp(funcionarios[j].nomefunc, nome);
            if(resultado == 0) {
                printf("\nO nome é %s", funcionarios[j].nomefunc);
                printf("\nO cargo é %s", funcionarios[j].cargo);
                printf("\nO telefone é %s", funcionarios[j].telfunc);
                printf("\nO salário é %.2f\n", funcionarios[j].salario);
                return;
            }
        }
        printf("\nNome de funcionário inexistente.\n");
    }
    else {
        printf("\nOpção inválida. Por favor, escolha 1 ou 2.\n");
    }
}

// Função para pesquisar clientes
void pesquisacli(){
    int cod;
    printf("\nInsira o código do cliente: ");
    scanf("%d", &cod);
    for(int i = 0; i < totcli; i++){
        if(clientes[i].codigocli == cod){
            printf("\nO nome é %s", clientes[i].nomecli);
            printf("\nO endereço é %s", clientes[i].enderecocli);
            printf("\nO telefone é %s", clientes[i].telcli);
            return;
        }
    }
    printf("\nCódigo de cliente inexistente.");
}

// Função para mostrar estadias de determinado cliente
void mostraestadia(){
    int cod;

    printf("\nInsira o código do cliente: ");
    scanf("%d", &cod);
    // Loop para encontrar o cliente desejado
    for(int i = 0; i < totcli; i++){
        if(clientes[i].codigocli == cod){
            // Loop para encontrar a estadia do cliente
            for(int j = 0; j < totestadias; j++){
                if(estadias[j].codcliente == cod){
                    printf("\nO nome do cliente é %s", clientes[i].nomecli);
                    printf("\nA quantidade de diárias é %d", estadias[j].qtddiarias);
                    printf("\nO número do quarto do cliente é %d", estadias[j].numquarto);
                }
            }
        }
    }
}
// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        printf("\n\nMenu:");
        printf("\n1 - Cadastrar Cliente");
        printf("\n2 - Cadastrar Funcionário");
        printf("\n3 - Cadastrar Quarto");
        printf("\n4 - Cadastrar Estadia");
        printf("\n5 - Baixar Estadia");
        printf("\n6 - Pesquisar clientes");
        printf("\n7 - Pesquisar funcionários");
        printf("\n8 - Mostrar estadias de determinado cliente");
        printf("\n9 - Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);


            if(opcao ==1){
                cadastrocli();
            }
            else if(opcao ==2){
                cadastrofunc();
            }
            else if(opcao ==3){
                cadastroquarto();
            }
            else if(opcao ==4){
                cadastroestadia();
            }
            else if(opcao ==5){
                baixarestadia();
            }
            else if(opcao ==6){
                pesquisacli();
            }
            else if(opcao ==1){
                pesquisafunc();
            }
            else if(opcao ==1){
                mostraestadia();
            }
            else{
                printf("\nOpção inválida.");
            }

    } while (opcao != 9);

    return 0;
}
