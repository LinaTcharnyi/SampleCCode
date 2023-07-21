#include <iostream>
#include <memory>
#include "VectorFunctions.h"
////#include "VectorFunctions.cpp"
//
//
void PrintVector(std::vector<float> vector) {
    for (auto value : vector) {
        std::cout << value << ",";
    }
    std::cout << "\n";
}

int main() {  
    std::vector<float> vector1({1.0,2.0,3.0,4.0,5.0});
    std::unique_ptr<SumValues<float,float>> mySumVectorFunction1(new SumValues<float,float>());
    mySumVectorFunction1->SetVector(vector1);
    std::unique_ptr<ProductValues<float, float>> myProductVectorFunction1(new ProductValues<float, float>());
    myProductVectorFunction1->SetVector(vector1);
    std::unique_ptr<AdjacentSumValues<float, std::vector<float>>> myAdjacentSumVectorFunction1(new AdjacentSumValues<float, std::vector<float>>());
    myAdjacentSumVectorFunction1->SetVector(vector1);
    std::cout << "\nPrint input vector";
    PrintVector(vector1);
    std::cout << "Sum of the values: " << mySumVectorFunction1->VectorOperation() << "\n";
    std::cout << "Product of the values: " << myProductVectorFunction1->VectorOperation() << "\n";
    std::cout << "Difference between adjacent values";
    //PrintVector(myAdjacentSumVectorFunction1->VectorOperation());
        
    std::vector<float> vector2({ -1.1, 2.2, -3.3, 4.4, -5.5, 6.6 });
    std::unique_ptr<SumValues<float, float>> mySumVectorFunction2(new SumValues<float, float>());
    mySumVectorFunction2->SetVector(vector2);
    std::unique_ptr<ProductValues<float, float>> myProductVectorFunction2(new ProductValues<float, float>());
    myProductVectorFunction2->SetVector(vector2);
    std::unique_ptr<AdjacentSumValues<float, std::vector<float>>> myAdjacentSumVectorFunction2(new AdjacentSumValues<float, std::vector<float>>());
    myAdjacentSumVectorFunction2->SetVector(vector2);
    std::cout << "\nPrint input vector";
    PrintVector(vector2);
    std::cout << "Sum of the values: " << mySumVectorFunction2->VectorOperation() << "\n";
    std::cout << "Product of the values: " << myProductVectorFunction2->VectorOperation() << "\n";
    std::cout << "Difference between adjacent values";
    //PrintVector(myAdjacentSumVectorFunction2->VectorOperation());

    std::vector<float> vector3;
    std::unique_ptr<SumValues<float, float>> mySumVectorFunction3(new SumValues<float,float>());
    mySumVectorFunction3->SetVector(vector3);
    std::unique_ptr<ProductValues<float, float>> myProductVectorFunction3(new ProductValues<float,float>());
    myProductVectorFunction3->SetVector(vector3);
    std::unique_ptr<AdjacentSumValues<float, std::vector<float>>> myAdjacentSumVectorFunction3(new AdjacentSumValues<float, std::vector<float>>());
    myAdjacentSumVectorFunction3->SetVector(vector3);
    std::cout << "\nPrint input vector";
    PrintVector(vector3);
    std::cout << "Sum of the values: " << mySumVectorFunction3->VectorOperation() << "\n";
    std::cout << "Product of the values: " << myProductVectorFunction3->VectorOperation() << "\n";
    std::cout << "Difference between adjacent values";
    //PrintVector(myAdjacentSumVectorFunction3->VectorOperation());

    size_t largeCount(10);
    std::vector<float> vector4(largeCount, 2.0);
    std::unique_ptr<ProductValues<float, float>> myVectorFunction4(new ProductValues<float, float>());
    myVectorFunction4->SetVector(vector4);
    std::cout << "Product of the values: " << myVectorFunction4->VectorOperation() << " expected: " << std::pow(2, 10);

}


