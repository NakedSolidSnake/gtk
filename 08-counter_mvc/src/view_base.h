#ifndef VIEW_BASE_H_
#define VIEW_BASE_H_

typedef struct 
{
    void *object;
    void (*set_text) (void *object, const char *text);
    void (*run) (void *object);
} view_base_t;

#endif /* VIEW_BASE_H_ */
