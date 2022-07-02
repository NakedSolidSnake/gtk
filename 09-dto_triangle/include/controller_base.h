#ifndef CONTROLLER_BASE_H_
#define CONTROLLER_BASE_H_

typedef struct 
{
    void *object;
    void (*on_submit) (void *object);
    void (*on_change) (void *object);
} controller_base_t;

#endif /* CONTROLLER_BASE_H_ */
