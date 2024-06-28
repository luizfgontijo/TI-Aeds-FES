# **Pontifícia Univerdade Católica de Minas Gerais**

**Instituto de Ciências Exatas e Informática**

**Unidade Educacional Coração Eucarístico**

## Enzo Casaes e Luiz Gontijo 

## Sistema do Hotel Descanso garantido 

**Introdução**

O Software foi desenvolvido para substituir as planilhas que deixavam confusas as tarefas de controle de estadia e cadastro de pessoas (clientes e funcionários). 

**Backlog do produto**

![Imagem do backlog do produto](assets/backlog.TI.png)

incialmente o produto necessitava dessas 6 funções que estão explicitadas na iamgem, mas com o decorrer do processo, a dupla sentiu a necessidade da adição de duas funções complementares ( Cadastro do quarto e a divisão entre pesquisa de clientes e funcionários). O quadro foi organizado pelo Trello. 

![Imagem da Sprint 1](assets/sprint1.TI.png) 

A imagem acima mostra a sprint 1, que deveria ter sido realizada até o dia 19/06/2024

![Imagem da Sprint 2](assets/sprint2.ti.png) 

A imagem acima mostra a sprint 2, que deveria ter sido realizada até o dia 22/06/2024

![Imagem da Sprint 3](assets/sprint3.ti.png)

A imagem acima mostra a sprint 3, que deveria ter sido realizada até o dia 24/06/2024. Essa sprint foi a última realizada pela dupla, após isso o sistema começou a passar por uma fase de testes gerais e, não de cada função separadamente, como havia sendo feito. 

**Lista de assinatura das funções e parâmetros**

Função "carregar quartos"= cria um arquivo, abre ele no modo de leitura e, caso o resultado seja nulo, inicializa-o com 0. Caso contrário, ele cria um laço para passar todos os dados contidos no arquivo. É chamada no início da execução, para não ocorrer erros durante o processo.

Função "carregar clientes"= cria um arquivo, abre ele no modo de leitura e, caso o resultado seja nulo, inicializa-o com 0. Caso contrário, ele cria um laço para passar todos os dados contidos no arquivo. É chamada no início da execução, para não ocorrer erros durante o processo.

Função "carregar funcionários"= cria um arquivo, abre ele no modo de leitura e, caso o resultado seja nulo, inicializa-o com 0. Caso contrário, ele cria um laço para passar todos os dados contidos no arquivo. É chamada no início da execução, para não ocorrer erros durante o processo.

Função "carregar estadias"= cria um arquivo, abre ele no modo de leitura e, caso o resultado seja nulo, inicializa-o com 0. Caso contrário, ele cria um laço para passar todos os dados contidos no arquivo. É chamada no início da execução, para não ocorrer erros durante o processo.

Função "salvar clientes"= Primeiro cria um arquivo, abre ele no modo de escrita, caso ele seja nulo, acontece um erro e exibe uma mensagem. Caso contrário, ele inicia um laço de execução e salva os dados necessários dentro do arquivo. 

Função "salvar funcionários"= Primeiro cria um arquivo, abre ele no modo de escrito, caso ele seja nulo, acontece um erro e exibe uma mensagem. Caso contrário, ele inicia um laço de execução e salva os dados necessários dentro do arquivo.

Função "salvar estadias"= Primeiro cria um arquivo, abre ele no modo de escrito, caso ele seja nulo, acontece um erro e exibe uma mensagem. Caso contrário, ele inicia um laço de execução e salva os dados necessários dentro do arquivo.

Função "salvar quartos"= Primeiro cria um arquivo, abre ele no modo de escrito, caso ele seja nulo, acontece um erro e exibe uma mensagem. Caso contrário, ele inicia um laço de execução e salva os dados necessários dentro do arquivo.

Função "cadastro de clientes"= Primeiro recebe um código, verifica se ele não está sendo utilizado por nenhum outro cliente, faz a leitura dos outros dados que são requisitados, cria um novo arrray para poder armazenar os dados desse novo cliente. Em seguida, ele adiciona esse novo array no final do array principal e incrementa a quantidade de clientes cadastrados no Hotel.

Função "cadastro de funcionários"= Primeiro recebe um código, verifica se ele não está sendo utilizado por nenhum outro funcionário, faz a leitura dos outros dados que são requisitados, cria um novo arrray para poder armazenar os dados desse novo funcionário. Em seguida, ele adiciona esse novo array no final do array principal e incrementa a quantidade de funcionários cadastrados no Hotel.

Função "cadastro de quartos"= Primeiro recebe um código, verifica se ele não está sendo utilizado por nenhum outro quarto, faz a leitura dos outros dados que são requisitados, cria um novo arrray para poder armazenar os dados desse novo quarto. Em seguida, ele adiciona esse novo array no final do array principal e incrementa a quantidade de quartos cadastrados no Hotel.

Função "cadastro de estadias"= Primeiro recebe um código, verifica se ele não está sendo utilizado por nenhuma outra estadia, recebe o código do cliente, verifica se ele existe e, após receber a quantidade de hóspedes que o quarto precisa, observa se tem algum quarto cadastrado com essas requisições. Pede as datas de entrada e saída e aciona a função "calcular diária", faz a leitura dos outros dados que são requisitados, cria um novo arrray para poder armazenar os dados dessa nova estadia. Em seguida, ele adiciona esse novo array no final do array principal, incrementa a quantidade de estadias cadastradas no Hotel e atualiza o status do quarto para não realizarem reservas na mesma data. 

Função "calcular diária"= Recebe parâmetros da função "cadastro de estadias" que são referentes às datas de chegada e saída, para que assim, possa ser realizado o cálculo de quantas diárias o cliente vai possuir no Hotel.

Função "baixar estadias e calcular valor total"= recebe um código de estadia cadastrada, faz um laço de repetição, verifica se a estadia está cadastrada, lê o número do quarto e calcula o valor (valor do quarto * diárias) e atualiza o status do quarto para desocupado e remove a estadia do cliente.

Função "pesquisa clientes"= Perguntam ao usuário se ele deseja pesquisar por código ou nome e, dependendo da resposta, entra em uma repetição para verificar a existência do cliente desejado. Após isso os dados dele são mostrados na tela.

Função "pesquisa funcionários"= Perguntam ao usuário se ele deseja pesquisar por código ou nome e, dependendo da resposta, entra em uma repetição para verificar a existência do funcionário desejado. Após isso os dados dele são mostrados na tela.


Função "mostra estadia"= recebe o código do clinete, verifica se ele existe, busca as estadias ativas dele e, caso existam, exibe os dados dessa estadia.

**TESTES**
Caso de teste 1- Cadastro de cliente: Entrada de dados: 999/ Pedro/ Rua 133/ 319999. Saída de dados esperada: Cliente cadastrado com sucesso. Resultado: funcionando! 

Caso de teste 2- Cadastro de um código de cliente repetido: Ao cadastrar cliente, colocar um código que já tenha sido cadastrado. Entrada de dados: 999. Saída de dados: O código já está cadastrado!. Resultado: funcionando!

Caso de teste 3: Cadastrar funcionário: Entrada de dados: 999/ Artur/ Chofer/ 3199/ 1500. Saída de dados: Funcionário cadastrado com sucesso!. Resultado: funcionando!

Caso de teste 4- Cadastro de um código de funcionário repetido: Ao cadastrar funcionário, colocar um código que já tenha sido cadastrado. Entrada de dados: 999. Saída de dados: O código já está cadastrado!. Resultado: funcionando!

Caso de teste 5- Cadastro de quarto: Entrada de dados: 999/ 4/ 300/ desocupado. Saída de dados: Quarto cadastrado com sucesso. Resultado: Funcionando!

Caso de teste 6: Cadastro de um código de quarto repetido: Ao cadastrar quarto, colocar um código que já tenha sido cadastrado. Entrada de dados: 999. Saída de dados: O número do quarto já está cadastrado!. Resultado: funcionando!

Caso de teste 7: Cadastro de estadia de um cliente não cadastrado: Entrada de dados: 999/999. Saída de dados: O cliente não está cadastrado. Resultado: Funcionando!

Caso de teste 8: Cadastro de estadia: Entrada de dados: 9000/999/4/"26/10/2005"/"29/10/2005". Saída de dados: Estadia cadastrada com sucesso. Resultado: Funcionando!

Caso de teste 9: Baixar estadia: Entrada de dados: 999. Saída de dados: 150 reais. Resultado: Funcionando!

Caso de teste 10: Cadastrar estadia antes de cadastrar um quarto: Entrada de dados: 9000/999/4. Saída de dados: Não tem quarto disponível com essa descrição. Resuldado: Funcionando!

Caso de teste 11: Cadastrar estadia antes de cadastrar um cliente: Entrada de dados: 9000/999. Saída de dados: Cliente não cadastrado. Resultado: Funcionando!

Caso de teste 12: Logo ao início digitar um número que não leva à nenhuma opção: Entrada de dados: -2. Saída de dados: opção inválida. Resultado: Funcionando!


