#include "catch.hpp"
#include "Array.h"
#include <string>
#include <iostream>

TEST_CASE("Testing Vector Class")
{
	SECTION("testing append function")
	{
		Array<int> a(3);
		REQUIRE(a.capacity() == 3);
		REQUIRE(a.size() == 0);
		a.append(15);
		REQUIRE(a.capacity() == 3);
		REQUIRE(a.size() == 1);
		a.append(1);
		a.append(7);
		a.append(12);
		a.append(66);
		REQUIRE(a.capacity() == 6);
		REQUIRE(a.size() == 5);
		a.append(23);
		REQUIRE(a.capacity() == 6);
		REQUIRE(a.size() == 6);


		Array<string> s(15);
		REQUIRE(s.capacity() == 15);
		REQUIRE(s.size() == 0);
		s.append("Hello");
		s.append("There");
		s.append("Users");
		REQUIRE(s.capacity() == 15);
		REQUIRE(s.size() == 3);
		s.pop();
		s.pop();
		REQUIRE(s.capacity() == 60);
		REQUIRE(s.size() == 1);
	}
}