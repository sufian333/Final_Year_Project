# ARDrone-Examples
Fixed examples from the University of Utah and some original programs for the Parrot ARDrone
-- 
Add these programs to your package inside catkin_ws/src 

You must modify your CMakeList to include the new files as executables 

add_executable(leds leds.cpp)
target_link_libraries(leds ${catkin_LIBRARIES})
add_executable(takeoff takeoff.cpp)
target_link_libraries(takeoff ${catkin_LIBRARIES})
add_executable(back_and_forth back_and_forth.cpp)
target_link_libraries(back_and_forth ${catkin_LIBRARIES})
add_executable(land land.cpp)
target_link_libraries(land ${catkin_LIBRARIES})
add_executable(camera camera.cpp)
target_link_libraries(camera ${catkin_LIBRARIES})

https://docs.google.com/document/d/1mZd2uy9QR2VdocuNvm8ew6fOoYHpK0A43sTOf9aav_o/edit?usp=sharing
