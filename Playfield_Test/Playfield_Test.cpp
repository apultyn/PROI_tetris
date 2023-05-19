#include "pch.h"
#include "CppUnitTest.h"
#include "../tetris/playfield.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlayfieldTest
{
	TEST_CLASS(PlayfieldTestCorrectPos)
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
	};
}
