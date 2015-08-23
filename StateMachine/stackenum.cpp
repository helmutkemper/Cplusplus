#include "stackenum.h"
#include "../AtModem/atmodem.h"

// Inicializa a lista de eventos da máquina de estados.
Event::eEvent StackEnum::eaEventList[ kDefEventListSize ];
int StackEnum::siEventListLineIn = 0;
int StackEnum::siEventListLineOut = 0;

// Construtor, nunca usado.
StackEnum::StackEnum()
{

}

void StackEnum::Reset ()
{
  // Limpa a fila de eventos
  for ( int i = 0; i != kDefEventListSize; i++ )
  {
    StackEnum::eaEventList[ i ] = Event::None;
  }

  // Redefine todos os ponteiros
  StackEnum::siEventListLineIn = 0;
  StackEnum::siEventListLineOut = 0;
}

void StackEnum::Add ( Event::eEvent asiEnum )
{
  // Arquiva o evento
  StackEnum::eaEventList[ StackEnum::siEventListLineIn ] = asiEnum;

  // Caso a fila esteja lotada, o evento é escrito na primeira posição da fila
  if ( StackEnum::siEventListLineIn >= kDefEventListSize - 1 )
  {
    StackEnum::siEventListLineIn = 0;
  }

  // Caso contrário, o evento é arquivado após o último evento
  else
  {
    StackEnum::siEventListLineIn += 1;
  }
}

Event::eEvent StackEnum::Get ()
{
  // Recebe o evento a ser retornado
  Event::eEvent lsiReturn;

  // Caso o ponterio de entrada e o de saída estejam no mesmo endereço, a fila de eventos está vazia.
  if ( StackEnum::siEventListLineIn == StackEnum::siEventListLineOut )
  {
    return Event::None;
  }

  // Arquiva o evento
  lsiReturn = StackEnum::eaEventList[ StackEnum::siEventListLineOut ];

  // Aponta para o próximo evento a sair.
  if ( StackEnum::siEventListLineOut >= kDefEventListSize - 1 )
  {
    StackEnum::siEventListLineOut = 0;
  }

  else
  {
    StackEnum::siEventListLineOut += 1;
  }

  return lsiReturn;
}
