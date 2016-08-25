#include <assert.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "maths.h"

using namespace std;

string test_result(int num, const string& check, bool test) {
	std::stringstream s; 
	s << setw(6) << setfill(' ') << to_string(num) + " - ";
	s << left << setw(28) << setfill(' ') << check;
	s << setw(6) << setfill(' ') << (test ? "PASS" : "FAIL");
	s << endl;
	return s.str();
}

template <typename T>
string test_result_debug(int num, const string& check, bool test, const T& v) {
	std::stringstream s;
	s << setw(6) << setfill(' ') << to_string(num) + " - ";
	s << left << setw(28) << setfill(' ') << check;
	s << setw(6) << setfill(' ') << (test ? "PASS" : "FAIL");
	if (!test)
		s << setw(6) << setfill(' ') << "EXPECTED: " << v;
	s << endl;
	return s.str();
}

int main() {
	{ // Tests for vec2 type
		std::string test_set{"2D Vector type checks:"};
		int test_item = 0;
		stringstream ss;
		ss << test_set << endl << endl;

		{
			maths::vec2 a = {0.f, 0.f};
			bool expected_result = true;

			string output = test_result(test_item++, "initialise", a.x == 0.f && a.y == 0.f);
			ss << output;
		}
		 
		{ 
			maths::vec2 a = {0.f, 0.f}; 
			a += {1.f, 1.f};
			string output = test_result(test_item++, "instance addition", a.x == 1.f && a.y == 1.f);
			ss << output;
		}

		{ 
			maths::vec2 a = {0.f, 0.f}; 
			a -= {1.f, 1.f};
			string output = test_result(test_item++, "instance subtraction", a.x == -1.f && a.y == -1.f);
			ss << output;
		}

		{ 
			maths::vec2 a = {2.f, 2.f}; 
			a *= 5.f;
			string output = test_result(test_item++, "instance scalar (multiply)", a.x == 10.f && a.y == 10.f);
			ss << output;
		}

		{ 
			maths::vec2 a = {10.f, 10.f}; 
			a /= 2.f;
			string output = test_result(test_item++, "instance scalar (divide)", a.x == 5.f && a.y == 5.f);
			ss << output;
		}

		{
			maths::vec2 a = {37.4f, -54.010f};
			string output = test_result(test_item++, "array data access", a[0] == 37.4f && a[1] == -54.010f);
			ss << output;
		}

		{
			maths::vec2 a = {37.4f, -54.010f};
			string output = test_result(test_item++, "proxy array access", a.x == 37.4f && a.y == -54.010f);
			ss << output;
		}

		{
			maths::vec2 a = {0.f, 0.f}; 
			maths::vec2 b = {0.f, 0.f};
			string output = test_result(test_item++, "equality (true)", a == b);
			ss << output;
		}

		{
			maths::vec2 a = {0.f, 0.f}; 
			maths::vec2 b = {39.f,-20.f};
			string output = test_result(test_item++, "equality (false)", a != b);
			ss << output;
		}
		{
			maths::vec2 a = maths::vec2{34.4f, -212.9f} + maths::vec2{-34.4f, 212.9f};
			string output = test_result(test_item++, "addition", a.x == 0.f && a.y == 0.f);
			ss << output;
		}

		{
			maths::vec2 a = maths::vec2{34.4f, -212.9f} - maths::vec2{-34.4f, 212.9f};
			string output = test_result(test_item++, "subtraction", a.x == 68.8f && a.y == -425.8f);
			ss << output;
		}

		{
			maths::vec2 a = maths::vec2{34.4f, -212.9f} * 10.f;
			string output = test_result(test_item++, "scalar (multiply)", a.x == 344.f && a.y == -2129.f);
			ss << output;
		}

		{
			maths::vec2 a = maths::vec2{34.0f, -212.0f} / 10.f;
			string output = test_result(test_item++, "scalar (divide)", a.x == 3.4f && a.y == -21.2f);
			ss << output;
		}

		std::cout << ss.str() << endl;
	}

	{ // Tests for vec3 type
		std::string test_set{"3D Vector type checks:"};
		int test_item = 0;
		stringstream ss;
		ss << test_set << endl << endl;

		{
			maths::vec3 a = {0.f, 0.f, 0.f};
			string output = test_result(test_item++, "initialise", a.x == 0.f && a.y == 0.f && a.z == 0.f);
			ss << output;
		}

		{
			maths::vec3 a = {0.f, 0.f, 0.f}; 
			a += {1.f, 1.f, 1.f};
			string output = test_result(test_item++, "instance addition", a.x == 1.f && a.y == 1.f && a.z == 1.f);
			ss << output;
		}

		{
			maths::vec3 a = {0.f, 0.f, 0.f}; 
			a -= {1.f, 1.f, 1.f};
			string output = test_result(test_item++, "instance subtraction", a.x == -1.f && a.y == -1.f && a.z == -1.f);
			ss << output;
		}

		{
			maths::vec3 a = {2.f, 2.f, 2.f}; 
			a *= 5.f;
			string output = test_result(test_item++, "instance scalar (multiply)", a.x == 10.f && a.y == 10.f && a.z == 10.f);
			ss << output;
		}

		{
			maths::vec3 a = {10.f, 10.f, 10.f}; 
			a /= 2.f;
			string output = test_result(test_item++, "instance scalar (divide)", a.x == 5.f && a.y == 5.f && a.z == 5.f);
			ss << output;
		}

		{
			maths::vec3 a = {37.4f, -54.010f, 3.141592f};
			string output = test_result(test_item++, "array data access", a[0] == 37.4f && a[1] == -54.010f && a[2] == 3.141592f);
			ss << output;
		}

		{
			maths::vec3 a = {37.4f, -54.010f, 3.141592f};
			string output = test_result(test_item++, "proxy array access", a.x == 37.4f && a.y == -54.010f && a.z == 3.141592f);
			ss << output;
		}

		{
			maths::vec3 a = {0.f, 0.f, 0.f}; 
			string output = test_result(test_item++, "equality (true)", a == maths::vec3{0.f, 0.f, 0.f});
			ss << output;
		}

		{
			maths::vec3 a = {0.f, 0.f, 0.f}; 
			string output = test_result(test_item++, "equality (false)", a != maths::vec3{39.f, -20.f, 2291038.f});
			ss << output;
		}

		{
			maths::vec3 a = maths::vec3{ 34.4f, -212.9f, 81.f} + maths::vec3{-34.4f,  212.9f, -81.f};
			string output = test_result(test_item++, "addition", a.x == 0.f && a.y == 0.f && a.z == 0.f);
			ss << output;
		}

		{
			maths::vec3 a = maths::vec3{ 34.4f, -212.9f,  81.f} - maths::vec3{-34.4f,  212.9f, -81.f};
			string output = test_result(test_item++, "subtraction", a.x == 68.8f && a.y == -425.8f && a.z == 162.f);
			ss << output;
		}

		{
			maths::vec3 a = maths::vec3{34.4f, -212.9f, 81.f} * 10.f;
			string output = test_result(test_item++, "scalar (multiply)", a.x == 344.f && a.y == -2129.f && a.z == 810.f);
			ss << output;
		}

		{
			maths::vec3 a = maths::vec3{34.0f, -212.0f, 81.f} / 10.f;
			string output = test_result(test_item++, "scalar (divide)", a.x == 3.4f && a.y == -21.2f && a.z == 8.1f);
			ss << output;
		}

		std::cout << ss.str() << endl;
	}

	{ // Tests for vec4 type
		std::string test_set{"4D Vector type checks:"};
		int test_item = 0;
		stringstream ss;
		ss << test_set << endl << endl;

		{
			maths::vec4 a = {0.f, 0.f, 0.f, 0.f};
			string output = test_result(test_item++, "initialise", a.x == 0.f && a.y == 0.f && a.z == 0.f && a.w == 0.f);
			ss << output;
		}

		{
			maths::vec4 a = {0.f, 0.f, 0.f, 0.f};
			a += {1.f, 1.f, 1.f, 1.f};
			string output = test_result(test_item++, "instance addition", a.x == 1.f && a.y == 1.f && a.z == 1.f && a.w == 1.f);
			ss << output;
		}

		{
			maths::vec4 a = {0.f, 0.f, 0.f, 0.f};
			a -= {1.f, 1.f, 1.f, 1.f};
			string output = test_result(test_item++, "instance subtraction", a.x == -1.f && a.y == -1.f && a.z == -1.f && a.w == -1.f);
			ss << output;
		}

		{
			maths::vec4 a = {2.f, 2.f, 2.f, 2.f};
			a *= 5.f;
			string output = test_result(test_item++, "instance scalar (multiply)", a.x == 10.f && a.y == 10.f && a.z == 10.f && a.w == 10.f);
			ss << output;
		}

		{
			maths::vec4 a = {10.f, 10.f, 10.f, 10.f};
			a /= 2.f;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
			string output = test_result(test_item++, "instance scalar (divide)", a.x == 5.f && a.y == 5.f && a.z == 5.f && a.w == 5.f);
			ss << output;
		}

		{
			maths::vec4 a = {37.4f, -54.010f, 3.141592f, 1.f};
			string output = test_result(test_item++, "array data access", a[0] == 37.4f && a[1] == -54.010f && a[2] == 3.141592f && a[3] == 1.f);
			ss << output;
		}

		{
			maths::vec4 a = {37.4f, -54.010f, 3.141592f, 1.f};
			string output = test_result(test_item++, "proxy array access", a.x == 37.4f && a.y == -54.010f && a.z == 3.141592f && a.w == 1.f);
			ss << output;
		}

		{
			maths::vec4 a = {0.f, 0.f, 0.f, 0.f};
			maths::vec4 b = {0.f, 0.f, 0.f, 0.f};
			string output = test_result(test_item++, "equality (true)", a == b);
			ss << output;
		}

		{
			maths::vec4 a = {0.f, 0.f, 0.f, 0.f};
			maths::vec4 b = {39.f, -20.f, 2291038.f, 1.f};
			string output = test_result(test_item++, "equality (false)", a != b);
			ss << output;
		}

		{
			maths::vec4 a = maths::vec4{34.4f, -212.9f,  81.f, 1.f} + maths::vec4{-34.4f,  212.9f, -81.f, -1.f};
			string output = test_result(test_item++, "addition", a.x == 0.f && a.y == 0.f && a.z == 0.f && a.w == 0.f);
			ss << output;
		}

		{
			maths::vec4 a = maths::vec4{34.4f, -212.9f,  81.f, 1.f} - maths::vec4{-34.4f,  212.9f, -81.f, -1.f};
			string output = test_result(test_item++, "subtraction", a.x == 68.8f && a.y == -425.8f && a.z == 162.f && a.w == 2.f);
			ss << output;
		}

		{
			maths::vec4 a = maths::vec4{34.4f, -212.9f, 81.f, 1.f} * 10.f;
			string output = test_result(test_item++, "scalar (multiply)", a.x == 344.f && a.y == -2129.f && a.z == 810.f && a.w == 10.f);
			ss << output;
		}

		{
			maths::vec4 a = maths::vec4{34.0f, -212.0f, 81.f, 1.f} / 10.f;
			string output = test_result(test_item++, "scalar (divide)", a.x == 3.4f && a.y == -21.2f && a.z == 8.1f && a.w == 0.1f);
			ss << output;
		}

		std::cout << ss.str() << endl;
	}

	{ // Tests for maths operations
		std::string test_set{"Math operation checks:"};
		int test_item = 0;
		stringstream ss;
		ss << test_set << endl << endl;

		{
			maths::vec3 a = maths::vec3{ 34.f, -32.f,   192.2f};
			maths::vec3 b = maths::vec3{-1.f,  -1000.f, 2.1f};
			maths::vec3 c = maths::cross_product(a, b);

			string output = test_result_debug(
				test_item++, 
				"vec3 cross product",
				{
					maths::almost_equal(c.x,  192133.f, 0.3f) && 
					maths::almost_equal(c.y, -263.6f,   0.3f) && 
				    maths::almost_equal(c.z, -34032.f,  0.3f)
				},
				c
			); ss << output;
		}

		{
			maths::vec2 a = maths::vec2{ 34.f, -32.f};
			maths::vec2 b = maths::vec2{-1.f,  -1000.f};
			float c = maths::dot_product(a, b);

			string output = test_result_debug(
				test_item++, "vec2 dot product", maths::almost_equal(c, 31966.f, 0.3f), c);
			ss << output;
		}

		{
			maths::vec3 a = maths::vec3{ 34.f, -32.f,   192.2f};
			maths::vec3 b = maths::vec3{-1.f,  -1000.f, 2.1f};
			float c = maths::dot_product(a, b);

			string output = test_result_debug(
				test_item++, "vec3 dot product", maths::almost_equal(c, 32369.6f, 0.3f), c);
			ss << output;
		}

		{
			maths::vec4 a = maths::vec4{ 34.f, -32.f,   192.2f, 47.2f};
			maths::vec4 b = maths::vec4{-1.f,  -1000.f, 2.1f,  -212.f};
			float c = maths::dot_product(a, b);

			string output = test_result_debug(
				test_item++, "vec4 dot product", maths::almost_equal(c, 22363.2f, 0.3f), c);
			ss << output;
		}

		{
			float c = maths::magnitude({34.f, -32.f});

			string output = test_result_debug(
				test_item++, "vec2 magnitude", maths::almost_equal(c, 46.6905f, 0.3f), c);
			ss << output;
		}

		{
			float c = maths::magnitude({34.f, -32.f, 192.2f});

			string output = test_result_debug(
				test_item++, "vec3 magnitude", maths::almost_equal(c, 197.79f, 0.3f), c);
			ss << output;
		}

		{
			float c = maths::magnitude({34.f, -32.f, 192.2f, 47.2f});

			string output = test_result_debug(
				test_item++, "vec4 magnitude", maths::almost_equal(c, 203.344, 0.3f), c);
			ss << output;
		}

		{
			maths::vec2 c = maths::normalise(maths::vec2{34.f, -32.f});

			string output = test_result_debug(
				test_item++, 
				"vec2 normalise",
				{
					maths::almost_equal(c.x,  0.7282f,   0.3f) &&
					maths::almost_equal(c.y, -0.685365f, 0.3f)
				}, 
				c
			);
			ss << output;
		}

		{
			maths::vec3 c = maths::normalise(maths::vec3{34.f, -32.f, 192.2f});

			string output = test_result_debug(
				test_item++,
				"vec3 normalise",
				{
					maths::almost_equal(c.x,  0.1719f,   0.3f) &&
					maths::almost_equal(c.y, -0.161788f, 0.3f) &&
				    maths::almost_equal(c.z,  0.971738f, 0.3f)
				},
				c
			);
			ss << output;
		}

		{
			maths::vec4 c = maths::normalise(maths::vec4{34.f, -32.f, 192.2f, 47.2f});

			string output = test_result_debug(
				test_item++,
				"vec4 normalise",
				{
					maths::almost_equal(c.x,  0.167205f, 0.3f) &&
					maths::almost_equal(c.y, -0.157369f, 0.3f) &&
				    maths::almost_equal(c.z,  0.945197f, 0.3f) &&
				    maths::almost_equal(c.w,  0.232119f, 0.3f)
				},
				c
			);
			ss << output;
		}

		{
			float c = maths::determinant(maths::vec2{34.f, -32.f}, maths::vec2{19.f, -23.f});

			string output = test_result_debug(
				test_item++, "vec2 determinant", maths::almost_equal(c, -174.f, 0.3f), c);
			ss << output;
		}

		{
			float a = 5.3f;
			float b = 5.4f;
			string output = test_result_debug(test_item++, "float comparison", maths::almost_equal(a, b, 0.5f), "true");
			ss << output;
		}

		{
			float c = maths::distance(maths::vec2{0.f, 0.f}, maths::vec2{-5.f, -5.f});

			string output = test_result_debug(
				test_item++, "vec2 distance", maths::almost_equal(c, 7.07107f, 0.3f), c);
			ss << output;
		}

		{ 
			/*	....B
				.../.
				../..
				./...
				A...P	*/

			maths::vec2 A = maths::vec2{0.f, 0.f};
			maths::vec2 B = maths::vec2{1.f, 1.f};

			maths::line L = {A, B};
			maths::vec2 P = {1.f, 0.f};

			bool c = maths::check_clockwise(L, P);

			string output = test_result_debug(test_item++, "check clockwise", c, "true");
			ss << output;
		}

		{
			/*	....B
				....|
				..P.|
				....|
				....A	*/

			maths::vec2 A = maths::vec2{0.f, 0.f};
			maths::vec2 B = maths::vec2{0.f, 1.f};

			maths::line L = {A, B};
			maths::vec2 P = {-0.5f, 0.5f};

			bool c = !maths::check_clockwise(L, P);

			string output = test_result_debug(test_item++, "check anti-clockwise", c, "true");
			ss << output;
		}

		{
			/*  L1	   L2
				B.......B
				.\...P./.
				..\.../..
				...\./...
				....A....	*/

			maths::vec2 A1 = maths::vec2{0.f, 0.f};
			maths::vec2 B1 = maths::vec2{-32.f, 93.f};
			maths::line L1 = {A1, B1};

			maths::vec2 A2 = maths::vec2{0.f, 0.f};
			maths::vec2 B2 = maths::vec2{32.f, 93.f};
			maths::line L2 = {A2, B2};

			maths::vec2 P = {17.5f, 63.f};

			bool b = maths::intersections::point_segment(P, L1, L2);

			string output = test_result(test_item++, "point between vectors", b == true);
			ss << output;
		}

		{
			/*  L1	   L2
				B.......B
				.\...../.
				..\.../..
				...\./.P.
				....A....	*/

			maths::vec2 A1 = maths::vec2{0.f, 0.f};
			maths::vec2 B1 = maths::vec2{-32.f, 93.f};
			maths::line L1 = {A1, B1};

			maths::vec2 A2 = maths::vec2{0.f, 0.f};
			maths::vec2 B2 = maths::vec2{32.f, 93.f};
			maths::line L2 = {A2, B2};

			maths::vec2 P = {44.5f, 63.f};

			bool b = maths::intersections::point_segment(P, L1, L2);

			string output = test_result(test_item++, "point outside vectors", b == false);
			ss << output;
		}

		{
			maths::vec2 P = {-4.5f, 4.5f};
			maths::vec2 O = {0.f, 0.f};
			bool b = maths::intersections::point_circle(P, O, 10.f);
			string output = test_result(test_item++, "point within circle", b == true);
			ss << output;
		}

		{
			maths::vec2 P = {-4.5f, 4.5f};
			maths::vec2 O = {0.f, 0.f};
			bool b = maths::intersections::point_circle(P, O, 6.f);
			string output = test_result(test_item++, "point outside circle", b == false);
			ss << output;
		}

		std::cout << ss.str() << endl;
	}

	system("pause");
	return 0;
}