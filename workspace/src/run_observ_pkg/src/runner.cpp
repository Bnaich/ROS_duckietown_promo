#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

 int main(int argc, char **argv)
{
	ros::init(argc, argv, "runner");
  	
	ros::NodeHandle n; 
	ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/runner/cmd_vel", 1000);
	
	ros::Rate loop_rate(1);
	for(int t = 0; t < 30; t++)
	{
		geometry_msgs::Twist pos;
		pos.linear.x = 1.5;
		pos.linear.y = t * t;
		pos.linear.z = sin(t);
		pos.angular.x = std::abs(2*cos(0.5*t));
		pos.angular.y = std::abs(2*sin(2.5*t));
		pos.angular.z = std::abs(2*cos(1.5*t));

		ROS_INFO("Move to position:\n"
			 "1) pos.linear: x=%f y=%f z=%f\n"
			 "2) pos.angular: x=%f y=%f z=%f\n",
			 pos.linear.x, pos.linear.y, pos.linear.z,
			 pos.angular.x, pos.angular.y, pos.angular.z);
		pub.publish(pos);
		loop_rate.sleep();
	}
	ros::spinOnce();
	return 0;
}
