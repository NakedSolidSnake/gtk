#include <view.h>
#include <controller.h>
#include <model.h>

int main (int argc, char *argv[])
{
    view_t view;
    triangle_t triangle;
    controller_t controller;

    view_init (&view);
    controller_init (&controller);

    view_args_t view_args = 
    {
        .argc = argc,
        .argv = argv,
        .con = &controller.base
    };

    controller_args_t con_args = 
    {
        .triangle = &triangle,
        .view = &view.base
    };

    view_open (&view, &view_args);
    controller_open (&controller, &con_args);

    controller_run (&controller);

    view_close (&view);
    controller_close (&controller);    
    
    return 0;
}