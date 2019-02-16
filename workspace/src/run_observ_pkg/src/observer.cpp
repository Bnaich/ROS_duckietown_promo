#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

void recieve(const geometry_msgs::Twist& movement)
{
	ROS_INFO("Got:\n"
		"1) pos.linear: x= %f y = %f z = %f\n"
		"2) pos.angular: x =%f y = %f z = %f\n",
		movement.linear.x, movement.linear.y, movement.linear.z,
		movement.angular.x, movement.angular.y, movement.angular.z);
	return; 
}
 int main(int argc, char **argv)
{
	ros::init(argc, argv, "observer");
  	
	ros::NodeHandle n; 
	ros::Subscriber sub = n.subscribe("/runner/cmd_vel", 1000, recieve);
	ros::spin();
	return 0;
}
