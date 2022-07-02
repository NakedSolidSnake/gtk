#include <business.h>

typedef bool (*is_valid_t) (triangle_t *t);

typedef struct 
{
    is_valid_t cb;
    const char *message;
} validation_rules_t;

static validation_rules_t rules [] = 
{
    {.cb = triangle_exists,         .message = "Triangulo não é possível de ser formado"},
    {.cb = triangle_is_equilateral, .message = "Triangulo é Equilátero"},
    {.cb = triangle_is_isosceles,   .message = "Triangulo é Isosceles"},
    {.cb = triangle_is_scalene,     .message = "Triangulo é Escaleno"},
};

static const int rules_amount = sizeof (rules) / sizeof (rules[0]);

const char *business_get_message (triangle_t *t)
{
    int i;

    for (i = 0; i < rules_amount; i++)
    {
        if (rules[i].cb (t) == true)
        {
            break;
        }
    }

    return rules[i].message;
}