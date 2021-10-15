//
//  main.c
//  Algorithms_lesson1
//
//  Created by Igor Potemkin on 15.10.2021.
//

#include <stdio.h>
#include <math.h>

void calculateBodyMassIndex(void);
void findMaximumWithinFourNumbers(void);
void searchForQuadraticEquationRoots(void);
void menu(void);

struct Person {
    double weight;
    double height;
};

int main(int argc, const char * argv[]) {
    int sel = 0;
    
    do {
        menu();
        scanf("%i", &sel);
        switch (sel) {
            case 1:
                calculateBodyMassIndex();
                break;
            case 2:
                findMaximumWithinFourNumbers();
                break;
            case 3:
                searchForQuadraticEquationRoots();
                break;
            case 0:
                printf("Bye-bye! See you next time\n");
                break;
            default:
                printf("Something went wrong, please try again\n");
                break;
        }
    } while (sel != 0);
    
    return 0;
}

void menu() {
    printf("1 - Body mass index calculation\n");
    printf("2 - Searсh of biggest number in sequence of four numbers\n");
    printf("3 - Search for quadratic equation roots\n");
    printf("0 - Exit\n");
}

void calculateBodyMassIndex() {
    struct Person person;
    double bodyMassIndex;
    
    printf("Enter person weight in kilograms: ");
    scanf("%lf", &person.weight);
    
    printf("Enter person height in meters: ");
    scanf("%lf", &person.height);
    
    bodyMassIndex = person.weight / (person.height * person.height);
    
    printf("BMI is: %lf\n", bodyMassIndex);
}

void findMaximumWithinFourNumbers(void) {
    double firstNumber;
    double secondNumber;
    double thirdNumber;
    double fourthNumber;
    
    double biggestNumber;
    
    printf("Enter four numbers with spacer: ");
    scanf("%lf %lf %lf %lf", &firstNumber, &secondNumber, &thirdNumber, &fourthNumber);
    
    biggestNumber = firstNumber;
    
    if (secondNumber > biggestNumber)  biggestNumber = secondNumber;
    if (thirdNumber > biggestNumber)  biggestNumber = thirdNumber;
    if (fourthNumber > biggestNumber)  biggestNumber = fourthNumber;
    
    printf("Biggest number fro sequence is: %lf\n", biggestNumber);
}

void searchForQuadraticEquationRoots(void) {
    double a, b, c;
    double discriminant;
    double root1, root2;
    
    printf("Enter a, b and c with spacer: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    discriminant = pow(b, 2) - 4 * a * c;
    
    if (discriminant < 0) {
        printf("There are no roots for this quadratic equation!\n");
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("There is one root for this quadratic equation! %lf\n", root1);
    } else if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("There are two roots for this quadratic equation! %lf %lf\n", root1, root2);
    }
}




