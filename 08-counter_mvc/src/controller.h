#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "controller_base.h"
#include "view_base.h"
#include "model.h"

typedef struct 
{
    controller_base_t base;
    view_base_t *view_base;
    counter_t *counter;
} controller_t;

typedef struct 
{
    view_base_t *view_base;
    counter_t *counter;
} controller_args_t;

bool controller_init (controller_t *controller);
bool controller_open (controller_t *controller, controller_args_t *args);
bool controller_run (controller_t *controller);
bool controller_close (controller_t *controller);

#endif /* CONTROLLER_H_ */
