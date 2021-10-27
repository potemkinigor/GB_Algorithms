//
//  main.c
//  Algorithms_lesson1
//
//  Created by Igor Potemkin on 15.10.2021.
//

//1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций.
//
//2. *Реализовать шейкерную сортировку.
//
//3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.
//
//4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void launchSorting(void);
void binarySearch(void);

void simpleBubbleSorting(int *initialArray, int arraySize);
void bubbleSortingOptimized(int *initialArray, int arraySize);
int * shakerSorting(int *initialArray, int arraySize);
void menu(void);

int main(int argc, const char * argv[]) {
    int sel = 0;

    do {
        menu();
        scanf("%i", &sel);
        switch (sel) {
            case 1:
                launchSorting();
                break;
            case 2:
                binarySearch();
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

void launchSorting(void) {
    int arraySize;
    int index;
    
    printf("Enter array size, please: ");
    scanf("%i", &arraySize);
    
    int initialArray[arraySize];
    int initialArrayForOptimizedSorting[arraySize];
    int initialArrayForShakerSorting[arraySize];
    
    for (index = 0; index < arraySize; index++) {
        int random = rand()%arraySize;
        initialArray[index] = random;
        initialArrayForOptimizedSorting[index] = random;
        initialArrayForShakerSorting[index] = random;
    }
    
    printf("Initial values for array are:\n");
    for (index = 0; index < arraySize; index++) {
        printf("%i ", initialArray[index]);
    }
    printf("\n");
    
    simpleBubbleSorting(initialArray, arraySize);
    bubbleSortingOptimized(initialArrayForOptimizedSorting, arraySize);
    shakerSorting(initialArrayForShakerSorting, arraySize);
}

void simpleBubbleSorting(int *initialArray, int arraySize) {
    int i, j;
    int comparisonCounter;
    int swapCounter;
    
    comparisonCounter = 0;
    swapCounter = 0;
    
    for (i = 0; i < arraySize; i++) {
        for (j = 0; j < arraySize - 1; j++) {
            comparisonCounter++;
            if (initialArray[j] > initialArray[j + 1]) {
                int temp;
                swapCounter++;
                temp = initialArray[j];
                initialArray[j] = initialArray[j + 1];
                initialArray[j + 1] = temp;
            }
        }
    }
    
    printf("\n");
    printf("With simple bubble sorting we will have:\n");
    for (i = 0; i < arraySize; i++) {
        printf("%i ", initialArray[i]);
    }
    printf("\n");
    printf("Comparison iterations: %i\n", comparisonCounter);
    printf("Swap iterations: %i\n", swapCounter);
    printf("O(n^2) should be %lf, but is %i\n", pow(arraySize, 2), comparisonCounter + swapCounter);
}

void bubbleSortingOptimized(int *initialArray, int arraySize) {
    int i, j;
    int comparisonCounter;
    int swapCounter;
    
    comparisonCounter = 0;
    swapCounter = 0;
    
    for (i = 0; i < arraySize; i++) {
        for (j = 0; j < arraySize - 1 - i; j++) {
            comparisonCounter++;
            if (initialArray[j] > initialArray[j + 1]) {
                int temp;
                swapCounter++;
                temp = initialArray[j];
                initialArray[j] = initialArray[j + 1];
                initialArray[j + 1] = temp;
            }
        }
    }
    
    printf("\n");
    printf("With optimized bubble sorting we will have:\n");
    for (i = 0; i < arraySize; i++) {
        printf("%i ", initialArray[i]);
    }
    printf("\n");
    printf("Comparison iterations: %i\n", comparisonCounter);
    printf("Swap iterations: %i\n", swapCounter);
    printf("O(n^2) should be %lf, but is %i\n", pow(arraySize, 2), comparisonCounter + swapCounter);
}

int * shakerSorting(int *initialArray, int arraySize) {
    int i, j;
    int comparisonCounter;
    int swapCounter;
    
    comparisonCounter = 0;
    swapCounter = 0;
    
    for (i = 0; i < arraySize; i++) {
        if (i % 2 == 0) {
            for (j = 0; j < arraySize - 1 - i; j++) {
                comparisonCounter++;
                if (initialArray[j] > initialArray[j + 1]) {
                    int temp;
                    swapCounter++;
                    temp = initialArray[j];
                    initialArray[j] = initialArray[j + 1];
                    initialArray[j + 1] = temp;
                }
            }
        } else {
            for (j = arraySize - 1; j > 0; j--) {
                comparisonCounter++;
                if (initialArray[j - 1] > initialArray[j]) {
                    int temp;
                    swapCounter++;
                    temp = initialArray[j - 1];
                    initialArray[j - 1] = initialArray[j];
                    initialArray[j] = temp;
                }
            }
        }
    }
    
    printf("\n");
    printf("With shaker sorting we will have:\n");
    for (i = 0; i < arraySize; i++) {
        printf("%i ", initialArray[i]);
    }
    printf("\n");
    printf("Comparison iterations: %i\n", comparisonCounter);
    printf("Swap iterations: %i\n", swapCounter);
    printf("O(n^2) should be %lf, but is %i\n", pow(arraySize, 2), comparisonCounter + swapCounter);
    
    return initialArray;
}

void binarySearch(void) {
    int arraySize;
    int index;
    int searchNumber;
    
    printf("Enter array size, please: ");
    scanf("%i", &arraySize);
    
    int array[arraySize];
    
    for (index = 0; index < arraySize; index++) {
        int random = rand()%arraySize;
        array[index] = random;
    }
    
    printf("Initial values for array are:\n");
    for (index = 0; index < arraySize; index++) {
        printf("%i ", array[index]);
    }
    printf("\n\n");
    
    int *sortedArray = shakerSorting(array, arraySize);
    
    printf("Enter number we are looking for: ");
    scanf("%i", &searchNumber);
    
    int min = 0;
    int max = arraySize - 1;
    
    if (searchNumber > sortedArray[arraySize - 1] || searchNumber < sortedArray[0]) {
        printf("Oops, there is no such a number!\n\n");
        return;
    }
    
    while (min <= max) {
        int mid;
        
        if (min == max && sortedArray[min] != searchNumber) {
            if (sortedArray[min] == searchNumber) {
                printf("Index of element we are looking for is %i\n\n", min + 1);
                break;
            } else {
                printf("Oops, there is no such a number!\n\n");
                break;
            }
        } else {
            mid = min + (max-min) * (searchNumber - sortedArray[min])/ (sortedArray[max] - sortedArray[min]);
        }
        
        if (sortedArray[mid] == searchNumber) {
            printf("Index of element we are looking for is %i\n", mid + 1);
            break;
        } else if (sortedArray[mid] < searchNumber) {
            min = mid + 1;
        } else if (sortedArray[mid] > searchNumber) {
            max = mid - 1;
        }
    }
}

void menu() {
    printf("1 - Bubble sorting algorithms\n");
    printf("2 - Binary search\n");
    printf("0 - Exit\n");
}


// MARK: - Lesson 2

//void transformFromDecimalToBinary(void);
//void raiseToDegreeLinear(void);
//void raiseToDegreeRecursion(void);
//void raiseToDegreeRecursionWithEvenProperty(void);
//
//
//int transformToBinary(int number);
//double transformToDegreeWithRecursion(double number, int degree);
//void menu(void);
//
//int main(int argc, const char * argv[]) {
//    int sel = 0;
//
//    do {
//        menu();
//        scanf("%i", &sel);
//        switch (sel) {
//            case 1:
//                transformFromDecimalToBinary();
//                break;
//            case 2:
//                raiseToDegreeLinear();
//                break;
//            case 3:
//                raiseToDegreeRecursion();
//                break;
//            case 4:
//                raiseToDegreeRecursionWithEvenProperty();
//                break;
//            case 0:
//                printf("Bye-bye! See you next time\n");
//                break;
//            default:
//                printf("Something went wrong, please try again\n");
//                break;
//        }
//    } while (sel != 0);
//
//    return 0;
//}
//
//
//void transformFromDecimalToBinary() {
//
//    int number;
//
//    printf("Enter required number: ");
//    scanf("%i", &number);
//
//    printf("Reversed result is: \n");
//    transformToBinary(number);
//    printf("\n");
//}
//
//int transformToBinary(int number) {
//    if (number % 2 == 0) {
//        printf("0");
//    } else {
//        printf("1");
//    }
//
//    if (number < 2) {
//        return 0;
//    } else {
//        return transformToBinary(number / 2);
//    }
//}
//
//
//void raiseToDegreeLinear(void) {
//    double a;
//    int i, n;
//    double result;
//
//    printf("Enter required number and degree: ");
//    scanf("%lf %i", &a, &n);
//
//    result = a;
//
//    for (i = 1; i < n; i++) {
//        result = result * a;
//    }
//
//    printf("Linear result is %lf\n", result);
//}
//
//
//void raiseToDegreeRecursion(void) {
//    double a, result;
//    int n;
//
//    printf("Enter required number and degree: ");
//    scanf("%lf %i", &a, &n);
//
//    result = transformToDegreeWithRecursion(a, n);
//
//    printf("Linear result is %lf\n", result);
//}
//
//
//void raiseToDegreeRecursionWithEvenProperty(void) {
//    double a, result;
//    int n;
//
//    printf("Enter required number and degree: ");
//    scanf("%lf %i", &a, &n);
//
//    if (n % 2 == 0 ) {
//        result = transformToDegreeWithRecursion(a, n / 2);
//        result = pow(result, 2);
//    } else {
//        result = transformToDegreeWithRecursion(a, n);
//    }
//
//    printf("Linear result is %lf\n", result);
//}
//
//
//double transformToDegreeWithRecursion(double number, int degree) {
//    if (degree == 1) {
//        return number;
//    } else {
//        return number * transformToDegreeWithRecursion(number, degree -= 1);
//    }
//}
//
//void menu() {
//    printf("1 - Transform from decimal to binary\n");
//    printf("2 - Raise to degree without recursion\n");
//    printf("3 - Raise to degree with recursion\n");
//    printf("4 - Raise to degree with recursion and with even property\n");
//    printf("0 - Exit\n");
//}

// MARK: - Lesson 1

//void calculateBodyMassIndex(void);
//void findMaximumWithinFourNumbers(void);
//void searchForQuadraticEquationRoots(void);
//void menu(void);
//
//struct Person {
//    double weight;
//    double height;
//};
//
//int main(int argc, const char * argv[]) {
//    int sel = 0;
//
//    do {
//        menu();
//        scanf("%i", &sel);
//        switch (sel) {
//            case 1:
//                calculateBodyMassIndex();
//                break;
//            case 2:
//                findMaximumWithinFourNumbers();
//                break;
//            case 3:
//                searchForQuadraticEquationRoots();
//                break;
//            case 0:
//                printf("Bye-bye! See you next time\n");
//                break;
//            default:
//                printf("Something went wrong, please try again\n");
//                break;
//        }
//    } while (sel != 0);
//
//    return 0;
//}
//
//void menu() {
//    printf("1 - Body mass index calculation\n");
//    printf("2 - Searсh of biggest number in sequence of four numbers\n");
//    printf("3 - Search for quadratic equation roots\n");
//    printf("0 - Exit\n");
//}
//
//void calculateBodyMassIndex() {
//    struct Person person;
//    double bodyMassIndex;
//
//    printf("Enter person weight in kilograms: ");
//    scanf("%lf", &person.weight);
//
//    printf("Enter person height in meters: ");
//    scanf("%lf", &person.height);
//
//    bodyMassIndex = person.weight / (person.height * person.height);
//
//    printf("BMI is: %lf\n", bodyMassIndex);
//}
//
//void findMaximumWithinFourNumbers(void) {
//    double firstNumber;
//    double secondNumber;
//    double thirdNumber;
//    double fourthNumber;
//
//    double biggestNumber;
//
//    printf("Enter four numbers with spacer: ");
//    scanf("%lf %lf %lf %lf", &firstNumber, &secondNumber, &thirdNumber, &fourthNumber);
//
//    biggestNumber = firstNumber;
//
//    if (secondNumber > biggestNumber)  biggestNumber = secondNumber;
//    if (thirdNumber > biggestNumber)  biggestNumber = thirdNumber;
//    if (fourthNumber > biggestNumber)  biggestNumber = fourthNumber;
//
//    printf("Biggest number fro sequence is: %lf\n", biggestNumber);
//}
//
//void searchForQuadraticEquationRoots(void) {
//    double a, b, c;
//    double discriminant;
//    double root1, root2;
//
//    printf("Enter a, b and c with spacer: ");
//    scanf("%lf %lf %lf", &a, &b, &c);
//
//    discriminant = pow(b, 2) - 4 * a * c;
//
//    if (discriminant < 0) {
//        printf("There are no roots for this quadratic equation!\n");
//    } else if (discriminant == 0) {
//        root1 = -b / (2 * a);
//        printf("There is one root for this quadratic equation! %lf\n", root1);
//    } else if (discriminant > 0) {
//        root1 = (-b + sqrt(discriminant)) / (2 * a);
//        root2 = (-b - sqrt(discriminant)) / (2 * a);
//        printf("There are two roots for this quadratic equation! %lf %lf\n", root1, root2);
//    }
//}




