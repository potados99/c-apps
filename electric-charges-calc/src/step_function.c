#include "step_function.h"

static inline int select_range(struct numeric_range *restrict result, const struct numeric_range *restrict range, range_t begin, range_t end) {
	if (!(result && range)) {
		return -1;
	}

	result->begin = MAX(range->begin, begin);
	result->end = MIN(range->end, end);

	if (result->end < result->begin) {
		result->begin = result->end = 0;
	}
	
	return result->end - result->begin;
}

value_t integrate_step_function(const struct step_function *restrict function, range_t begin_inclusive, range_t end_inclusive) {
	if (!function) {
		return -1;
	}

	value_t total = 0;
	size_t n_steps = function->n_steps;
	const struct step_piece *steps = function->steps;

	struct numeric_range selection = {0, 0};

	for (size_t i = 0; i < n_steps; ++i) {
		if (select_range(&selection, &steps[i].range, begin_inclusive, end_inclusive) > 0) {
			total += (selection.end - selection.begin) * steps[i].value;	
		}
	}

	return total;
}


