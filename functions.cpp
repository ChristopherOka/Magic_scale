#include "functions.h"
#include <iostream>
#include <stdlib.h>

/*Program steps:
1. Accept 5 weight values and a total weight value
2. Find the remainder of the total weight / the largest weight
3. Subtract the remainder from the total weight
4. Check if the remainder is greater than or equal to 0, and check if the weight can actually divide into the total weight without giving a value smaller than 1
5. Divide the new subtracted total by the largest weight
6. Save the value of the amount of times the largest weight could divide into the augmented total
7. Repeat with each weight value
8. Output the amount of times each weight can go into the total weight
9. Output the remainder if the total cannot be divided exactly into all the weights
*/


/*
Tested numbers:
(2048, 125, 75, 42, 15, 1) = (16, 0, 1, 0, 6) <- this checks out
(100, 100, 100, 100, 100, 100) = (1, 0, 0, 0, 0) <- works!
(1, 100, 100, 100, 100, 100) = (0, 0, 0, 0, 0) R1 <- checks out
(100, 1, 100, 100, 100, 100) = (100, 0, 0, 0 0) <- works
(100, 100, 1, 100, 100, 100) = (1, 0, 0, 0, 0) <- works
(100, 100, 100, 1, 100, 100) = (1, 0, 0, 0, 0) <- works
(100, 100, 100, 100, 1, 100) = (1, 0, 0, 0, 0) <- works
(100, 100, 100, 100, 100, 1) = (1, 0, 0, 0, 0) <- works
(0, 0, 0, 0, 0, 0) = Invalid input
(-1, -1, -1, -1, -1) = Invalid input
(100, 200, 200, 200, 200, 5) = (0, 0, 0, 0, 20) <- works
(100, 99, 100, 100, 100, 100) = (1, 0, 0, 0, 0) R1 <- works

*/
int balance(int TOTAL_WEIGHT, int WEIGHT1, int WEIGHT2, int WEIGHT3, int WEIGHT4, int WEIGHT5) { //function accepts the total weight, and the 5 other weights
	int first_division = 0; //declare the stored values of how many weights can go into the large weight
	int second_division = 0;
	int third_division = 0;
	int fourth_division = 0;
	int fifth_division = 0;
	int new_total; //declare the the new_total variable which will be helpful for calculations
	int remainder1; //declare the remainder variables that will be useful for each remainder calculation
	int remainder2;
	int remainder3;
	int remainder4;
	int remainder5;
	if (TOTAL_WEIGHT < 0 || WEIGHT1 < 0 || WEIGHT2 < 0 || WEIGHT3 < 0 || WEIGHT4 < 0 || WEIGHT5 < 0) { //check if the weights are negative integers
		std::cout << "                   Invalid weights. Although this scale is magical, it cannot compute the weight of antimatter!\n";
		return 0; //end the function while outputting "invalid weights"
	}
	if (TOTAL_WEIGHT == 0 || WEIGHT1 == 0 || WEIGHT2 == 0 || WEIGHT3 == 0 || WEIGHT4 == 0 || WEIGHT5 == 0) { //check if the weights are equal to 0
		std::cout << "             Sorry! This scale can only work when exactly 1 weight is placed on one side, and 5 on the other side.\n";
			return 0; //end the function while outputting "invalid weights"
	}
	remainder1 = TOTAL_WEIGHT % WEIGHT1; //find the remainder of the TOTAL_WEIGHT divided by the first weight
	new_total = TOTAL_WEIGHT - remainder1; //find the new integer total by subtracting the remainder from the total weight
	if (remainder1 >= 0 && new_total/WEIGHT1 != 0) { //check if the total weight is actually evenly divisible by the first weight 
		first_division = new_total / WEIGHT1; //set the first_division variable to the amount of times the first weight can fit into the total
	}//this if statement is skipped if the total weight is not evenly divisible by the first weight, keeping the total weight at its original total, and keeping the first_division variable at 0.
	
	remainder2 = remainder1 % WEIGHT2; //repeat the previous steps with each weight
	new_total = remainder1 - remainder2;
	if (remainder2 >= 0 && new_total / WEIGHT2 != 0) {
		second_division = new_total / WEIGHT2;
	}
	remainder3 = remainder2 % WEIGHT3;
	new_total = remainder2 - remainder3;
	if (remainder3 >= 0 && new_total / WEIGHT3 != 0) {
		third_division = new_total / WEIGHT3;
	}
	remainder4 = remainder3 % WEIGHT4;
	new_total = remainder3 - remainder4;
	if (remainder4 >= 0 && new_total / WEIGHT4 != 0) {
		fourth_division = new_total / WEIGHT4;
	}
	remainder5 = remainder4 % WEIGHT5;
	new_total = remainder4 - remainder5;
	if (remainder5 >= 0 && new_total / WEIGHT5 != 0) {
		fifth_division = new_total / WEIGHT5;
	}
	
	int final_remainder = TOTAL_WEIGHT - (first_division * WEIGHT1) - (second_division * WEIGHT2) - (third_division * WEIGHT3) - (fourth_division * WEIGHT4) - (fifth_division * WEIGHT5);
	//declare the final remainder variable that calculates how much of the original weight is left over after all the divisions

	
	std::cout << "                                                   You can fit exactly: \n\n"
		<< "                                                     " << first_division << " " << WEIGHT1 << " lb weights\n"
		<< "                                                     " << second_division << " " << WEIGHT2 << " lb weights\n"
		<< "                                                     " << third_division << " " << WEIGHT3 << " lb weights\n"
		<< "                                                     " << fourth_division << " " << WEIGHT4 << " lb weights\n"
		<< "                                                     " << fifth_division << " " << WEIGHT5 << " lb weights\n\n"
		<< "                                                  with a remainder of: " << final_remainder << std::endl << std::endl
		<< "                           into " << TOTAL_WEIGHT << " lb, while prioritizing weights in the order they were inputted.\n\n";
	
		return 0; //print all the weight values and the remainder and end the function

}

void magic_scale() {
	std::cout << "                                          [-------------------------------------]\n"
		      << "                                          |    Welcome to the magical scale!    |\n"
		      << "                                          [-------------------------------------]\n\n";
	std::cout << "        - You can choose to put one heavy weight on one side of the scale, and 5 others to put on the other side.-\n\n"
		      << "         - This scale will automagically calculate how many of the small weights can fit into the large one! -\n\n"
		      << "                  - This is optimized so the priority of weights is in the order you put enter them in as -\n\n";
	char y_n; //declare the yes or no variable 
	std::cout << "                                              Would you like to play? (y/n)\n";
	std::cout << "                                                             ";
	std::cin >> y_n; //user enters in 'y' if they want to play and 'n' if they don't
	std::cout << std::endl;
	system("CLS"); //console is cleared
	while (y_n == 'y') { //while the user continues to select 'y' for play again, this loop will continue
		int INITIAL_WEIGHT; //declare variables to put into the balance function
		int WEIGHT_ONE;
		int WEIGHT_TWO;
		int WEIGHT_THREE;
		int WEIGHT_FOUR;
		int WEIGHT_FIVE;

		std::cout << "                            What would you like your total weight on one side of the scale to be?\n\n";
		std::cout << "                                                           ";
		std::cin >> INITIAL_WEIGHT; //user enters in the value of the total weight and the 5 other weights
		std::cout << std::endl;
		std::cout << "                                       What would you like your first weight to be?\n\n";
		std::cout << "                                                           ";
		std::cin >> WEIGHT_ONE;
		std::cout << std::endl;
		std::cout << "                                       What would you like your second weight to be?\n\n";
		std::cout << "                                                           ";
		std::cin >> WEIGHT_TWO;
		std::cout << std::endl;
		std::cout << "                                       What would you like your third weight to be?\n\n";
		std::cout << "                                                           ";
		std::cin >> WEIGHT_THREE;
		std::cout << std::endl;
		std::cout << "                                       What would you like your fourth weight to be?\n\n";
		std::cout << "                                                           ";
		std::cin >> WEIGHT_FOUR;
		std::cout << std::endl;
		std::cout << "                                       What would you like your fifth weight to be?\n\n";
		std::cout << "                                                           ";
		std::cin >> WEIGHT_FIVE;
		std::cout << std::endl;
		balance(INITIAL_WEIGHT, WEIGHT_ONE, WEIGHT_TWO, WEIGHT_THREE, WEIGHT_FOUR, WEIGHT_FIVE); //balance function is run to calculate the final values and output them to the console
		std::cout << "                                            Would you like to try again? (y/n)\n\n";
		std::cout << "                                                           ";
		std::cin >> y_n; //user is prompted to play again and if they select 'y', it will run the function again
		std::cout << std::endl;
	}
	std::cout << "                                                     Okay! Goodbye.\n";
}//outputs goodbye if the user does not enter 'y'. The function then ends
