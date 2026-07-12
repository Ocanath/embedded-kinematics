#include "kinematics_dual_quat.h"
#include <stdbool.h>
#include <stdio.h>

/*
A link is a node.
A joint is an edge.
*/

int init_stack_dq(stack_dual_quat_t * stack)
{
	stack->depth= 0;
	stack->num_links = STACK_DEPTH;	
	return 0;
}

int link_push_dq(stack_dual_quat_t * stack, link_dual_quat_t * node)
{
	if(stack->depth >= stack->num_links)
	{
		return -1;
	}
	stack->links[stack->depth++] = node;
	return 0;
}

link_dual_quat_t * link_pop_dq(stack_dual_quat_t * stack)
{
	if(stack->depth == 0)
	{
		return NULL;
	}
	stack->depth--;
	return stack->links[stack->depth];
}


int kin_dfs_dq(stack_dual_quat_t * stack, link_dual_quat_t * root)
{
	bool done = false;
	link_dual_quat_t * cur_link = root;
	
	printf("link %s\n", cur_link->name);

	link_push_dq(stack, cur_link);

	while(done == false)
	{
		bool nochildren = true;
		for(size_t joint_idx = 0; joint_idx < cur_link->num_joints; joint_idx++)
		{
			joint_dual_quat_t * j = &cur_link->joints[joint_idx];
			
			if(j->parent == cur_link)
			{
				printf("link %s has child: %s\n", cur_link->name, j->child->name);
				//joint points to children of the current node
				link_push_dq(stack, j->child);
				nochildren = false;
			}
			else if (j->child == cur_link)
			{
				printf("link %s has parent: %s\n", cur_link->name, j->parent);
				//this is the link that got us here
			}
			else
			{
				//error! for the joint to be in our list of joints, either the parent or the child must be connected to us. 
				//Otherwise, it is an orphaned joint!
				return -1;
			}
		}
		if(nochildren)
		{
			printf("link %s is a leaf\n", cur_link->name);
		}
		//pop?
	}

	return 0;
}
