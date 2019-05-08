/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

//  Defines a new array element.
typedef struct ArrayElement
{
    void *value;
    struct ArrayElement *next;
}
ArrayElement;
