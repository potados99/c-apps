/**
  * electric_charges.h
  * 
  * create: 2019.08.07
  * author: potados
  */

#ifndef electric_charges_h
#define electric_charges_h

#include "types.h"

#define ELECTRIC_CHARGES_FUNCTION												\
	{																			\
			.n_steps = 3,														\
			.steps = {															\
				{ .range = { 0, 200 }, .value = 93.3 },							\
				{ .range = { 201, 400 }, .value = 187.9 },						\
				{ .range = { 401, RANGE_MAX }, .value = 280.9 }					\
			}																	\
	}

#define ELECTRIC_CHARGES_FUNCTION_SUMMER_WINTER									\
	{																			\
			.n_steps = 4,														\
			.steps = {															\
				{ .range = { 0, 200 }, .value = 93.3 },							\
				{ .range = { 201, 400 }, .value = 187.9 },						\
				{ .range = { 401, 1000 }, .value = 280.9 },						\
				{ .range = { 1001, RANGE_MAX }, .value = 709.5 }				\
			}																	\
	}

#endif /* electric_charges_h */
