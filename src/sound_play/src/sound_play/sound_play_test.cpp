#include <sound_play/sound_play.h>
#include <unistd.h>

void sleepok(int t, ros::NodeHandle &nh)
{
	if(nh.ok())
	sleep(t);
}

int main (int argc,char **argv)
{
	ros::init(argc, argv, "sound_play_test");
	ros::NodeHandle nh;
	sound_play::SoundClient sc;

	sleepok(1,nh);

	while(nh.ok())
	{
	     ROS_INFO("--------------------------------------------------");
	     //const char *str2 = "/home/ljh/下载/1-Liu.ruo.ying后来.mp3";
	     //sc.startWave(str2);
	     //sleepok(4, nh);
	     //sc.stopWave(str2);
	     ROS_INFO("--------------------------------------------------");
  	}
}
