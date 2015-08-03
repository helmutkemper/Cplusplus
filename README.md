# Cplusplus

*Dicas de programação.*

Quando se trabalha com com C++ para hardware deve-se tomar cuidado no uso excessivo de ponteiros para a inicialização de classes, por isto, a maioria das classes são estáticas. Isto poupa memória e tempo de execução.

Uma outra coisa muito importante é o fato de você necessitar criar funções externas a classe sempre que uma função específica do hardware for usada.

Na prática, o código fica dividido em camadas, como na orientação a objeto, porém, a sua classe genérica nunca conterá acesso direto ao hardware ou configuração específica do mesmo. Quando isto for necessário você deve criar um ponteiro de função e fazer a sua classe genérica chamar uma função externa com esta finalidade.

Por isto é comum em minhas classes haver o uso de ponteiros para funções como no exemplo abaixo.

extern "C"
{
  typedef void ( * StatusModem ) ( eEvent );
  typedef void ( * ExternalDataModem ) ( char );
  typedef void ( * Action ) ();
}

Caso você não esteja familiarizado com este tipo de construção da linguagem, por favor, pare e estude sobre isto antes de continuar. É de vital importância o entendimento da construção de ponteiros para se trabalhar bem com hardware.

Ao contrário do que diz a lenda sobre ponteiros, eles não são complicados de serem usados e ajudam a poupar tempo de processamento e memória do hardware. Fazendo com que sua compreensão seja de vital importância para qualquer programador de hardware.

# Dica para virar um bom programador

Pare de escutar as pessoas que nunca programaram quando elas falam sobre programação;
Deixe seu orgulho de lado e entenda de uma vez por todas, seu código pode ser feito de forma melhor. Tenha sempre isto em mente;
Quando fizer um programa, pare analise e refaça o mesmo do zero até o dia que a próxima versão não ficar tão melhor do que a anterior;
Programe por programar, apenas pelo desafio de fazer. Esta é a única forma de aprender a programar;
As regras de orientação a objetos são muito mais do que teoria e devem ser absorvidas. Pratique e refaça seus códigos até a orientação a objeto deixar de ser uma teoria e passar a ser uma forma de pensar cotidiana;
Você só será um programador quando seus erros forem fáceis de corrigir e seus códigos desorganizados forem fáceis de entende e corrigir por qualquer pessoa;
Não se julgue um bom programador. Você ainda está vivo e pode fazer melhor;
Programação de verdade vai muito além de fazer funcionar. É necessário fazer funcionar da maneira certa e realmente saber o que está fazendo. Programação é uma ciência exata e não tem espaço para "eu acho...".

# Licença de uso

Este repositório tem a finalidade de ajudar programadores de hardware a entenderem melhor programação C++ para as necessidades
de hardware, possibilitando a criação de códigos C++ livres de plataforma, onde o mesmo código deve rodar em uma placa Arduino
simples e também em um Linux ( x86, x64, ARM ), Mac Os X e Windows.

Todos os códigos são distribuídos com o intúito de ajudar, porém, são distribuídos sem garantia de funcionamento ou obrigação
de suporte de qualquer tipo de minha parte.

Você é livre para copiar, modificar e distribuir meu código livremente, porém, sempre que fizer algum tipo de alteração deve 
deixar claro o fato de não ser o meu código original e tem a obrigação de mencionar meu nome como desenvolvedor original.

Helmut Kemper - helmut.kemper@gmail.com
