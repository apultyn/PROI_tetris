#include "pch.h"
#include "CppUnitTest.h"
#include "../tetris/playfield.cpp"
#include "../tetris/Tetromino.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlayfieldTest
{
	TEST_CLASS(PlayfieldTestCorrectPosTrue)
	{
	public:
		TEST_METHOD(BasicCheck)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('Z');
			Assert::IsTrue(playfield.correctPos(block));
		};
		TEST_METHOD(CheckOHigh)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('O', 5, -1);
			Assert::IsTrue(playfield.correctPos(block));
		};
		TEST_METHOD(CheckORight)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('O', 7, 0);
			Assert::IsTrue(playfield.correctPos(block));
		};
		TEST_METHOD(CheckODown)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('O', 0, 17);
			Assert::IsTrue(playfield.correctPos(block));
		};
		TEST_METHOD(CheckOLeft)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('O', -1, 0);
			Assert::IsTrue(playfield.correctPos(block));
		};
		TEST_METHOD(CheckZRotatedHigh) 
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('Z', 5, -1);
			block.rotate_left();
			Assert::IsTrue(playfield.correctPos(block));
		}
		TEST_METHOD(CheckZRotatedRight)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('Z', 7, 10);
			block.rotate_left();
			Assert::IsTrue(playfield.correctPos(block));
		}
	};
}
