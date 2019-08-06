/**
  * step_function.h
  * 
  * create: 2019.08.07
  * author: potados
  */

#ifndef step_function_h
#define step_function_h

#include "types.h"

/**
  * Perform integral of given step function [function] 
  * from [begin_inclusive] to [end_inclusive] and return the result.
  */
value_t integrate_step_function(const struct step_function *restrict function, range_t begin_inclusive, range_t end_inclusive);

#endif /* step_function_h */
