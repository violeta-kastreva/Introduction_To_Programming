#include<iostream>

//Група тестови структури - 1
struct E {}; // 1

struct A
{
    char a[3]; // 3B
    // 1B padding
	short b; // 2B
    // 2B padding
	double c[4]; // 32B
	char d; // 1B
    // 7B padding
}; // 48B

struct AOpt
{
	char d; // 1B
    // 1B padding
	short b; // 2B
    char a[3]; // 3B
    // 1B padding
	double c[4]; // 32B
}; // 40B

struct B
{
    char a; // 1B
};

struct C 
{
    short a; // 2B
};


//Група тестови структури - 2
struct D 
{
    double  a; // 8B
    int     b; // 4B
    int     c; // 4B
};

struct F 
{
    int     a; // 4B
    // 4B padding
    double  b; // 8B
    int     c; // 4B
    // 4B padding
}; // 24B

struct FOpt
{
    int     a; // 4B
    int     c; // 4B
    double  b; // 8B
}; // 16B

//Група тестови структури - 3
struct J
{
    E e; // 1B
    // 7B padding
    D d; // 16B
    int a; // 4B
    // 4B padding
}; // 32B

struct JOpt
{
    E e; // 1B
    // 3B padding
    int a; // 4B
    D d; // 16B
}; // 24B

struct I
{
    F f[2]; // 48B
    char ch[3]; // 3B
    // 5B padding
};

int main(){
    //Група тестови структури - 1
    std::cout<< "The size of E is " << sizeof(E) << std::endl;
    std::cout<< "The size of A is " << sizeof(A) << std::endl;
    std::cout<< "The size of B is " << sizeof(B) << std::endl;
    std::cout<< "The size of C is " << sizeof(C) << std::endl;

    //Група тестови структури - 2
    std::cout<< "The size of D is "<< sizeof(D) << std::endl;
    std::cout<< "The size of F is "<< sizeof(F) << std::endl;

    //Група тестови структури - 3
    std::cout<< "The size of J is "<< sizeof(J) << std::endl;
    std::cout<< "The size of I is "<< sizeof(I) << std::endl;
} 