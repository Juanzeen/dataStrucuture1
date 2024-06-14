# Questões - Juan

## Quest 2 

### Struct
Struct stack definida com um campo inteiro de topo, que será referente ao índice de onde está o último elemento de nossa pilha no vetor.

### Funções

#### createStack
- Função responsável pela criação da pilha;
- Fazemos uma alocação com base no tamanho da estrutura;
- Inicializamos o topo em -1, pois todas as inserções na pilha são feitos com o push, que primeiro incrementa um no topo e depois insere;
- Fecha retornando a pilha criada dentro da função.

#### push
- Função que insere elementos na pilha;
- Como mencionado na função de criação, incrementamos um no topo e depois inserimos o elemento na pilha usando o topo como índice.

#### pop
- Função que remove elementos da nossa pilha;
- Simplesmente pegamos o último elemento da pilha acessando o vetor utilizando o topo da pilha como índice;
- Após isso decrementamos um do topo e retornamos o elemento removido do topo da pilha.

#### fillStack
- Função criada para preencher a pilha com a string;
- Inserção feita de forma muito simples, usando somente um for para cada índice do vetor de char e inserindo na pilha com o push;

#### copyStackReverse
- Função bem autoexplicativa;
- Percorremos uma pilha inteira, partindo do topo (último elemento) até chegarmos no primeiro elemento que foi inserido;
- Enquanto fazemos esse percurso, utilizamos o push para remover cada um dos elementos e salvamos estes elementos em uma outra pilha auxiliar, que será retornada ao fim da função;
- Com isso, a nossa pilha é copiada de forma inversa, pois o elemento que era o nosso topo na pilha inicial, torna-se o primeiro na nova pilha retornada, por isso é uma cópia reversa;
- Ao final retornamos a pilha que foi criada dentro da função.

#### show
- Função de exibição dos elementos da pilha.

#### checkPalindrome 
- Função que realmente faz o que é pedido para verificação se é palíndromo ou não; 
- Essa função recebe a pilha criada pela `fillStack()` e também a pilha copiada de forma inversa pela `copyStackReverse`;
- Recebendo ambas, as duas pilha sofrem `pop()` de forma constante até que estejam vazias; 
- Se elas estiverem vazias e a variável booleana itsPalindrome permanecer true por todo o caminho, definitvamente a palavra é palíndromo;
- Mas, no primeiro caracter divergência, caso isso aconteça, a variável itsPalindrome recebe valor falso e o loop é interrompido, pois com uma letra diferente a palavra já deixa de ser palíndromo.

## Quest 4

### Struct
Criamos nossa estrutura queue, que tem um array de ponteiro void, pois vamos lidar com caracteres para os operadores e inteiros para os números que serão operados. Além disso, temos três campos de int, um para o começo de nossa fila, um para o fim e outro que será responsável por armazena o resultado da nossa operação.

### Funções

#### createQueue
- Fazemos alocação de memória da estrutura;
- Iniciamos resulado, início e fim em 0;
- Retornamos o que foi criado dentro da função.

#### enqueue
- Função que insere elementos na fila;
- A inserção sempre é feita ao fim, então inserimos os elementos no vetor com base no índice `queue->end`, que é o fim de nossa fila;
- Pós inserção, incrementamos um ao fim.

#### dequeue
- Função que remove elementos da fila;
- Como nossa fila possui elementos do tipo char e do tipo int, colocamos essa função com retorno void *;
- Na fila a remoção é feita pelo primeiro elemento, então simplesmente acessamos o vetor no índice `queue->start`;
- Incrementamos um no começo da fila e depois retornamos o elemento.

#### isOperator 
- Função que verifica se o elemento passado é um operador;
- Formada por diversos cases que analisam se o elemento é: "+ - / *";
- Sendo algum dos elementos acima é retornado true, caso contrário retorna false;

#### applyOperator
- Muito similar a função de verificar se é operador;
- A diferença é que nessa função já sabemos que vamos receber um operador válido e dois números;
- Com base no operador recebido realizamos as operações correspondentes, o que é verifiacado por meio de um case.

#### showQueue
- Função criada para exibir a fila.

#### searchingResult
- Função que realiza a operação propriamente dita;
- Criamos algumas variáveis para podermos realizar as operações:
    - int twoInRow: contador que verifica se tivemos dois números seguidos;
    - void *dequedOperator: função que vai armazenar os operadores retirados da fila;
    - void *dequedNumber: duas variáveis que vão armazenar números retirados da fila;
    - bool haveOperator: variável que vai ser responsável por dizer se temos um operador em dequedOperator ou não;
    - bool haveApplied: variável responsável por dizer se acabamos de aplicar um operador e realizar uma operação matemática ou não.
- Nossa operação começa em um for que vai ser incrementado enquanto o começo for menor que o fim e o fim menor que o total de elementos do nosso vetor. Basicamente, são as verificações se nossa fila está vazia ou cheia.
- Explicando por blocos:
    - Primeiro verificamos se o primeiro elemento da nossa fila é operador, caso seja realizamos as seguintes operações: 
        - Se já tivermos operador guardado, colocamos ele no final da fila;
        - Se tivermos número armazenado, também o colocamos ao final da fila;
        - Após isso fazemos dequeue na fila e guardamos no dequedOperator, para salvarmos o novo operador;
        - Declaramos que é verdadeiro que temos operador e que é falso que acabamos de aplicar um operador;
        - Por fim, colocamos o twoInRow em 0, pois não tivemos dois números seguidos, já que estamos em uma ocorrência de operador
    - Caso nosso elemento a ser removido não seja operador:
        - Se tivermos um operador guardado e ainda não tivermos nenhuma ocorrência no nosso contador de números consecutivos, guardamos o número no dequedNumber1 e incrementamos um no contador de dois seguidos
        - Caso a gente já tenha uma ocorrência de um número em sequência, ou seja, nosso twoInRow == 1 e tivermos operador, significa que só precisamos de mais um número para aplicarmos a operação, então faremos isso. Fazemos o dequeue na fila e salvamos em dequedNumber2. Após isso, salvamos em queue->result o resultado da nossa operação entre dequedNumber1 e dequedNumber2 com base no dequedOperator. Por fim, só voltamos a reorganizar nossas variáveis para a próxima execução: haveOperator = false já que não temos mais operador, haveApllied = true pois acabamos de fazer uma operação, twoInRow = 0 pois tivemos dois seguidos e queremos voltar a condição inicial, terminamos deixando os nossos dequedNumbers nulos, para reiniciar todas as operações;
    - Por fim, temos nosso caso de else, que vai consistir na ocorrência de quando temos dequeue em um número e não temos nenhum operador armazenado para aplicarmos a operação, quando isso acontece simplesmente pegamos o elemento e reinserimos ao fim da fila.

## Quest 7

### Structs

#### stElement
- Estrutura para armazenar os estados;
- Temos o nome como string, valores para 2000 e 1990 como int e o next (próximo) também como stElement, mas como ponteiro para realizarmos o encadeamento.

#### stList
- Estrutura para a lista multiencadeada;
- Temos 4 variáveis de ponteiro stElement, duas que representam source (raíz) da lista, uma para 1990 e outra para 2000;
- Da mesma forma, também temos duas variáveis para o last, que representa o último elemento, também para cada lista.

### Funções

#### createEl
- Criação para cada nó;
- Consiste em um malloc com inicialização nula em cada um dos campos do nó.

#### createList
- Alocação de memória para a lista;
- Inicialização dos nós de raíz e de fim com a função `createEl`.

#### putInfos
- Função usada para adicionar as informações em um nó específico;
- Recebemos name, value2k e value90, o name é o nome do estado, value2k é o valor no ano 2000 e value90 valor no ano de 1990.


#### insert
- Essencialmente a mesma função para 90 e 2k, por isso explicação somente uma vez;
- Nossa lista será organizada de forma decrescente, então nosso maior elemento será o primeiro;
- Casos de inserção:
    - Quando a lista está vazia: iniciamos a lista colocando um único elemento como primeiro e último;
    - Lista não está vazia:
        - Elemento que será inserido maior que a raiz: o novo elemento será nossa nova raiz. Antigo elemento raiz será o próximo do novo elemento;
        - Elemento a ser inserido menor que o último: o elemento a ser inserido será nosso novo último elemento, o antigo último recebe o novo como próximo e nosso `list->last` será o novo elemento;
        - Por fim, temos a inserção no meio da lista, que funcionará da seguinte forma: Teremos um loop que será percorrido enquanto o nó "iterável" (variável que vai receber diversos nós para pecorrer a lista) tiver um próximo diferente de nulo. Dessa forma, sempre iremos comparar se o elemento a ser inserido é maior do que o próximo do nosso nó iterável, quando essa condição for satisfeita, o próximo do nosso novo elemento será o próximo do nó iterável e o próximo do nó iterável será o novo elemento.

### showList
- Muito similar a estratégia do nó iterável;
- Fazemos a mesma coisa mas sem reinserção, somente com um printf dentro do for.
