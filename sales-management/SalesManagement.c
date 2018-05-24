//
//  SalesManagement.c
//  sales-management
//
//  Created by POTADOS on 2018. 5. 24..
//  Copyright © 2018 POTADOS. All rights reserved.
//

#include "SalesManagement.h"

void start_main_loop() {
	int selected = 0;
	rewind(stdin);

	while ((selected = getchar() - '0') != 4) {
		rewind(stdin);
		switch (selected) {
			case 1:
				//print_sales();
				break;
			case 2:
				//add_new_part();
				//print_sales();
				break;
			case 3:
				//edit_part();
				//print_sales();
				break;
			case 4:
				break;
			default:
				break;

		}

	}
	printf("Exiting program.\n");
}

void display_menu() {
	printf("==================\n");
	printf("1. Show sales data\n");
	printf("2. Add new part\n");
	printf("3. Edit data\n");
	printf("4. Exit\n");
	printf("==================\n");
}

void add_new_part() {

}

void edit_part() {
	int targetIndex = 0;
	printf("Enter the index of part you want to edit");

	while ((targetIndex = getchar() -'0') == NULL) {
		printf("Enter proper index!");
	}

	
}
