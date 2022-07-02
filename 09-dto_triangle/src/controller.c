#include <controller.h>
#include <string.h>
#include <stdlib.h>
#include <business.h>

static void controller_on_submit (void *object);
static void controller_on_change (void *object);

bool controller_init (controller_t *con)
{
    bool status = false;

    if (con != NULL)
    {
        memset (con, 0, sizeof (controller_t));

        con->base.object = con;
        con->base.on_change = controller_on_change;
        con->base.on_submit = controller_on_submit;

        status = true;
    }

    return status;
}

bool controller_open (controller_t *con, controller_args_t *args)
{
    bool status = false;

    if (con != NULL && args != NULL)
    {
        con->triangle = args->triangle;
        con->view = args->view;

        status = true;
    }

    return status;
}

bool controller_run (controller_t *con)
{
    bool status = false;

    if (con != NULL)
    {
        con->view->run (con->view->object);
        status = true;
    }

    return status;
}

bool controller_close (controller_t *con)
{
    bool status = false;

    if (con != NULL)
    {        
        memset (con, 0, sizeof (controller_t));
        status = true;
    }

    return status;
}

static void controller_on_submit (void *object)
{
    char *message = NULL;
    controller_t *c = (controller_t *)object;
    triangle_dto_t dto = c->view->get_triangle_dto (c->view->object);

    c->triangle->side_a = atoi (dto.side_a);
    c->triangle->side_b = atoi (dto.side_b);
    c->triangle->side_c = atoi (dto.side_c);

    message = (char *)business_get_message (c->triangle);

    c->view->set_triangle_result (c->view->object, message);
}

static void controller_on_change (void *object)
{
    controller_t *c = (controller_t *)object;
    c->view->set_triangle_result (c->view->object, "");
}