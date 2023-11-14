#pragma once

#ifdef INTEGER
void InitArrInt(int* arr, const int size);
void PrintArrInt(int* arr, const int size);
int SearchArrIntMin(int* arr, const int size);
int SearchArrIntMax(int* arr, const int size);
void SortArrInt(int* arr, const int size);
void ChangeArrInt(int* arr, const int size);
#define Init InitArrInt
#define Print PrintArrInt
#define SearchMin SearchArrIntMin
#define SearchMax SearchArrIntMax
#define Sort SortArrInt
#define Change ChangeArrInt
#endif
#ifdef FLOAT
void InitArrFlo(float* arr, const int size);
void PrintArrFlo(float* arr, const int size);
float SearchArrFloMin(float* arr, const int size);
float SearchArrFloMax(float* arr, const int size);
void SortArrFlo(float* arr, const int size);
void ChangeArrFlo(float* arr, const int size);
#define Init InitArrFlo
#define Print PrintArrFlo
#define SearchMin SearchArrFloMin
#define SearchMax SearchArrFloMax
#define Sort SortArrFlo
#define Change ChangeArrFlo
 // FLOAT
#endif
#ifdef CHAR
void InitArrCha(char* arr, const int size);
void PrintArrCha(char* arr);
char SearchArrChaMin(char* arr, const int size);
char SearchArrChaMax(char* arr, const int size);
void SortArrCha(char* arr, const int size);
void ChangeArrCha(char* arr);
#define Init InitArrCha
#define Print PrintArrCha
#define SearchMin SearchArrChaMin
#define SearchMax SearchArrChaMax
#define Sort SortArrCha
#define Change ChangeArrCha
#endif