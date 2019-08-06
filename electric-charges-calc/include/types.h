/**
  * types.h
  * 
  * create: 2019.08.07
  * author: potados
  */

#ifndef types_h
#define types_h

#include <sys/types.h>
#include <stdbool.h>
#include <math.h>

typedef int 	range_t;
typedef double 	value_t;

#define VFMT_BGN			"%"
#define VFMT_COMMA			"'"
#define VFMT_INTONLY 		".0"
#define VFMT_END			"lf"

#define STEPS_MAX			5
#define RANGE_MAX			(~(1<<31))

#define MIN(a,b) 			(((a)<(b))?(a):(b))
#define MAX(a,b) 			(((a)>(b))?(a):(b))

struct numeric_range {
	range_t 				begin;
	range_t 				end;
};

struct step_piece {
	struct numeric_range	range;
	value_t					value;
};

struct step_function {
	size_t					n_steps;
	struct step_piece		steps[STEPS_MAX];
};

#endif /* types_h */
