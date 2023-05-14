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
		TEST_METHOD(TransposeMatrixI)
		{
			Tetromino block = Tetromino('I');
			block.transpose_matrix();
			std::string expected = "[0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(TransposeMatrixJ)
		{
			Tetromino block = Tetromino('J');
			block.transpose_matrix();
			std::string expected = "[1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(TransposeMatrixL)
		{
			Tetromino block = Tetromino('L');
			block.transpose_matrix();
			std::string expected = "[0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(TransposeMatrixO)
		{
			Tetromino block = Tetromino('O');
			block.transpose_matrix();
			std::string expected = "[0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(TransposeMatrixS)
		{
			Tetromino block = Tetromino('S');
			block.transpose_matrix();
			std::string expected = "[0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(TransposeMatrixT)
		{
			Tetromino block = Tetromino('T');
			block.transpose_matrix();
			std::string expected = "[0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(TransposeMatrixZ)
		{
			Tetromino block = Tetromino('Z');
			block.transpose_matrix();
			std::string expected = "[0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(TransposeMatrixDoubleZ)
		{
			Tetromino block = Tetromino('Z');
			block.transpose_matrix();
			block.transpose_matrix();
			std::string expected = "[0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
	};
}
