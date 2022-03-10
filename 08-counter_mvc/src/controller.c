#include "controller.h"
#include <string.h>

static void controller_on_click (void *object);

bool controller_init (controller_t *controller)
{
    bool status = false;

    if (controller != NULL)
    {
        memset (controller, 0, sizeof (controller_t));

        controller->base.object = controller;
        controller->base.on_click = controller_on_click;

        status = true;
    }

    return status;
}

bool controller_open (controller_t *controller, controller_args_t *args)
{
    bool status = false;

    if (controller != NULL && args != NULL)
    {
        controller->counter = args->counter;
        controller->view_base = args->view_base;
        status = true;
    }

    return status;
}

bool controller_run (controller_t *controller)
{
    bool status = false;

    if (controller != NULL)
    {
        controller->view_base->set_text (controller->view_base->object, "0");
        controller->view_base->run (controller->view_base->object);
        status = true;
    }

    return status;
}

bool controller_close (controller_t *controller)
{
    bool status = false;

    if (controller != NULL)
    {
        memset (controller, 0, sizeof (controller_t));
        status = true;
    }

    return status;
}

static void controller_on_click (void *object)
{
    controller_t *controller = (controller_t *)object;
    char buffer[1024] = {0};
    counter_increment (controller->counter, 1);
    snprintf (buffer, 1024, "%d", counter_get_value (controller->counter));

    controller->view_base->set_text (controller->view_base->object, buffer);
}