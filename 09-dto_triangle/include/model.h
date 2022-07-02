#ifndef MODEL_H_
#define MODEL_H_

#include <stdbool.h>

typedef struct 
{
    int side_a;
    int side_b;
    int side_c;
} triangle_t;

triangle_t triangle_create (int side_a, int side_b, int side_c);
bool triangle_is_equilateral (triangle_t *t);
bool triangle_is_isosceles (triangle_t *t);
bool triangle_is_scalene (triangle_t *t);
bool triangle_exists (triangle_t *t);



#endif /* MODEL_H_ */
