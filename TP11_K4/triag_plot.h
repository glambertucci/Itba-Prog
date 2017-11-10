
#ifndef TRIAG_PLOT_H
#define TRIAG_PLOT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "triag.h"
#include "front_end.h"
    
void draw_default(triangle_t* tri, shared_vars_t* shared);
void fe_triag_plot(triangle_hd_t *triag_st , int depth, shared_vars_t* shared);

void write_triangle_data(shared_vars_t *shared_vars,FILE *file);

#ifdef __cplusplus
}
#endif

#endif /* TRIAG_PLOT_H */

