#include <iostream>
#include <cmath>
#include <array>

using namespace std;

// This Function's purpose is to get the information easily.
void getInfo(string& name, float& weight, float& height, float& exercise_hours)
{
    cout << "Please write your name: " << endl;
    cin >> name;
    cout << "Enter your weight: " << endl;
    cin >> weight;
    cout << "Enter your height: (Ex. = 1.84) " << endl;
    cin >> height;
    cout << "How many hours do you work out weekly ?" << endl;
    cin >> exercise_hours;
}

//This one is calculating BMI value with parameters.
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

// Generates a diet report based on BMI, exercise hours, and user's name.
// Recommends meal options for different body types and provides exercise advice.
void dietReport(float bmi, float exercise_hours, string name)
{
    array<string, 3> breakfast;
    array<string, 3> lunch;
    array<string, 3> dinner;
    string recommendations;
    string bodyType;

    cout << "\nHello" <<" "<< name << endl;

    //This part decide for the daily program according to your BMI.
    if (bmi < 18.5) {
        bodyType = "Underweight"; 
        breakfast = {"Scrambled eggs with spinach", "Greek yogurt with berries and almonds", "Whole grain toast with avocado"};
        lunch = {"Grilled chicken salad with quinoa", "Salmon and vegetable stir-fry", "Lentil soup with whole grain roll"};
        dinner = {"Baked tilapia with sweet potato and broccoli", "Vegetarian chili with brown rice", "Quinoa-stuffed bell peppers\n"};
    } 
    else if (bmi >= 18.5 && bmi <= 24.9) {
        bodyType = "Normal"; 
        breakfast = {"Oatmeal with banana and walnuts", "Whole grain pancakes with maple syrup", "Smoothie with kale, banana, and protein powder"};
        lunch = {"Turkey and avocado wrap with whole grain tortilla", "Quinoa salad with mixed vegetables", "Grilled shrimp and quinoa bowl"};
        dinner = {"Grilled chicken with sweet potato and asparagus", "Vegetarian lasagna with a side salad", "Salmon with quinoa and roasted Brussels sprouts\n"};
    } 
    else if (bmi >= 25 && bmi <= 29.9) {
        bodyType = "Overweight"; 
        breakfast = {"Greek yogurt parfait with granola and mixed berries", "Whole grain waffles with fresh fruit", "Egg white omelette with vegetables"};
        lunch = {"Grilled vegetable and hummus wrap", "Turkey and black bean lettuce wraps", "Quinoa and black bean salad"};
        dinner = {"Baked chicken breast with quinoa and steamed broccoli", "Vegetable stir-fry with tofu and brown rice", "Zucchini noodles with marinara sauce and lean ground turkey\n"};
    } 
    else if (bmi >= 30 && bmi < 100) {
        bodyType = "Obese";
        recommendations = "Consult with a nutritionist or healthcare professional for a personalized plan.\nFocus on portion control and regular exercise.";
    }
    else{
        cout << "There is a problem with the values" << endl;
    }

    //This part is for the exercise recommendation.
    if (exercise_hours >= 3) {
        recommendations += "\nConsider increasing protein intake to support your active lifestyle.";
    } else if (exercise_hours < 3) {
        recommendations += "\nYou should add more exercises to your weekly plan.";
    }

    //Printing body type.
    cout << "Your body type is: " << bodyType << endl;
    
    //Printing recommendations.
    cout << recommendations << "\n" << endl;

    cout << "These are your day options and, you can choose one of them for your diet program.\n" << endl;
    
    
    cout << "Daily Program \n" << endl;

    // This for loop gives us our daily options.
    for(int i = 0; i < 3; i++)
    {
        cout <<"Day "<< i + 1 
        << "\nBreakfast : " <<breakfast[i] << "\n"
        << "Lunch : " << lunch[i] << "\n"
        << "Dinner :" << dinner[i] << "\n" << endl;
    } 
}
