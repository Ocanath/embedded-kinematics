#include "unity.h"
#include "kinematics_dual_quat.h"

//declarations of joints
joint_dual_quat_t j1_2;
joint_dual_quat_t j2_3;
joint_dual_quat_t j3_4;
joint_dual_quat_t j3_5;
joint_dual_quat_t j3_6;
joint_dual_quat_t j1_7;
joint_dual_quat_t j7_8;
joint_dual_quat_t j8_9;
joint_dual_quat_t j8_10;
joint_dual_quat_t j8_11;

//provide link connection to each edge
joint_dual_quat_t * l1_joints[] = {&j1_2, &j1_7};
link_dual_quat_t link_1 = 
{
	.name = "link 1",
	.joints = l1_joints,
	.num_joints = sizeof(l1_joints)/sizeof(joint_dual_quat_t *)
};

joint_dual_quat_t * l2_joints[] = {&j1_2, &j2_3};
link_dual_quat_t link_2 = 
{
	.name = "link 2",
	.joints = l2_joints,
	.num_joints = sizeof(l2_joints)/sizeof(joint_dual_quat_t*)
};

joint_dual_quat_t * l3_joints[] = {&j2_3, &j3_4, &j3_5, &j3_6};
link_dual_quat_t link_3 = 
{
	.name = "link 3",
	.joints = l3_joints,
	.num_joints = sizeof(l3_joints)/sizeof(joint_dual_quat_t*)
};

joint_dual_quat_t * l4_joints[] = {&j3_4};
link_dual_quat_t link_4 = 
{
	.name = "link 4",
	.joints = l4_joints,
	.num_joints = sizeof(l4_joints)/sizeof(joint_dual_quat_t*)
};

joint_dual_quat_t * l5_joints[] = {&j3_5};
link_dual_quat_t link_5 = 
{
	.name = "link 5",
	.joints = l5_joints,
	.num_joints = sizeof(l5_joints)/sizeof(joint_dual_quat_t*)
};

joint_dual_quat_t * l6_joints[] = {&j3_6};
link_dual_quat_t link_6 = 
{
	.name = "link 6",
	.joints = l6_joints,
	.num_joints = sizeof(l6_joints)/sizeof(joint_dual_quat_t*)
};

joint_dual_quat_t * l7_joints[] = {&j1_7};
link_dual_quat_t link_7;

joint_dual_quat_t * l8_joints[] = {};
link_dual_quat_t link_8;

joint_dual_quat_t * l9_joints[] = {};
link_dual_quat_t link_9;

joint_dual_quat_t * l10_joints[] = {};
link_dual_quat_t link_10;

joint_dual_quat_t * l11_joints[] = {};
link_dual_quat_t link_11;



joint_dual_quat_t j1_2 = 
{
	.name = "j1_2",
	.type = JOINT_ROTATIONAL,
	.parent = &link_1,
	.child = &link_2,
	.q = 0,
	.axis = {},
	.offset = {},
	.dof = {},
	.result = {},
};

joint_dual_quat_t j2_3 = 
{
	.name = "j2_3",
	.type = JOINT_ROTATIONAL,
	.parent = &link_2,
	.child = &link_3,
	.q = 0,
	.axis = {},
	.offset = {},
	.dof = {},
	.result = {},
};

joint_dual_quat_t j3_4 = 
{
	.name = "j3_4",
	.type = JOINT_ROTATIONAL,
	.parent = &link_3,
	.child = &link_4,
	.q = 0,
	.axis = {},
	.offset = {},
	.dof = {},
	.result = {},
};

joint_dual_quat_t j3_5 = 
{
	.name = "j3_5",
	.type = JOINT_ROTATIONAL,
	.parent = &link_3,
	.child = &link_5,
	.q = 0,
	.axis = {},
	.offset = {},
	.dof = {},
	.result = {},
};

joint_dual_quat_t j3_6 = 
{
	.name = "j3_6",
	.type = JOINT_ROTATIONAL,
	.parent = &link_3,
	.child = &link_6,
	.q = 0,
	.axis = {},
	.offset = {},
	.dof = {},
	.result = {},
};

joint_dual_quat_t j1_7 = 
{
	.name = "j1_7",
	.type = JOINT_ROTATIONAL,
	.parent = &link_1,
	.child = &link_7,
	.q = 0,
	.axis = {},
	.offset = {},
	.dof = {},
	.result = {},
};

joint_dual_quat_t j7_8 = 
{
	.name = "j7_8",
	.type = JOINT_ROTATIONAL,
	.parent = &link_7,
	.child = &link_8,
	.q = 0,
	.axis = {},
	.offset = {},
	.dof = {},
	.result = {},
};

joint_dual_quat_t j8_9 = 
{
	.name = "j8_9",
	.type = JOINT_ROTATIONAL,
	.parent = &link_8,
	.child = &link_9,
	.q = 0,
	.axis = {},
	.offset = {},
	.dof = {},
	.result = {},
};

joint_dual_quat_t j8_10 = 
{
	.name = "j8_10",
	.type = JOINT_ROTATIONAL,
	.parent = &link_8,
	.child = &link_10,
	.q = 0,
	.axis = {},
	.offset = {},
	.dof = {},
	.result = {},
};

joint_dual_quat_t j8_11 = 
{
	.name = "j8_11",
	.type = JOINT_ROTATIONAL,
	.parent = &link_8,
	.child = &link_11,
	.q = 0,
	.axis = {},
	.offset = {},
	.dof = {},
	.result = {},
};


void test_dfs(void)
{

}