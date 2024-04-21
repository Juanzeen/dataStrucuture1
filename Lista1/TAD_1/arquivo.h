
struct locadora{ // é uma boa pratica em C deixar a definicao da struct na header,
                 // pois assim todos os arquivos terao acesso, é como se fosse o "meio" do arquivo.
   char nome_filme[50], genero[15];
   int ano_lanca;
} ;

typedef struct locadora Filme;


void clearScreen();
void aloca(Filme **locadora, int *ptr_totalF);
void verificacao_input(char *name);
void consulta(Filme *locadora, int total_filmes);
void pesquisar( Filme *locadora, int total_entradas);
void excluir( Filme **locadora, int *total_entradas);
void alterar(Filme *locadora, int total_entradas);