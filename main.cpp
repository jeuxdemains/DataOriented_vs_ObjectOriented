#include "ood.h"
#include "dod.h"

#include <chrono>
#include <cstdio>
#include <string>

// up to 4 threads, everything above is simply inefficient
// for your CPU core cache synchronization in this context
const int MAX_THREADS = 2;

const unsigned int NUM_OBJECTS = 80;
const unsigned int NUM_DATA_SETS = 150;

// push higher number of updates
// if you like to test with more threads
// and see any significant performance differences
const unsigned int UPDATE_CNT = 200000; 

const int MAX_ID = 1000;
const int MAX_INT_VAL = 9999;
const int MAX_DBL_VAL = 99999;

const double ONE_SECOND = 1000.0;

typedef std::chrono::milliseconds ms_t;

int main()
{

    /*
        OBJECT ORIENTED DESIGN
        ----------------------
    */

    OOD ood;

    for (size_t i = 0; i < NUM_OBJECTS; ++i)
        ood.CreateObject(NUM_DATA_SETS);

    printf("OOD performing %u updates @ %d threads.\n", 
        (NUM_OBJECTS * NUM_DATA_SETS * UPDATE_CNT),
        MAX_THREADS);
    
    auto start = std::chrono::high_resolution_clock::now();

    #pragma omp parallel for num_threads(MAX_THREADS)
    for (size_t i = 0; i < UPDATE_CNT; ++i)
    {
        
        const Data_t newData = 
        {
            .id = rand() % MAX_ID,
            .intVal = rand() % MAX_INT_VAL,
            .doubleVal = 0.5 * static_cast<double>(rand() % MAX_DBL_VAL)
        };

        for (int objIdx = 0; objIdx < ood.ObjectsNum() - 1; ++objIdx)
            ood.UpdateObject(objIdx, newData);
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<ms_t>(stop - start);
    double seconds = static_cast<double>(duration.count()) / ONE_SECOND;
    printf("OOD updates complete in %f seconds.\n", seconds);


    /*
         DATA ORIENTED DESIGN
        ----------------------  
    */

    DOD dod;
    for (size_t i = 0; i < NUM_OBJECTS; ++i)
        dod.CreateObject(NUM_DATA_SETS);

    printf("DOD performing %u updates @ %d threads.\n", 
        (NUM_OBJECTS * NUM_DATA_SETS * UPDATE_CNT),
        MAX_THREADS);
    
    start = std::chrono::high_resolution_clock::now();

    #pragma omp parallel for num_threads(MAX_THREADS)
    for (size_t i = 0; i < UPDATE_CNT; ++i)
    {
        const Data_t newData = 
        {
            .id = rand() % MAX_ID,
            .intVal = rand() % MAX_INT_VAL,
            .doubleVal = 0.5 * static_cast<double>(rand() % MAX_DBL_VAL)
        };

        dod.UpdateAllData(newData);       
    }

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<ms_t>(stop - start);
    seconds = static_cast<double>(duration.count()) / ONE_SECOND;
    printf("DOD updates complete in %f seconds.\n", seconds);

    return 0;
}