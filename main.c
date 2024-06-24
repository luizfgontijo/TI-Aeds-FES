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

typedef struct{
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

//Função para carregar dados existentes no arquivo clientes
void carregarClientes() {
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        // Se o arquivo não existir, inicialize com 0 clientes
        totcli = 0;
        return;
    }

    while (fscanf(arquivo, "%d\n", &clientes[totcli].codigocli) != EOF) {
            //le todos os dados contidos no documento
        fgets(clientes[totcli].nomecli, 30, arquivo);
        strtok(clientes[totcli].nomecli, "\n"); // Remove o \n do final
        fgets(clientes[totcli].enderecocli, 30, arquivo);
        strtok(clientes[totcli].enderecocli, "\n");
        fgets(clientes[totcli].telcli, 15, arquivo);
        strtok(clientes[totcli].telcli, "\n");
        totcli++;
    }

    fclose(arquivo);
}

//Função para carregar dados existentes no arquivo funcionários
void carregarFuncionarios() {
    FILE *arquivofunc = fopen("func.txt", "r");
    if (arquivofunc == NULL) {
        // Se o arquivo não existir, inicialize com 0
        totalfunc = 0;
        return;
    }

    while (fscanf(arquivofunc, "%d\n", &funcionarios[totalfunc].codigofunc) != EOF) {
        fgets(funcionarios[totalfunc].nomefunc, 30, arquivofunc);
        strtok(funcionarios[totalfunc].nomefunc, "\n"); // Remove o \n do final
        fgets(funcionarios[totalfunc].cargo, 30, arquivofunc);
        strtok(funcionarios[totalfunc].cargo, "\n");
        fgets(funcionarios[totalfunc].telfunc, 15, arquivofunc);
        strtok(funcionarios[totalfunc].telfunc, "\n");
        fscanf(arquivofunc, "%f\n", &funcionarios[totalfunc].salario);
        totalfunc++;
    }

    fclose(arquivofunc);
}


//Função para carregar dados existentes no arquivo estadias
void carregarEstadias() {
    FILE *arquivo = fopen("estadias.txt", "r");
    if (arquivo == NULL) {
        totestadias = 0;
        return;
    }
    while (fscanf(arquivo, "%d\n", &estadias[totestadias].codigoest) != EOF) {
              //le todos os dados contidos no documento
        fgets(estadias[totestadias].dentrada, 20, arquivo);
        strtok(estadias[totestadias].dentrada, "\n");
        fgets(estadias[totestadias].dsaida, 20, arquivo);
        strtok(estadias[totestadias].dsaida, "\n");
        fscanf(arquivo, "%d\n", &estadias[totestadias].qtddiarias);
        fscanf(arquivo, "%d\n", &estadias[totestadias].codcliente);
        fscanf(arquivo, "%d\n", &estadias[totestadias].numquarto);
        totestadias++;
    }
    fclose(arquivo);
}

// Função para carregar dados existentes no arquivo de quartos
void carregarQuartos() {
    FILE *arquivo = fopen("quartos.txt", "r");
    if (arquivo == NULL) {
        totquartos = 0;
        return;
    }
      //le todos os dados contidos no documento
    while (fscanf(arquivo, "%d %d %f %s\n", &quartos[totquartos].nquarto, &quartos[totquartos].qtdhospedes, &quartos[totquartos].valordiaria, quartos[totquartos].status) != EOF) {
        totquartos++;
    }
    fclose(arquivo);
}

//função para salvar os clientes no arquivo
void salvarClientes() {
    FILE *arquivo = fopen("clientes.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    for (int i = 0; i < totcli; i++) {
            //coloca os dados informados em um arquivo para salvar
        fprintf(arquivo, "%d\n", clientes[i].codigocli);
        fprintf(arquivo, "%s\n", clientes[i].nomecli);
        fprintf(arquivo, "%s\n", clientes[i].enderecocli);
        fprintf(arquivo, "%s\n", clientes[i].telcli);
    }

    fclose(arquivo);
}

//Função para salvar funcionarios
void salvarFuncionarios() {
    FILE *arquivofunc = fopen("func.txt", "w");
    if (arquivofunc == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    for (int i = 0; i < totalfunc; i++) {
        fprintf(arquivofunc, "%d\n", funcionarios[i].codigofunc);
        fprintf(arquivofunc, "%s\n", funcionarios[i].nomefunc);
        fprintf(arquivofunc, "%s\n", funcionarios[i].cargo);
        fprintf(arquivofunc, "%s\n", funcionarios[i].telfunc);
        fprintf(arquivofunc, "%.2f\n", funcionarios[i].salario);
    }

    fclose(arquivofunc);
}

// Função para salvar as estadias no arquivo
void salvarEstadias() {
    FILE *arquivo = fopen("estadias.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }
    for (int i = 0; i < totestadias; i++) {
            //coloca os dados informados em um arquivo para salvar
        fprintf(arquivo, "%d\n", estadias[i].codigoest);
        fprintf(arquivo, "%s\n", estadias[i].dentrada);
        fprintf(arquivo, "%s\n", estadias[i].dsaida);
        fprintf(arquivo, "%d\n", estadias[i].qtddiarias);
        fprintf(arquivo, "%d\n", estadias[i].codcliente);
        fprintf(arquivo, "%d\n", estadias[i].numquarto);
    }
    fclose(arquivo);
}

// Função para salvar os quartos no arquivo
void salvarQuartos() {
    FILE *arquivo = fopen("quartos.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }
    for (int i = 0; i < totquartos; i++) {
            //coloca os dados informados em um arquivo para salvar
        fprintf(arquivo, "%d %d %.2f %s\n", quartos[i].nquarto, quartos[i].qtdhospedes, quartos[i].valordiaria, quartos[i].status);
    }
    fclose(arquivo);
}

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
    //é informado todos os dados necessários
    printf("\nDigite o nome do cliente: ");
    scanf(" %[^\n]", nome);
    printf("\nDigite o endereço do cliente: ");
    scanf(" %[^\n]", endereco);
    printf("\nDigite o telefone do cliente: ");
    scanf(" %[^\n]", tel);

    //copia os dados inseridos para um array novo cliente e depois adiciona no array de cliente, que é onde ficará armazenado
    cliente novocliente;
    novocliente.codigocli = cod;
    strcpy(novocliente.nomecli, nome);
    strcpy(novocliente.enderecocli, endereco);
    strcpy(novocliente.telcli, tel);

    // Adiciona a nova estadia ao array e incrementa a contagem
    clientes[totcli] = novocliente;
    totcli++;
    printf("\nCliente cadastrado com sucesso");
    //chama a função para salvar tudo no arquivo
    salvarClientes();
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

    //é informado todos os dados necessários
    printf("\nDigite o nome do funcionário: ");
    scanf(" %[^\n]", nomef);
    printf("\nDigite o cargo do funcionário: ");
    scanf(" %[^\n]", cargo);
    printf("\nDigite o telefone do funcionário: ");
    scanf(" %[^\n]", telf);
    printf("\nDigite o salário do funcionário: ");
    scanf("%f", &salario);

    //copia os dados inseridos para um array novo cliente e depois adiciona no array de cliente, que é onde ficará armazenado
    funcionario novofuncionario;
    novofuncionario.codigofunc = cod;
    strcpy(novofuncionario.nomefunc, nomef);
    strcpy(novofuncionario.cargo, cargo);
    strcpy(novofuncionario.telfunc, telf);
    novofuncionario.salario = salario;

    // Adiciona a nova estadia ao array e incrementa a contagem
    funcionarios[totalfunc] = novofuncionario;
    totalfunc++;
    printf("\nFuncionário cadastrado com sucesso");
    //chama a função para salvar os funcionários no arquivo
    salvarFuncionarios();
}

// Função para calcular a quantidade de diárias
int calcular_diarias(const char* dataentrada, const char* datasaida) {
//const usado para nao modificar o valor da variavel dentro da função e utilização de ponteiros
    int d1, m1, a1, d2, m2, a2;
    //lê as variaveis informadas e atribui elas a algumas variaveis locais para efetuar o calculo de diarias
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

    //é informado todos os dados necessários
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

    // chama a função de calcular a quantidade de diárias
    qtddiarias = calcular_diarias(dataentrada, datasaida);

    //copia os dados inseridos para um array novo cliente e depois adiciona no array de cliente, que é onde ficará armazenado
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

    //chama a função para salvar os dados no arquivo
    salvarEstadias();
    salvarQuartos();
}

// Função para cadastrar quarto
void cadastroquarto() {
    int num, qtdhospedes;
    float vdiaria;
    char status[15];

    printf("\nInsira o número do quarto: ");
    scanf("%d", &num);
    // Verifica se o número do quarto está disponível
    for (int i = 0; i < totquartos; i++) {
        if (quartos[i].nquarto == num) {
            printf("\nO número do quarto já está cadastrado!");
            return;
        }
    }

    //é informado todos os dados necessários
    printf("\nDigite a quantidade de hóspedes: ");
    scanf("%d", &qtdhospedes);
    printf("\nDigite o valor da diária: ");
    scanf("%f", &vdiaria);
    printf("\nDigite o status do quarto (ocupado/desocupado): ");
    scanf("%s", status);

    //copia os dados inseridos para um array novo cliente e depois adiciona no array de cliente, que é onde ficará armazenado
    quarto novoquarto;
    novoquarto.nquarto = num;
    novoquarto.qtdhospedes = qtdhospedes;
    novoquarto.valordiaria = vdiaria;
    strcpy(novoquarto.status, status);

    // Adiciona a nova estadia ao array e incrementa a contagem
    quartos[totquartos] = novoquarto;
    totquartos++;
    printf("\nQuarto cadastrado com sucesso");

    // chama a função para salvar os dados no arquivo
    salvarQuartos();
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
                        //calcula o valor total a ser pago, de acordo o valor da diaria
                    vtotal = quartos[j].valordiaria * estadias[i].qtddiarias;
                    // Atualiza status do quarto para desocupado
                    strcpy(quartos[j].status, "desocupado");
                    break;
                }
            }
            // Remove a estadia
            for (int k = i; k < totestadias - 1; k++) {
                estadias[k] = estadias[k + 1];
            }
            totestadias--;
            salvarEstadias();
            salvarQuartos();
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
                printf("\nO código é %d", funcionarios[j].codigofunc);
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
    int cod, opcao, resultado;
    char nome[30];

    printf("\nDeseja pesquisar por nome ou código? 1 - código || 2 - nome\n");
    scanf("%d", &opcao);

    if(opcao == 1){
    printf("\nInsira o código do cliente: ");
    scanf("%d", &cod);
    for(int i = 0; i < totcli; i++){
        if(clientes[i].codigocli == cod){
                //exibe dados do cliente solicitado
            printf("\nO nome é %s", clientes[i].nomecli);
            printf("\nO endereço é %s", clientes[i].enderecocli);
            printf("\nO telefone é %s", clientes[i].telcli);
            return;
        }
    }
    printf("\nCódigo de cliente inexistente.");
    }

      else if(opcao == 2) {
        printf("\nInsira o nome do cliente: ");
        scanf(" %[^\n]", nome);
        for(int j = 0; j < totcli; j++) {
                //repetição para encontrar o cliente
            resultado = strcmp(clientes[j].nomecli, nome);
            if(resultado == 0) {
                //exibe dados do cliente solicitado
                printf("\nO nome é %s", clientes[j].nomecli);
                printf("\nO código é %d", clientes[j].codigocli);
                printf("\nO endereço é %s", clientes[j].enderecocli);
                printf("\nO telefone é %s", clientes[j].telcli);
                return;
            }
        }
        printf("\nNome de cliente inexistente.\n");
    }
    else {
        printf("\nOpção inválida. Por favor, escolha 1 ou 2.\n");
    }

}

// Função para mostrar estadias de determinado cliente
void mostraestadia() {
    int cod;

    printf("\nInsira o código do cliente: ");
    scanf("%d", &cod);
    // Loop para encontrar o cliente desejado
    for (int i = 0; i < totcli; i++) {
        if (clientes[i].codigocli == cod) {
            // Loop para encontrar a estadia do cliente
            printf("\nO nome do cliente é %s", clientes[i].nomecli);
            for (int j = 0; j < totestadias; j++) {
                if (estadias[j].codcliente == cod) {
                    printf("\n\nCódigo da estadia: %d", estadias[j].codigoest);
                    printf("\nData de entrada: %s", estadias[j].dentrada);
                    printf("\nData de saída: %s", estadias[j].dsaida);
                    printf("\nQuantidade de diárias: %d", estadias[j].qtddiarias);
                    printf("\nNúmero do quarto: %d\n", estadias[j].numquarto);
                }
            }
            return;
        }
    }
    printf("\nCliente não encontrado.");
}
// Função principal
int main() {
    //chama as funções de carregar os dados antes da execução
    carregarClientes();
    carregarFuncionarios();
    carregarEstadias();
    carregarQuartos();

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

        //estrutura para identificar qual função do programa executar
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
            else if(opcao ==7){
                pesquisafunc();
            }
            else if(opcao ==8){
                mostraestadia();
            }
            else{
                printf("\nOpção inválida.");
            }

    } while (opcao != 9);

    return 0;
}
