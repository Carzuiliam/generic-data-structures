/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

//  Defines a new array element.
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

//  Lists the function prototypes.
ArrayElement* new_ArrayElement();

void dispose_ArrayElement(ArrayElement *_arrayElement);
void setAsChar_ArrayElement(ArrayElement *_arrayElement, char _value);
void setAsFloat_ArrayElement(ArrayElement *_arrayElement, float _value);
void setAsInt_ArrayElement(ArrayElement *_arrayElement, int _value);
void setAsString_ArrayElement(ArrayElement *_arrayElement, char* _value);
void print_ArrayElement(ArrayElement *_arrayElement);
