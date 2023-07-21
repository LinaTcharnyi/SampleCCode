#pragma once
#include <vector>
#include <iostream>

#ifndef VECTORFUNCTIONS_H
#define VECTORFUNCTIONS_H

// this is the abstract class that would need to have pure virtual function VectorOperation implemented for each vector operation. Every additional vector operation will need its
// own class. This is to adhere to SOLID design principles. Variable vector types and VectorOperation return types are allowed
template <typename T, typename TReturn>
class VectorFunctions {
        std::vector<T> inputVector;
    public:         
        VectorFunctions() {

        }
        
        VectorFunctions(std::vector<T> inputVector_) {
            inputVector = inputVector_;
        }

        std::vector<T> GetVector() {
            return inputVector;
        }
        
        void SetVector(std::vector<T> inputVector_) {
            inputVector = inputVector_;
        }
        virtual TReturn VectorOperation() = 0;             
    };

// computing sum of values in the given vector
template <typename T, typename TReturn>
class SumValues : public VectorFunctions<T, TReturn> {
    public:
        TReturn VectorOperation() {
            T result(0);
            // range-based for loop is the most effecient
            for (auto value : this->GetVector()) {
                result = result + value;
            }
            return result;
        }      
    };

// computing product of values in the given vector
template <typename T, typename TReturn>
class ProductValues : public VectorFunctions<T, TReturn> {
    public:            
        TReturn VectorOperation() {
            T result(1);
            for (auto value : this->GetVector()) {
                result = result * value;
            }
            return result;
        }
    };
    
//computing difference between adjacent values in the given vector
template <typename T, typename TReturn>
class AdjacentSumValues : public VectorFunctions<T, TReturn> {
public:

    TReturn VectorOperation() {        
        std::vector<T> currentVector(this->GetVector());
        std::vector<T> result(currentVector.size());

        if (currentVector.empty())
            return result;

        // using raw pointers is equavalently efficient
        // using iterators and index-based loops are less efficient    
        T* dataPtr = currentVector.data();
        size_t i(0);
        result[0] = dataPtr[0];
        for (auto value : currentVector) {
            if (i > 0) {
                result[i] = dataPtr[i] - dataPtr[i - 1];
            }
            ++i;
        }
        return result;
    }

};
#endif

