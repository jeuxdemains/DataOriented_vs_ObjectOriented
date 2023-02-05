#pragma once

typedef struct __attribute__((aligned(16))) //we prepare for intrinsic vectorization, don't we?
{
    int id;
    int intVal;
    double doubleVal;
} Data_t;