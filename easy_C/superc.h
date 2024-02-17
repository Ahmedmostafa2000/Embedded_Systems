//
// Created by Ahmad Mostafa on 1/4/2020.
//

#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
//to print an array
void arrPrint(int arr[],int n){
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
}

//swaping
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//to print a single integar
void intPrint(int x){
    printf("%d",x);
}

//to print a single float
void floatPrint(double x){
    printf("%f",x);
}

//to go to a new ling
void Sprint(){
    printf("\n");
}
//to print a tab
void Tprint(){
    printf("\t");
}
//to print an array in reverse
void arrRevPrint(int arr[],int n){
    for(int i=0;i<n;i++)
        printf("%d\t",arr[n-i-1]);
}
//for sorting an array
void arrBubbleSort(int arr[],int n){
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(arr[j]<arr[i])
                swap(&arr[j],&arr[i]);
        }

    }
}
//to return the sum of an array
int arrSum(int arr[],int start,int end){
    int sum=0;
    for (int i = start; i < end; ++i) {
        sum += arr[i];
    }
    return sum;
}
//to print a matrix
void matPrint(int m,int n,int arr[m][n]){
    for(int i=0;i<m;i++){
        arrPrint(arr[i],n);
        Sprint();}
}
//to input an array
void arrInput(int arr[],int n){
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
}
//to input an matrix
void matInput(int m,int n,int arr[m][n]){
    for(int i=0;i<m;i++){
        arrInput(arr[i],n);
        }
}
//to compare two arrays
int arrcmp(int arr1[],int arr2[],int n){
    for (int i = 0; i < n; ++i) {
        if(arr1[i]!=arr2[i]){
            return 0;
        }
    }
    return 1;
}
void strRevPrint(char str[]){
    int n = strlen(str);
    for(int i=0;i<n;i++)
        printf("%c",str[n-i-1]);
}
void intInput(int x){
    scanf("%d",&x);
}
//to split an string to words
void split(char x[],int word,int maxWord,char splite[word][maxWord],char sep){
    int wordIndex=0;
    int wordCount =0 ;
    int spacesCounter=0;
    for (int i = 0; i < strlen(x); ++i) {
        if(x[i]!=sep){
            splite[wordCount][wordIndex] = x[i];
            wordIndex++;
            spacesCounter=0;
        }
        else{
            spacesCounter++;
            if(spacesCounter==1){
            splite[wordCount][wordIndex]='\0';
            wordCount++;
            }
            wordIndex=0;
        }

    }
    splite[wordCount][wordIndex]='\0';

}
/*
void arrToString(){

}

void arrRev(int arr[],int n){

}*/