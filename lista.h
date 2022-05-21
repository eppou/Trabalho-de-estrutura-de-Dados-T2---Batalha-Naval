#include "bibliotecas.h"

typedef void *Lista;

/*FUNÇÃO INICIA LISTA
     !pre-condição:Memoria disponivel no sistema;
     !retorna: Um void pointer que aponta para a lista;
*/

void *inicia();

/*FUNÇÃO PARA INICIAR UM NÓ DA LISTA
    !recebe: ponteiro para lista
    !pre-condição:Memoria disponivel no sistema e o ponteiro para lista ser valido
    !retorna: Um ponteiro para o nó criado
*/
void *inicia_no(Lista);

/*FUNÇÃO PARA ACHAR NÓ
    !recebe: ponteiro para lista e um inteiro que é a posição do nó que voce quer achar
    !pre-condição: o valor inteiro ser uma posição existente na lista,e o ponteiro para lista ser valido
    !retorna: um ponteiro para o nó na posição que foi dada
*/
void *procura_no(Lista, int);

/*FUNÇÂO INSEREÇÂO NO FIM
    !recebe: ponteiro para lista e o dado para ser inserido na lista
    !pre-condição: o ponteiro para lista ser valido e haver memoria disponivel para o nó
    !retorna: um inteiro para dizer se a inserção foi completada com sucesso  ou não
*/
int lista_inserenofim(Lista, void *);

/*FUNÇÂO REMOVE
    !recebe: ponteiro para lista e um inteiro que é a posição do nó que deve ser removido
    !pre-condição: o valor inteiro ser uma posição existente na lista,e o ponteiro para lista ser valido
    !retorna: o dado removido;
*/

void *aux_remove(Lista, int);

/*FUNÇÂO REMOVE DO COMEÇO
    !recebe: Ponteiro para lista
    !pre-condição: O ponteiro para lista ser valido, e a lista não estar vazia
    !retorna: O dado removido;
*/
void *lista_pop(Lista);

/*FUNÇÂO TAMANHO DA LISTA
    !recebe: Ponteiro para lista
    !pre-condição: O ponteiro para lista ser valido
    !retorna: Tamanho da lista.
*/
int returnlistsize(Lista);

/*FUNÇÂO GET DADO DA LISTA
    !recebe: ponteiro para lista e um inteiro que é a posição do nó que armazena o dado que voce quer achar na lista
    !pre-condição: o valor inteiro ser uma posição existente na lista,e o ponteiro para lista ser valido
    !retorna: o dado que estava armazenado no nó "int" da lista
*/
void *returnData(Lista,int);
