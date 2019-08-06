/**
  * electric_charges.h
  * 
  * create: 2019.08.07
  * author: potados
  */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <err.h>

#include "step_function.h"
#include "electric_charges.h"

const char *opstring = "hs";

int main(int argc, const char * argv[]) {
	if (argc < 2) {
		goto error_arg_no;
	}
	
	const char 				*fmt = VFMT_BGN VFMT_INTONLY VFMT_END "\n";
	struct step_function 	func = ELECTRIC_CHARGES_FUNCTION;

	value_t 				power_usage = -1;
	
	int 					c; 	

	while (optind < argc) {
		if ((c = getopt(argc, (char *const *)argv, opstring)) != -1) {
			switch (c) {
				case 'h':
					fmt = VFMT_BGN VFMT_COMMA VFMT_INTONLY VFMT_END "\n";
					break;

				case 's':
					func = (struct step_function)ELECTRIC_CHARGES_FUNCTION_SUMMER_WINTER;
					break;

				case '?':
					goto error_option;

				default:
					/* NEVER REACH */
					err(-1, "Impossible case: unhandled option: %c", c);		
					break;
			}
		}
		else {
			if (power_usage != -1) {
				goto error_arg_too_many;
			}

			char *end = NULL;
			power_usage = strtol(argv[optind], &end, 10);

			if (*end != '\0' || end == argv[optind]) {
				goto error_arg;
			}

			if (power_usage < 0) {
				goto error_arg;
			}

			optind++;
		}
	}

	if (power_usage == -1) {
		goto error_arg_no;
	}

	value_t result = integrate_step_function(&func, 0, power_usage);

	setlocale(LC_NUMERIC, "");
	printf(fmt, result);
	
	return 0;

error_arg_no:
	puts("No arguments.");
	goto usage;

error_arg_too_many:
	puts("Too many arguments.");
	goto usage;

error_arg:
	puts("Invalid argument.");
	goto usage;

error_option:
	puts("Unknown option.");
	goto usage;

usage:
	puts("Usage: calculate [-s] power_usage");
	puts("	-s	Apply winter/summer extra charge.");
	return -1;
}
