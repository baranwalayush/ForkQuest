<!-- this script is hardcoded to use the folder it is running and file name is hardcoded; 
	> make this to take arguments from commandline one for path and one for file name -->

# Backup Automation — README
## Overview
This script automates the backup of specified files and directories by copying them to a designated backup location.

## CLI usage (example)
python3 main.py 

## Expected Behavior
When executed, the script will create a backup of the specified file or directory in the designated backup location, appending the current date to the backup folder name for easy identification.

File name, source path and backup location should be specified as command line arguments.
python3 main.py "main.py" "D:/source/path/" "D:/backup/location/"