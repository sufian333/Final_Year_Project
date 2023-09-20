
#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

	geometry_msgs::Twist twist_msg;
	geometry_msgs::Twist twist_msg_rot;
	geometry_msgs::Twist twist_msg_left;
	geometry_msgs::Twist twist_msg_right;
	geometry_msgs::Twist twist_msg_neg;
	geometry_msgs::Twist twist_msg_hover;
	geometry_msgs::Twist twist_msg_up;
	std_msgs::Empty emp_msg;	
	


int main(int argc, char** argv)
{

	ROS_INFO("Flying ARdrone");
	ros::init(argc, argv,"ARDrone_test");
    ros::NodeHandle node;		
    ros::Rate loop_rate(50);
	ros::Publisher pub_empty1;
	ros::Publisher pub_empty2;
	ros::Publisher pub_empty3;
	pub_empty1 = node.advertise<std_msgs::Empty>("/ardrone_1/takeoff", 1); 
	pub_empty2 = node.advertise<std_msgs::Empty>("/ardrone_2/takeoff", 1);
	pub_empty3 = node.advertise<std_msgs::Empty>("/ardrone_3/takeoff", 1);
 	while (ros::ok()) 
 				{
				double time_start=(double)ros::Time::now().toSec();
				while ((double)ros::Time::now().toSec()< time_start+5.0) 
					pub_empty1.publish(emp_msg); 
					pub_empty2.publish(emp_msg);
					pub_empty3.publish(emp_msg);
					ros::spinOnce();
					loop_rate.sleep();
					}
				ROS_INFO("ARdrone launched");
				break;
				}

	ROS_INFO("ARdrone Test Back and Forth Starting");
	ros::init(argc, argv,"ARDrone_test");
    
	ros::Publisher pub_empty_land_1;
	ros::Publisher pub_empty_land_2;
	ros::Publisher pub_empty_land_3;
	ros::Publisher pub_twist_1;
	ros::Publisher pub_twist_2;
	ros::Publisher pub_twist_3;
	ros::Publisher pub_empty_takeoff_1;
	ros::Publisher pub_empty_takeoff_2;
	ros::Publisher pub_empty_takeoff_3;
	ros::Publisher pub_empty_reset_1;
	ros::Publisher pub_empty_reset_2;
	ros::Publisher pub_empty_reset_3;
	double start_time;
			twist_msg_hover.linear.x=0.0; 
			twist_msg_hover.linear.y=0.0;
			twist_msg_hover.linear.z=0.0;
			twist_msg_hover.angular.x=0.0; 
			twist_msg_hover.angular.y=0.0;
			twist_msg_hover.angular.z=0.0;  
//rotate message
			twist_msg_rot.linear.x=0.0; 
			twist_msg_rot.linear.y=0.0; 
			twist_msg_rot.linear.z=0.0;
			twist_msg_rot.angular.x=0.0; 
			twist_msg_rot.angular.y=0.0;
			twist_msg_rot.angular.z=0.7;
//up message
			twist_msg_up.linear.x=0.0; 
			twist_msg_up.linear.y=0.0;
			twist_msg_up.linear.z=0.0;
			twist_msg_up.angular.x=0.0; 
			twist_msg_up.angular.y=0.0;
			twist_msg_up.angular.z=0.0;
//command message
			float takeoff_time=2.0;
			float fly_time=5.0;
			float land_time=2.0;
			float kill_time =1.0;	
			float new_time=4.0;
//forward			
			twist_msg.linear.x=1.0; 
			twist_msg.linear.y=0.0; 
			twist_msg.linear.z=0.0;
			twist_msg.angular.x=0.0; 
			twist_msg.angular.y=0.0;
			twist_msg.angular.z=0.0;
//Backword
			twist_msg_neg.linear.x=-twist_msg.linear.x; 
			twist_msg_neg.linear.y=-twist_msg.linear.y;
			twist_msg_neg.linear.z=-twist_msg.linear.z;
			twist_msg_neg.angular.x=-twist_msg.angular.x; 
			twist_msg_neg.angular.y=-twist_msg.angular.y;
			twist_msg_neg.angular.z=-twist_msg.angular.z;
//left
			twist_msg_left.linear.x=0.0; 
			twist_msg_left.linear.y=1.0; 
			twist_msg_left.linear.z=0.0;
			twist_msg_left.angular.x=0.0; 
			twist_msg_left.angular.y=0.0;
			twist_msg_left.angular.z=0.0;
//Right

			twist_msg_right.linear.x=0.0; 
			twist_msg_right.linear.y=-1.0; 
			twist_msg_right.linear.z=0.0;
			twist_msg_right.angular.x=0.0; 
			twist_msg_right.angular.y=0.0;
			twist_msg_right.angular.z=0.0;
	
        pub_twist_1 = node.advertise<geometry_msgs::Twist>("/ardrone_1/cmd_vel", 1); /* Message queue length is just 1 */
	pub_empty_takeoff_1 = node.advertise<std_msgs::Empty>("/ardrone_1/takeoff", 1); /* Message queue length is just 1 */
	pub_empty_land_1 = node.advertise<std_msgs::Empty>("/ardrone_1/land", 1); /* Message queue length is just 1 */
	pub_empty_reset_1 = node.advertise<std_msgs::Empty>("/ardrone_1/reset", 1); /* Message queue length is just 1 */

	pub_twist_2 = node.advertise<geometry_msgs::Twist>("/ardrone_2/cmd_vel", 1); /* Message queue length is just 1 */
	pub_empty_takeoff_2 = node.advertise<std_msgs::Empty>("/ardrone_2/takeoff", 1); /* Message queue length is just 1 */
	pub_empty_land_2 = node.advertise<std_msgs::Empty>("/ardrone_2/land", 1); /* Message queue length is just 1 */
	pub_empty_reset_2 = node.advertise<std_msgs::Empty>("/ardrone_2/reset", 1); /* Message queue length is just 1 */

	pub_twist_3 = node.advertise<geometry_msgs::Twist>("/ardrone_3/cmd_vel", 1); /* Message queue length is just 1 */
	pub_empty_takeoff_3 = node.advertise<std_msgs::Empty>("/ardrone_3/takeoff", 1); /* Message queue length is just 1 */
	pub_empty_land_3 = node.advertise<std_msgs::Empty>("/ardrone_3/land", 1); /* Message queue length is just 1 */
	pub_empty_reset_3 = node.advertise<std_msgs::Empty>("/ardrone_3/reset", 1); /* Message queue length is just 1 */
	
	start_time =(double)ros::Time::now().toSec();	
	ROS_INFO("Starting ARdrone_test loop");

while (ros::ok()) {
		while ((double)ros::Time::now().toSec()< start_time+takeoff_time){ //takeoff
		
			pub_empty_takeoff_1.publish(emp_msg);
			pub_empty_takeoff_2.publish(emp_msg);
			pub_empty_takeoff_3.publish(emp_msg); //launches the drone
				pub_twist_1.publish(twist_msg_hover);
				pub_twist_2.publish(twist_msg_hover);
				pub_twist_3.publish(twist_msg_hover);	 //drone is flat
			ROS_INFO("Taking off");
			ros::spinOnce();
			loop_rate.sleep();
			}//while takeoff

		while  ((double)ros::Time::now().toSec()> start_time+takeoff_time+fly_time+new_time){
		
			pub_twist_1.publish(twist_msg_hover); //drone1 is flat
			pub_twist_2.publish(twist_msg_hover); //drone2 is flat
			pub_twist_3.publish(twist_msg_hover); //drone3 is flat	
			pub_empty_land_1.publish(emp_msg); //lands the drone1
			pub_empty_land_2.publish(emp_msg); //lands the drone2
			pub_empty_land_3.publish(emp_msg); //lands the drone3
			ROS_INFO("Landing");
			
					
			if ((double)ros::Time::now().toSec()> takeoff_time+start_time+fly_time+new_time+land_time+kill_time){
		
				ROS_INFO("Closing Node");
				exit(0); 	}
			ros::spinOnce();
			loop_rate.sleep();			
}//while land
		
		while ( (double)ros::Time::now().toSec()> start_time+takeoff_time && (double)ros::Time::now().toSec()< start_time+takeoff_time+fly_time){		

			if((double)ros::Time::now().toSec()< start_time+takeoff_time+fly_time/2){
			pub_twist_1.publish(twist_msg);
			pub_twist_2.publish(twist_msg);
			pub_twist_3.publish(twist_msg);
			ROS_INFO("forward");

			}//fly according to desired twist
			
			if((double)ros::Time::now().toSec()> start_time+takeoff_time+fly_time/2){
			pub_twist_1.publish(twist_msg_rot);
			pub_twist_2.publish(twist_msg_rot);
			pub_twist_3.publish(twist_msg_rot);
			ROS_INFO("left rotate");

			}//fly according to desired twist
			
			ros::spinOnce();
		loop_rate.sleep();
			}
		
	while ( (double)ros::Time::now().toSec()> start_time+takeoff_time && (double)ros::Time::now().toSec()< start_time+takeoff_time+fly_time+new_time){	
			
			if((double)ros::Time::now().toSec()< start_time+takeoff_time+fly_time+new_time/2){
			pub_twist_1.publish(twist_msg);
			pub_twist_2.publish(twist_msg);
			pub_twist_3.publish(twist_msg);
			ROS_INFO("forward");

			}//fly according to desired twist
			
			if((double)ros::Time::now().toSec()> start_time+takeoff_time+fly_time+new_time/2){
			pub_twist_1.publish(twist_msg_rot);
			pub_twist_2.publish(twist_msg_rot);
			pub_twist_3.publish(twist_msg_rot);
			ROS_INFO("left Rotate");

			}//fly according to desired twist
			
			ros::spinOnce();
		loop_rate.sleep();
			}

	ros::spinOnce();
	loop_rate.sleep();

}
}
