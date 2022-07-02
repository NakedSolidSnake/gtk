#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "controller_base.h"
#include "view_base.h"
#include "model.h"

typedef struct 
{
    controller_base_t base;
    view_base_t *view;
    triangle_t *triangle;
} controller_t;

typedef struct 
{
    view_base_t *view;
    triangle_t *triangle;
} controller_args_t;

bool controller_init (controller_t *con);
bool controller_open (controller_t *con, controller_args_t *args);
bool controller_run (controller_t *con);
bool controller_close (controller_t *con);

#endif /* CONTROLLER_H_ */
