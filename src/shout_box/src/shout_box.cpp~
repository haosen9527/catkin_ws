#include <ros/ros.h>
#include <std_msgs/String.h>
#include <stdio.h>
#include <stdlib.h>
//#include <wiringPi.h>

void announce_callback(const std_msgs::String::ConstPtr& msg)
{   
    ROS_INFO("announce cmd:[%s]",msg->data.c_str());
    if(msg->data=="start")
    {
         ROS_INFO("announce cmd: start");
	// digitalWrite(17,HIGH);
	 system("madplay /home/ljh/下载/1-Liu.ruo.ying后来.mp3 -r &");//循环播放：参数-r
    }
    else if(msg->data=="stop")
    {
        ROS_INFO("announce cmd: stop");
	system("killall -9 madplay");
        //digitalWrite(17,LOW);
    }
    else if(msg->data=="pause")
    {
         ROS_INFO("announce cmd: pause");
	 system("killall -STOP madplay &");//利用system函数调用killall命令将madplay暂停
    }
    else if(msg->data=="recovery")
    {
	 ROS_INFO("announce cmd: recovery");
	 system("killall -CONT madplay &");//利用system函数调用killall命令恢复madplay的播放
    }
}

int main(int argc,char **argv)
{
    ros::init(argc,argv,"shout_box");
    //wiringPiSetup();
   //// wiringPiSetupSys();
	//pinMode(17,OUTPUT);
    ros::NodeHandle n;
    ros::Subscriber sub =n.subscribe("annonce",10,announce_callback);
    ros::Rate loop_rate(100);
    ros::spin();
    return 0;
}
