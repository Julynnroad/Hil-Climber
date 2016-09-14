// hillclimb.cpp
//  
//  This hill climber search algorithm will conduct a search of a
//  100 digit binary combination.  A random guess will be created
//  which will be evalauted with a fitness value.  Between 1 and n bits
//  randomly distributed in the solution will be flipped to create a 
//  new solution which will be evaluated once more.  If the new solution
//  has a higher fitness, it will be adopted and morphed to create another
//  new solution.  If the new solution is not better, the program will keep
//  it and morph it to try again.  Once the climber stagnates 20 times, the
//  program will end.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
double score( int check[100]); //declare internal evaluation function

int main(){
	srand (time(NULL)); // set seed for random numbers	
	// double eval(int *pj); // decalare external evaluation function
	int solution[100]; // soution is the attempt at the combination
	int solutionnew[100]; // solution new is the new morphed combination
	int answer[100]; //answer is the combination answer used in the internal evaluation
	int check[100]; // internal array in evaluation function
	double fitness; //fitness is the returned value of the eval (1-100)
	double fitnessnew; //fitnessnew is the fitness of the new morphed combination
	int bits; // number of bits to flip in the morph
	int random1; //random1 is the number of bits to be flipped to create the new morph
	int h; // loop counter
	int i; // loop counter
	int j; // loop counter
	int k; // counter for fitness
	int bit; // bit position to flip
	int stagnate = 0; // Indicates number of stagnate steps


	// Intialize solutionnew(100) with values randomly 0 or 1
	for (h = 0; h < 99; h++){
		solution[h] = rand() % 2; //randomly assign each bit a 1 or 0
                //cout << solution[h];
	}

	//get fitness of the solution
	fitness = score(solution);
	cout << fitness << endl;


	while (stagnate < 20){
		// create a new soluton to morph
		for (int p = 0; p<99; p++){
		solutionnew[p] = solution[p];
		}
	
		// morph the new solution:
		// Determine how many bits to flip in the morph; 1 to 6
		bits = (rand() % 6)+1;
		for (i = 0; i < bits; i++) {
			bit = rand() % 100; ; // determine random location of bit to flip
			if (solutionnew[bit] = 1){
			solutionnew[bit] = 0;
			}
			else{
			solutionnew[bit] = 1;
			}
		}

		// Evaluate the fitness of solutionnew
		fitnessnew = score(solutionnew);
		cout << "fitness =" << fitnessnew << endl;

		//compare the new fitness to the previous fitness
		if (fitnessnew > fitness) {
			for (int q = 0; q<99; q++){ // Store the solutionnew as solution
			solution[q] = solutionnew[q];
			}
			fitness = fitnessnew;  // Store the fitnessnew as fitness
			stagnate = 0;
		}
		else {
			stagnate++; // Count number of stagnate results
			// leave solution and fitness as is
		}

	}

}


double score(int check[100]) {	// checks and scores fitness, returns score as value of k
	int k = 0;
	// Three possible answers are shown below that will excercise the evalaution function in different ways.
	int answer[100] = {1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0};
	//  int answer = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	//  answer = [1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1];
	for (int j = 0; j< 99; j++) {
		if (check[j] == answer[j]){
		k++;
		}
	}
return k;
}






