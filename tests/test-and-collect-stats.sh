#!/bin/sh

ROBOT_COUNT=$1
RUN_COUNT=$2

cd ../src/

echo "Changing robot count..."
sed -i 's/#define\ ROBOT_COUNT.*/#define\ ROBOT_COUNT\ '$ROBOT_COUNT'/g' configs.hh 

echo "Running test with $ROBOT_COUNT robots $RUN_COUNT times.."

ROBOT_WALK=./robot-walk
for i in `seq 1 $RUN_COUNT`; do
	$ROBOT_WALK && sleep 1
done
