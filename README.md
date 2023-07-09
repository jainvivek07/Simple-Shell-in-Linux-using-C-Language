# Simple-Assembler-Simulator
Created a simple shell using C language which handles some of the terminal commands and gives the output accordingly.

Name: Vivek Jain
Roll no.: 2021218
OS assignment 1
_____________________________________________________________________________________________________________________________________________________________________
This writeup describes the working of my code.

To run the code just type "make" and then "./vivek21218.out"

the commands that can be executed using this code are: 
1)echo
2)cat
3)ls
4)date
5)mkdir
6)cd
7)rm
8)pwd

these command work like the commands we give to terminal and output is also similar.

the options that my code can take are: 
1)echo:
	a) echo * : It lists all the files and directories (like ls command).

	b) echo -e: It prints all the input strings without any spaces. {echo -e vivek jain with give output vivekjain}

2)cat:
	a) cat -n : It prints the content of the file along with line number for each line.

	b) cat -e : It prints $ sign at the end of each line of the file

3)ls:
	a) ls -m : It at lists all the files and directories separated by comma.

	b) ls -1 : It lists all the files and directories in a new line.

4)date:
	a) date -d : it prints the current date in the format dd/mm/yy

	b) date -t : it prints the current time in the format hh:mm:ss

5)mkdir:
	a) mkdir -p : It creates parent directory if they don't exist.

	b) mkdir -v : It gives a confirmation message when a directory is successfully created.

6)cd:
	a) cd / : It changes the directory to root directory

	b) cd ~ : It changes the directory to home directory

7)rm:
	a) rm -d : It removes the empty directories

	b) rm -v : It gives confirmation when it removes a file.


how to use these commands (syntax):

echo <anything you want to output>
echo *
echo -e <anything you want as output>

cat file(s)
cat -n file(s)
cat -e file(s)

ls
ls -m
ls -1

date
date -d
date -t

mkdir <directory name(s)>
mkdir -p <direcotry path> : eg: mkdir -p one/two/three 
mkdir -v <directory name(s)>

cd <directory name> {.. to go to parent directory}
cd /
cd ~
cd also works if you give complete path : eg: cd /home/kern/work

rm <file name(s)>
rm -d <directory name(s)>
rm -v <file name(s)>

pwd

assumption: max length a command can have is 1024
assumption2: no two flags will be executed together {you can not do rm -d -v <directory name>}
assumption3: cat command cannot take directory as argument

Some test cases to check code can be:


echo vivek jain 2021218
echo *
echo -e vivek jain 2021218

cat a1.txt a2.txt
cat -n a1.txt a2.txt
cat -e a1.txt a2.txt

ls
ls -m
ls -1

date
date -d
date -t

mkdir one
mkdir -p one/two/three/four 
mkdir -v one two three

cd one
cd ..
cd /
cd ~
cd /home/kern/work/OS_A1/os1	{this gets to current directory in my system}

rm a1.txt
rm -d two three
rm -v a2.txt

pwd


finally to exit the code you can type "exit"
_____________________________________________________________________________________________________________________________________________________________________
