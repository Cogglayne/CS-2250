#include <string>
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../CS2250_SimpleTrophyCase/Trophy.h"
#include "../CS2250_SimpleTrophyCase/Trophy.cpp"
#include "../CS2250_SimpleTrophyCase/TrophyCase.h"
#include "../CS2250_SimpleTrophyCase/TrophyCase.cpp"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TrophyTest
{
	TEST_CLASS(TrophyDataTests)
	{
	public:
		TEST_METHOD(Trophy_DefaultConstructor)
		{
			std::string name = "";
			int level = 0;
			Color color = BRONZE;
			Trophy trophy;

			Assert::AreEqual(name, trophy.getName());
			Assert::AreEqual(level, trophy.getLevel());
			Assert::AreEqual(int(color), int(trophy.getColor()));
		}
		TEST_METHOD(Trophy_Constructor)
		{
			std::string name = "This is a Trophy Name";
			int level = 25;
			Color color = BRONZE;
			Trophy trophy(name, level, color);

			Assert::AreEqual(name, trophy.getName());
			Assert::AreEqual(level, trophy.getLevel());
			Assert::AreEqual(int(color), int(trophy.getColor()));
		}
		TEST_METHOD(Trophy_Copy)
		{
			std::string name = "This is a Trophy Name";
			int level = 25;
			Color color = BRONZE;
			Trophy trophy(name, level, color);
			Trophy trophy2(trophy);

			Assert::AreEqual(name, trophy2.getName());
			Assert::AreEqual(level, trophy2.getLevel());
			Assert::AreEqual(int(color), int(trophy2.getColor()));
		}
		TEST_METHOD(Trophy_SetName)
		{
			std::string name = "This is a Trophy Name";
			int level = 25;
			Color color = BRONZE;
			Trophy trophy(name, level, color);

			std::string newName = "Gave it a new name";
			trophy.setName(newName);

			Assert::AreEqual(newName, trophy.getName());
			Assert::AreEqual(level, trophy.getLevel());
			Assert::AreEqual(int(color), int(trophy.getColor()));
		}
		TEST_METHOD(Trophy_SetLevel)
		{
			std::string name = "This is a Trophy Name";
			int level = 25;
			Color color = BRONZE;
			Trophy trophy(name, level, color);

			int newLevel = 1;
			trophy.setLevel(newLevel);

			Assert::AreEqual(name, trophy.getName());
			Assert::AreEqual(newLevel, trophy.getLevel());
			Assert::AreEqual(int(color), int(trophy.getColor()));
		}
		TEST_METHOD(Trophy_SetColor)
		{
			std::string name = "This is a Trophy Name";
			int level = 25;
			Color color = BRONZE;
			Trophy trophy(name, level, color);

			Color newColor = GOLD;
			trophy.setColor(newColor);

			Assert::AreEqual(name, trophy.getName());
			Assert::AreEqual(level, trophy.getLevel());
			Assert::AreEqual(int(newColor), int(trophy.getColor()));
		}

	};

	TEST_CLASS(TrophyOperators)
	{
	public:
		TEST_METHOD(Trophy_EqualTo)
		{
			{
				Trophy trophy1("Try same object", 10, BRONZE);
				Assert::AreEqual(true, trophy1 == trophy1);
			}
			{
				Trophy trophy1("Try same values", 10, BRONZE);
				Trophy trophy2("Try same values", 10, BRONZE);
				Assert::AreEqual(true, trophy1 == trophy2);
				Assert::AreEqual(true, trophy2 == trophy1);
			}
			{
				Trophy trophy1("Try different lengths", 10, BRONZE);
				Trophy trophy2("Try different lengthss", 10, BRONZE);
				Assert::AreEqual(false, trophy1 == trophy2);
				Assert::AreEqual(false, trophy2 == trophy1);
			}
			{
				Trophy trophy1("Try Different Capitalization", 10, BRONZE);
				Trophy trophy2("Try different capitalization", 10, BRONZE);
				Assert::AreEqual(false, trophy1 == trophy2);
				Assert::AreEqual(false, trophy2 == trophy1);
			}
			{
				Trophy trophy1("Try different letters", 10, BRONZE);
				Trophy trophy2("Try eiggerent metters", 10, BRONZE);
				Assert::AreEqual(false, trophy1 == trophy2);
				Assert::AreEqual(false, trophy2 == trophy1);
			}
			{
				Trophy trophy1("Try different levels", 10, BRONZE);
				Trophy trophy2("Try different levels", 25, BRONZE);
				Assert::AreEqual(false, trophy1 == trophy2);
				Assert::AreEqual(false, trophy2 == trophy1);
			}
			{
				Trophy trophy1("Try different levels", 15, BRONZE);
				Trophy trophy2("Try different levels", 16, BRONZE);
				Assert::AreEqual(false, trophy1 == trophy2);
				Assert::AreEqual(false, trophy2 == trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, BRONZE);
				Trophy trophy2("Try different colors", 15, SILVER);
				Assert::AreEqual(false, trophy1 == trophy2);
				Assert::AreEqual(false, trophy2 == trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, BRONZE);
				Trophy trophy2("Try different colors", 15, GOLD);
				Assert::AreEqual(false, trophy1 == trophy2);
				Assert::AreEqual(false, trophy2 == trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, SILVER);
				Trophy trophy2("Try different colors", 15, GOLD);
				Assert::AreEqual(false, trophy1 == trophy2);
				Assert::AreEqual(false, trophy2 == trophy1);
			}
			{
				const Trophy trophy1("Try constant same object", 15, SILVER);
				Assert::AreEqual(true, trophy1 == trophy1);
			}
			{
				const Trophy trophy1("Try different constant objects", 15, SILVER);
				const Trophy trophy2("Try different constant objects", 15, GOLD);
				Assert::AreEqual(false, trophy1 == trophy2);
				Assert::AreEqual(false, trophy2 == trophy1);
			}
			{
				const Trophy trophy1("Try same constant objects", 15, SILVER);
				const Trophy trophy2("Try same constant objects", 15, SILVER);
				Assert::AreEqual(true, trophy1 == trophy2);
				Assert::AreEqual(true, trophy2 == trophy1);
			}
		}
		TEST_METHOD(Trophy_NotEqualTo)
		{
			{
				Trophy trophy1("Try same object", 10, BRONZE);
				Assert::AreEqual(false, trophy1 != trophy1);
			}
			{
				Trophy trophy1("Try same values", 10, BRONZE);
				Trophy trophy2("Try same values", 10, BRONZE);
				Assert::AreEqual(false, trophy1 != trophy2);
				Assert::AreEqual(false, trophy2 != trophy1);
			}
			{
				Trophy trophy1("Try different lengths", 10, BRONZE);
				Trophy trophy2("Try different lengthss", 10, BRONZE);
				Assert::AreEqual(true, trophy1 != trophy2);
				Assert::AreEqual(true, trophy2 != trophy1);
			}
			{
				Trophy trophy1("Try Different Capitalization", 10, BRONZE);
				Trophy trophy2("Try different capitalization", 10, BRONZE);
				Assert::AreEqual(true, trophy1 != trophy2);
				Assert::AreEqual(true, trophy2 != trophy1);
			}
			{
				Trophy trophy1("Try different letters", 10, BRONZE);
				Trophy trophy2("Try eiggerent metters", 10, BRONZE);
				Assert::AreEqual(true, trophy1 != trophy2);
				Assert::AreEqual(true, trophy2 != trophy1);
			}
			{
				Trophy trophy1("Try different levels", 10, BRONZE);
				Trophy trophy2("Try different levels", 25, BRONZE);
				Assert::AreEqual(true, trophy1 != trophy2);
				Assert::AreEqual(true, trophy2 != trophy1);
			}
			{
				Trophy trophy1("Try different levels", 15, BRONZE);
				Trophy trophy2("Try different levels", 16, BRONZE);
				Assert::AreEqual(true, trophy1 != trophy2);
				Assert::AreEqual(true, trophy2 != trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, BRONZE);
				Trophy trophy2("Try different colors", 15, SILVER);
				Assert::AreEqual(true, trophy1 != trophy2);
				Assert::AreEqual(true, trophy2 != trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, BRONZE);
				Trophy trophy2("Try different colors", 15, GOLD);
				Assert::AreEqual(true, trophy1 != trophy2);
				Assert::AreEqual(true, trophy2 != trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, SILVER);
				Trophy trophy2("Try different colors", 15, GOLD);
				Assert::AreEqual(true, trophy1 != trophy2);
				Assert::AreEqual(true, trophy2 != trophy1);
			}
			{
				const Trophy trophy1("Try constant same object", 15, SILVER);
				Assert::AreEqual(false, trophy1 != trophy1);
			}
			{
				const Trophy trophy1("Try different constant objects", 15, SILVER);
				const Trophy trophy2("Try different constant objects", 15, GOLD);
				Assert::AreEqual(true, trophy1 != trophy2);
				Assert::AreEqual(true, trophy2 != trophy1);
			}
			{
				const Trophy trophy1("Try same constant objects", 15, SILVER);
				const Trophy trophy2("Try same constant objects", 15, SILVER);
				Assert::AreEqual(false, trophy1 != trophy2);
				Assert::AreEqual(false, trophy2 != trophy1);
			}
		}
		TEST_METHOD(Trophy_LessThan)
		{
			{
				Trophy trophy1("Try same object", 10, BRONZE);
				Assert::AreEqual(false, trophy1 < trophy1);
			}
			{
				Trophy trophy1("Try same values", 10, BRONZE);
				Trophy trophy2("Try same values", 10, BRONZE);
				Assert::AreEqual(false, trophy1 < trophy2);
				Assert::AreEqual(false, trophy2 < trophy1);
			}
			{
				Trophy trophy1("Try different lengths", 10, BRONZE);
				Trophy trophy2("Try different lengthss", 10, BRONZE);
				Assert::AreEqual(true, trophy1 < trophy2);
				Assert::AreEqual(false, trophy2 < trophy1);
			}
			{
				Trophy trophy1("Try Different Capitalization", 10, BRONZE);
				Trophy trophy2("Try different capitalization", 10, BRONZE);
				Assert::AreEqual(true, trophy1 < trophy2);
				Assert::AreEqual(false, trophy2 < trophy1);
			}
			{
				Trophy trophy1("Try different letters", 10, BRONZE);
				Trophy trophy2("Try eiggerent metters", 10, BRONZE);
				Assert::AreEqual(true, trophy1 < trophy2);
				Assert::AreEqual(false, trophy2 < trophy1);
			}
			{
				Trophy trophy1("Try different levels", 10, BRONZE);
				Trophy trophy2("Try different levels", 25, BRONZE);
				Assert::AreEqual(true, trophy1 < trophy2);
				Assert::AreEqual(false, trophy2 < trophy1);
			}
			{
				Trophy trophy1("Try different levels", 15, BRONZE);
				Trophy trophy2("Try different levels", 16, BRONZE);
				Assert::AreEqual(true, trophy1 < trophy2);
				Assert::AreEqual(false, trophy2 < trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, BRONZE);
				Trophy trophy2("Try different colors", 15, SILVER);
				Assert::AreEqual(true, trophy1 < trophy2);
				Assert::AreEqual(false, trophy2 < trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, BRONZE);
				Trophy trophy2("Try different colors", 15, GOLD);
				Assert::AreEqual(true, trophy1 < trophy2);
				Assert::AreEqual(false, trophy2 < trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, SILVER);
				Trophy trophy2("Try different colors", 15, GOLD);
				Assert::AreEqual(true, trophy1 < trophy2);
				Assert::AreEqual(false, trophy2 < trophy1);
			}
			{
				const Trophy trophy1("Try constant same object", 15, SILVER);
				Assert::AreEqual(false, trophy1 < trophy1);
			}
			{
				const Trophy trophy1("Try different constant objects", 15, SILVER);
				const Trophy trophy2("Try different constant objects", 15, GOLD);
				Assert::AreEqual(true, trophy1 < trophy2);
				Assert::AreEqual(false, trophy2 < trophy1);
			}
			{
				const Trophy trophy1("Try same constant objects", 15, SILVER);
				const Trophy trophy2("Try same constant objects", 15, SILVER);
				Assert::AreEqual(false, trophy1 < trophy2);
				Assert::AreEqual(false, trophy2 < trophy1);
			}
		}
		TEST_METHOD(Trophy_LessThanEqualTo)
		{
			{
				Trophy trophy1("Try same object", 10, BRONZE);
				Assert::AreEqual(true, trophy1 <= trophy1);
			}
			{
				Trophy trophy1("Try same values", 10, BRONZE);
				Trophy trophy2("Try same values", 10, BRONZE);
				Assert::AreEqual(true, trophy1 <= trophy2);
				Assert::AreEqual(true, trophy2 <= trophy1);
			}
			{
				Trophy trophy1("Try different lengths", 10, BRONZE);
				Trophy trophy2("Try different lengthss", 10, BRONZE);
				Assert::AreEqual(true, trophy1 <= trophy2);
				Assert::AreEqual(false, trophy2 <= trophy1);
			}
			{
				Trophy trophy1("Try Different Capitalization", 10, BRONZE);
				Trophy trophy2("Try different capitalization", 10, BRONZE);
				Assert::AreEqual(true, trophy1 <= trophy2);
				Assert::AreEqual(false, trophy2 <= trophy1);
			}
			{
				Trophy trophy1("Try different letters", 10, BRONZE);
				Trophy trophy2("Try eiggerent metters", 10, BRONZE);
				Assert::AreEqual(true, trophy1 <= trophy2);
				Assert::AreEqual(false, trophy2 <= trophy1);
			}
			{
				Trophy trophy1("Try different levels", 10, BRONZE);
				Trophy trophy2("Try different levels", 25, BRONZE);
				Assert::AreEqual(true, trophy1 <= trophy2);
				Assert::AreEqual(false, trophy2 <= trophy1);
			}
			{
				Trophy trophy1("Try different levels", 15, BRONZE);
				Trophy trophy2("Try different levels", 16, BRONZE);
				Assert::AreEqual(true, trophy1 <= trophy2);
				Assert::AreEqual(false, trophy2 <= trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, BRONZE);
				Trophy trophy2("Try different colors", 15, SILVER);
				Assert::AreEqual(true, trophy1 <= trophy2);
				Assert::AreEqual(false, trophy2 <= trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, BRONZE);
				Trophy trophy2("Try different colors", 15, GOLD);
				Assert::AreEqual(true, trophy1 <= trophy2);
				Assert::AreEqual(false, trophy2 <= trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, SILVER);
				Trophy trophy2("Try different colors", 15, GOLD);
				Assert::AreEqual(true, trophy1 <= trophy2);
				Assert::AreEqual(false, trophy2 <= trophy1);
			}
			{
				const Trophy trophy1("Try constant same object", 15, SILVER);
				Assert::AreEqual(true, trophy1 <= trophy1);
			}
			{
				const Trophy trophy1("Try different constant objects", 15, SILVER);
				const Trophy trophy2("Try different constant objects", 15, GOLD);
				Assert::AreEqual(true, trophy1 <= trophy2);
				Assert::AreEqual(false, trophy2 <= trophy1);
			}
			{
				const Trophy trophy1("Try same constant objects", 15, SILVER);
				const Trophy trophy2("Try same constant objects", 15, SILVER);
				Assert::AreEqual(true, trophy1 <= trophy2);
				Assert::AreEqual(true, trophy2 <= trophy1);
			}
		}
		TEST_METHOD(Trophy_GreaterThan)
		{
			{
				Trophy trophy1("Try same object", 10, BRONZE);
				Assert::AreEqual(false, trophy1 > trophy1);
			}
			{
				Trophy trophy1("Try same values", 10, BRONZE);
				Trophy trophy2("Try same values", 10, BRONZE);
				Assert::AreEqual(false, trophy1 > trophy2);
				Assert::AreEqual(false, trophy2 > trophy1);
			}
			{
				Trophy trophy1("Try different lengths", 10, BRONZE);
				Trophy trophy2("Try different lengthss", 10, BRONZE);
				Assert::AreEqual(false, trophy1 > trophy2);
				Assert::AreEqual(true, trophy2 > trophy1);
			}
			{
				Trophy trophy1("Try Different Capitalization", 10, BRONZE);
				Trophy trophy2("Try different capitalization", 10, BRONZE);
				Assert::AreEqual(false, trophy1 > trophy2);
				Assert::AreEqual(true, trophy2 > trophy1);
			}
			{
				Trophy trophy1("Try different letters", 10, BRONZE);
				Trophy trophy2("Try eiggerent metters", 10, BRONZE);
				Assert::AreEqual(false, trophy1 > trophy2);
				Assert::AreEqual(true, trophy2 > trophy1);
			}
			{
				Trophy trophy1("Try different levels", 10, BRONZE);
				Trophy trophy2("Try different levels", 25, BRONZE);
				Assert::AreEqual(false, trophy1 > trophy2);
				Assert::AreEqual(true, trophy2 > trophy1);
			}
			{
				Trophy trophy1("Try different levels", 15, BRONZE);
				Trophy trophy2("Try different levels", 16, BRONZE);
				Assert::AreEqual(false, trophy1 > trophy2);
				Assert::AreEqual(true, trophy2 > trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, BRONZE);
				Trophy trophy2("Try different colors", 15, SILVER);
				Assert::AreEqual(false, trophy1 > trophy2);
				Assert::AreEqual(true, trophy2 > trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, BRONZE);
				Trophy trophy2("Try different colors", 15, GOLD);
				Assert::AreEqual(false, trophy1 > trophy2);
				Assert::AreEqual(true, trophy2 > trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, SILVER);
				Trophy trophy2("Try different colors", 15, GOLD);
				Assert::AreEqual(false, trophy1 > trophy2);
				Assert::AreEqual(true, trophy2 > trophy1);
			}
			{
				const Trophy trophy1("Try constant same object", 15, SILVER);
				Assert::AreEqual(false, trophy1 > trophy1);
			}
			{
				const Trophy trophy1("Try different constant objects", 15, SILVER);
				const Trophy trophy2("Try different constant objects", 15, GOLD);
				Assert::AreEqual(false, trophy1 > trophy2);
				Assert::AreEqual(true, trophy2 > trophy1);
			}
			{
				const Trophy trophy1("Try same constant objects", 15, SILVER);
				const Trophy trophy2("Try same constant objects", 15, SILVER);
				Assert::AreEqual(false, trophy1 > trophy2);
				Assert::AreEqual(false, trophy2 > trophy1);
			}
		}
		TEST_METHOD(Trophy_GreaterThanEqualTo)
		{
			{
				Trophy trophy1("Try same object", 10, BRONZE);
				Assert::AreEqual(true, trophy1 >= trophy1);
			}
			{
				Trophy trophy1("Try same values", 10, BRONZE);
				Trophy trophy2("Try same values", 10, BRONZE);
				Assert::AreEqual(true, trophy1 >= trophy2);
				Assert::AreEqual(true, trophy2 >= trophy1);
			}
			{
				Trophy trophy1("Try different lengths", 10, BRONZE);
				Trophy trophy2("Try different lengthss", 10, BRONZE);
				Assert::AreEqual(false, trophy1 >= trophy2);
				Assert::AreEqual(true, trophy2 >= trophy1);
			}
			{
				Trophy trophy1("Try Different Capitalization", 10, BRONZE);
				Trophy trophy2("Try different capitalization", 10, BRONZE);
				Assert::AreEqual(false, trophy1 >= trophy2);
				Assert::AreEqual(true, trophy2 >= trophy1);
			}
			{
				Trophy trophy1("Try different letters", 10, BRONZE);
				Trophy trophy2("Try eiggerent metters", 10, BRONZE);
				Assert::AreEqual(false, trophy1 >= trophy2);
				Assert::AreEqual(true, trophy2 >= trophy1);
			}
			{
				Trophy trophy1("Try different levels", 10, BRONZE);
				Trophy trophy2("Try different levels", 25, BRONZE);
				Assert::AreEqual(false, trophy1 >= trophy2);
				Assert::AreEqual(true, trophy2 >= trophy1);
			}
			{
				Trophy trophy1("Try different levels", 15, BRONZE);
				Trophy trophy2("Try different levels", 16, BRONZE);
				Assert::AreEqual(false, trophy1 >= trophy2);
				Assert::AreEqual(true, trophy2 >= trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, BRONZE);
				Trophy trophy2("Try different colors", 15, SILVER);
				Assert::AreEqual(false, trophy1 >= trophy2);
				Assert::AreEqual(true, trophy2 >= trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, BRONZE);
				Trophy trophy2("Try different colors", 15, GOLD);
				Assert::AreEqual(false, trophy1 >= trophy2);
				Assert::AreEqual(true, trophy2 >= trophy1);
			}
			{
				Trophy trophy1("Try different colors", 15, SILVER);
				Trophy trophy2("Try different colors", 15, GOLD);
				Assert::AreEqual(false, trophy1 >= trophy2);
				Assert::AreEqual(true, trophy2 >= trophy1);
			}
			{
				const Trophy trophy1("Try constant same object", 15, SILVER);
				Assert::AreEqual(true, trophy1 >= trophy1);
			}
			{
				const Trophy trophy1("Try different constant objects", 15, SILVER);
				const Trophy trophy2("Try different constant objects", 15, GOLD);
				Assert::AreEqual(false, trophy1 >= trophy2);
				Assert::AreEqual(true, trophy2 >= trophy1);
			}
			{
				const Trophy trophy1("Try same constant objects", 15, SILVER);
				const Trophy trophy2("Try same constant objects", 15, SILVER);
				Assert::AreEqual(true, trophy1 >= trophy2);
				Assert::AreEqual(true, trophy2 >= trophy1);
			}
		}
		TEST_METHOD(Trophy_Assignment)
		{
			std::string name = "This is a Trophy Name";
			int level = 25;
			Color color = BRONZE;
			Trophy trophy(name, level, color);
			Trophy trophy1;
			trophy1 = trophy;

			Assert::AreEqual(name, trophy1.getName());
			Assert::AreEqual(level, trophy1.getLevel());
			Assert::AreEqual(int(color), int(trophy1.getColor()));
		}
		TEST_METHOD(Trophy_InsertionOperator)
		{
			std::string name = "This is a Trophy Name";
			int level = 25;
			Color color = BRONZE;
			Trophy trophy(name, level, color);

			string result = "[ This is a Trophy Name          : 25 : BRONZE ]";
			stringstream sout;
			sout << trophy;

			Assert::AreEqual(result, sout.str());
		}
	};

	TEST_CLASS(TrophyMemoryTests)
	{
	public:
		TEST_METHOD(Trophy_DynamicMemoryConstructor)
		{
			std::string *name = new string("");
			int* level = new int(1);
			Color* color = new Color(BRONZE);

			Trophy trophy(*name, *level, *color);

			delete name;
			delete level;
			delete color;
			try
			{
				Assert::AreEqual(string(""), trophy.getName());
				Assert::AreEqual(1, trophy.getLevel());
				Assert::AreEqual(int(BRONZE), int(trophy.getColor()));
			}
			catch (exception&)
			{
				// Threw an exception - not a deep copy
				Assert::Fail();
			}
		}
		TEST_METHOD(Trophy_DynamicMemoryCopyConstructor)
		{
			std::string name = "";
			int level = 1;
			Color color = BRONZE;

			Trophy* trophy = new Trophy(name, level, color);
			Trophy trophy1(*trophy);
			delete trophy;

			try
			{
				Assert::AreEqual(name, trophy1.getName());
				Assert::AreEqual(level, trophy1.getLevel());
				Assert::AreEqual(int(color), int(trophy1.getColor()));
			}
			catch (exception&)
			{
				// Threw an exception - not a deep copy
				Assert::Fail();
			}
		}
		TEST_METHOD(Trophy_DynamicMemorySetName)
		{
			std::string *name = new string("");
			int* level = new int(1);
			Color* color = new Color(BRONZE);

			Trophy trophy;
			trophy.setName(*name);
			trophy.setLevel(*level);
			trophy.setColor(*color);

			delete name;
			delete level;
			delete color;

			try
			{
				Assert::AreEqual(string(""), trophy.getName());
			}
			catch (exception&)
			{
				// Threw an exception - not a deep copy
				Assert::Fail();
			}
		}
		TEST_METHOD(Trophy_DynamicMemorySetLevel)
		{
			std::string *name = new string("");
			int* level = new int(1);
			Color* color = new Color(BRONZE);

			Trophy trophy;
			trophy.setName(*name);
			trophy.setLevel(*level);
			trophy.setColor(*color);

			delete name;
			delete level;
			delete color;

			try
			{
				Assert::AreEqual(1, trophy.getLevel());
			}
			catch (exception&)
			{
				// Threw an exception - not a deep copy
				Assert::Fail();
			}
		}
		TEST_METHOD(Trophy_DynamicMemorySetColor)
		{
			std::string *name = new string("");
			int* level = new int(1);
			Color* color = new Color(BRONZE);

			Trophy trophy;
			trophy.setName(*name);
			trophy.setLevel(*level);
			trophy.setColor(*color);

			delete name;
			delete level;
			delete color;

			try
			{
				Assert::AreEqual(int(BRONZE), int(trophy.getColor()));
			}
			catch (exception&)
			{
				// Threw an exception - not a deep copy
				Assert::Fail();
			}
		}
		TEST_METHOD(Trophy_DynamicMemoryAssignmentOperator)
		{
			std::string name = "";
			int level = 1;
			Color color = BRONZE;

			Trophy* trophy = new Trophy(name, level, color);
			Trophy trophy1;
			trophy1 = *trophy;
			delete trophy;

			try
			{
				Assert::AreEqual(name, trophy1.getName());
				Assert::AreEqual(level, trophy1.getLevel());
				Assert::AreEqual(int(color), int(trophy1.getColor()));
			}
			catch (exception&)
			{
				// Threw an exception - not a deep copy
				Assert::Fail();
			}
		}
	};

	TEST_CLASS(TrophyCaseConstructors)
	{
		string colors[3] = { "BRONZE", "SILVER", "GOLD  " };

	public:
		TEST_METHOD(TrophyCase_Constructor)
		{
			TrophyCase trophyCase;

			Assert::AreEqual(0, trophyCase.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase.getAllocatedSize());
		}
		TEST_METHOD(TrophyCase_CopyConstructor_OneTrophy)
		{
			TrophyCase trophyCase1;
			trophyCase1.addTrophy("Trophy 1", 1, BRONZE);
			TrophyCase trophyCase2(trophyCase1);

			stringstream s1;
			s1 << trophyCase1;
			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(1, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_CopyConstructor_TenTrophies)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 10; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, BRONZE);
			}

			TrophyCase trophyCase2(trophyCase1);

			stringstream s1;
			s1 << trophyCase1;
			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(10, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_CopyConstructor_ElevenTrophies)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 11; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, BRONZE);
			}

			TrophyCase trophyCase2(trophyCase1);

			stringstream s1;
			s1 << trophyCase1;
			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(11, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(11, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_CopyConstructor_OneHundredTrophies)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 100; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), int(i / 2), BRONZE);
			}

			TrophyCase trophyCase2(trophyCase1);

			stringstream s1;
			s1 << trophyCase1;
			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(100, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(103, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
	};
	TEST_CLASS(TrophyCaseAddTrophy)
	{
		string colors[3] = { "BRONZE", "SILVER", "GOLD  " };

	public:
		TEST_METHOD(TrophyCase_AddTrophy_One)
		{
			string expectedOutput = "[ Trophy 1                       :  1 : GOLD   ]\n";

			TrophyCase trophyCase1;
			for (int i = 1; i <= 1; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, GOLD);
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(1, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_AddTrophy_Ten)
		{
			string expectedOutput;
			for (int i = 1; i <= 10; ++i)
			{
				expectedOutput += "[ ";
				string name = "Trophy " + to_string(i);
				string nameSpaces(30 - name.size(), ' ');
				expectedOutput += name + nameSpaces;
				string level = to_string(i);
				string levelSpaces(2 - level.size(), ' ');
				expectedOutput += " : " + levelSpaces + level + " : GOLD   ]\n";
			}

			TrophyCase trophyCase1;
			for (int i = 1; i <= 10; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, GOLD);
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(10, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_AddTrophy_Eleven)
		{
			string expectedOutput;
			for (int i = 1; i <= 11; ++i)
			{
				expectedOutput += "[ ";
				string name = "Trophy " + to_string(i);
				string nameSpaces(30 - name.size(), ' ');
				expectedOutput += name + nameSpaces;
				string level = to_string(i);
				string levelSpaces(2 - level.size(), ' ');
				expectedOutput += " : " + levelSpaces + level + " : GOLD   ]\n";
			}

			TrophyCase trophyCase1;
			for (int i = 1; i <= 11; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, GOLD);
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(11, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(11, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_AddTrophy_Fifty)
		{
			string expectedOutput;
			for (int i = 1; i <= 50; ++i)
			{
				expectedOutput += "[ ";
				string name = "Trophy " + to_string(i);
				string nameSpaces(30 - name.size(), ' ');
				expectedOutput += name + nameSpaces;
				string level = to_string(i);
				string levelSpaces(2 - level.size(), ' ');
				expectedOutput += " : " + levelSpaces + level + " : GOLD   ]\n";
			}

			TrophyCase trophyCase1;
			for (int i = 1; i <= 50; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, GOLD);
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(50, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(50, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_AddTrophy_TenSorted)
		{
			string expectedOutput = "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 2                       :  2 : SILVER ]\n";
			expectedOutput += "[ Trophy 3                       :  3 : GOLD   ]\n";
			expectedOutput += "[ Trophy 4                       :  4 : BRONZE ]\n";
			expectedOutput += "[ Trophy 5                       :  5 : SILVER ]\n";
			expectedOutput += "[ Trophy 6                       :  6 : GOLD   ]\n";
			expectedOutput += "[ Trophy 7                       :  7 : BRONZE ]\n";
			expectedOutput += "[ Trophy 8                       :  8 : SILVER ]\n";
			expectedOutput += "[ Trophy 9                       :  9 : GOLD   ]\n";
			expectedOutput += "[ Trophy 10                      : 10 : BRONZE ]\n";

			TrophyCase trophyCase1;
			for (int i = 1; i <= 10; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(10, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_AddTrophy_TenUnsorted)
		{
			string expectedOutput;
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 2                       :  2 : SILVER ]\n";
			expectedOutput += "[ Trophy 3                       :  3 : GOLD   ]\n";
			expectedOutput += "[ Trophy 4                       :  4 : BRONZE ]\n";
			expectedOutput += "[ Trophy 5                       :  5 : SILVER ]\n";
			expectedOutput += "[ Trophy 6                       :  6 : GOLD   ]\n";
			expectedOutput += "[ Trophy 7                       :  7 : BRONZE ]\n";
			expectedOutput += "[ Trophy 8                       :  8 : SILVER ]\n";
			expectedOutput += "[ Trophy 9                       :  9 : GOLD   ]\n";
			expectedOutput += "[ Trophy 10                      : 10 : BRONZE ]\n";

			TrophyCase trophyCase1;
			trophyCase1.addTrophy("Trophy 9", 9, GOLD);
			trophyCase1.addTrophy("Trophy 5", 5, SILVER);
			trophyCase1.addTrophy("Trophy 2", 2, SILVER);
			trophyCase1.addTrophy("Trophy 7", 7, BRONZE);
			trophyCase1.addTrophy("Trophy 3", 3, GOLD);
			trophyCase1.addTrophy("Trophy 10", 10, BRONZE);
			trophyCase1.addTrophy("Trophy 4", 4, BRONZE);
			trophyCase1.addTrophy("Trophy 8", 8, SILVER);
			trophyCase1.addTrophy("Trophy 1", 1, BRONZE);
			trophyCase1.addTrophy("Trophy 6", 6, GOLD);

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(10, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_AddTrophy_TenReverseSorted)
		{
			string expectedOutput;
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 2                       :  2 : SILVER ]\n";
			expectedOutput += "[ Trophy 3                       :  3 : GOLD   ]\n";
			expectedOutput += "[ Trophy 4                       :  4 : BRONZE ]\n";
			expectedOutput += "[ Trophy 5                       :  5 : SILVER ]\n";
			expectedOutput += "[ Trophy 6                       :  6 : GOLD   ]\n";
			expectedOutput += "[ Trophy 7                       :  7 : BRONZE ]\n";
			expectedOutput += "[ Trophy 8                       :  8 : SILVER ]\n";
			expectedOutput += "[ Trophy 9                       :  9 : GOLD   ]\n";
			expectedOutput += "[ Trophy 10                      : 10 : BRONZE ]\n";

			TrophyCase trophyCase1;
			trophyCase1.addTrophy("Trophy 10", 10, BRONZE);
			trophyCase1.addTrophy("Trophy 9", 9, GOLD);
			trophyCase1.addTrophy("Trophy 8", 8, SILVER);
			trophyCase1.addTrophy("Trophy 7", 7, BRONZE);
			trophyCase1.addTrophy("Trophy 6", 6, GOLD);
			trophyCase1.addTrophy("Trophy 5", 5, SILVER);
			trophyCase1.addTrophy("Trophy 4", 4, BRONZE);
			trophyCase1.addTrophy("Trophy 3", 3, GOLD);
			trophyCase1.addTrophy("Trophy 2", 2, SILVER);
			trophyCase1.addTrophy("Trophy 1", 1, BRONZE);

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(10, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_AddTrophy_TwentyVarious)
		{
			string expectedOutput;
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 2                       :  2 : SILVER ]\n";
			expectedOutput += "[ Trophy 3                       :  3 : GOLD   ]\n";
			expectedOutput += "[ Trophy 4                       :  4 : BRONZE ]\n";
			expectedOutput += "[ Trophy 5                       :  5 : SILVER ]\n";
			expectedOutput += "[ Trophy 6                       :  6 : GOLD   ]\n";
			expectedOutput += "[ Trophy 7                       :  7 : BRONZE ]\n";
			expectedOutput += "[ Trophy 8                       :  8 : SILVER ]\n";
			expectedOutput += "[ Trophy 9                       :  9 : GOLD   ]\n";
			expectedOutput += "[ Trophy 10                      : 10 : BRONZE ]\n";
			expectedOutput += "[ Trophy 11                      : 11 : SILVER ]\n";
			expectedOutput += "[ Trophy 12                      : 12 : GOLD   ]\n";
			expectedOutput += "[ Trophy 13                      : 13 : BRONZE ]\n";
			expectedOutput += "[ Trophy 14                      : 14 : SILVER ]\n";
			expectedOutput += "[ Trophy 15                      : 15 : GOLD   ]\n";
			expectedOutput += "[ Trophy 16                      : 16 : BRONZE ]\n";
			expectedOutput += "[ Trophy 17                      : 17 : SILVER ]\n";
			expectedOutput += "[ Trophy 18                      : 18 : GOLD   ]\n";
			expectedOutput += "[ Trophy 19                      : 19 : BRONZE ]\n";
			expectedOutput += "[ Trophy 20                      : 20 : SILVER ]\n";

			TrophyCase trophyCase1;
			for (int i = 1; i <= 20; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(20, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(20, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_AddTrophy_SortByLevelThenColorThenName)
		{
			string expectedOutput;
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 10                      :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 11                      :  1 : SILVER ]\n";
			expectedOutput += "[ Trophy 2                       :  1 : SILVER ]\n";
			expectedOutput += "[ Trophy 12                      :  1 : GOLD   ]\n";
			expectedOutput += "[ Trophy 3                       :  1 : GOLD   ]\n";
			expectedOutput += "[ Trophy 13                      :  2 : BRONZE ]\n";
			expectedOutput += "[ Trophy 4                       :  2 : BRONZE ]\n";
			expectedOutput += "[ Trophy 14                      :  2 : SILVER ]\n";
			expectedOutput += "[ Trophy 5                       :  2 : SILVER ]\n";
			expectedOutput += "[ Trophy 15                      :  2 : GOLD   ]\n";
			expectedOutput += "[ Trophy 6                       :  2 : GOLD   ]\n";
			expectedOutput += "[ Trophy 16                      :  3 : BRONZE ]\n";
			expectedOutput += "[ Trophy 7                       :  3 : BRONZE ]\n";
			expectedOutput += "[ Trophy 17                      :  3 : SILVER ]\n";
			expectedOutput += "[ Trophy 8                       :  3 : SILVER ]\n";
			expectedOutput += "[ Trophy 18                      :  3 : GOLD   ]\n";
			expectedOutput += "[ Trophy 9                       :  3 : GOLD   ]\n";

			TrophyCase trophyCase1;
			trophyCase1.addTrophy("Trophy 9", 3, GOLD);
			trophyCase1.addTrophy("Trophy 5", 2, SILVER);
			trophyCase1.addTrophy("Trophy 11", 1, SILVER);
			trophyCase1.addTrophy("Trophy 2", 1, SILVER);
			trophyCase1.addTrophy("Trophy 7", 3, BRONZE);
			trophyCase1.addTrophy("Trophy 16", 3, BRONZE);
			trophyCase1.addTrophy("Trophy 3", 1, GOLD);
			trophyCase1.addTrophy("Trophy 14", 2, SILVER);
			trophyCase1.addTrophy("Trophy 4", 2, BRONZE);
			trophyCase1.addTrophy("Trophy 8", 3, SILVER);
			trophyCase1.addTrophy("Trophy 1", 1, BRONZE);
			trophyCase1.addTrophy("Trophy 18", 3, GOLD);
			trophyCase1.addTrophy("Trophy 10", 1, BRONZE);
			trophyCase1.addTrophy("Trophy 12", 1, GOLD);
			trophyCase1.addTrophy("Trophy 6", 2, GOLD);
			trophyCase1.addTrophy("Trophy 13", 2, BRONZE);
			trophyCase1.addTrophy("Trophy 17", 3, SILVER);
			trophyCase1.addTrophy("Trophy 15", 2, GOLD);

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(18, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(18, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_AddTrophy_SortByName)
		{
			string expectedOutput;
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 2                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 3                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 4                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 5                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 6                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 7                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 8                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 9                       :  1 : BRONZE ]\n";

			TrophyCase trophyCase1;
			trophyCase1.addTrophy("Trophy 9", 1, BRONZE);
			trophyCase1.addTrophy("Trophy 5", 1, BRONZE);
			trophyCase1.addTrophy("Trophy 2", 1, BRONZE);
			trophyCase1.addTrophy("Trophy 7", 1, BRONZE);
			trophyCase1.addTrophy("Trophy 3", 1, BRONZE);
			trophyCase1.addTrophy("Trophy 4", 1, BRONZE);
			trophyCase1.addTrophy("Trophy 8", 1, BRONZE);
			trophyCase1.addTrophy("Trophy 1", 1, BRONZE);
			trophyCase1.addTrophy("Trophy 6", 1, BRONZE);

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(9, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_AddTrophy_SortByLevelThenColor)
		{
			string expectedOutput;
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 1                       :  1 : SILVER ]\n";
			expectedOutput += "[ Trophy 1                       :  1 : GOLD   ]\n";
			expectedOutput += "[ Trophy 1                       :  2 : BRONZE ]\n";
			expectedOutput += "[ Trophy 1                       :  2 : SILVER ]\n";
			expectedOutput += "[ Trophy 1                       :  2 : GOLD   ]\n";
			expectedOutput += "[ Trophy 1                       :  3 : BRONZE ]\n";
			expectedOutput += "[ Trophy 1                       :  3 : SILVER ]\n";
			expectedOutput += "[ Trophy 1                       :  3 : GOLD   ]\n";

			TrophyCase trophyCase1;
			trophyCase1.addTrophy("Trophy 1", 3, GOLD);
			trophyCase1.addTrophy("Trophy 1", 1, SILVER);
			trophyCase1.addTrophy("Trophy 1", 3, BRONZE);
			trophyCase1.addTrophy("Trophy 1", 1, BRONZE);
			trophyCase1.addTrophy("Trophy 1", 3, SILVER);
			trophyCase1.addTrophy("Trophy 1", 2, BRONZE);
			trophyCase1.addTrophy("Trophy 1", 1, GOLD);
			trophyCase1.addTrophy("Trophy 1", 2, SILVER);
			trophyCase1.addTrophy("Trophy 1", 2, GOLD);

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(9, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
	};
	TEST_CLASS(TrophyCaseCopyTrophy)
	{
		string colors[3] = { "BRONZE", "SILVER", "GOLD  " };

	public:
		TEST_METHOD(TrophyCase_CopyTrophy_Single)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 1; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), 1, Color((i - 1) % 3));
			}

			for (int i = 1; i <= 9; ++i)
			{
				trophyCase1.copyTrophy("Trophy " + to_string(1));
			}

			string expectedOutput;
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(10, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_CopyTrophy_InOrder)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 3; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), 1, Color((i - 1) % 3));
			}

			for (int i = 1; i <= 3; ++i)
			{
				trophyCase1.copyTrophy("Trophy " + to_string(i));
			}

			string expectedOutput;
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 2                       :  1 : SILVER ]\n";
			expectedOutput += "[ Trophy 2                       :  1 : SILVER ]\n";
			expectedOutput += "[ Trophy 3                       :  1 : GOLD   ]\n";
			expectedOutput += "[ Trophy 3                       :  1 : GOLD   ]\n";

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(6, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_CopyTrophy_ReverseOrder)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 3; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), 1, Color((i - 1) % 3));
			}

			for (int i = 3; i >= 1; --i)
			{
				trophyCase1.copyTrophy("Trophy " + to_string(i));
			}

			string expectedOutput;
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 2                       :  1 : SILVER ]\n";
			expectedOutput += "[ Trophy 2                       :  1 : SILVER ]\n";
			expectedOutput += "[ Trophy 3                       :  1 : GOLD   ]\n";
			expectedOutput += "[ Trophy 3                       :  1 : GOLD   ]\n";

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(6, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_CopyTrophy_ArbitraryOrder)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 3; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), 1, Color((i - 1) % 3));
			}

			trophyCase1.copyTrophy("Trophy 2");
			trophyCase1.copyTrophy("Trophy 1");
			trophyCase1.copyTrophy("Trophy 3");
			trophyCase1.copyTrophy("Trophy 2");
			trophyCase1.copyTrophy("Trophy 3");
			trophyCase1.copyTrophy("Trophy 1");

			string expectedOutput;
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 1                       :  1 : BRONZE ]\n";
			expectedOutput += "[ Trophy 2                       :  1 : SILVER ]\n";
			expectedOutput += "[ Trophy 2                       :  1 : SILVER ]\n";
			expectedOutput += "[ Trophy 2                       :  1 : SILVER ]\n";
			expectedOutput += "[ Trophy 3                       :  1 : GOLD   ]\n";
			expectedOutput += "[ Trophy 3                       :  1 : GOLD   ]\n";
			expectedOutput += "[ Trophy 3                       :  1 : GOLD   ]\n";

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(9, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_CopyTrophy_Fifty)
		{
			string expectedOutput;
			for (int i = 1; i <= 25; ++i)
			{
				for (int j = 0; j < 2; ++j)
				{

					expectedOutput += "[ ";
					string name = "Trophy " + to_string(i);
					string nameSpaces(30 - name.size(), ' ');
					expectedOutput += name + nameSpaces;
					string level = to_string(i);
					string levelSpaces(2 - level.size(), ' ');
					expectedOutput += " : " + levelSpaces + level;
					string color = colors[((i - 1) % 3)];
					expectedOutput += " : " + color + " ]\n";
				}
			}

			TrophyCase trophyCase1;
			for (int i = 1; i <= 25; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			for (int i = 1; i <= 25; ++i)
			{
				trophyCase1.copyTrophy("Trophy " + to_string(i));
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(50, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(50, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
	};
	TEST_CLASS(TrophyCaseDeleteTrophy)
	{
		string colors[3] = { "BRONZE", "SILVER", "GOLD  " };

	public:
		TEST_METHOD(TrophyCase_DeleteTrophy_Single)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 1; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, GOLD);
			}

			trophyCase1.deleteTrophy("Trophy 1");

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(0, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(string(""), s1.str());
		}

		TEST_METHOD(TrophyCase_DeleteTrophy_First)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 10; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			trophyCase1.deleteTrophy("Trophy 1");

			string expectedOutput;
			for (int i = 2; i <= 10; ++i)
			{

				expectedOutput += "[ ";
				string name = "Trophy " + to_string(i);
				string nameSpaces(30 - name.size(), ' ');
				expectedOutput += name + nameSpaces;
				string level = to_string(i);
				string levelSpaces(2 - level.size(), ' ');
				expectedOutput += " : " + levelSpaces + level;
				string color = colors[((i - 1) % 3)];
				expectedOutput += " : " + color + " ]\n";
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(9, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}

		TEST_METHOD(TrophyCase_DeleteTrophy_Last)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 10; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			trophyCase1.deleteTrophy("Trophy 10");

			string expectedOutput;
			for (int i = 1; i <= 9; ++i)
			{

				expectedOutput += "[ ";
				string name = "Trophy " + to_string(i);
				string nameSpaces(30 - name.size(), ' ');
				expectedOutput += name + nameSpaces;
				string level = to_string(i);
				string levelSpaces(2 - level.size(), ' ');
				expectedOutput += " : " + levelSpaces + level;
				string color = colors[((i - 1) % 3)];
				expectedOutput += " : " + color + " ]\n";
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(9, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}

		TEST_METHOD(TrophyCase_DeleteTrophy_Middle)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 10; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			trophyCase1.deleteTrophy("Trophy 5");

			string expectedOutput;
			for (int i = 1; i <= 10; ++i)
			{
				if (i == 5)
					continue;
				expectedOutput += "[ ";
				string name = "Trophy " + to_string(i);
				string nameSpaces(30 - name.size(), ' ');
				expectedOutput += name + nameSpaces;
				string level = to_string(i);
				string levelSpaces(2 - level.size(), ' ');
				expectedOutput += " : " + levelSpaces + level;
				string color = colors[((i - 1) % 3)];
				expectedOutput += " : " + color + " ]\n";
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(9, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}

		TEST_METHOD(TrophyCase_DeleteTrophy_InOrder)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 10; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			for (int i = 1; i <= 10; ++i)
			{
				trophyCase1.deleteTrophy("Trophy " + to_string(i));
			}

			string expectedOutput;

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(0, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}

		TEST_METHOD(TrophyCase_DeleteTrophy_ReverseOrder)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 10; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			for (int i = 10; i >= 1; --i)
			{
				trophyCase1.deleteTrophy("Trophy " + to_string(i));
			}

			string expectedOutput;

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(0, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}

		TEST_METHOD(TrophyCase_DeleteTrophy_FiftyInOrder)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 50; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			for (int i = 1; i <= 50; ++i)
			{
				trophyCase1.deleteTrophy("Trophy " + to_string(i));
			}

			string expectedOutput;

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(0, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(50, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_DeleteTrophy_FiftyReverseOrder)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 50; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			for (int i = 50; i >= 1; --i)
			{
				trophyCase1.deleteTrophy("Trophy " + to_string(i));
			}

			string expectedOutput;

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(0, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(50, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
	};

	TEST_CLASS(TrophyCaseRenameTrophy)
	{
		string colors[3] = { "BRONZE", "SILVER", "GOLD  " };

	public:
		TEST_METHOD(TrophyCase_RenameTrophy_Single)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 1; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			for (int i = 1; i <= 1; ++i)
			{
				trophyCase1.renameTrophy("Trophy " + to_string(i), "Trophy " + to_string(i + 1));
			}

			string expectedOutput;
			for (int i = 1; i <= 1; ++i)
			{
				expectedOutput += "[ ";
				string name = "Trophy " + to_string(i + 1);
				string nameSpaces(30 - name.size(), ' ');
				expectedOutput += name + nameSpaces;
				string level = to_string(i);
				string levelSpaces(2 - level.size(), ' ');
				expectedOutput += " : " + levelSpaces + level;
				string color = colors[Color((i - 1) % 3)];
				expectedOutput += " : " + color + " ]\n";
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(1, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_RenameTrophy_Eight)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 8; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			for (int i = 8; i >= 1; --i)
			{
				trophyCase1.renameTrophy("Trophy " + to_string(i), "Trophy " + to_string(i + 1));
			}

			string expectedOutput;
			for (int i = 1; i <= 8; ++i)
			{
				expectedOutput += "[ ";
				string name = "Trophy " + to_string(i + 1);
				string nameSpaces(30 - name.size(), ' ');
				expectedOutput += name + nameSpaces;
				string level = to_string(i);
				string levelSpaces(2 - level.size(), ' ');
				expectedOutput += " : " + levelSpaces + level;
				string color = colors[Color((i - 1) % 3)];
				expectedOutput += " : " + color + " ]\n";
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(8, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_RenameTrophy_Forty)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 40; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			for (int i = 40; i >= 1; --i)
			{
				trophyCase1.renameTrophy("Trophy " + to_string(i), "Trophy " + to_string(i + 1));
			}

			string expectedOutput;
			for (int i = 1; i <= 40; ++i)
			{
				expectedOutput += "[ ";
				string name = "Trophy " + to_string(i + 1);
				string nameSpaces(30 - name.size(), ' ');
				expectedOutput += name + nameSpaces;
				string level = to_string(i);
				string levelSpaces(2 - level.size(), ' ');
				expectedOutput += " : " + levelSpaces + level;
				string color = colors[Color((i - 1) % 3)];
				expectedOutput += " : " + color + " ]\n";
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(40, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(42, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
	};

	TEST_CLASS(TrophyCaseRelevelTrophy)
	{
		string colors[3] = { "BRONZE", "SILVER", "GOLD  " };

	public:
		TEST_METHOD(TrophyCase_RelevelTrophy_Single)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 1; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			for (int i = 1; i <= 1; ++i)
			{
				trophyCase1.relevelTrophy("Trophy " + to_string(i), i + 1);
			}

			string expectedOutput;
			for (int i = 1; i <= 1; ++i)
			{
				expectedOutput += "[ ";
				string name = "Trophy " + to_string(i);
				string nameSpaces(30 - name.size(), ' ');
				expectedOutput += name + nameSpaces;
				string level = to_string(i + 1);
				string levelSpaces(2 - level.size(), ' ');
				expectedOutput += " : " + levelSpaces + level;
				string color = colors[Color((i - 1) % 3)];
				expectedOutput += " : " + color + " ]\n";
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(1, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_RelevelTrophy_Eight)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 8; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			for (int i = 8; i >= 1; --i)
			{
				trophyCase1.relevelTrophy("Trophy " + to_string(i), i + 1);
			}

			string expectedOutput;
			for (int i = 1; i <= 8; ++i)
			{
				expectedOutput += "[ ";
				string name = "Trophy " + to_string(i);
				string nameSpaces(30 - name.size(), ' ');
				expectedOutput += name + nameSpaces;
				string level = to_string(i + 1);
				string levelSpaces(2 - level.size(), ' ');
				expectedOutput += " : " + levelSpaces + level;
				string color = colors[Color((i - 1) % 3)];
				expectedOutput += " : " + color + " ]\n";
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(8, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_RelevelTrophy_Forty)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 40; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			for (int i = 40; i >= 1; --i)
			{
				trophyCase1.relevelTrophy("Trophy " + to_string(i), i + 1);
			}

			string expectedOutput;
			for (int i = 1; i <= 40; ++i)
			{
				expectedOutput += "[ ";
				string name = "Trophy " + to_string(i);
				string nameSpaces(30 - name.size(), ' ');
				expectedOutput += name + nameSpaces;
				string level = to_string(i + 1);
				string levelSpaces(2 - level.size(), ' ');
				expectedOutput += " : " + levelSpaces + level;
				string color = colors[Color((i - 1) % 3)];
				expectedOutput += " : " + color + " ]\n";
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(40, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(42, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
	};
	TEST_CLASS(TrophyCaseRecolorTrophy)
	{
		string colors[3] = { "BRONZE", "SILVER", "GOLD  " };

	public:
		TEST_METHOD(TrophyCase_RecolorTrophy_Single)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 1; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			for (int i = 1; i <= 1; ++i)
			{
				trophyCase1.recolorTrophy("Trophy " + to_string(i), Color((i) % 3));
			}

			string expectedOutput;
			for (int i = 1; i <= 1; ++i)
			{
				expectedOutput += "[ ";
				string name = "Trophy " + to_string(i);
				string nameSpaces(30 - name.size(), ' ');
				expectedOutput += name + nameSpaces;
				string level = to_string(i);
				string levelSpaces(2 - level.size(), ' ');
				expectedOutput += " : " + levelSpaces + level;
				string color = colors[Color((i) % 3)];
				expectedOutput += " : " + color + " ]\n";
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(1, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_RecolorTrophy_Eight)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 8; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			for (int i = 8; i >= 1; --i)
			{
				trophyCase1.recolorTrophy("Trophy " + to_string(i), Color((i) % 3));
			}

			string expectedOutput;
			for (int i = 1; i <= 8; ++i)
			{
				expectedOutput += "[ ";
				string name = "Trophy " + to_string(i);
				string nameSpaces(30 - name.size(), ' ');
				expectedOutput += name + nameSpaces;
				string level = to_string(i);
				string levelSpaces(2 - level.size(), ' ');
				expectedOutput += " : " + levelSpaces + level;
				string color = colors[Color((i) % 3)];
				expectedOutput += " : " + color + " ]\n";
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(8, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
		TEST_METHOD(TrophyCase_RecolorTrophy_Forty)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 40; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, Color((i - 1) % 3));
			}

			for (int i = 40; i >= 1; --i)
			{
				trophyCase1.recolorTrophy("Trophy " + to_string(i), Color((i) % 3));
			}

			string expectedOutput;
			for (int i = 1; i <= 40; ++i)
			{
				expectedOutput += "[ ";
				string name = "Trophy " + to_string(i);
				string nameSpaces(30 - name.size(), ' ');
				expectedOutput += name + nameSpaces;
				string level = to_string(i);
				string levelSpaces(2 - level.size(), ' ');
				expectedOutput += " : " + levelSpaces + level;
				string color = colors[Color((i) % 3)];
				expectedOutput += " : " + color + " ]\n";
			}

			stringstream s1;
			s1 << trophyCase1;

			Assert::AreEqual(40, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(42, trophyCase1.getAllocatedSize());
			Assert::AreEqual(expectedOutput, s1.str());
		}
	};
	TEST_CLASS(TrophyCaseAssignmentOperator)
	{
		string colors[3] = { "BRONZE", "SILVER", "GOLD  " };

	public:
		TEST_METHOD(TrophyCase_AssignmentOperator_OneTrophy)
		{
			TrophyCase trophyCase1;
			trophyCase1.addTrophy("Trophy 1", 1, BRONZE);
			TrophyCase trophyCase2 = trophyCase1;

			stringstream s1;
			s1 << trophyCase1;
			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(1, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_AssignmentOperator_TenTrophies)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 10; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, BRONZE);
			}

			TrophyCase trophyCase2 = trophyCase1;

			stringstream s1;
			s1 << trophyCase1;
			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(10, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_AssignmentOperator_ElevenTrophies)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 11; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, BRONZE);
			}

			TrophyCase trophyCase2 = trophyCase1;

			stringstream s1;
			s1 << trophyCase1;
			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(11, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(11, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_AssignmentOperator_OneHundredTrophies)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 100; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), int(i / 2), BRONZE);
			}

			TrophyCase trophyCase2 = trophyCase1;

			stringstream s1;
			s1 << trophyCase1;
			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(100, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(103, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_AssignmentOperator_OverwriteOneTrophy)
		{
			TrophyCase trophyCase1;
			trophyCase1.addTrophy("Trophy 1", 1, BRONZE);
			TrophyCase trophyCase2;
			trophyCase2.addTrophy("Trophy 2", 2, SILVER);
			trophyCase2 = trophyCase1;

			stringstream s1;
			s1 << trophyCase1;
			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(1, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_AssignmentOperator_OverwriteTenTrophies)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 10; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, BRONZE);
			}

			TrophyCase trophyCase2;
			trophyCase2.addTrophy("Trophy 2", 2, SILVER);
			trophyCase2 = trophyCase1;

			stringstream s1;
			s1 << trophyCase1;
			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(10, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_AssignmentOperator_OverwriteElevenTrophies)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 11; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), i, BRONZE);
			}

			TrophyCase trophyCase2;
			trophyCase2.addTrophy("Trophy 2", 2, SILVER);
			trophyCase2 = trophyCase1;

			stringstream s1;
			s1 << trophyCase1;
			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(11, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(11, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_AssignmentOperator_OverwriteOneHundredTrophies)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 100; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), int(i / 2), BRONZE);
			}

			TrophyCase trophyCase2;
			trophyCase2.addTrophy("Trophy 2", 2, SILVER);
			trophyCase2 = trophyCase1;

			stringstream s1;
			s1 << trophyCase1;
			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(100, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(103, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_AssignmentOperator_SelfAssignment)
		{
			TrophyCase trophyCase1;
			for (int i = 1; i <= 50; ++i)
			{
				trophyCase1.addTrophy("Trophy " + to_string(i), int(i / 2), BRONZE);
			}

			stringstream s1;
			s1 << trophyCase1;

			trophyCase1 = trophyCase1;

			stringstream s2;
			s2 << trophyCase1;

			Assert::AreEqual(50, trophyCase1.getNbrOfTrophies());
			Assert::AreEqual(50, trophyCase1.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
	};

	TEST_CLASS(TrophyCaseAssignmentMemory)
	{
		string colors[3] = { "BRONZE", "SILVER", "GOLD  " };

	public:
		TEST_METHOD(TrophyCase_AssignmentMemory_OneTrophy)
		{
			TrophyCase* trophyCase1 = new TrophyCase();
			trophyCase1->addTrophy("Trophy 1", 1, BRONZE);
			TrophyCase trophyCase2;
			trophyCase2 = *trophyCase1;

			stringstream s1;
			s1 << *trophyCase1;
			delete trophyCase1;

			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(1, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_AssignmentMemory_TenTrophies)
		{
			TrophyCase* trophyCase1 = new TrophyCase();
			for (int i = 1; i <= 10; ++i)
			{
				trophyCase1->addTrophy("Trophy " + to_string(i), i, BRONZE);
			}
			TrophyCase trophyCase2;
			trophyCase2 = *trophyCase1;

			stringstream s1;
			s1 << *trophyCase1;
			delete trophyCase1;

			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(10, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_AssignmentMemory_ElevenTrophies)
		{
			TrophyCase* trophyCase1 = new TrophyCase();
			for (int i = 1; i <= 11; ++i)
			{
				trophyCase1->addTrophy("Trophy " + to_string(i), i, BRONZE);
			}
			TrophyCase trophyCase2;
			trophyCase2 = *trophyCase1;

			stringstream s1;
			s1 << *trophyCase1;
			delete trophyCase1;

			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(11, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(11, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_AssignmentMemory_OneHundredTrophies)
		{
			TrophyCase* trophyCase1 = new TrophyCase();
			for (int i = 1; i <= 100; ++i)
			{
				trophyCase1->addTrophy("Trophy " + to_string(i), int(i / 2), BRONZE);
			}
			TrophyCase trophyCase2;
			trophyCase2 = *trophyCase1;

			stringstream s1;
			s1 << *trophyCase1;
			delete trophyCase1;

			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(100, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(103, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_AssignmentMemory_OverwriteOneTrophy)
		{
			TrophyCase* trophyCase1 = new TrophyCase();
			trophyCase1->addTrophy("Trophy 1", 1, BRONZE);
			TrophyCase trophyCase2;
			trophyCase2.addTrophy("Trophy 2", 2, SILVER);
			trophyCase2 = *trophyCase1;

			stringstream s1;
			s1 << *trophyCase1;
			delete trophyCase1;

			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(1, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_AssignmentMemory_OverwriteTenTrophies)
		{
			TrophyCase* trophyCase1 = new TrophyCase();
			for (int i = 1; i <= 10; ++i)
			{
				trophyCase1->addTrophy("Trophy " + to_string(i), i, BRONZE);
			}

			TrophyCase trophyCase2;
			trophyCase2.addTrophy("Trophy 2", 2, SILVER);
			trophyCase2 = *trophyCase1;

			stringstream s1;
			s1 << *trophyCase1;
			delete trophyCase1;

			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(10, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(10, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_AssignmentMemory_OverwriteElevenTrophies)
		{
			TrophyCase* trophyCase1 = new TrophyCase();
			for (int i = 1; i <= 11; ++i)
			{
				trophyCase1->addTrophy("Trophy " + to_string(i), i, BRONZE);
			}

			TrophyCase trophyCase2;
			trophyCase2.addTrophy("Trophy 2", 2, SILVER);
			trophyCase2 = *trophyCase1;

			stringstream s1;
			s1 << *trophyCase1;
			delete trophyCase1;

			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(11, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(11, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
		TEST_METHOD(TrophyCase_AssignmentMemory_OverwriteOneHundredTrophies)
		{
			TrophyCase* trophyCase1 = new TrophyCase();
			for (int i = 1; i <= 100; ++i)
			{
				trophyCase1->addTrophy("Trophy " + to_string(i), int(i / 2), BRONZE);
			}

			TrophyCase trophyCase2;
			trophyCase2.addTrophy("Trophy 2", 2, SILVER);
			trophyCase2 = *trophyCase1;

			stringstream s1;
			s1 << *trophyCase1;
			delete trophyCase1;

			stringstream s2;
			s2 << trophyCase2;

			Assert::AreEqual(100, trophyCase2.getNbrOfTrophies());
			Assert::AreEqual(103, trophyCase2.getAllocatedSize());
			Assert::AreEqual(s1.str(), s2.str());
		}
	};
}