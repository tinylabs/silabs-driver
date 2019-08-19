#
# Root cmake file for silabs drivers
#
cmake_minimum_required( VERSION 3.2 )
cmake_policy( VERSION "3.2" )

# This path must point to LeOS install
set( LEOS_ROOT /opt/leos )
set( CMAKE_MODULE_PATH ${LEOS_ROOT}/share/cmake )
set( CMAKE_TOOLCHAIN_FILE LeOS-Toolchain )

# Create project
project( silabs-driver )
include( UseLeOS )

# Add targets here...
add_subdirectory( gecko )

# Add testing target
leos_check ()
