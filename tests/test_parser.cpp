#include <gtest/gtest.h>

extern "C" {
#include "config.h"
}

void expect_vec3(t_vec3 vec, double x, double y, double z) {
	const double epsilon = 0.0001;
	EXPECT_NEAR(vec.x, x, epsilon);
	EXPECT_NEAR(vec.y, y, epsilon);
	EXPECT_NEAR(vec.z, z, epsilon);
}

// parse_uint, normal
TEST(ConfigTest, ParseUint) {
	EXPECT_EQ(parse_uint("123"), 123);
}

// parse_uint, zero
TEST(ConfigTest, ParseUintZero) {
	EXPECT_EQ(parse_uint("0"), 0);
}

// parse_uint, max
TEST(ConfigTest, ParseUintMax) {
	EXPECT_EQ(parse_uint("4294967295"), 4294967295);
}

// parse_uint, overflow
// expect exit
TEST(ConfigTest, ParseUintOverflow) {
	EXPECT_EXIT(parse_uint("4294967296"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_uint, negative
// expect exit
TEST(ConfigTest, ParseUintNegative) {
	EXPECT_EXIT(parse_uint("-1"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_uint, sign
// expect exit
TEST(ConfigTest, ParseUintSign) {
	EXPECT_EXIT(parse_uint("+1"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_uint, sign
// expect exit
TEST(ConfigTest, ParseUintSign2) {
	EXPECT_EXIT(parse_uint("+-1"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_uint, dot
// expect exit
TEST(ConfigTest, ParseUintDot) {
	EXPECT_EXIT(parse_uint("1.2"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_uint, non-numeric
// expect exit
TEST(ConfigTest, ParseUintNonNumeric) {
	EXPECT_EXIT(parse_uint("a"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_uint, empty
// expect exit
TEST(ConfigTest, ParseUintEmpty) {
	EXPECT_EXIT(parse_uint(""), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_uint, space
// expect exit
TEST(ConfigTest, ParseUintSpace) {
	EXPECT_EXIT(parse_uint(" "), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_uint, with space
// expect exit
TEST(ConfigTest, ParseUintWithSpace) {
	EXPECT_EXIT(parse_uint("1 "), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_uint, with space
// expect exit
TEST(ConfigTest, ParseUintWithSpace2) {
	EXPECT_EXIT(parse_uint(" 1"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_uint, with space
// expect exit
TEST(ConfigTest, ParseUintWithSpace3) {
	EXPECT_EXIT(parse_uint("1 2"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_double, normal
TEST(ConfigTest, ParseDouble) {
	EXPECT_DOUBLE_EQ(parse_double("123.4"), 123.4);
}

// parse_double, negative
TEST(ConfigTest, ParseDoubleNegative) {
	EXPECT_DOUBLE_EQ(parse_double("-123.4"), -123.4);
}

// parse_double, zero
TEST(ConfigTest, ParseDoubleZero) {
	EXPECT_DOUBLE_EQ(parse_double("0"), 0);
}

// parse_double, start with zero
TEST(ConfigTest, ParseDoubleStartWithZero) {
	EXPECT_DOUBLE_EQ(parse_double("0.123"), 0.123);
}

// parse_double, start with dot
TEST(ConfigTest, ParseDoubleStartWithDot) {
	EXPECT_DOUBLE_EQ(parse_double(".123"), 0.123);
}

// parse_double, empty
// expect exit
TEST(ConfigTest, ParseDoubleEmpty) {
	EXPECT_EXIT(parse_double(""), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_double, space
// expect exit
TEST(ConfigTest, ParseDoubleSpace) {
	EXPECT_EXIT(parse_double(" "), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_double, with space
// expect exit
TEST(ConfigTest, ParseDoubleWithSpace) {
	EXPECT_EXIT(parse_double("1.2 "), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_double, with space
// expect exit
TEST(ConfigTest, ParseDoubleWithSpace2) {
	EXPECT_EXIT(parse_double(" 1.2"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_double, with space
// expect exit
TEST(ConfigTest, ParseDoubleWithSpace3) {
	EXPECT_EXIT(parse_double("1. 2"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_double, non-numeric
// expect exit
TEST(ConfigTest, ParseDoubleNonNumeric) {
	EXPECT_EXIT(parse_double("a"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_double, sign
// expect exit
TEST(ConfigTest, ParseDoubleSign) {
	EXPECT_EXIT(parse_double("+1.2"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_double, sign
// expect exit
TEST(ConfigTest, ParseDoubleSign2) {
	EXPECT_EXIT(parse_double("+-1.2"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_vec3, normal
TEST(ConfigTest, ParseVec3) {
	t_vec3 vec = parse_vec3("1.2,3.4,5.6");
	expect_vec3(vec, 1.2, 3.4, 5.6);
}

// parse_vec3, negative
TEST(ConfigTest, ParseVec3Negative) {
	t_vec3 vec = parse_vec3("-1.2,-3.4,-5.6");
	expect_vec3(vec, -1.2, -3.4, -5.6);
}

// parse_vec3, extra space
// expect exit
TEST(ConfigTest, ParseVec3ExtraSpace) {
	EXPECT_EXIT(parse_vec3("1.2, 3.4, 5.6"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_vec3, extra comma
// expect exit
TEST(ConfigTest, ParseVec3ExtraComma) {
	EXPECT_EXIT(parse_vec3("1.2,,3.4,5.6"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_vec3, missing comma
// expect exit
TEST(ConfigTest, ParseVec3MissingComma) {
	EXPECT_EXIT(parse_vec3("1.2,3.4 5.6"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_vec3, missing value
// expect exit
TEST(ConfigTest, ParseVec3MissingValue) {
	EXPECT_EXIT(parse_vec3("1.2,3.4,"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_vec3, empty
// expect exit
TEST(ConfigTest, ParseVec3Empty) {
	EXPECT_EXIT(parse_vec3(""), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_vec3, space
// expect exit
TEST(ConfigTest, ParseVec3Space) {
	EXPECT_EXIT(parse_vec3(" "), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_rgb, normal
TEST(ConfigTest, ParseRgb) {
	t_rgb rgb = parse_rgb("1,2,3");
	expect_vec3(rgb, 1, 2, 3);
}

// parse_rgb, max
TEST(ConfigTest, ParseRgbMax) {
	t_rgb rgb = parse_rgb("255,255,255");
	expect_vec3(rgb, 255, 255, 255);
}

// parse_rgb, zero
TEST(ConfigTest, ParseRgbZero) {
	t_rgb rgb = parse_rgb("0,0,0");
	expect_vec3(rgb, 0, 0, 0);
}

// parse_rgb, negative
// expect exit
TEST(ConfigTest, ParseRgbNegative) {
	EXPECT_EXIT(parse_rgb("-1,2,3"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_rgb, out of range
// expect exit
TEST(ConfigTest, ParseRgbOutOfRange) {
	EXPECT_EXIT(parse_rgb("256,2,3"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_rgb, extra space
// expect exit
TEST(ConfigTest, ParseRgbExtraSpace) {
	EXPECT_EXIT(parse_rgb("1, 2, 3"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_rgb, extra comma
// expect exit
TEST(ConfigTest, ParseRgbExtraComma) {
	EXPECT_EXIT(parse_rgb("1,,2,3"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_rgb, missing comma
// expect exit
TEST(ConfigTest, ParseRgbMissingComma) {
	EXPECT_EXIT(parse_rgb("1,2 3"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_rgb, missing value
// expect exit
TEST(ConfigTest, ParseRgbMissingValue) {
	EXPECT_EXIT(parse_rgb("1,2,"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_ambient, normal
TEST(ConfigTest, ParseAmbient) {
	auto line = "A  0.2  255,255,255";
	auto ambient = parse_ambient(line);
	EXPECT_DOUBLE_EQ(ambient.ratio, 0.2);
	expect_vec3(ambient.color, 255, 255, 255);
}

// parse_ambient, missing ratio
// expect exit
TEST(ConfigTest, ParseAmbientMissingRatio) {
	EXPECT_EXIT(parse_ambient("A 255,255,255"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_ambient, missing color
// expect exit
TEST(ConfigTest, ParseAmbientMissingColor) {
	EXPECT_EXIT(parse_ambient("A 0.2"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_camera
TEST(ConfigTest, ParseCamera) {
	auto line = "C  -50,0,20  0,0,0  70";
	auto camera = parse_camera(line);
	expect_vec3(camera.position, -50, 0, 20);
	expect_vec3(camera.orientation, 0, 0, 0);
	EXPECT_DOUBLE_EQ(camera.fov, 70);
}

// parse_camera, missing position
// expect exit
TEST(ConfigTest, ParseCameraMissingPosition) {
	EXPECT_EXIT(parse_camera("C 0,0,0 70"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_camera, missing fov
// expect exit
TEST(ConfigTest, ParseCameraMissingFov) {
	EXPECT_EXIT(parse_camera("C 0,0,0 0,0,0"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_light
TEST(ConfigTest, ParseLight) {
	auto line = "L  -40,0,30  0.7  255,255,255";
	auto light = parse_light(line);
	expect_vec3(light.position, -40, 0, 30);
	EXPECT_DOUBLE_EQ(light.brightness, 0.7);
	expect_vec3(light.color, 255, 255, 255);
}

// parse_light, missing position
// expect exit
TEST(ConfigTest, ParseLightMissingPosition) {
	EXPECT_EXIT(parse_light("L 0.7 255,255,255"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_light, missing brightness
// expect exit
TEST(ConfigTest, ParseLightMissingBrightness) {
	EXPECT_EXIT(parse_light("L 0,0,0 255,255,255"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_light, missing color
// expect exit
TEST(ConfigTest, ParseLightMissingColor) {
	EXPECT_EXIT(parse_light("L 0,0,0 0.7"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_sphere
TEST(ConfigTest, ParseSphere) {
	auto line = "sp  -30,0,40  20  255,255,255";
	auto sphere = parse_sphere(line);
	expect_vec3(sphere.center, -30, 0, 40);
	EXPECT_DOUBLE_EQ(sphere.diameter, 20);
	expect_vec3(sphere.color, 255, 255, 255);
}

// parse_sphere, missing center
// expect exit
TEST(ConfigTest, ParseSphereMissingCenter) {
	EXPECT_EXIT(parse_sphere("sp 20 255,255,255"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_sphere, missing diameter
// expect exit
TEST(ConfigTest, ParseSphereMissingDiameter) {
	EXPECT_EXIT(parse_sphere("sp 0,0,0 255,255,255"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_sphere, missing color
// expect exit
TEST(ConfigTest, ParseSphereMissingColor) {
	EXPECT_EXIT(parse_sphere("sp 0,0,0 20"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_plane
TEST(ConfigTest, ParsePlane) {
	auto line = "pl  0,1,0  0,0,0  255,255,255";
	auto plane = parse_plane(line);
	expect_vec3(plane.point, 0, 1, 0);
	expect_vec3(plane.normal, 0, 0, 0);
	expect_vec3(plane.color, 255, 255, 255);
}

// parse_plane, missing point
// expect exit
TEST(ConfigTest, ParsePlaneMissingPoint) {
	EXPECT_EXIT(parse_plane("pl 0,0,0 255,255,255"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_plane, missing color
// expect exit
TEST(ConfigTest, ParsePlaneMissingColor) {
	EXPECT_EXIT(parse_plane("pl 0,0,0 0,0,0"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_cylinder
TEST(ConfigTest, ParseCylinder) {
	auto line = "cy  50.0,0.0,20.6  0,0,1.0  14.2  21.42  10,0,255";
	auto cylinder = parse_cylinder(line);
	expect_vec3(cylinder.center, 50.0, 0.0, 20.6);
	expect_vec3(cylinder.axis, 0, 0, 1.0);
	EXPECT_DOUBLE_EQ(cylinder.diameter, 14.2);
	EXPECT_DOUBLE_EQ(cylinder.height, 21.42);
	expect_vec3(cylinder.color, 10, 0, 255);
}

// parse_cylinder, missing center
// expect exit
TEST(ConfigTest, ParseCylinderMissingCenter) {
	EXPECT_EXIT(parse_cylinder("cy 0,0,0 0,0,1.0 14.2 21.42 10,0,255"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR),
				"");
}

// parse_cylinder, missing diameter
// expect exit
TEST(ConfigTest, ParseCylinderMissingDiameter) {
	EXPECT_EXIT(parse_cylinder("cy 0,0,0 0,0,1.0 21.42 10,0,255"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}

// parse_cylinder, missing color
// expect exit
TEST(ConfigTest, ParseCylinderMissingColor) {
	EXPECT_EXIT(parse_cylinder("cy 0,0,0 0,0,1.0 14.2 21.42"), ::testing::ExitedWithCode(EXIT_PARSE_ERROR), "");
}
