/*********************************************************************
* Software License Agreement (BSD License)
*
*  Copyright (c) 2009, Willow Garage, Inc.
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the Willow Garage nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/

#include <sound_play/sound_play.h>
#include <unistd.h>
#include "std_msgs/String.h"


void sleepok(int t, ros::NodeHandle &nh)
{
  if (nh.ok())
	 sleep(t);
}

void sound_callback(const std_msgs::String::ConstPtr& msg)
{
 sound_play::SoundClient sc;
  ROS_INFO("---------------------------");
	if(msg->data=="start")
{
	ROS_INFO("------------start------------");
	sc.start(sound_play::SoundRequest::BACKINGUP);
        sc.playWave("/home/ljh/下载/夜的钢琴曲五.wav");
}
else if(msg->data=="stop")
{
ROS_INFO("------------stop------------");
        sc.stop(sound_play::SoundRequest::BACKINGUP);
}
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sound_play_test");

  ros::NodeHandle nh;
  sound_play::SoundClient sc;

  ros::Subscriber sub=nh.subscribe("annnoce",10,sound_callback);


  sleepok(1, nh);
  
 /* while(nh.ok())
  {
	sc.start(sound_play::SoundRequest::BACKINGUP);
        sleepok(4, nh);
        sc.stop(sound_play::SoundRequest::BACKINGUP);
  }
*/
ros::spin();


}
