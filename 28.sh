#!/bin/bash

# Get the current priority of the process
old_priority=$(ps -o ni= -p $$)
echo "Old priority of the process: $old_priority"

# Attempt to modify the priority using nice command
echo "Modifying priority of the process..."
nice -n -10 sleep 0

if [ $? -eq 0 ]; then
    # Get the new priority of the process
    new_priority=$(ps -o ni= -p $$)
    echo "New priority of the process: $new_priority"
else
    echo "Failed to modify priority. Permission denied."
fi
