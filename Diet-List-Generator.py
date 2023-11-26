#Constants to use in our codes
UNDERWEIGHT_RANGE = (0, 18.5)
NORMAL_RANGE = (18.5, 24.9)
OVERWEIGHT_RANGE = (25, 29.9)
OBESE_RANGE = (30, 100)

#BMI Calculation using the basic formula
def bmi_calculate(weight, height):
    height_meters = height / 100

    # Calculate BMI
    bmi = weight / (height_meters ** 2)

    return bmi

#Function to decide client's body type according to BMI
def diet_list(bmi, exercise_hours):
    if bmi < UNDERWEIGHT_RANGE[1]:
        breakfast, lunch, dinner = get_underweight_diet()
    elif NORMAL_RANGE[0] <= bmi < NORMAL_RANGE[1]:
        breakfast, lunch, dinner = get_normal_diet()
    elif OVERWEIGHT_RANGE[0] <= bmi < OVERWEIGHT_RANGE[1]:
        breakfast, lunch, dinner = get_overweight_diet()
    elif OBESE_RANGE[0] <= bmi < OBESE_RANGE[1]:
        return get_obese_diet()

    if exercise_hours >= 3:
        recommendations = "Consider increasing protein intake to support your active lifestyle."
    elif exercise_hours < 3:
        recommendations = "You should add more exercises in your weekly plan."

    return f"Breakfast options: {breakfast}\nLunch options: {lunch}\nDinner options: {dinner}\n{recommendations}"

#Function for meal options according to client's body type
def get_underweight_diet():
    breakfast = ["Scrambled eggs with spinach", "Greek yogurt with berries and almonds", "Whole grain toast with avocado"]
    lunch = ["Grilled chicken salad with quinoa", "Salmon and vegetable stir-fry", "Lentil soup with whole grain roll"]
    dinner = ["Baked tilapia with sweet potato and broccoli", "Vegetarian chili with brown rice", "Quinoa-stuffed bell peppers"]
    
    return breakfast, lunch, dinner

#Function for meal options according to client's body type
def get_normal_diet():
    breakfast = ["Oatmeal with banana and walnuts", "Whole grain pancakes with maple syrup", "Smoothie with kale, banana, and protein powder"]
    lunch = ["Turkey and avocado wrap with whole grain tortilla", "Quinoa salad with mixed vegetables", "Grilled shrimp and quinoa bowl"]
    dinner = ["Grilled chicken with sweet potato and asparagus", "Vegetarian lasagna with a side salad", "Salmon with quinoa and roasted Brussels sprouts"]

    return breakfast, lunch, dinner

#Function for meal options according to client's body type
def get_overweight_diet():
    breakfast = ["Greek yogurt parfait with granola and mixed berries", "Whole grain waffles with fresh fruit", "Egg white omelette with vegetables"]
    lunch = ["Grilled vegetable and hummus wrap", "Turkey and black bean lettuce wraps", "Quinoa and black bean salad"]
    dinner = ["Baked chicken breast with quinoa and steamed broccoli", "Vegetable stir-fry with tofu and brown rice", "Zucchini noodles with marinara sauce and lean ground turkey"]

    return breakfast, lunch, dinner

#Function for meal options according to client's body type
def get_obese_diet():
    return (
        "Consult with a nutritionist or healthcare professional for a personalized plan.",
        "Focus on portion control and regular exercise."
    )

#Main Function
def main():
    name = input("Enter your name: ")
    weight = float(input("Enter your weight: "))
    height = float(input("Enter your height: "))
    exercise_hours = int(input("How many hours do you work weekly? "))

    bmi = bmi_calculate(weight, height)

    diet = diet_list(bmi, exercise_hours)
    
    print(f"\nHello, {name}! Your diet plan you can choose one them for your meal ")
    print(diet)

if __name__ == "__main__":
    main()
