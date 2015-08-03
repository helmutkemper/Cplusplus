#ifndef STACKENUM_H
#define STACKENUM_H

#include "atmodem.h"

/** Quantidades de itens máximos na fila de eventos
 *
 */
#define kDefEventListSize 16

/** Classe feita para trabalhar com máquina de status finitos.
 *  A finalidade dessa classe é poder gerar uma fila de eventos a serem tratados
 *  de forma consecutiva.
 *  @autor Helmut Kemper - helmut.kemper@gmail.com
 */
class StackEnum
{
  public:

    /** Fila de eventos a serem tratados. Perceba que a fila é usada como uma memória em anel 
     *  onde não há uma distinção clara de início e de fim, apenas dois ponteiros, um para 
     *  entrada e outro para saída.
     *  @var eaEventList array de enum com todos os eventos
     */
    static Event::eEvent eaEventList[];

    /** Ponteiro de entrada do evento
     *  @var int aponta para o endereço onde o próximo evento será arquivado.
     */
    static int siEventListLineIn;

    /** Ponteiro de saída do evento
     *  @var int aponta para o endereço do próximo evento a sr lido.
     */
    static int siEventListLineOut;

    /** Construtor, nunca usado
     *
     */
    StackEnum ();

    /** Adiciona um evento a fila
     *  @var enum de eventos
     */
    static void Add ( Event::eEvent asiEnum );

    /** [ Re ] Inicializa a fila de eventos
     *
     */
    static void Reset ();

    /** Retorna o próximo evento da lista
     *  @return enum de eventos
     */
    static Event::eEvent Get();
};

#endif // STACKENUM_H
