#ifndef VIEW_H_
#define VIEW_H_

#include "view_base.h"
#include "controller_base.h"
#include <stdbool.h>

typedef struct 
{
    void *window;
    void *txt_counter;
    void *bt_counter;
} widgets_t;

typedef struct 
{
    view_base_t base;
    controller_base_t *controller_base;
    widgets_t *widgets;
    int argc;
    char **argv;
} view_t;

typedef struct 
{
    controller_base_t *controller_base;
    int argc;
    char **argv;
} view_args_t;

bool view_init (view_t *view);
bool view_open (view_t *view, view_args_t *args);
bool view_close (view_t *view);

#endif /* VIEW_H_ */
