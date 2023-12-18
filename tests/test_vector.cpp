#include <gtest/gtest.h>

extern "C" {
#include "vector.h"
}

void expect_vec3(t_vec3 vec, double x, double y, double z) {
	const double epsilon = 0.0001;
	EXPECT_NEAR(vec.x, x, epsilon);
	EXPECT_NEAR(vec.y, y, epsilon);
	EXPECT_NEAR(vec.z, z, epsilon);
}

// constructor
TEST(VectorTest, Constructor) {
	t_vec3 vec = vec3(1, 2, 3);
	expect_vec3(vec, 1, 2, 3);
}

// zero
TEST(VectorTest, Zero) {
	t_vec3 vec = vec3_zero();
	expect_vec3(vec, 0, 0, 0);
}

// one
TEST(VectorTest, One) {
	t_vec3 vec = vec3_one();
	expect_vec3(vec, 1, 1, 1);
}

// axis_x
TEST(VectorTest, AxisX) {
	t_vec3 vec = vec3_axis_x();
	expect_vec3(vec, 1, 0, 0);
}

// axis_y
TEST(VectorTest, AxisY) {
	t_vec3 vec = vec3_axis_y();
	expect_vec3(vec, 0, 1, 0);
}

// axis_z
TEST(VectorTest, AxisZ) {
	t_vec3 vec = vec3_axis_z();
	expect_vec3(vec, 0, 0, 1);
}

// add
TEST(VectorTest, Add) {
	t_vec3 a = vec3(1, 2, 3);
	t_vec3 b = vec3(4, 5, 6);
	t_vec3 vec = vec3_add(a, b);
	expect_vec3(vec, 5, 7, 9);
}

// sub
TEST(VectorTest, Sub) {
	t_vec3 a = vec3(1, 2, 3);
	t_vec3 b = vec3(4, 5, 6);
	t_vec3 vec = vec3_sub(a, b);
	expect_vec3(vec, -3, -3, -3);
}

// cross
TEST(VectorTest, Cross) {
	t_vec3 a = vec3(1, 2, 3);
	t_vec3 b = vec3(4, 5, 6);
	t_vec3 vec = vec3_cross(a, b);
	expect_vec3(vec, -3, 6, -3);
}

// scale
TEST(VectorTest, Scale) {
	t_vec3 a = vec3(1, 2, 3);
	t_vec3 vec = vec3_scale(2, a);
	expect_vec3(vec, 2, 4, 6);
}

// scale 0
TEST(VectorTest, Scale0) {
	t_vec3 a = vec3(1, 2, 3);
	t_vec3 vec = vec3_scale(0, a);
	expect_vec3(vec, 0, 0, 0);
}

// scale -1
TEST(VectorTest, ScaleMinus1) {
	t_vec3 a = vec3(1, 2, 3);
	t_vec3 vec = vec3_scale(-1, a);
	expect_vec3(vec, -1, -2, -3);
}

// dot
TEST(VectorTest, Dot) {
	t_vec3 a = vec3(1, 2, 3);
	t_vec3 b = vec3(4, 5, 6);
	double dot = vec3_dot(a, b);
	EXPECT_EQ(dot, 32);
}

// length
TEST(VectorTest, Length) {
	t_vec3 a = vec3(1, 2, 3);
	double length = vec3_length(a);
	EXPECT_EQ(length, sqrt(14));
}

// length squared
TEST(VectorTest, LengthSquared) {
	t_vec3 a = vec3(1, 2, 3);
	double length = vec3_length_squared(a);
	EXPECT_EQ(length, 14);
}

// distance
TEST(VectorTest, Distance) {
	t_vec3 a = vec3(1, 2, 3);
	t_vec3 b = vec3(4, 5, 6);
	double distance = vec3_distance(a, b);
	EXPECT_EQ(distance, sqrt(27));
}

// angle
TEST(VectorTest, Angle) {
	t_vec3 a = vec3(1, 2, 3);
	t_vec3 b = vec3(4, 5, 6);
	t_radian angle = vec3_angle(a, b);
	EXPECT_EQ(angle, acos(32 / (sqrt(14) * sqrt(77))));
}

// rotate
TEST(VectorTest, Rotate) {
	t_vec3 a = vec3(1, 0, 0);
	t_vec3 axis = vec3(1, 1, 1);
	t_vec3 vec = vec3_rotate(a, 2 * M_PI / 3, axis);
	expect_vec3(vec, 0, 1, 0);
}

// rotate x
TEST(VectorTest, RotateX) {
	t_vec3 a = vec3(0, 1, 0);
	t_radian angle = M_PI / 6;
	t_vec3 vec = vec3_rotate_x(a, angle);
	expect_vec3(vec, 0, cos(angle), sin(angle));
}

// rotate y
TEST(VectorTest, RotateY) {
	t_vec3 a = vec3(0, 0, 1);
	t_radian angle = M_PI / 6;
	t_vec3 vec = vec3_rotate_y(a, angle);
	expect_vec3(vec, sin(angle), 0, cos(angle));
}

// rotate z
TEST(VectorTest, RotateZ) {
	t_vec3 a = vec3(1, 0, 0);
	t_radian angle = M_PI / 6;
	t_vec3 vec = vec3_rotate_z(a, angle);
	expect_vec3(vec, cos(angle), sin(angle), 0);
}

// equal
TEST(VectorTest, Equal) {
	t_vec3 a = vec3(1, 2, 3);
	t_vec3 b = vec3(1, 2, 3);
	bool equal = vec3_equal(a, b);
	EXPECT_TRUE(equal);
}

// not equal
TEST(VectorTest, NotEqual) {
	t_vec3 a = vec3(1, 2, 3);
	t_vec3 b = vec3(4, 5, 6);
	bool equal = vec3_equal(a, b);
	EXPECT_FALSE(equal);
}

// unit
TEST(VectorTest, Unit) {
	t_vec3 a = vec3(1, 1, 1);
	t_vec3 vec = vec3_unit(a);
	expect_vec3(vec, 1 / sqrt(3), 1 / sqrt(3), 1 / sqrt(3));
}

// negate
TEST(VectorTest, Negate) {
	t_vec3 a = vec3(1, 2, 3);
	t_vec3 vec = vec3_negate(a);
	expect_vec3(vec, -1, -2, -3);
}

// project
TEST(VectorTest, Project) {
	t_vec3 a = vec3(1, 2, 3);
	t_vec3 onto = vec3(1, 1, 1);
	t_vec3 vec = vec3_project(a, onto);
	expect_vec3(vec, 2, 2, 2);
}

// add 3
TEST(VectorTest, Add3) {
	t_vec3 a = vec3(1, 2, 3);
	t_vec3 b = vec3(4, 5, 6);
	t_vec3 c = vec3(7, 8, 9);
	t_vec3 vec = vec3_add_3(a, b, c);
	expect_vec3(vec, 12, 15, 18);
}

// min
TEST(VectorTest, Min) {
	t_vec3 a = vec3(1, -2, 3);
	t_vec3 b = vec3(-4, 5, -6);
	t_vec3 vec = vec3_min(a, b);
	expect_vec3(vec, -4, -2, -6);
}

// max
TEST(VectorTest, Max) {
	t_vec3 a = vec3(1, -2, 3);
	t_vec3 b = vec3(-4, 5, -6);
	t_vec3 vec = vec3_max(a, b);
	expect_vec3(vec, 1, 5, 3);
}

// clamp
TEST(VectorTest, Clamp) {
	t_vec3 a = vec3(1, -2, 3);
	t_vec3 min = vec3(-1, -1, -1);
	t_vec3 max = vec3(1, 1, 1);
	t_vec3 vec = vec3_clamp(a, min, max);
	expect_vec3(vec, 1, -1, 1);
}

// lerp
TEST(VectorTest, Lerp) {
	t_vec3 a = vec3(1, 2, 3);
	t_vec3 b = vec3(4, 5, 6);
	t_vec3 vec = vec3_lerp(a, b, 0.5);
	expect_vec3(vec, 2.5, 3.5, 4.5);
}

// lerp 0.8
TEST(VectorTest, Lerp08) {
	t_vec3 a = vec3(1, 2, 3);
	t_vec3 b = vec3(4, 5, 6);
	t_vec3 vec = vec3_lerp(a, b, 0.8);
	expect_vec3(vec, 3.4, 4.4, 5.4);
}

// slerp
TEST(VectorTest, Slerp) {
	t_vec3 a = vec3(1, 0, 0);
	t_vec3 b = vec3(0, 1, 0);
	t_vec3 vec = vec3_slerp(a, b, 0.5);
	expect_vec3(vec, M_SQRT1_2, M_SQRT1_2, 0);
}

// slerp 2/3
TEST(VectorTest, Slerp08) {
	t_vec3 a = vec3(1, 0, 0);
	t_vec3 b = vec3(0, 1, 0);
	t_vec3 vec = vec3_slerp(a, b, 2.0 / 3);
	expect_vec3(vec, 0.5, sqrt(3) / 2, 0);
}

// slerp 3d
TEST(VectorTest, Slerp3d) {
	t_vec3 a = vec3(M_SQRT1_2, M_SQRT1_2, 0);
	t_vec3 b = vec3(0, 0, 1);
	t_vec3 vec = vec3_slerp(a, b, 0.5);
	expect_vec3(vec, 0.5, 0.5, M_SQRT1_2);
}

// reflect on xy-plane
TEST(VectorTest, ReflectXY) {
	t_vec3 v = vec3(0, 0, -1);
	t_vec3 normal = vec3(0, 0, 1);
	t_vec3 vec = vec3_reflect(v, normal);
	expect_vec3(vec, 0, 0, 1);
}

// reflect on xy-plane, 2
TEST(VectorTest, ReflectXY2) {
	t_vec3 v = vec3(1, 2, -3);
	t_vec3 normal = vec3(0, 0, 1);
	t_vec3 vec = vec3_reflect(v, normal);
	expect_vec3(vec, 1 / sqrt(14), 2 / sqrt(14), 3 / sqrt(14));
}

// reflect on xz-plane
TEST(VectorTest, ReflectXZ) {
	t_vec3 v = vec3(0, -1, 0);
	t_vec3 normal = vec3(0, 1, 0);
	t_vec3 vec = vec3_reflect(v, normal);
	expect_vec3(vec, 0, 1, 0);
}

// reflect on xz-plane, 2
TEST(VectorTest, ReflectXZ2) {
	t_vec3 v = vec3(1, -2, 3);
	t_vec3 normal = vec3(0, 1, 0);
	t_vec3 vec = vec3_reflect(v, normal);
	expect_vec3(vec, 1 / sqrt(14), 2 / sqrt(14), 3 / sqrt(14));
}

// reflect on yz-plane
TEST(VectorTest, ReflectYZ) {
	t_vec3 v = vec3(-1, 0, 0);
	t_vec3 normal = vec3(1, 0, 0);
	t_vec3 vec = vec3_reflect(v, normal);
	expect_vec3(vec, 1, 0, 0);
}

// reflect on yz-plane, 2
TEST(VectorTest, ReflectYZ2) {
	t_vec3 v = vec3(-1, 2, 3);
	t_vec3 normal = vec3(1, 0, 0);
	t_vec3 vec = vec3_reflect(v, normal);
	expect_vec3(vec, 1 / sqrt(14), 2 / sqrt(14), 3 / sqrt(14));
}

// reflect complex
TEST(VectorTest, ReflectComplex) {
	t_vec3 v = vec3(2, 3, 4);
	t_vec3 normal = vec3(1, 1, 1);
	t_vec3 vec = vec3_reflect(v, normal);
	expect_vec3(vec, -4 / sqrt(29), -3 / sqrt(29), -2 / sqrt(29));
}
