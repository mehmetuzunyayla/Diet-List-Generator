#include "Diet-List-Generator.h"

int main() {

    // Creating variables.
    string name;
    float weight, height, exercise_hours;

    // Using "getInfo()" function to get our client's information.
    getInfo(name, weight, height, exercise_hours);

    // Calculating BMI using the "calculateBMI()" function and assigning the result to a variable for later use.
    float bmi = calculateBMI(weight, height);

    // Generating a diet report based on BMI, exercise hours, and user's name using the "dietReport()" function.
    dietReport(bmi, exercise_hours, name); 

    return 0;
}