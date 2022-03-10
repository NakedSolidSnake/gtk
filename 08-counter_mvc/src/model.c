#include "model.h"
#include <string.h>

bool counter_init (counter_t *counter)
{
    bool status = false;

    if (counter != NULL)
    {
        memset (counter, 0, sizeof (counter_t));
        status = true;
    }

    return status;
}

bool counter_increment (counter_t *counter, int step)
{
    bool status = false;

    if (counter != NULL)
    {
        counter->value += step;
        status = true;
    }

    return status;
}

int counter_get_value (counter_t *counter)
{
    int value = -1;
    if (counter != NULL)
    {
        value = counter->value;
    }

    return value;
}
