#include "maths.h"

namespace maths {
	bool almost_equal(float x, float y, float error_factor) {
		float diff = std::abs(x - y);
		return diff < error_factor;
	}

	bool check_clockwise(const line& l, const vec2& p) {
		float d = ((p.x - l.a.x) * (l.b.y - l.a.y)) - ((p.y - l.a.y) * (l.b.x - l.a.x));
		return d > 0;
	}

	bool check_anticlockwise(const line& l, const vec2& p) {
		return !check_clockwise(l, p);
	}

	vec3 cross_product(const vec3& a, const vec3& b) {
		return {
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		};
	}

	float determinant(const vec2& a, const vec2& b) {
		return (a.x * b.y) - (a.y * b.x);
	}

	float distance(const vec2& a, const vec2& b) {
		return sqrt(
			(a.x - b.x) * (a.x - b.x) +
			(a.y - b.y) * (a.y - b.y)
		);
	}

	float distance(const vec3& a, const vec3& b) {
		return sqrt(
			(a.x - b.x) * (a.x - b.x) +
			(a.y - b.y) * (a.y - b.y) +
			(a.z - b.z) * (a.z - b.z)
		);
	}

	float distance(const vec4& a, const vec4& b) {
		return sqrt(
			(a.x - b.x) * (a.x - b.x) +
			(a.y - b.y) * (a.y - b.y) +
			(a.z - b.z) * (a.z - b.z) +
			(a.w - b.w) * (a.w - b.w)
		);
	}

	float dot_product(const vec2& a, const vec2& b) { 
		return (a.x * b.x) + (a.y * b.y); 
	}

	float dot_product(const vec3& a, const vec3& b) { 
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z); 
	}

	float dot_product(const vec4& a, const vec4& b) { 
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w); 
	}

	float magnitude(const vec2& v) { 
		return sqrt(v.x * v.x + v.y * v.y); 
	}

	float magnitude(const vec3& v) { 
		return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); 
	}

	float magnitude(const vec4& v) { 
		return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w); 
	}

	vec2 normalise(const vec2& v) { 
		return (v == vec2{0.f}) ? v : v / magnitude(v); 
	}

	vec3 normalise(const vec3& v) { 
		return (v == vec3{0.f}) ? v : v / magnitude(v); 
	}

	vec4 normalise(const vec4& v) { 
		return (v == vec4{0.f}) ? v : v / magnitude(v); 
	}

	mat4 orthographic_matrix(const vec2& resolution, float nZ, float fZ, mat4 m) {
		m.x.x =  2.f / resolution.x;
		m.y.y =  2.f / resolution.y;
		m.z.z = -2.f / (fZ - nZ);

		m.w.x = -resolution.x / resolution.x;
		m.w.y = -resolution.y / resolution.y;
		m.w.z = -(fZ + nZ) / (fZ - nZ);
		return m;
	}

	namespace intersections {
		bool point_circle(const vec2& P, const vec2& o, float r) {
			float d = distance(o, P);
			return d < r;
		}


		bool point_segment(const vec2& P, const line& L1, const line& L2) {
			float r = magnitude(L1.a - L1.b);

			bool b1 = point_circle(P, L1.a, r);
			bool b2 = maths::check_clockwise(L1, P);
			bool b3 = maths::check_anticlockwise(L2, P);

			return b1 && b2 && b3;
		}
	}
}

