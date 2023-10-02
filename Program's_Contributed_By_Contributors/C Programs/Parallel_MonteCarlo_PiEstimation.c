//Problem 4.25: Estimating value of pi using openMP
/*Importing necessary libraries*/
#include <stdio.h> 
#include <omp.h> //open multi processing
#include <stdlib.h> //for rand() and srand()
#include <math.h> //for sqrt() and pow()
#include <time.h> // for time(NULL)

/*Defining total number of points*/
#define NUM_COUNT 40000000 //4*(10**7)

/*Variable Declaration*/
long int inside_circle = 0; //number of points inside the circle
long int i;
int threads = 1; //Number of threads specified

int main(void){
    printf("Please enter the number of threads to be used: ");
    scanf("%d",&threads);
    /*
    srand means set seed for rand, so we need to call srand() before rand().
    Best practice is to call srand() once at the beginning, to ensure it's truly random.    
    Any other value for the seed produces a different sequence.
    srand(time(NULL)); makes use of the computer's internal clock to control the choice of the seed.
    Since time is continually changing, the seed is forever changing.
    */
    srand(time(NULL) + omp_get_num_threads()); 

    #pragma omp parallel for num_threads(threads) reduction(+: inside_circle)
    for(i=0; i<NUM_COUNT; i++){
        double x_ran = (2.0 * (1.0*rand()/RAND_MAX)) - 1; //rand()/RAND_MAX lies betweeen 0 and 1
        double y_ran = (2.0 * (1.0*rand()/RAND_MAX)) - 1; //Thus [2.0 * rand()/RAND_MAX]-1 will lie between -1 and 1
        
        /*
        rand() is always positive ranging from 0 to RAND_MAX, 
        thus by the above equations,
        we obtain a point whose x and y coordinates lie between -1 and 1
        */

        double dist = sqrt(pow(x_ran,2)+pow(y_ran,2)); //Root over x^2 + y^2 
        
        if(dist<1.0){ //1.0 is written instead of 1 to ensure uniform data type comparison
            inside_circle++; //Point lies inside the Circle
        } 
    }
    double pi = 4 * ((double) inside_circle)/NUM_COUNT; //Number of points inside the circle divided by total.

    //printf("Number of threads used were: %d\n",threads);
    printf("pi = %f", pi); 
}