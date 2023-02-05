#pragma once

#include "typedefs.h"
#include <vector>
#include <random>

class Object 
{
    std::vector<Data_t> m_Data = {};

    public:
        Object() = default;
        ~Object() = default;

        void AddData()
        {
            Data_t data =
            {
                .id = rand() % 1024,
                .intVal = rand() % 99999, 
                .doubleVal = 0.5 * double(rand() % 8888)
            };

            m_Data.emplace_back(data);
        }

        void UpdateValues(const int idx, const Data_t& vals)
        {
            m_Data[idx] = vals;
        }

        const int NumDataSets() const
        {
            return m_Data.size();
        }
};

class OOD
{
    std::vector<Object> m_Objects = {};
    
    public:
        OOD() = default;
        ~OOD() = default;

        void CreateObject(const unsigned int numDataSets)
        {
            m_Objects.emplace_back(Object());
            const int numObjects = m_Objects.size() - 1;

            for (size_t i = 0; i < numDataSets; ++i)
                m_Objects[numObjects].AddData();
        }

        const int ObjectsNum() const 
        {
            return m_Objects.size();
        }

        void UpdateObject(const int idx, const Data_t& data)
        {
            for (size_t i = 0; i < m_Objects[idx].NumDataSets(); ++i)
                m_Objects[idx].UpdateValues(i, data);
        }
};
