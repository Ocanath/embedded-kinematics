#include "kinematics.h"
#include <stdbool.h>

typedef struct joint_stack_t
{
	joint_dual_quat_t * joints;
	size_t num_joints;
}joint_stack_t;


int joint_pop(joint_stack_t * stack)
{

}

int joint_push(joint_dual_quat_t * stack)
{

}


int kin_dfs_dq(link_dual_quat_t * root)
{
	bool done = false;
	while(done == false)
	{
		for(size_t joint_idx = 0; joint_idx < root->num_joints; joint_idx++)
		{
			joint_dual_quat_t * j = &root->joints[joint_idx];
			if(j->child == NULL)
			{

			}
		}
	}
}