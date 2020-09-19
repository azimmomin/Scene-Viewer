// Transform.cpp: implementation of the Transform class.

// Note: when you construct a matrix using mat4() or mat3(), it will be COLUMN-MAJOR
// Keep this in mind in readfile.cpp and display.cpp
// See FAQ for more details or if you're having problems.

#include "Transform.h"

// Helper rotation function.  Please implement this.  
mat3 Transform::rotate(const float degrees, const vec3& axis)
{
    // Initialze result as the idenity matrix.
    mat3 result(1.0f);

    // Initialize rotation in radians and dual matrix of the axis.
    float radians = glm::radians(degrees);
    mat3 dualMatrix(
        0, axis.z, -axis.y,
        -axis.z, 0, axis.x,
        axis.y, -axis.x, 0
    );

    // Add in perpendicular component
    result += (glm::sin(radians) * dualMatrix);

    // Add in parallel component.
    result += ((1 - glm::cos(radians)) * (dualMatrix * dualMatrix));

    return result;
}

void Transform::left(float degrees, vec3& eye, vec3& up)
{
    mat3 rotation = rotate(degrees, glm::normalize(up));
    eye = rotation * eye;
}

void Transform::up(float degrees, vec3& eye, vec3& up)
{
    vec3 axis = glm::normalize(glm::cross(eye, up));
    mat3 rotation = rotate(degrees, axis);
    eye = rotation * eye;
    up = rotation * up;
}

mat4 Transform::lookAt(const vec3& eye, const vec3& center, const vec3& up)
{
    vec3 forward = glm::normalize(-eye);
    vec3 right = glm::normalize(glm::cross(forward, up));
    vec3 newUp = glm::cross(right, forward);

    return mat4(
        right.x, newUp.x, -forward.x, 0,
        right.y, newUp.y, -forward.y, 0,
        right.z, newUp.z, -forward.z, 0,
        -glm::dot(right, eye), -glm::dot(newUp, eye), glm::dot(forward, eye), 1
    );
}

mat4 Transform::perspective(float fovy, float aspect, float zNear, float zFar)
{
    mat4 ret;
    // YOUR CODE FOR HW2 HERE
    // New, to implement the perspective transform as well.  
    return ret;
}

mat4 Transform::scale(const float& sx, const float& sy, const float& sz)
{
    mat4 ret;
    // YOUR CODE FOR HW2 HERE
    // Implement scaling 
    return ret;
}

mat4 Transform::translate(const float& tx, const float& ty, const float& tz)
{
    mat4 ret;
    // YOUR CODE FOR HW2 HERE
    // Implement translation 
    return ret;
}

// To normalize the up direction and construct a coordinate frame.  
// As discussed in the lecture.  May be relevant to create a properly 
// orthogonal and normalized up. 
// This function is provided as a helper, in case you want to use it. 
// Using this function (in readfile.cpp or display.cpp) is optional.  

vec3 Transform::upvector(const vec3& up, const vec3& zvec)
{
    vec3 x = glm::cross(up, zvec);
    vec3 y = glm::cross(zvec, x);
    vec3 ret = glm::normalize(y);
    return ret;
}


Transform::Transform()
{

}

Transform::~Transform()
{

}
