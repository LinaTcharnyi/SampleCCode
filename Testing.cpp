#include "pch.h"
#include "CppUnitTest.h"
#include "..\CodingAssignment\VectorFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(UnitTest1) {
		//TESTING SUM

		// test vector with positive values
		TEST_METHOD(TestMethodSum1) {
			std::vector<float> vector1({ 1.0,2.0,3.0 });
			std::unique_ptr<SumValues<float,float>> myVectorFunction1(new SumValues<float, float>());
			myVectorFunction1->SetVector(vector1);
			Assert::AreEqual(myVectorFunction1->VectorOperation(), float(6.0));
		}
		// test vector with a mix of positive and negative
		TEST_METHOD(TestMethodSum2) {
			std::vector<float> vector2({ 1.0,3,3.0, -1,10 });
			std::unique_ptr<SumValues<float, float>> myVectorFunction2(new SumValues<float, float>());
			myVectorFunction2->SetVector(vector2);
			Assert::AreEqual(myVectorFunction2->VectorOperation(), float(16.0));
		}
		// test a large vector
		TEST_METHOD(TestMethodSum3) {
			size_t largeCount(1000000);
			std::vector<float> vector3(largeCount, 2.0);
			std::unique_ptr<SumValues<float, float>> myVectorFunction3(new SumValues<float, float>());
			myVectorFunction3->SetVector(vector3);
			Assert::AreEqual(myVectorFunction3->VectorOperation(), float(2000000.0));
		}
		// test a empty vector
		TEST_METHOD(TestMethodSum4) {
			std::vector<float> vector4;
			std::unique_ptr<SumValues<float, float>> myVectorFunction4(new SumValues<float, float>());
			myVectorFunction4->SetVector(vector4);
			Assert::AreEqual(myVectorFunction4->VectorOperation(), float(0.0));
		}
		// test vector with negative values
		TEST_METHOD(TestMethodSum5) {
			std::vector<float> vector5({ -1.0,-3.0,3.0, -1.0,10.0 });
			std::unique_ptr<SumValues<float, float>> myVectorFunction5(new SumValues<float, float>());
			myVectorFunction5->SetVector(vector5);
			Assert::AreEqual(myVectorFunction5->VectorOperation(), float(8.0));
		}

		//TESTING PRODUCT

		// test vector with positive values
		TEST_METHOD(TestMethodProduct1) {
			std::vector<float> vector1({ 1.0,2.0,3.0 });
			std::unique_ptr<ProductValues<float, float>> myVectorFunction1(new ProductValues<float, float>());
			myVectorFunction1->SetVector(vector1);
			Assert::AreEqual(myVectorFunction1->VectorOperation(), float(6.0));
		}
		// test vector with a mix of positive and negative
		TEST_METHOD(TestMethodProduct2) {
			std::vector<float> vector2({ 1.0,3,3.0, -1,10 });
			std::unique_ptr<ProductValues<float, float>> myVectorFunction2(new ProductValues<float, float>());
			myVectorFunction2->SetVector(vector2);
			Assert::AreEqual(myVectorFunction2->VectorOperation(), float(-90.0));
		}
		// test a large vector
		TEST_METHOD(TestMethodProduct3) {
			size_t largeCount(1000);
			std::vector<float> vector3(largeCount, 2.0);
			std::unique_ptr<ProductValues<float, float>> myVectorFunction3(new ProductValues<float, float>());
			myVectorFunction3->SetVector(vector3);
			Assert::AreEqual(myVectorFunction3->VectorOperation(), float(std::pow(2, 1000)));
		}
		// test a empty vector
		TEST_METHOD(TestMethodProduct4) {
			std::vector<float> vector4;
			std::unique_ptr<ProductValues<float, float>> myVectorFunction4(new ProductValues<float, float>());
			myVectorFunction4->SetVector(vector4);
			Assert::AreEqual(myVectorFunction4->VectorOperation(), float(1.0));
		}
		// test vector with negative values
		TEST_METHOD(TestMethodProduct5) {
			std::vector<float> vector5({ -1.0,-3.0,-3.0, -1.0,-10.0 });
			std::unique_ptr<ProductValues<float, float>> myVectorFunction5(new ProductValues<float, float>());
			myVectorFunction5->SetVector(vector5);
			Assert::AreEqual(myVectorFunction5->VectorOperation(), float(-90.0));
		}

		//TESTING ADJACENT SUM

		// test vector with positive values
		TEST_METHOD(TestMethodAdjacentSum1) {
			std::vector<float> vector1({ 1.0,2.0,3.0 });
			std::unique_ptr<AdjacentSumValues<float, std::vector<float>>> myVectorFunction1(new AdjacentSumValues<float, std::vector<float>>());
			myVectorFunction1->SetVector(vector1);
			Assert::IsTrue(myVectorFunction1->VectorOperation() == std::vector<float>({1.0,1.0,1.0}));
		}
		// test vector with a mix of positive and negative
		TEST_METHOD(TestMethodAdjacentSum2) {
			std::vector<float> vector2({ 1.0,3.0,3.0, -1.0,10.0 });
			std::unique_ptr<AdjacentSumValues<float, std::vector<float>>> myVectorFunction2(new AdjacentSumValues<float, std::vector<float>>());
			myVectorFunction2->SetVector(vector2);
			Assert::IsTrue(myVectorFunction2->VectorOperation() == std::vector<float>({1.0,2.0,0.0,-4.0,11.0}));
		}
		// test a large vector
		TEST_METHOD(TestMethodAdjacentSum3) {
			size_t largeCount(10);
			std::vector<float> vector3(largeCount, 2.0);
			std::unique_ptr<AdjacentSumValues<float, std::vector<float>>> myVectorFunction3(new AdjacentSumValues<float, std::vector<float>>());
			myVectorFunction3->SetVector(vector3);
			Assert::IsTrue(myVectorFunction3->VectorOperation() == std::vector<float>({2.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}));
		}
		// test a empty vector
		TEST_METHOD(TestMethodAdjacentSum4) {
			std::vector<float> vector4;
			std::unique_ptr<AdjacentSumValues<float, std::vector<float>>> myVectorFunction4(new AdjacentSumValues<float, std::vector<float>>());
			myVectorFunction4->SetVector(vector4);
			Assert::IsTrue(myVectorFunction4->VectorOperation() == vector4);
		}
		// test vector with negative values
		TEST_METHOD(TestMethodAdjacentSum5) {
			std::vector<float> vector5({ -1.0,-3.0,-3.0, -1.0,-10.0 });
			std::unique_ptr<AdjacentSumValues<float, std::vector<float>>> myVectorFunction5(new AdjacentSumValues<float, std::vector<float>>());
			myVectorFunction5->SetVector(vector5);
			Assert::IsTrue(myVectorFunction5->VectorOperation() == std::vector<float>({-1.0,-2.0,0.0,2.0,-9.0}));
		}
	};
}