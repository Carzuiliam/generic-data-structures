# Estruturas de Dados Genéricas em C

Este projeto exibe um exemplo de como criar uma estrutura de dados genérica em C.

## Introdução

Antes de tudo: não há uma implementação específica para tipos genéricos em C. Somente a partir do C++ surgiu o conceito de variável genérica (por meio de [templates ou objetos](https://web.eecs.utk.edu/~bvz/cs365/notes/generic-types.html)). Mas há duas formas básicas de contornar tal problema: 

 - A primeira é por meio da declaração de variáveis do tipo `void *`, exigindo um _downcast_ para o tipo apropriado da variável antes da manipulação desta. Embora dê um poder maior ao programador (inclusive permitindo utilizar funções como parâmetros), o _downcast_ é extremamente perigoso uma vez que a linguagem C não realiza checagem de tipos em tempo de execução.
 - A segunda forma é por meio de uma estrutura do tipo `union` (contendo todos os tipos possíveis para a variável em questão) combinada com um `enum` (contendo o índice dos tipos). Embora exiga um certo trabalho do programador para gerenciar o valor contido na variável, é mais fácil de ser depurado do que trabalhar com ponteiros, como o método anterior faz. 

 ## Licença de Uso

Os códigos disponibilizados aqui estão sob a GNU General Public License, versão 3.0 (veja o arquivo `LICENSE` em anexo para mais detalhes). Dúvidas sobre a biblioteca podem ser enviadas para o meu e-mail: carloswdecarvalho@outlook.com.