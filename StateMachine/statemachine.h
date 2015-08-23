#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#define kDefFlagRuning 0
#define kDefFlagNextStep 1
#define kDefFlagWaiting 2
#define kDefFlagInternetGet 3
#define kDefFlagCheckEnd 4
#define kDefFlagProcessEnd 5

/** Quantidades de itens máximos na fila de ações
 *
 */
#define kDefActionListSize 5

/** Define ponteiro para funções do tipo void FUNCTION_NAME ( void ) {}
 *
 */
extern "C"
{
  typedef void ( * Action ) ();
}

/** Classe feita para trabalhar com máquina de status finitos.
 *  @autor Helmut Kemper - helmut.kemper@gmail.com
 */
class StateMachine
{
  public:
    /** Lista de funções ( void FUNCTION_NAME ( void ) {} ) a serem executadas em ordem. 
     *  Perceba que a fila é usada como uma memória em anel 
     *  onde não há uma distinção clara de início e de fim, apenas dois ponteiros, um para 
     *  entrada e outro para saída.
     *
     */
    static Action fnpaActionList[];

    /** Ponteiro de entrada para a lista de funções
     *
     */
    static int siActionListLineIn;

    /** Ponteiro de saída para a lista de funções
     *
     */
    static int siActionListLineOut;

    /** contrutor, não usado
     *
     */
    StateMachine();

    /** [ re ] inicializa a máquina de estados
     *
     */
    void static Reset ();

    /** Adiciona o endereço de uma nova função a ser executada
     *  @var afnAction endereço de função do tipo void FUNCTION_NAME ( void ) {}
     */
    void static Add ( Action afnpAction );

    /** Executa a próxima função da fila
     *
     */
    void static Step ();
};

#endif // STATE_MACHINE_H
