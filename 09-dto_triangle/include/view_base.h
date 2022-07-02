#ifndef VIEW_BASE_H_
#define VIEW_BASE_H_

#include <stdbool.h>
#include "model_dto.h"

typedef struct 
{
    void *object;
    triangle_dto_t (*get_triangle_dto) (void *object);
    void (*set_triangle_result) (void *object, const char *message);
    bool (*run) (void *object);
} view_base_t;

#endif /* VIEW_BASE_H_ */
