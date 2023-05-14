#include "pch.h"
#include "../tetris/Tetrominoes.cpp"
#include "CppUnitTest.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tetrominotest
{
	TEST_CLASS(TetrominoTestTranspose)
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
	TEST_CLASS(TetrominoTestRotation)
	{
	public:
		TEST_METHOD(RotateLeftI)
		{
			Tetromino block = Tetromino('I');
			block.rotate_left();
			std::string expected = "[0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateRightI)
		{
			Tetromino block = Tetromino('I');
			block.rotate_right();
			std::string expected = "[0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateLeftJ)
		{
			Tetromino block = Tetromino('J');
			block.rotate_left();
			std::string expected = "[0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateRightJ)
		{
			Tetromino block = Tetromino('J');
			block.rotate_right();
			std::string expected = "[0,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateLeftL)
		{
			Tetromino block = Tetromino('L');
			block.rotate_left();
			std::string expected = "[0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateRightL)
		{
			Tetromino block = Tetromino('L');
			block.rotate_right();
			std::string expected = "[0,0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateLeftO)
		{
			Tetromino block = Tetromino('O');
			block.rotate_left();
			std::string expected = "[0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateRightO)
		{
			Tetromino block = Tetromino('O');
			block.rotate_right();
			std::string expected = "[0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateLeftS)
		{
			Tetromino block = Tetromino('S');
			block.rotate_left();
			std::string expected = "[0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateRightS)
		{
			Tetromino block = Tetromino('S');
			block.rotate_right();
			std::string expected = "[0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateLeftT)
		{
			Tetromino block = Tetromino('T');
			block.rotate_left();
			std::string expected = "[0,0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateRightT)
		{
			Tetromino block = Tetromino('T');
			block.rotate_right();
			std::string expected = "[0,1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateLeftZ)
		{
			Tetromino block = Tetromino('Z');
			block.rotate_left();
			std::string expected = "[0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateRightZ)
		{
			Tetromino block = Tetromino('Z');
			block.rotate_right();
			std::string expected = "[0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateRightLeftT)
		{
			Tetromino block = Tetromino('T');
			block.rotate_right();
			block.rotate_left();
			std::string expected = "[0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateFourL)
		{
			Tetromino block = Tetromino('T');
			block.rotate_right();
			block.rotate_right();
			block.rotate_right();
			block.rotate_right();
			std::string expected = "[0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
	};
}
