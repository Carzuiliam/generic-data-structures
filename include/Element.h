/**-----------------------------------------------------
                    Structure definition
 -----------------------------------------------------*/

typedef struct Element
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

    struct Element *next;
}
Element;

/**-----------------------------------------------------
                    Functions prototypes
 -----------------------------------------------------*/

Element* new_Element();
Element* new_CharElement(char _value);
Element* new_FloatElement(float _value);
Element* new_IntElement(int _value);
Element* new_StringElement(char *_value);

void dispose_Element(Element *_element);

void setAsChar_Element(Element *_element, char _value);
void setAsFloat_Element(Element *_element, float _value);
void setAsInt_Element(Element *_element, int _value);
void setAsString_Element(Element *_element, char* _value);

void print_Element(Element *_element);
