#ifndef RINGMEMORY_H
#define RINGMEMORY_H

#include "typeskemper.h"

/** @autor Helmut Kemper - helmut.kemper@gmail.com
 *  Esta classe cria uma mem�ria em anel para arquivar dados em espa�os f�sicos limitados.
 *  Mem�ria em anel � um tipo de mem�ria FIFO, onde o primeiro dado a entrar � o primeiro dado a
 *  sair, por�m, se entrar mais dados do que a mem�ria comporta, os dados mais antigos s�o perdidos.
 *  Aten��o: Esta classe aloca espa�o em mem�ria de forma din�mica e deve ser usada com cuidado.
 *           Quando o construtor RingMemory::RingMemory( valor ) � chamado, s�o alucados ( valor *
 *           <tipo template> ) espa�os de mem�ria.
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

      qDebug() << "Lista na mem�ria: ";
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
     *  Quando o construtor RingMemory::RingMemory( valor ) � chamado, s�o alucados ( valor * <tipo template> )
     *  espa�os de mem�ria.
     *  @var sizeATplt <template type>, define o tamanho da mem�ria.
     */
    RingMemory( DataSizeTplt sizeATplt );

    /** Limpa os dados contidos na mem�ria
     *
     */
    void reset ();

    /** Adiciona um novo dado a mem�ria.
     *  @var dataATplt <template type>, dado a ser adicionado.
     */
    void add( DataTypeTplt dataATplt );

    /** L� o pr�ximo dado da mem�ria.
     *  @return <template type>, dado adicionado.
     */
    DataTypeTplt get();

    DataTypeTplt read( DataSizeTplt addressATplt );

    DataTypeTplt readLast();

    /** Chama uma fun��o esterna sempre que se d� in�cio a sobrescri��o de dados, e apenas no in�cio do evento.
     *
     */
    void onErrorAddEvent ( PT_VOID_VOID functionAVdVdPt );

    /** Chama uma fun��o esterna sempre que se l� mais dados do que se tem na mem�ria.
     *  Perceba que o evento � chamado antes do dado ser retornado.
     */
    void onErrorGetEvent ( PT_VOID_VOID functionAVdVdPt );

    /** Desconstrutor.
     *
     */
    ~RingMemory();

  private:

    /** Ponteiro para a fun��o de erro.
     *
     */
    PT_VOID_VOID onErrorAdd;

    /** Ponteiro para a fun��o de erro.
     *
     */
    PT_VOID_VOID onErrorGet;

    /** Ponteiro da mem�ria
     *  @var <template type> ponteiro para array criado dinamicamente.
     */
    DataTypeTplt *memoryCTplt;

    /** Apontador do dado de entrada.
     *
     */
    DataSizeTplt dataPointerIn;

    /** Apontador do dado de sa�da.
     *
     */
    DataSizeTplt dataPointerOut;

    /** Tamanho da mem�ria
     *
     */
    unsigned int sizeCTplt;
};

template class RingMemory<UINT_4B, UINT_1B>;
template class RingMemory<unsigned char, unsigned char>;
template class RingMemory<char, unsigned char>;
template class RingMemory<int, unsigned char>;

#endif // RINGMEMORY_H
