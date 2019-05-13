# Estruturas de Dados Genéricas em C

Este projeto exibe um exemplo de estrutura de dados com um tipo genérico de dados em C.

## Introdução

Antes de tudo: **não há uma implementação específica para tipos genéricos em C**. Somente a partir do C++ surgiu o conceito de tipo genérico (por meio de [templates ou objetos](https://web.eecs.utk.edu/~bvz/cs365/notes/generic-types.html)). Mas há **2 (duas) formas básicas** de contornar tal problema: 

 - A primeira é por meio de **ponteiros vazios** (do tipo `void*`), exigindo um _downcast_ para o tipo apropriado da variável antes da manipulação desta. Embora isso dê um poder maior ao programador (inclusive permitindo utilizar funções como parâmetros de função -- algo impensável em outras linguagens de programação), o _downcast_ é extremamente inseguro, uma vez que a linguagem C não realiza checagem de tipos em tempo de execução.
 - A segunda forma é por meio de **estruturas com memória compartilhada**, construída usando uma estrutura `union` combinada com uma estrutura `enum` (contendo o índice dos tipos). Tal método é mais fácil de ser depurado do que trabalhar com ponteiros, embora exija um certa atenção do programador para gerenciar o valor contido na variável. 

## Sobre Este Projeto

Os códigos-fontes presentes aqui implementam, utilizando a abordagem `union`/`enum` descrita anterior, um exemplo de lista dinâmica simples.

Usando o tipo `union`, é possível alocar múltiplas variáveis em um único bloco de memória. Por exemplo, considere as seguintes linhas de código do arquivo [ArrayElement.c](libraries/ArrayElement.c):

```C
typedef struct ArrayElement
{
    enum Type
    {
        CHAR,
        FLOAT,
        INTEGER,
        STRING
    }
    type;

    union Value
    {
        char c;
        float f;
        int i;
        char *s;
    }
    value;

    struct ArrayElement *next;
}
ArrayElement;
```

Tal trecho de código define que, dentro de um `ArrayElement`, há uma estrutura do tipo `union`, que contém um `char`, um `float`, um `int` e uma _string_ (`char*`), todas compartilhando o mesmo bloco de memória. Há também uma estrutura do tipo `enum`, que contém o tipo de valor que foi atribuído ao `ArrayElement`, e uma variável `ArrayElement*`, utilizado no controle da estrutura `ArrayList` (definida no arquivo [ArrayList.c](libraries/ArrayList.c)).

Com base na estrutura anterior, o trecho de código a seguir demonstra a criação de um `ArrayElement` do tipo `int`:

```C
//  Cria novo elemento
ArrayElement *_arrayElement = new_ArrayElement();       

//  Atribui os valores ao elemento
arrayElement->type = INTEGER;
arrayElement->value.i = 100;                        
arrayElement->next = NULL;
```

Note que é necessário guardar o tipo da variável atribuída pois, ao fazer `_arrayElement->value.i = _value`, não só e atribuído um valor para `i`, mas também para `c`, `f`  e `*s`, já que a área de memória para `value` é compartilhada. Isso pode ser observado pelo fato de que, após o código acima ser executado, todas as operações seguintes são válidas do ponto de vista do compilador -- mesmo que gerem dados inconsistentes:

```C
//  Imprime o valor de "value" como char (provavelmente
// o caractere correspondente ao valor 100)
printf("%c", arrayElement->value.c);

//  Imprime o valor de "value" como float (provavelmente
// errado)
printf("%.2f", arrayElement->value.f);

//  Imprime o valor de "value" como int (único correto)
printf("%i", arrayElement->value.i);

//  Imprime o valor de "value" como uma string (apenas
// lixo)
printf("%s", arrayElement->value.s);
```

No entanto, se o tipo da variável estiver disponível, é possível fazer

```C
switch (_arrayElement->type)
    {
        case CHAR:
            printf("%c", arrayElement->value.c);
            break;

        case FLOAT:
            printf("%.2f", arrayElement->value.f);
            break;

        case INTEGER:
            printf("%i", arrayElement->value.i);
            break;

        case STRING:
            printf("%s", arrayElement->value.s);
            break;
    }
```

o que garante que os dados possam ser tratados corretamente.

## Informações Adicionais

Como isso é um trabalho em progresso, provavelmente adicionarei algumas coisas futuramente (e.g, pilhas, matrizes esparsas e árvores). Fique atento!

## Licença de Uso

Os códigos disponibilizados aqui estão sob a GNU General Public License, versão 3.0 (veja o arquivo `LICENSE` em anexo para mais detalhes). Dúvidas sobre este projeto podem ser enviadas para o meu e-mail: carloswdecarvalho@outlook.com.