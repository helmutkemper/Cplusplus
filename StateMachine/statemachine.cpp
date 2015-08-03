#include "statemachine.h"

// Inicializa as variáveis
Action StateMachine::fnpaActionList[ kDefActionListSize ];
int StateMachine::siActionListLineIn = 0;
int StateMachine::siActionListLineOut = 0;

StateMachine::StateMachine()
{
}

void StateMachine::Reset ()
{
  // Escreve 0x00 em todos os itens da lista de funções
  for ( int i = 0; i != kDefActionListSize; i++ )
  {
    StateMachine::fnpaActionList[ i ] = '\0';
  }

  // Inicializa os ponteiros de entrada e saída
  StateMachine::siActionListLineIn = 0;
  StateMachine::siActionListLineOut = 0;
}

void StateMachine::Add ( Action afnpAction )
{
  // Adiciona um novo endereço de função a ser executada
  StateMachine::fnpaActionList[ StateMachine::siActionListLineIn ] = afnpAction;

  // Caso a fila esteja lotada, o primeiro endereço da lista é reescrito
  if ( StateMachine::siActionListLineIn >= kDefActionListSize - 1 )
  {
    StateMachine::siActionListLineIn = 0;
  }

  // Caso contrário, adiciona ao fim da fila
  else
  {
    StateMachine::siActionListLineIn += 1;
  }
}

void StateMachine::Step ()
{
  // Se o endereço de entrada for igual ao de saída, não faz nada.
  if ( StateMachine::siActionListLineIn == StateMachine::siActionListLineOut )
  {
    return;
  }

  // Se o ponteiro estiver apontando para o endeço zero, reset do computador, ele não faz nada.
  if ( StateMachine::fnpaActionList[ StateMachine::siActionListLineOut ] == '\0' )
  {
    return;
  }

  // Executa a função e a apaga em seguida.
  StateMachine::fnpaActionList[ StateMachine::siActionListLineOut ] ();
  StateMachine::fnpaActionList[ StateMachine::siActionListLineOut ] = '\0';

  // Incrementa para o endereço da próxima função a ser executada.
  if ( StateMachine::siActionListLineOut >= kDefActionListSize - 1 )
  {
    StateMachine::siActionListLineOut = 0;
  }

  else
  {
    StateMachine::siActionListLineOut += 1;
  }
}
