
#include <stdint.h>
#include <stddef.h>

enum {JOINT_FIXED, JOINT_ROTATIONAL, JOINT_TRANSLATIONAL};



typedef struct link_t
{
	const char * name;	
}link_t;

typedef struct joint_t
{
	link_t * parent;

	link_t * children;
	size_t num_children;

	float q;

}joint_t;