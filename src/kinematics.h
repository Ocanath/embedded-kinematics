#ifndef KINEMATICS_H
#define KINEMATICS_H

#include <stdint.h>
#include <stddef.h>

typedef enum {JOINT_FIXED, JOINT_ROTATIONAL, JOINT_TRANSLATIONAL} joint_type_t;

typedef struct quat_f_t
{
	float a;
	float b;
	float c;
	float d;
}quat_f_t;

typedef struct vect3_t
{
	float x;
	float y;
	float z;
}vect3_t;

typedef struct link_t
{
	const char * name;	
	//add information
}link_t;

typedef struct joint_t
{
	joint_type_t type;
	link_t * parent;

	link_t * children;
	size_t num_children;

	float q;

	quat_f_t rotation;
	vect3_t translation;

}joint_t;

#endif