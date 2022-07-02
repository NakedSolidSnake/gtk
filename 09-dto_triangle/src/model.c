#include <model.h>

triangle_t triangle_create (int side_a, int side_b, int side_c)
{
    triangle_t t = 
    {
        .side_a = side_a,
        .side_b = side_b,
        .side_c = side_c
    };

    return t;
}

bool triangle_is_equilateral (triangle_t *t)
{
    return (t->side_a == t->side_b && t->side_a == t->side_c);
}

bool triangle_is_isosceles (triangle_t *t)
{
    bool status = false;

    status |= ((t->side_a == t->side_b) && (t->side_b != t->side_c));
    status |= ((t->side_b == t->side_c) && (t->side_c != t->side_a));
    status |= ((t->side_a == t->side_c) && (t->side_a != t->side_b));

    return status;
}

bool triangle_is_scalene (triangle_t *t)
{
    return ((t->side_a != t->side_b) && 
            (t->side_b != t->side_c) &&
            (t->side_a != t->side_c));
}

bool triangle_exists (triangle_t *t)
{
    return !((t->side_a + t->side_b > t->side_c) && 
             (t->side_b + t->side_c > t->side_b) && 
             (t->side_c + t->side_a > t->side_b));
}   