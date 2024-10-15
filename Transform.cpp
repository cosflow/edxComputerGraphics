// Transform.cpp: implementation of the Transform class.

#include "Transform.h"

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
	float rads =glm::radians(degrees);
	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	glm::mat3 m1(1.0f);
	glm::mat3 m2(x * x, x * y, x * z, y * x, y * y, y * z, z * x, z * y, z * z);
	glm::mat3 m3(0, z, -y, -z, 0, x, y, -x, 0);

	glm::mat3 ret = cos(rads)*m1 + (1-cos(rads))*m2 + sin(rads)*m3;
	
  return ret;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
	mat3 rotation_matrix = Transform::rotate(degrees, up);
	mat3 normal_rotation_matrix = glm::transpose(glm::inverse(rotation_matrix));
	eye = rotation_matrix * eye;
	up = normal_rotation_matrix * up;
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
	vec3 ort = glm::cross(eye, up);
	mat3 rotation_matrix = Transform::rotate(degrees, ort); // Esta matriz no tiene las mismas propiedades que la de la función ant
	mat3 normal_rotation_matrix = glm::transpose(glm::inverse(rotation_matrix)); 
	float eye_length = glm::length(eye);
	eye = rotation_matrix * eye;
	eye = glm::normalize(eye) * eye_length;
	up = normal_rotation_matrix * up;
	glm::normalize(up);
	printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", up.x, up.y, up.z, sqrt(pow(up.x, 2) + pow(up.y, 2) + pow(up.z, 2)));
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE

  // You will change this return call
  return mat4();
}

Transform::Transform()
{

}

Transform::~Transform()
{

}