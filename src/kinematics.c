#include "kinematics.h"
#include <stdbool.h>


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