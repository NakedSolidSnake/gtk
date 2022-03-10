#ifndef MODEL_H_
#define MODEL_H_

#include <stdbool.h>

typedef struct 
{
    int value;
} counter_t;

bool counter_init (counter_t *counter);
bool counter_increment (counter_t *counter, int step);
int counter_get_value (counter_t *counter);

#endif /* MODEL_H_ */
