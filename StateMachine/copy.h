#ifndef COPY_H
#define COPY_H

/** Classe feita para copiar array de char
 *  @autor Helmut Kemper - helmut.kemper@gmail.com
 *  
 *  Esta classe é disponibilizada na esperança de ajudar, porém, sem garantias ou promessas de suporte.
 *  Você é livre para copiar alterar ou distribuir livremente, porém, deve deixar claro o fato do meu
 *  nome ter ajudado no seu trabalho e divulgar o meu nome.
 *  
 *  Nomenclatura usada:
 *  prefixo + nome funcional
 *  prefixo = modificador + tipo;
 *  modificador = p - ponteiro, c - constante;
 *  tipo = ch - char
 */
class Copy
{
  public:
    /** ponteiro para a string usada como espaçamento entre os dados copiados.
     *  @var pcchSpacer ponteiro para const char.
     */
    static const char *pcchSpacer;

    /** ponteiro para a string usando como espaçamento entre os dados copiados.
     *  @var pchSpacer ponteiro para char.
     */
    static char *pchSpacer;

    /** Recebe o espaçamento entre textos 
     *  @var pcchar ponteiro do array de char terminado em \0
     */
    static void Spacer ( const char *pcchData );

    /** Recebe o espaçamento entre os textos
     *  @var pchar ponteiro do array de char terminado em \0
     */
    static void Spacer ( char *pcchData );
    
    /** Concatena os dados contidos em Data1 e Data2 em Destination.
     *  Data1 a DataN devem ser terminados em \0.
     *  Destination = Data1 + Spacer + DataN ...  + Spacer + DataN
     *  @var pchar Destination
     *  @var pcchar Data1
     *  @var pchar  Data2
     */
    static void  Data ( char *chpDestination, const char *pcchData1, char *pchData2 );
    
    /** Concatena os dados contidos em Data1 e Data2 em Destination.
     *  Data1 a DataN devem ser terminados em \0.
     *  Destination = Data1 + Spacer + DataN ...  + Spacer + DataN
     *  @var pchar Destination
     *  @var pcchar Data1
     *  @var pcchar Data2
     */
    static void  Data ( char *chpDestination, const char *pcchData1, const char *pcchData2 );
    
    /** Concatena os dados contidos em Data1 e Data2 em Destination.
     *  Data1 a DataN devem ser terminados em \0.
     *  Destination = Data1 + Spacer + DataN ...  + Spacer + DataN
     *  @var pchar Destination
     *  @var pcchar Data1
     *  @var pchar  Data2
     *  @var pchar  Data3
     */
    static void  Data ( char *chpDestination, const char *pcchData1, char *pchData2, char *pchData3 );
    
    /** Concatena os dados contidos em Data1 e Data2 em Destination.
     *  Data1 a DataN devem ser terminados em \0.
     *  Destination = Data1 + Spacer + DataN ...  + Spacer + DataN
     *  @var pchar Destination
     *  @var pcchar Data1
     *  @var pchar  Data2
     *  @var pchar  Data3
     *  @var pchar  Data4
     */
    static void  Data ( char *chpDestination, const char *pcchData1, char *pchData2, char *pchData3, char *pchData4 );
    
    /** Concatena os dados contidos em Data1 e Data2 em Destination.
     *  Data1 a DataN devem ser terminados em \0.
     *  Destination = Data1 + Spacer + DataN ...  + Spacer + DataN
     *  @var pchar Destination
     *  @var pcchar Data1
     *  @var pchar  Data2
     *  @var pchar  Data3
     *  @var pchar  Data4
     *  @var pchar  Data5
     */
    static void  Data ( char *chpDestination, const char *pcchData1, char *pchData2, char *pchData3, char *pchData4, char *pchData5 );
    
    /** Concatena os dados contidos em Data1 e Data2 em Destination.
     *  Data1 a DataN devem ser terminados em \0.
     *  Destination = Data1 + Spacer + DataN ...  + Spacer + DataN
     *  @var pchar Destination
     *  @var pcchar Data1
     *  @var pchar  Data2
     *  @var pchar  Data3
     *  @var pchar  Data4
     *  @var pchar  Data5
     *  @var pchar  Data6
     */
    static void  Data ( char *chpDestination, const char *pcchData1, char *pchData2, char *pchData3, char *pchData4, char *pchData5, char *pchData6 );
    
    /** Copia os dados contidos em Data1 em Destination.
     *  Data1 a DataN devem ser terminados em \0.
     *  Destination = Data1 + Spacer + DataN ...  + Spacer + DataN
     *  @var pchar Destination
     *  @var pcchar Data1
     */
    static char* Data ( char *chpDestination, const char *pcchData1 );
    
    /** Copia os dados contidos em Data1 em Destination.
     *  Data1 a DataN devem ser terminados em \0.
     *  Destination = Data1 + Spacer + DataN ...  + Spacer + DataN
     *  @var pchar Destination
     *  @var pchar Data1
     */
    static char* Data ( char *chpDestination, char *pchData1 );
    Copy();
};

#endif // COPY_H
