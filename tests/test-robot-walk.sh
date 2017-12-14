#!/bin/sh

ROBOT_COUNT=$1
POINT_COUNT=1000
UI_ENABLED=0
UI_SPEED=0
LOG_ENABLED=0
MAKE=make
ROBOT_WALK=./robot-walk
UI_ENABLED=0
UI_SPEED=0

cd ../src

echo "Modifying configs"

echo "Changing robot count..."
sed -i 's/#define\ ROBOT_COUNT.*/#define\ ROBOT_COUNT\ '$ROBOT_COUNT'/g' configs.hh 

echo "Ensuring point count..."
sed -i 's/#define\ POINT_COUNT.*/#define\ POINT_COUNT\ '$POINT_COUNT'/g' configs.hh

echo "Disabling Logging..."
sed -i 's/#define\ LOG_ENABLED.*/#define\ LOG_ENABLED\ '$LOG_ENABLED'/g' configs.hh

echo "Enabling UI..."

sed -i 's/#define\ UI_ENABLED.*/#define\ UI_ENABLED\ '$UI_ENABLED'/g' configs.hh

echo "Enabling UI Speed..."
sed -i 's/#define\ UI_SPEED.*/#define\ UI_SPEED\ '$UI_SPEED'/g' configs.hh

if [ -z $2 ] || [ "$2" != "-b" ]; then
	echo "Skipping build..."
else
	$MAKE
fi
$ROBOT_WALK
