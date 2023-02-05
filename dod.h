#pragma once

#include "typedefs.h"
#include <vector>
#include <unordered_map>

typedef struct
{
    unsigned int id;
} Object_t;

//this is your Registry/Data manager
class DOD
{
    unsigned int nextObject = 0;

    //store all objects at one place
    std::vector<Object_t> m_Objects = {};

    //store all data in one place
    std::vector<Data_t> m_Data = {};

    //map the object_id to it's data in the m_Data array
    std::unordered_map<int, int> m_DataRegistry = {};

    public:
        DOD() = default;
        ~DOD() = default;

        void CreateObject(const unsigned int numDataSets)
        {
            Object_t object = { .id = nextObject };
            m_Objects.emplace_back(object);

            const Data_t data =
            {
                .id = rand() % 1024,
                .intVal = rand() % 99999, 
                .doubleVal = 0.5 * double(rand() % 8888)
            };
            
            for (int i = 0; i < numDataSets; ++i)
                m_Data.emplace_back(data);

            m_DataRegistry.emplace(std::make_pair(object.id, numDataSets));
            nextObject += numDataSets;
        }

        void UpdateAllData(const Data_t& data)
        {
            for (int i = 0; i < m_Data.size() - 1; ++i)
                m_Data[i] = data;
        }

        const int NumObjects() const 
        {
            return m_Objects.size();
        }
};
