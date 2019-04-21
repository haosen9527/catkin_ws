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
	  sc.say("Hello world!");
     sleepok(2, nh);
 
     const char *str1 = "I am annoying.";
     sc.repeat(str1);
     sleepok(4, nh);
     sc.stopSaying(str1);
 
     sc.playWave("/home/ljh/catkin_ws/src/sound_play/sounds/NEEDS_UNPLUGGING_BADLY.ogg");
     sleepok(2, nh);
 
     const char *str2 = "/home/ljh/catkin_ws/src/sound_play/sounds/NEEDS_UNPLUGGING_BADLY.ogg";
     sc.startWave(str2);
     sleepok(4, nh);
     sc.stopWave(str2);
 
     sc.play(sound_play::SoundRequest::NEEDS_UNPLUGGING);
     sleepok(2, nh);
 
     sc.start(sound_play::SoundRequest::BACKINGUP);
     sleepok(4, nh);
     sc.stop(sound_play::SoundRequest::BACKINGUP);
 
                 sleepok(2, nh);
                 sound_play::Sound s1 = sc.waveSound("/home/ljh/catkin_ws/src/sound_play/sounds/NEEDS_UNPLUGGING_BADLY.ogg");
                 s1.repeat();
                 sleepok(1, nh);
                 s1.stop();
                 
                 sleepok(2, nh);
                 sound_play::Sound s2 = sc.voiceSound("This is a really long sentence that will get cut off.");
                 s2.play();
                 sleepok(1, nh);
                 s2.stop();
 
                 sleepok(2, nh);
                 sound_play::Sound s3 = sc.builtinSound(sound_play::SoundRequest::NEEDS_UNPLUGGING_BADLY);
                 s3.play();
                 sleepok(1, nh);
                 s3.stop();
 
                 sleepok(2, nh);
                 sound_play::Sound s4 = sc.waveSoundFromPkg("sound_play", "sounds/BACKINGUP.ogg");
                 s4.play();
                 sleepok(1, nh);
                 s4.stop();
   }
	}
