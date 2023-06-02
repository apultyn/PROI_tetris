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
			Tetromino block = Tetromino(7, 3, 0);
			Assert::IsTrue(playfield.correctPos(block));
		};
		TEST_METHOD(CheckOHigh)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino(4, 5, -1);
			Assert::IsTrue(playfield.correctPos(block));
		};
		TEST_METHOD(CheckORight)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino(4, 7, 0);
			Assert::IsTrue(playfield.correctPos(block));
		};
		TEST_METHOD(CheckODown)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino(4, 0, 17);
			Assert::IsTrue(playfield.correctPos(block));
		};
		TEST_METHOD(CheckOLeft)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino(4, -1, 0);
			Assert::IsTrue(playfield.correctPos(block));
		};
		TEST_METHOD(CheckZRotatedHigh) 
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino(7, 5, -1);
			block.rotate_left();
			Assert::IsTrue(playfield.correctPos(block));
		}
		TEST_METHOD(CheckZRotatedRight)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino(7, 7, 10);
			block.rotate_left();
			Assert::IsTrue(playfield.correctPos(block));
		}
		TEST_METHOD(CheckZRotatedDown)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino(7, 4, 16);
			block.rotate_left();
			Assert::IsTrue(playfield.correctPos(block));
		}
		TEST_METHOD(CheckZRotatedLeft)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino(7, -1, 12);
			block.rotate_left();
			Assert::IsTrue(playfield.correctPos(block));
		}
		TEST_METHOD(CheckTRightHigh)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino(6, 7, -1);
			block.rotate_left();
			Assert::IsTrue(playfield.correctPos(block));
		}
		TEST_METHOD(CheckTRightDown)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino(6, 7, 17);
			block.rotate_right();
			Assert::IsTrue(playfield.correctPos(block));
		}
		TEST_METHOD(CheckTLeftDown)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino(6, 2, 17);
			block.rotate_right();
			block.rotate_right();
			Assert::IsTrue(playfield.correctPos(block));
		}
		TEST_METHOD(CheckTLeftUp)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = { 0 };
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Tetromino block = Tetromino(6, 2, -1);
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
			Tetromino block = Tetromino(1, 4, 16);
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
			Tetromino block = Tetromino(1, 4, 16);
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
			Tetromino block = Tetromino(1, 8, 9);
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
			Tetromino block = Tetromino(1, 8, 8);
			Assert::IsFalse(playfield.correctPos(block));
		};
	};
	TEST_CLASS(PlayfieldTestIfDelete)
	{
	public:
		TEST_METHOD(EmptyMatrix)
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
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			};
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Assert::IsFalse(playfield.checkIfDelete());
			std::vector<int> num = {};
			Assert::IsTrue(playfield.getRowsToDelete() == num);
		};
		TEST_METHOD(CommonCase)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = {
				{3, 1, 6, 8, 0, 5, 2, 7, 4, 9},
				{7, 0, 9, 2, 4, 1, 8, 3, 5, 6},
				{5, 8, 9, 6, 1, 7, 0, 3, 4, 2},
				{2, 7, 5, 9, 8, 3, 1, 0, 6, 4},
				{9, 5, 0, 3, 6, 4, 2, 8, 1, 7},
				{6, 2, 7, 0, 3, 9, 1, 5, 8, 4},
				{4, 6, 8, 1, 2, 0, 7, 9, 3, 5},
				{8, 9, 4, 7, 5, 6, 3, 2, 0, 1},
				{1, 4, 3, 5, 9, 8, 6, 7, 2, 0},
				{0, 3, 1, 4, 7, 2, 9, 6, 8, 5},
				{7, 8, 2, 0, 6, 1, 5, 4, 9, 3},
				{5, 1, 4, 9, 8, 3, 7, 2, 0, 6},
				{9, 0, 5, 1, 3, 7, 4, 6, 8, 2},
				{6, 2, 8, 7, 4, 0, 3, 5, 1, 9},
				{3, 7, 6, 8, 2, 5, 0, 4, 1, 9},
				{4, 5, 9, 2, 1, 6, 8, 0, 7, 3},
				{8, 1, 7, 3, 0, 4, 6, 9, 5, 2},
				{2, 3, 0, 6, 9, 8, 1, 4, 7, 5},
				{1, 9, 3, 7, 5, 2, 6, 0, 4, 8},
				{0, 4, 2, 1, 6, 7, 5, 9, 8, 3}
			};
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Assert::IsFalse(playfield.checkIfDelete());
			std::vector<int> num = {};
			Assert::IsTrue(playfield.getRowsToDelete() == num);
		};
		TEST_METHOD(LastToDelete)
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
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
			};
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Assert::IsTrue(playfield.checkIfDelete());
			std::vector<int> num = {19};
			playfield.setRowsToDelete();
			Assert::IsTrue(playfield.getRowsToDelete() == num);
		};
		TEST_METHOD(AllToDelete)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = {
				{1, 2, 3, 4, 5, 6, 7, 8, 9, 1},
				{2, 3, 4, 5, 6, 7, 8, 9, 1, 2},
				{3, 4, 5, 6, 7, 8, 9, 1, 2, 3},
				{4, 5, 6, 7, 8, 9, 1, 2, 3, 4},
				{5, 6, 7, 8, 9, 1, 2, 3, 4, 5},
				{6, 7, 8, 9, 1, 2, 3, 4, 5, 6},
				{7, 8, 9, 1, 2, 3, 4, 5, 6, 7},
				{8, 9, 1, 2, 3, 4, 5, 6, 7, 8},
				{9, 1, 2, 3, 4, 5, 6, 7, 8, 9},
				{1, 2, 3, 4, 5, 6, 7, 8, 9, 1},
				{2, 3, 4, 5, 6, 7, 8, 9, 1, 2},
				{3, 4, 5, 6, 7, 8, 9, 1, 2, 3},
				{4, 5, 6, 7, 8, 9, 1, 2, 3, 4},
				{5, 6, 7, 8, 9, 1, 2, 3, 4, 5},
				{6, 7, 8, 9, 1, 2, 3, 4, 5, 6},
				{7, 8, 9, 1, 2, 3, 4, 5, 6, 7},
				{8, 9, 1, 2, 3, 4, 5, 6, 7, 8},
				{9, 1, 2, 3, 4, 5, 6, 7, 8, 9},
				{1, 2, 3, 4, 5, 6, 7, 8, 9, 1},
				{2, 3, 4, 5, 6, 7, 8, 9, 1, 2}
			};
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Assert::IsTrue(playfield.checkIfDelete());
			std::vector<int> num = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
			playfield.setRowsToDelete();
			Assert::IsTrue(playfield.getRowsToDelete() == num);
		};
	};
	TEST_CLASS(PlayfieldTestCheckIfOver)
	{
	public:
		TEST_METHOD(EmptyMatrix)
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
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			};
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Assert::IsFalse(playfield.checkGameOver());
		};
		TEST_METHOD(CommonCase)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = {
				{3, 1, 6, 8, 0, 5, 2, 7, 4, 9},
				{7, 0, 9, 2, 4, 1, 8, 3, 5, 6},
				{5, 8, 9, 6, 1, 7, 0, 3, 4, 2},
				{2, 7, 5, 9, 8, 3, 1, 0, 6, 4},
				{9, 5, 0, 3, 6, 4, 2, 8, 1, 7},
				{6, 2, 7, 0, 3, 9, 1, 5, 8, 4},
				{4, 6, 8, 1, 2, 0, 7, 9, 3, 5},
				{8, 9, 4, 7, 5, 6, 3, 2, 0, 1},
				{1, 4, 3, 5, 9, 8, 6, 7, 2, 0},
				{0, 3, 1, 4, 7, 2, 9, 6, 8, 5},
				{7, 8, 2, 0, 6, 1, 5, 4, 9, 3},
				{5, 1, 4, 9, 8, 3, 7, 2, 0, 6},
				{9, 0, 5, 1, 3, 7, 4, 6, 8, 2},
				{6, 2, 8, 7, 4, 0, 3, 5, 1, 9},
				{3, 7, 6, 8, 2, 5, 0, 4, 1, 9},
				{4, 5, 9, 2, 1, 6, 8, 0, 7, 3},
				{8, 1, 7, 3, 0, 4, 6, 9, 5, 2},
				{2, 3, 0, 6, 9, 8, 1, 4, 7, 5},
				{1, 9, 3, 7, 5, 2, 6, 0, 4, 8},
				{0, 4, 2, 1, 6, 7, 5, 9, 8, 3}
			};
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Assert::IsTrue(playfield.checkGameOver());
		};
		TEST_METHOD(LastToDelete)
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
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
			};
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Assert::IsFalse(playfield.checkGameOver());
		};
		TEST_METHOD(AllToDelete)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = {
				{1, 2, 3, 4, 5, 6, 7, 8, 9, 1},
				{2, 3, 4, 5, 6, 7, 8, 9, 1, 2},
				{3, 4, 5, 6, 7, 8, 9, 1, 2, 3},
				{4, 5, 6, 7, 8, 9, 1, 2, 3, 4},
				{5, 6, 7, 8, 9, 1, 2, 3, 4, 5},
				{6, 7, 8, 9, 1, 2, 3, 4, 5, 6},
				{7, 8, 9, 1, 2, 3, 4, 5, 6, 7},
				{8, 9, 1, 2, 3, 4, 5, 6, 7, 8},
				{9, 1, 2, 3, 4, 5, 6, 7, 8, 9},
				{1, 2, 3, 4, 5, 6, 7, 8, 9, 1},
				{2, 3, 4, 5, 6, 7, 8, 9, 1, 2},
				{3, 4, 5, 6, 7, 8, 9, 1, 2, 3},
				{4, 5, 6, 7, 8, 9, 1, 2, 3, 4},
				{5, 6, 7, 8, 9, 1, 2, 3, 4, 5},
				{6, 7, 8, 9, 1, 2, 3, 4, 5, 6},
				{7, 8, 9, 1, 2, 3, 4, 5, 6, 7},
				{8, 9, 1, 2, 3, 4, 5, 6, 7, 8},
				{9, 1, 2, 3, 4, 5, 6, 7, 8, 9},
				{1, 2, 3, 4, 5, 6, 7, 8, 9, 1},
				{2, 3, 4, 5, 6, 7, 8, 9, 1, 2}
			};
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			Assert::IsTrue(playfield.checkGameOver());
		};
	};
	TEST_CLASS(PlayfieldDeleteTest)
	{
	public:
		TEST_METHOD(CommonCase)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = {
				{3, 1, 6, 8, 0, 5, 2, 7, 4, 9},
				{7, 0, 9, 2, 4, 1, 8, 3, 5, 6},
				{5, 8, 9, 6, 1, 7, 0, 3, 4, 2},
				{2, 7, 5, 9, 8, 3, 1, 0, 6, 4},
				{9, 5, 0, 3, 6, 4, 2, 8, 1, 7},
				{6, 2, 7, 0, 3, 9, 1, 5, 8, 4},
				{4, 6, 8, 1, 2, 0, 7, 9, 3, 5},
				{8, 9, 4, 7, 5, 6, 3, 2, 0, 1},
				{1, 4, 3, 5, 9, 8, 6, 7, 2, 0},
				{0, 3, 1, 4, 7, 2, 9, 6, 8, 5},
				{7, 8, 2, 1, 6, 1, 5, 4, 9, 3}, //
				{5, 1, 4, 9, 8, 3, 7, 2, 2, 6}, //
				{9, 0, 5, 1, 3, 7, 4, 6, 8, 2},
				{6, 2, 8, 7, 4, 0, 3, 5, 1, 9},
				{3, 7, 6, 8, 2, 5, 0, 4, 1, 9},
				{4, 5, 9, 2, 1, 6, 8, 0, 7, 3},
				{8, 1, 7, 3, 0, 4, 6, 9, 5, 2},
				{2, 3, 0, 6, 9, 8, 1, 4, 7, 5},
				{1, 9, 3, 7, 5, 2, 6, 0, 4, 8},
				{0, 4, 2, 1, 6, 7, 5, 9, 8, 3}
			};

			int expected[20][10] = {
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{3, 1, 6, 8, 0, 5, 2, 7, 4, 9},
				{7, 0, 9, 2, 4, 1, 8, 3, 5, 6},
				{5, 8, 9, 6, 1, 7, 0, 3, 4, 2},
				{2, 7, 5, 9, 8, 3, 1, 0, 6, 4},
				{9, 5, 0, 3, 6, 4, 2, 8, 1, 7},
				{6, 2, 7, 0, 3, 9, 1, 5, 8, 4},
				{4, 6, 8, 1, 2, 0, 7, 9, 3, 5},
				{8, 9, 4, 7, 5, 6, 3, 2, 0, 1},
				{1, 4, 3, 5, 9, 8, 6, 7, 2, 0},
				{0, 3, 1, 4, 7, 2, 9, 6, 8, 5},
				{9, 0, 5, 1, 3, 7, 4, 6, 8, 2},
				{6, 2, 8, 7, 4, 0, 3, 5, 1, 9},
				{3, 7, 6, 8, 2, 5, 0, 4, 1, 9},
				{4, 5, 9, 2, 1, 6, 8, 0, 7, 3},
				{8, 1, 7, 3, 0, 4, 6, 9, 5, 2},
				{2, 3, 0, 6, 9, 8, 1, 4, 7, 5},
				{1, 9, 3, 7, 5, 2, 6, 0, 4, 8},
				{0, 4, 2, 1, 6, 7, 5, 9, 8, 3}
			};
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			playfield.setRowsToDelete();
			playfield.deleteRows();
			for (int i = 0; i < HEIGHT; i++) {                    
				for (int j = 0; j < WIDTH; j++) {
					Assert::IsTrue(playfield.playfield_matrix[i][j] == expected[i][j]);
				}
			}
		};
		TEST_METHOD(Delete4)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = {
				{3, 1, 6, 8, 0, 5, 2, 7, 4, 9},
				{7, 0, 9, 2, 4, 1, 8, 3, 5, 6},
				{5, 8, 9, 6, 1, 7, 0, 3, 4, 2},
				{2, 7, 5, 9, 8, 3, 1, 0, 6, 4},
				{9, 5, 0, 3, 6, 4, 2, 8, 1, 7},
				{6, 2, 7, 0, 3, 9, 1, 5, 8, 4},
				{4, 6, 8, 1, 2, 0, 7, 9, 3, 5},
				{8, 9, 4, 7, 5, 6, 3, 2, 0, 1},
				{1, 4, 3, 5, 9, 8, 6, 7, 2, 0},
				{0, 3, 1, 4, 7, 2, 9, 6, 8, 5},
				{7, 8, 2, 1, 6, 1, 5, 4, 9, 3}, //
				{5, 1, 4, 9, 8, 3, 7, 2, 2, 6}, //
				{9, 2, 5, 1, 3, 7, 4, 6, 8, 2}, //
				{6, 2, 8, 7, 4, 7, 3, 5, 1, 9}, //
				{3, 7, 6, 8, 2, 5, 0, 4, 1, 9},
				{4, 5, 9, 2, 1, 6, 8, 0, 7, 3},
				{8, 1, 7, 3, 0, 4, 6, 9, 5, 2},
				{2, 3, 0, 6, 9, 8, 1, 4, 7, 5},
				{1, 9, 3, 7, 5, 2, 6, 0, 4, 8},
				{0, 4, 2, 1, 6, 7, 5, 9, 8, 3}
			};

			int expected[20][10] = {
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{3, 1, 6, 8, 0, 5, 2, 7, 4, 9},
				{7, 0, 9, 2, 4, 1, 8, 3, 5, 6},
				{5, 8, 9, 6, 1, 7, 0, 3, 4, 2},
				{2, 7, 5, 9, 8, 3, 1, 0, 6, 4},
				{9, 5, 0, 3, 6, 4, 2, 8, 1, 7},
				{6, 2, 7, 0, 3, 9, 1, 5, 8, 4},
				{4, 6, 8, 1, 2, 0, 7, 9, 3, 5},
				{8, 9, 4, 7, 5, 6, 3, 2, 0, 1},
				{1, 4, 3, 5, 9, 8, 6, 7, 2, 0},
				{0, 3, 1, 4, 7, 2, 9, 6, 8, 5},
				{3, 7, 6, 8, 2, 5, 0, 4, 1, 9},
				{4, 5, 9, 2, 1, 6, 8, 0, 7, 3},
				{8, 1, 7, 3, 0, 4, 6, 9, 5, 2},
				{2, 3, 0, 6, 9, 8, 1, 4, 7, 5},
				{1, 9, 3, 7, 5, 2, 6, 0, 4, 8},
				{0, 4, 2, 1, 6, 7, 5, 9, 8, 3}
			};
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			playfield.setRowsToDelete();
			playfield.deleteRows();
			for (int i = 0; i < HEIGHT; i++) {                      
				for (int j = 0; j < WIDTH; j++) {
					Assert::IsTrue(playfield.playfield_matrix[i][j] == expected[i][j]);
				}
			}
			
		};
		TEST_METHOD(DeleteLast)
		{
			Playfield playfield = Playfield();
			int new_matrix[20][10] = {
				{3, 1, 6, 8, 0, 5, 2, 7, 4, 9},
				{7, 0, 9, 2, 4, 1, 8, 3, 5, 6},
				{5, 8, 9, 6, 1, 7, 0, 3, 4, 2},
				{2, 7, 5, 9, 8, 3, 1, 0, 6, 4},
				{9, 5, 0, 3, 6, 4, 2, 8, 1, 7},
				{6, 2, 7, 0, 3, 9, 1, 5, 8, 4},
				{4, 6, 8, 1, 2, 0, 7, 9, 3, 5},
				{8, 9, 4, 7, 5, 6, 3, 2, 0, 1},
				{1, 4, 3, 5, 9, 8, 6, 7, 2, 0},
				{0, 3, 1, 4, 7, 2, 9, 6, 8, 5},
				{7, 8, 2, 1, 6, 1, 0, 4, 9, 3}, 
				{5, 1, 4, 9, 0, 3, 7, 2, 2, 6}, 
				{9, 2, 5, 1, 0, 7, 4, 6, 8, 2}, 
				{6, 2, 8, 7, 0, 7, 3, 5, 1, 9}, 
				{3, 7, 6, 8, 2, 5, 0, 4, 1, 9},
				{4, 5, 9, 2, 1, 6, 8, 0, 7, 3},
				{8, 1, 7, 3, 0, 4, 6, 9, 5, 2},
				{2, 3, 0, 6, 9, 8, 1, 4, 7, 5},
				{1, 9, 3, 7, 5, 2, 6, 0, 4, 8},
				{2, 4, 2, 1, 6, 7, 5, 9, 8, 3} //
			};

			int expected[20][10] = {
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{3, 1, 6, 8, 0, 5, 2, 7, 4, 9},
				{7, 0, 9, 2, 4, 1, 8, 3, 5, 6},
				{5, 8, 9, 6, 1, 7, 0, 3, 4, 2},
				{2, 7, 5, 9, 8, 3, 1, 0, 6, 4},
				{9, 5, 0, 3, 6, 4, 2, 8, 1, 7},
				{6, 2, 7, 0, 3, 9, 1, 5, 8, 4},
				{4, 6, 8, 1, 2, 0, 7, 9, 3, 5},
				{8, 9, 4, 7, 5, 6, 3, 2, 0, 1},
				{1, 4, 3, 5, 9, 8, 6, 7, 2, 0},
				{0, 3, 1, 4, 7, 2, 9, 6, 8, 5},
				{7, 8, 2, 1, 6, 1, 0, 4, 9, 3},
				{5, 1, 4, 9, 0, 3, 7, 2, 2, 6},
				{9, 2, 5, 1, 0, 7, 4, 6, 8, 2},
				{6, 2, 8, 7, 0, 7, 3, 5, 1, 9},
				{3, 7, 6, 8, 2, 5, 0, 4, 1, 9},
				{4, 5, 9, 2, 1, 6, 8, 0, 7, 3},
				{8, 1, 7, 3, 0, 4, 6, 9, 5, 2},
				{2, 3, 0, 6, 9, 8, 1, 4, 7, 5},
				{1, 9, 3, 7, 5, 2, 6, 0, 4, 8},
			};
			memcpy(playfield.playfield_matrix, new_matrix, sizeof(playfield.playfield_matrix));
			playfield.setRowsToDelete();
			playfield.deleteRows();
			for (int i = 0; i < HEIGHT; i++) {            
				for (int j = 0; j < WIDTH; j++) {
					Assert::IsTrue(playfield.playfield_matrix[i][j] == expected[i][j]);
				}
			}

		};
	};

}
