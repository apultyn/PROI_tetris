#include "pch.h"
#include "CppUnitTest.h"
#include "../tetris/playfield.cpp"
#include "../tetris/Tetromino.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlayfieldTest
{
	TEST_CLASS(PlayfieldTestCorrectPosEdge)
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
		TEST_METHOD(CheckZRotatedDown)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('Z', 4, 16);
			block.rotate_left();
			Assert::IsTrue(playfield.correctPos(block));
		}
		TEST_METHOD(CheckZRotatedLeft)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('Z', -1, 12);
			block.rotate_left();
			Assert::IsTrue(playfield.correctPos(block));
		}
		TEST_METHOD(CheckTRightHigh)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('T', 7, -1);
			block.rotate_left();
			Assert::IsTrue(playfield.correctPos(block));
		}
		TEST_METHOD(CheckTRightDown)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('T', 7, 17);
			block.rotate_right();
			Assert::IsTrue(playfield.correctPos(block));
		}
		TEST_METHOD(CheckTLeftDown)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('T', 2, 17);
			block.rotate_right();
			block.rotate_right();
			Assert::IsTrue(playfield.correctPos(block));
		}
		TEST_METHOD(CheckTLeftUp)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('T', 2, -1);
			block.rotate_left();
			Assert::IsTrue(playfield.correctPos(block));
		}
	};
	TEST_CLASS(PlayfieldTestCorrectPosObjects)
	{
	public:
		TEST_METHOD(BasicColision)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = {
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 1, 0, 0, 0}
			};
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('I', 4, 16);
			Assert::IsFalse(playfield.correctPos(block));
		};
		TEST_METHOD(CollisionWithDifferentColor)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = {
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 8, 0, 0, 0},
				{0, 0, 0, 0, 0, 3, 9, 0, 0, 0},
				{0, 0, 0, 0, 0, 5, 2, 0, 0, 0}
			};
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('I', 4, 16);
			Assert::IsFalse(playfield.correctPos(block));
		};
		TEST_METHOD(TightSpace)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = {
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 2, 5},
				{0, 0, 0, 0, 0, 0, 0, 0, 6, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 5, 0},
				{0, 0, 0, 0, 0, 0, 0, 2, 1, 0},
				{0, 0, 0, 0, 0, 0, 0, 5, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 7, 2},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 8, 0, 0, 0},
				{0, 0, 0, 0, 0, 3, 9, 0, 0, 0},
				{0, 0, 0, 0, 0, 5, 2, 0, 0, 0}
			};
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('I', 8, 9);
			block.rotate_left();
			Assert::IsTrue(playfield.correctPos(block));
		};
		TEST_METHOD(CollisionAndOut)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = {
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 2, 5},
				{0, 0, 0, 0, 0, 0, 0, 0, 6, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 5, 0},
				{0, 0, 0, 0, 0, 0, 0, 2, 1, 0},
				{0, 0, 0, 0, 0, 0, 0, 5, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 7, 2},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 8, 0, 0, 0},
				{0, 0, 0, 0, 0, 3, 9, 0, 0, 0},
				{0, 0, 0, 0, 0, 5, 2, 0, 0, 0}
			};
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino('I', 8, 8);
			Assert::IsFalse(playfield.correctPos(block));
		};
	};
}
