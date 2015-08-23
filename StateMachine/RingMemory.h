#ifndef RINGMEMORY_H
#define RINGMEMORY_H

#include "typeskemper.h"

/** @autor Helmut Kemper - helmut.kemper@gmail.com
 *  Esta classe cria uma memória em anel para arquivar dados em espaços físicos limitados.
 *  Memória em anel é um tipo de memória FIFO, onde o primeiro dado a entrar é o primeiro dado a
 *  sair, porém, se entrar mais dados do que a memória comporta, os dados mais antigos são perdidos.
 *  Atenção: Esta classe aloca espaço em memória de forma dinâmica e deve ser usada com cuidado.
 *           Quando o construtor RingMemory::RingMemory( valor ) é chamado, são alucados ( valor *
 *           <tipo template> ) espaços de memória.
 *  @code
      RingMemory<int, unsigned char> *rg = new RingMemory<int, unsigned char>( RING_SIZE );
      rg->onErrorAddEvent( &MainWindow::onErrorAdd );
      rg->onErrorGetEvent( &MainWindow::onErrorAdd );
      rg->add( 1 );  // 1
      rg->add( 2 );  // 2
      rg->add( 3 );  // 3
      rg->add( 5 );  // 4
      rg->add( 7 );  // 5
      rg->add( 11 ); // 6
      rg->add( 13 ); // 7
      rg->add( 17 ); // 8
      rg->add( 19 ); // 9
      rg->add( 23 ); // 0
      rg->add( 29 ); // 1
      rg->add( 31 ); // 2
      rg->add( 37 ); // 3
      rg->add( 41 ); // 4
      rg->add( 43 ); // 5

      qDebug() << "Lista na memória: ";
      for ( unsigned int i = 0; i != RING_SIZE * 4; i += 1 )
      {
        qDebug() << rg->get();
      }
 *  @endcode
 */
template <class DataTypeTplt, class DataSizeTplt>
class RingMemory
{
  public:

    /** Construtor.
     *  Quando o construtor RingMemory::RingMemory( valor ) é chamado, são alucados ( valor * <tipo template> )
     *  espaços de memória.
     *  @var sizeATplt <template type>, define o tamanho da memória.
     */
    RingMemory( DataSizeTplt sizeATplt );

    /** Limpa os dados contidos na memória
     *
     */
    void reset ();

    /** Adiciona um novo dado a memória.
     *  @var dataATplt <template type>, dado a ser adicionado.
     */
    void add( DataTypeTplt dataATplt );

    /** Lê o próximo dado da memória.
     *  @return <template type>, dado adicionado.
     */
    DataTypeTplt get();

    DataTypeTplt read( DataSizeTplt addressATplt );

    DataTypeTplt readLast();

    /** Chama uma função esterna sempre que se dá início a sobrescrição de dados, e apenas no início do evento.
     *
     */
    void onErrorAddEvent ( PT_VOID_VOID functionAVdVdPt );

    /** Chama uma função esterna sempre que se lê mais dados do que se tem na memória.
     *  Perceba que o evento é chamado antes do dado ser retornado.
     */
    void onErrorGetEvent ( PT_VOID_VOID functionAVdVdPt );

    /** Desconstrutor.
     *
     */
    ~RingMemory();

  private:

    /** Ponteiro para a função de erro.
     *
     */
    PT_VOID_VOID onErrorAdd;

    /** Ponteiro para a função de erro.
     *
     */
    PT_VOID_VOID onErrorGet;

    /** Ponteiro da memória
     *  @var <template type> ponteiro para array criado dinamicamente.
     */
    DataTypeTplt *memoryCTplt;

    /** Apontador do dado de entrada.
     *
     */
    DataSizeTplt dataPointerIn;

    /** Apontador do dado de saída.
     *
     */
    DataSizeTplt dataPointerOut;

    /** Tamanho da memória
     *
     */
    unsigned int sizeCTplt;
};

template class RingMemory<UINT_4B, UINT_1B>;
template class RingMemory<unsigned char, unsigned char>;
template class RingMemory<char, unsigned char>;
template class RingMemory<int, unsigned char>;

#endif // RINGMEMORY_H
