#include "pch.h"
#include "../tetris/Tetromino.cpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tetrominotest
{
	TEST_CLASS(TetrominoTestTranspose)
	{
	public:
		TEST_METHOD(TransposeMatrixI)
		{
			Tetromino block = Tetromino('1');
			block.transpose_matrix();
			std::string expected = "[0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(TransposeMatrixJ)
		{
			Tetromino block = Tetromino('2');
			block.transpose_matrix();
			std::string expected = "[1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(TransposeMatrixL)
		{
			Tetromino block = Tetromino('3');
			block.transpose_matrix();
			std::string expected = "[0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(TransposeMatrixO)
		{
			Tetromino block = Tetromino('4');
			block.transpose_matrix();
			std::string expected = "[0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(TransposeMatrixS)
		{
			Tetromino block = Tetromino('5');
			block.transpose_matrix();
			std::string expected = "[0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(TransposeMatrixT)
		{
			Tetromino block = Tetromino('6');
			block.transpose_matrix();
			std::string expected = "[0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(TransposeMatrixZ)
		{
			Tetromino block = Tetromino('7');
			block.transpose_matrix();
			std::string expected = "[0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(TransposeMatrixDoubleZ)
		{
			Tetromino block = Tetromino('7');
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
			Tetromino block = Tetromino('1');
			block.rotate_left();
			std::string expected = "[0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateRightI)
		{
			Tetromino block = Tetromino('1');
			block.rotate_right();
			std::string expected = "[0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateLeftJ)
		{
			Tetromino block = Tetromino('2');
			block.rotate_left();
			std::string expected = "[0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateRightJ)
		{
			Tetromino block = Tetromino('2');
			block.rotate_right();
			std::string expected = "[0,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateLeftL)
		{
			Tetromino block = Tetromino('3');
			block.rotate_left();
			std::string expected = "[0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateRightL)
		{
			Tetromino block = Tetromino('3');
			block.rotate_right();
			std::string expected = "[0,0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateLeftO)
		{
			Tetromino block = Tetromino('4');
			block.rotate_left();
			std::string expected = "[0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateRightO)
		{
			Tetromino block = Tetromino('4');
			block.rotate_right();
			std::string expected = "[0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateLeftS)
		{
			Tetromino block = Tetromino('5');
			block.rotate_left();
			std::string expected = "[0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateRightS)
		{
			Tetromino block = Tetromino('5');
			block.rotate_right();
			std::string expected = "[0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateLeftT)
		{
			Tetromino block = Tetromino('6');
			block.rotate_left();
			std::string expected = "[0,0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateRightT)
		{
			Tetromino block = Tetromino('6');
			block.rotate_right();
			std::string expected = "[0,1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateLeftZ)
		{
			Tetromino block = Tetromino('7');
			block.rotate_left();
			std::string expected = "[0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateRightZ)
		{
			Tetromino block = Tetromino('7');
			block.rotate_right();
			std::string expected = "[0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateRightLeftT)
		{
			Tetromino block = Tetromino('6');
			block.rotate_right();
			block.rotate_left();
			std::string expected = "[0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateFourT)
		{
			Tetromino block = Tetromino('6');
			block.rotate_right();
			block.rotate_right();
			block.rotate_right();
			block.rotate_right();
			std::string expected = "[0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(RotateThreeLeftEqualOneRight)
		{
			Tetromino block_left = Tetromino('5');
			Tetromino block_right = Tetromino('5');
			block_left.rotate_left();
			block_left.rotate_left();
			block_left.rotate_left();
			block_right.rotate_right();
			Assert::AreEqual(block_left.toString(), block_right.toString());
		};
	};
	TEST_CLASS(TetrominoTestSetColor)
	{
		TEST_METHOD(SetColorOnce)
		{
			Tetromino block = Tetromino('6');
			block.setColor('2');
			std::string expected = "[0,0,0,0,0,2,0,0,2,2,2,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
		TEST_METHOD(DoManyThingsWithMatrix)
		{
			Tetromino block = Tetromino('7');
			block.setColor('2');
			block.rotate_right();
			block.setColor('3');
			std::string expected = "[0,0,3,0,0,3,3,0,0,3,0,0,0,0,0,0,]";
			Assert::AreEqual(block.toString(), expected);
		};
	};
}
