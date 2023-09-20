
// GTRI ATAS Program for Camera Toggling
//This code send the camera's live feed to the pc on execution



#include <cstdlib>
#include "ros/ros.h"

int main(int argc, char **argv)
{
	
using namespace std;
  
system( "rosrun rqt_image_view rqt_image_view image:=/ardrone_1/front/image_raw" );




}
