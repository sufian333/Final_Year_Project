# Final_Year_Project

-------------Install Ros_indigo,Gazebo,TumSimulator-------------

" Before install ROS and GAZEBO Ubuntu, you should install UBUNTU 14.0 in your machine " 

1. Install Git

$ sudo apt-get install git
 
2. Install ROS
 you can follow the instruction how to install of ROS 
  
$ sudo apt-get update

$ sudo apt-get install ros-indigo-desktop-full

$ sudo rosdep init

$ rosdep update

$ echo "source /opt/ros/indigo/setup.bash" >> ~/.bashrc
 
$ source ~/.bashrc

$ sudo apt-get install python-rosinstall

To check and verify write command

$ roscore

3. Install -GAZEBO 	

$ sudo apt-get install ros-indigo-simulators

 

4. Install Tum Simulator
 - You can follow the instruction steps

$ mkdir -p ~/tum_simulator_ws/src

$ cd  ~/tum_simulator_ws/src

$ catkin_init_workspace

$ sudo git clone https://github.com/AutonomyLab/ardrone_autonomy.git
 
$ sudo git clone https://github.com/occomco/tum_simulator.git

$ cd ..
 
$ rosdep install --from-paths src --ignore-src --rosdistro indigo -y

$ catkin_make

$ source devel/setup.bash

->Run a simulation by executing a launch file in cvg_sim_gazebo package: 
 
$ roslaunch cvg_sim_gazebo ardrone_testworld.launch

--------------------------------------------------------------
->Download the code form the link 
->Make a folder name git 

$ cd git

$ sudo git clone https://github.com/amroygaol/AR_Drone_Example_code.git



#Creating pakage for code.

1. Open new terminal

$ cd ~/tum_simulator_ws/src

$ catkin_create_pkg script std_msgs rospy roscpp

$ cd ..

$  catkin_make

$ source devel/setup.bash

$ rospack depends script

2. copy the code file "forward.py" from git folder and paste it into the script folder. 

3. open the code and coment the line "from drone_status import DroneStatus"

4.edit the code line  " elif i<=60 : " to  " elif i<=70 : "

5. save the file and close.

$ cd ~/tum_simulator_ws/src/script

$ chmod +x forward.py

->to make sure your code is node $ls and if your code colour is green, run code

6. Open a new terminal

$ source devel/setup.bash 

$ roslaunch cvg_sim_gazebo ardrone_testworld.launch

#new terminal 

$ cd ~/tum_simulator_ws

$ source devel/setup.bash

$ rosrun script forwad.py

$ rostopic echo/ardrone/navdata

$ rostopic list

$ rostopic echo /"any name from list"

Now you are ready to simulate code.
