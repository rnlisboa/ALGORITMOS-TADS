/**
 *  \file array_list_int.h
 * 
 *  \brief Biblioteca de array dinâmico de valores inteiros em C
 *
 * \author
 * \date:
 *
 */
#ifndef _ARRAY_LIST_INT_H_ 
#define _ARRAY_LIST_INT_H_

typedef struct array_list_int array_list_int;

/**
 * \brief Cria uma nova lista de números inteiros.
 * 
 * \return Um ponteiro para uma nova estrutura de lista de inteiros. 
 */

array_list_int * array_list_create();

/**
 * \brief  Obtém o valor armazenado no índice 'index'
 * 
 * \param list Um ponteiro para a estrutura da lista
 * \param index Um inteiro com o índice onde obter o elemento
 * \param error Um ponteiro para um inteiro para definir um erro, caso ocorra.
 * \return int O valor armazenado no índice 'index'
 */
int array_list_get(array_list_int * list, int index, int *error);

/**
 * \brief  Acrescenta um novo elemento ao final da lista.
 * 
 * \param list Um ponteiro para a estrutura da lista
 * \param value O valor a ser acrescentado à 'list'
 * \return unsigned int 
 */
unsigned int array_list_push_back(array_list_int * list, int i);

/**
 * \brief Remove o último elemento da lista.
 * 
 * \param list Um ponteiro para a estrutura da lista
 * \return unsigned int O número total de elementos após remover o último.
 */
unsigned int array_list_pop_back(array_list_int * list);

/**
 * \brief Obtém o número total de valores armazenados na lista 'list'
 * 
 * \param list Um ponteiro para a estrutura da lista.
 * \return unsigned int O número total de elementos armazenados em 'list'.
 */
unsigned int array_list_size(array_list_int * list);

/**
 * \brief  Obtém o índice do elemento 'elemento'.
 * 
 * \param list Um ponteiro para a estrutura da lista.
 * \param element O número inteiro a ser procurado na lista
 * \return int O índice do elemento 'elemento' se o elemento estiver no intervalo [0..size−1].
 * \todo Implementar a função.
 */
int array_list_find(array_list_int * list, int element);


/**
 * \brief Insere o valor inteiro 'value' no índice 'index'. 'index' deve
 *        ser um índice válido, entre 0 e 'array_list_size'. Se
 *        'index' for igual a 'size', a função terá o mesmo
 *        efeito de array_list_push_back().  
 * 
 * \param list  Um ponteiro para a estrutura da lista.
 * \param index O índice onde inserir o elemento. Deve estar no intervalo [0..size]
 * \param value O valor inteiro a ser inserido
 * \return unsigned int O novo tamanho da lista.
 * \todo Implementar a função.
 */
unsigned int array_list_insert_at(array_list_int * list, int index, int value);


/**
 * \brief Remove o elemento no índice 'index' de 'list'. 'index' deve
 *              ser um índice válido, entre 0 e 'array_list_size'−1.
 *
 * \param list  Um ponteiro para a estrutura da lista.
 * \param index O índice onde inserir o elemento. Deve estar no intervalo [0..size]
 * \return unsigned int O novo tamanho da lista.
 * \todo Implementar a função.
 */
unsigned int array_list_remove_from(array_list_int * list, int index);


/**
 * \brief Calcula o total de espaço reservado para 'list'
 * 
 * \param list A lista para obter a capacidade.
 * \return unsigned int O total de espaço para 'list'.
 */
unsigned int array_list_capacity(array_list_int * list);


/**
 * \brief Verifica a ocupação da array_list_int 'list', em percentual.
 * 
 * \param list A 'lista' a ser verificada.
 * \return double Um número entre 0.0 e 1.0, representando o
 * espaço total usado como percentual do espaço reservado. 
 */
double array_list_percent_occupied(array_list_int * list); 

/**
 * \brief Libera toda a memória reservada pela 'list'
 * 
 * \param list A lista a ser liberada
 * \todo
 */
void array_list_destroy(array_list_int * list); 

#endif
