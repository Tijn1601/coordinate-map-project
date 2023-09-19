# Coordinate Map Project
## Description:
This project uses custom classes to create a linked list of coordinates on a map. With these coordinates, the total area of all the coordinates when connected can be calculated. It is also possible to find the corresponding driver given the total area or to print out the total area given the driver's name.

## Usage:
When running the program you will need to input the file name for the routes, and after that, you will need to input the file name for the commands that will be executed. For example, "sample_routes.txt sample_commands.txt" will load the names and coordinates on "sample_routes.txt", and then will execute the commands on "sample_commands.txt". Each command in the commands file must be separated with a new line. See "sample_commands.txt" for reference.

## Commands:
Sort name asc - sorts the list of names and areas by name in ascending alphabetical order

Sort name des - sorts the list of names and areas by name in descending alphabetical order

Sort area asc - sorts the list of names and areas by name in ascending order of area size

Sort area des - sorts the list of names and areas by name in descending order of area size

When the name of a driver or an area is given as a command, the console will output the name of the driver along with its corresponding area. If the name or area does not exist in the file with commands, the console will print out that it does not exist.
