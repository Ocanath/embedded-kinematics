#include "kinematics_dual_quat.h"
#include <stdbool.h>

#include <stdio.h>

#define STACK_DEPTH 256	//adjust as needed

/*
A link is a node.
A joint is an edge.
*/

typedef struct link_stack_t
{
	link_dual_quat_t * links[STACK_DEPTH];
	size_t num_links;
	size_t depth;
}link_stack_t;

int init_stack(link_stack_t * stack)
{
	stack->depth= 0;
	stack->num_links = STACK_DEPTH;	
	return 0;
}

int link_push(link_stack_t * stack, link_dual_quat_t * node)
{
	if(stack->depth >= stack->num_links)
	{
		return -1;
	}
	stack->links[stack->depth++] = node;
	return 0;
}

link_dual_quat_t * link_pop(link_stack_t * stack)
{
	if(stack->depth == 0)
	{
		return NULL;
	}
	stack->depth--;
	return stack->links[stack->depth];
}


int kin_dfs_dq(link_stack_t * stack, link_dual_quat_t * root)
{
	bool done = false;
	link_dual_quat_t * cur_link = root;
	
	printf("link %s\n", cur_link->name);

	link_push(stack, cur_link);

	while(done == false)
	{
		if(cur_link->num_joints == 0)
		{
			//we've hit a terminal node. we have to pop something 
		}
		for(size_t joint_idx = 0; joint_idx < cur_link->num_joints; joint_idx++)
		{
			joint_dual_quat_t * j = &root->joints[joint_idx];
			
			if(j->parent == cur_link)
			{
				/*
					We need to use the result of the parent edge (H0_i) to compute the outgoing edges.
				*/
				printf("Parent joint: %s\n", j->name);
			}

		}
	}
}