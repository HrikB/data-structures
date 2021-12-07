#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //*p = x p points to address x

    //&a = address of a

    // int a = 10;
    // int *p = &a;
    // printf("%d\n", *p);


    // //Poitner arithmetic
    // int a = 10;
    // int* p;
    // p = &a;
    // printf("%d\n", p); //if p is 2002
    // printf("size of integer is %d bytes\n", sizeof(int));
    // printf("Address of p+5 is %d\n", p+5);
    // printf("value of p+5 is %d\n", *(p + 5)); //p + 1 is 2006. Integer poitner has 4 bytes... incrementing the pointer increases it by 4


    // //Pointer types, void pointer
    // int a = 1025;
    // int* p;
    // p = &a;
    // printf("size of integer is %d\n", sizeof(int));
    // printf("Address = %d, value = %d\n", p, *p);
    // printf("(p+1)Address = %d, value = %d\n", p+1, *(p+1));


    // char *p0;
    // p0 = (char*)p;
    // printf("size of char is %d\n", sizeof(char));
    // printf("Address = %d, value = %d\n", p0, *p0);  //*p0 = 1 because it only goes to first byte
    // printf("(p0+1)Address = %d, value = %d\n", p0+1, *(p0+(1))); //*(p0+1) = 4 because it only goes to second byte
    // // 1025 = 00000000 00000000 00000100 00000001
    //                             //4       //1       //in binary
    // //void pointer (cannot dereference)
    // void *p1;
    // p1 = p;
    

    // //Pointers as function arguments
    // int a = 10;
    // int *p = &a;
    // Increment(p);
    // printf("a main %d\n", &a);
    // printf("a main value %d\n", a);

    // //Pointers and Arrays
    // int arr[] = {2, 4, 5, 8, 1};
    // printf("&arr arr: %d %d\n", &arr, arr);
    // for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
    //     printf("%d\n", i);
    //     printf("ADDRESS %d\n", arr + i);
    //     printf("ADDRESS %d\n", &arr[i]);
    //     printf("VALUE %d\n", arr[i]);
    //     printf("VALUE %d\n\n----\n", *(arr + i));
    // }


    // //Arrays as function arguments
    // int A[] = {1, 2, 3, 4, 5};
    // int size = sizeof(A) / sizeof(A[0]);
    // doubleElements(A, size); 
    // for(int j = 0; j < size; j++) {
    //     printf("element %d = %d\n", j, A[j]);
    // }


    // //Character arrays and poitner
    // //Strings in C ternimated by null chars
    // char *c = "JOHN";
    // //c[0] = 'J'; c[1] = 'o'; c[2] = 'h'; c[3] = 'n'; c[4] = 'h'; c[5] = 't'; c[6] = '\0';
    // char* p = c;
    // int len = strlen(c);
    // printf("Length = %d\n", len);
    // print(c);

    // //Pointers and multi-dimensional arrays
    // int B[2][3]; //2 1-d arrays of of 3 integers 
    // int* p = B;
    // int (*q)[3] = B; 
    // printf("%d\n", *q);
    // printf("%d\n", B /*, &B[0], *B, B[0] */);
    // printf("%d\n", *B);  
    // printf("%d\n", B[0]); //all same memory address
    // printf("%d\n", B[0][0]); //actual element. But if you use &, same as all above
    
    // printf("%d\n", B + 1 /*, &B[1]*/);  
    


    // int c[3][2][2] = {
    //                   {{2, 5}, {7, 9}},
    //                   {{3, 4}, {6, 1}},
    //                   {{0, 8}, {11, 13}}
    //                   };
    // int (*p)[2][2] = c;
    // printf("p: %d\n", p); //type int (*)[2][2]
    // printf("*p: %d\n", *p); //type int (*)[2]
    // printf("*(*p): %d\n", *(*p)); //3 above are all same -> type int*
    // printf("*(*(*p))): %d\n", *(*(*p))); //type int -> result is 17

    // printf("p + 1: %d\n", p + 1); 
    // printf("*(p + 1): %d\n", *(p + 1));
    // printf("*(*(p + 1)): %d\n", *(*(p + 1))); 
    // printf("*(*(*(p + 1)))): %d\n", *(*(*(p + 1)))); 

    // printf("%d\n", *(c[1]+1));
    

    // //Pointers and dynamic memory
    // int a;
    // int* p = (int*)malloc(sizeof(int));
    // *p = 10;
    // free(p);
    // p = (int*)malloc(sizeof(int));
    // *p = 20;
    // printf("%d\n", *p);
    // free(p);

    // p = (int*)malloc(20*sizeof(int)); //int array of 20 elements on heap


    //malloc, calloc, realloc, free
    int n;

    int *A = (int*)malloc(15*sizeof(int)); //dynamically allocated array
    int *B = (int*)calloc(15, sizeof(int)); //also initializes all elements to zero

    for(int i = 1; i < 15; i++) {
        printf("%d ", B[i]);
         A[i] = i;
    }
    printf("\n");
    
    for(int j = 1; j < 15; j++){ 
        printf("%d ", A[j]);        
    }
    free(A);

    printf("\n");
    for(int j = 1; j < 15; j++){ 
        printf("%d ", A[j]);        
    }

}

void print(char* c) {

    while (*c != '\0') {
        printf("%c", *c);
        c++;
    }
}

void doubleElements(int* A, int size) {
    int i;
    
    for(i = 0; i < size; i++){
         A[i] *= 2;
    }

}

void Increment(int* a) {
    *a = *a + 1;
    printf("a incr %d\n", &*a);
}