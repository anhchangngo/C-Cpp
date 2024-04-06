//Exercise 3:
//Write a structure to represent complex numbers and complete operators: add and multiply

//  add and multiply complex numbers
// (a + bi) + (с + di) = (a + c) + (b + d)i;
// (a + bi)(с + di) = (ac - bd) + (ad + bc)i;

#include <stdio.h>

// Define a structure for complex numbers
struct Complex {
    double real;
    double img;
};

typedef struct Complex CP; //  creates a new name CP for the struct Complex

// I can use CP in my code to declare variables of the complex number structure, 
// like CP a,CP b;, instead of having to write struct Complex

// Function to add two complex numbers
void add(CP a,CP b) {
    CP result;
    result.real = a.real + b.real;
    result.img = a.img + b.img;
    printf ("Sum of 2 complex number : %.2lf + %.2lfi\n", result.real, result.img);
}

// Function to multiply two complex numbers
void multiply(CP a, CP b) {
    CP result;
    result.real = (a.real * b.real) - (a.img * b.img);
    result.img = (a.real * b.img) + (a.img * b.real);
    printf("Product of 2 complex number : %.2lf + %.2lfi\n", result.real, result.img);
}

int main() {
CP a = {2, 3};
CP b = {3, 4};
    printf("Complex a: %.2lf + %.2lfi\n", a.real, a.img);
    printf("Complex b: %.2lf + %.2lfi\n", b.real, b.img);
    add(a, b);
    multiply(a, b);
    return 0;
};