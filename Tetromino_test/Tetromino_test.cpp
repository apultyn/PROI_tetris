#include "pch.h"
#include "../tetris/Tetrominoes.cpp"
#include "CppUnitTest.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tetrominotest
{
	TEST_CLASS(Tetrominotest)
	{
	public:
		
		TEST_METHOD(TransposeMatrix)
		{
			Tetromino block = Tetromino('J');
			std::cout << "Test";
			block.transpose_matrix();
			std::string expected = "[1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		}
	};
}
