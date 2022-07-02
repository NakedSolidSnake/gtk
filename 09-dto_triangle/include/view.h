#ifndef VIEW_H_
#define VIEW_H_

#include "view_base.h"
#include "controller_base.h"

typedef struct 
{
    void *window;
    void *bt_submit;
    void *lb_resul;
    void *txt_side_a;
    void *txt_side_b;
    void *txt_side_c;
} view_widgets_t;

typedef struct 
{
    view_base_t base;
    view_widgets_t *vw;
    controller_base_t *con;
} view_t;

typedef struct 
{
    int argc;
    char **argv;
    controller_base_t *con;
} view_args_t;

bool view_init (view_t *view);
bool view_open (view_t *view, view_args_t *args);
bool view_close (view_t *view);

#endif /* VIEW_H_ */
