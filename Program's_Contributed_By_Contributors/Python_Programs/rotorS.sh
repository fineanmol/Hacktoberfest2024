 #!/bin/bash

# Dependencies 

sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu `lsb_release -sc` main" > /etc/apt/sources.list.d/ros-latest.list'
wget http://packages.ros.org/ros.key -O - | sudo apt-key add -
sudo apt-get update
sudo apt-get install ros-melodic-desktop-full ros-melodic-joy ros-melodic-octomap-ros ros-melodic-mavlink python-wstool python-catkin-tools protobuf-compiler libgoogle-glog-dev ros-melodic-control-toolbox ros-melodic-mavros
sudo rosdep init
rosdep update
source /opt/ros/melodic/setup.bash

# setting up the Simulation 
# Run " roslaunch rotors_gazebo mav_hovering_example.launch mav_name:=firefly world_name:=basic " to verify 

mkdir -p ~/hex_ws/src
cd ~/hex_ws/src
catkin_init_workspace
wstool init
wget https://raw.githubusercontent.com/ethz-asl/rotors_simulator/master/rotors_hil.rosinstall
wstool merge rotors_hil.rosinstall
wstool update
cd

# setting up basic drone control 
# Run " rosrun rotors_joy_interface key_joystick.py " to verify

git clone git@github.com:devbharat/python-uinput.git
cd python-uinput
python setup.py build
sudo python setup.py install
pip install pygame
pip install python-uinput
modprobe -i uinput
cd udev-rules
sudo cp 40-uinput.rules /etc/udev/rules.d
sudo addgroup uinput
sudo adduser $USER uinput

cd ~/hex_ws/src
git clone git@github.com:ethz-asl/rotors_simulator.git
git clone git@github.com:ethz-asl/mav_comm.git

cd ~/hex_ws/src/rotors_simulator/
git reset --hard ac77a8a

cd ~/hex_ws/
catkin build
echo "source ~/hex_ws/devel/setup.bash" >> ~/.bashrc
source ~/.bashrc
echo "

Run the command :-

roslaunch rotors_gazebo mav_with_keyboard.launch "

echo " Thank you :) " 



