#ifndef CONTROLLER_BASE_H_
#define CONTROLLER_BASE_H_

typedef struct 
{
    void *object;
    void (*on_click) (void *object);
} controller_base_t;

#endif /* CONTROLLER_BASE_H_ */
