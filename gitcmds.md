mkdir
cd
git init
git status
ls .git
git add.
git commit -m "<message>" //makes branch and save the changes individually to github
git log //shows all history made in the repository
git
git reset ...(memory path)//to delete above files from memory location which we can can get by "git log" command 
git restore <file name> //to get down from stage to a particular file
git stash //we can go back in the project

touch <file name> //creates a file in the directory
rm -rf <file name> //to delete the file
vi <file name> //make changes in the file
cat <file name> // shows content included in the file


        git stash pop   //get back in the stage
        git stash clear
 
 *AFTER CREATING A GIT REPOSITORY*

 git remote add origin <url of repository> //we can attach repository to our project
 git remote -v //this will show all the url's that is attach to the current directory
 git push origin master //pushes the file to git hub 


 *after forking we have to clone the repository in our system to make changes*
 git clone <url> //get all files in our system
 then we can check that by 
 cd <repository name>
 cat <file name included in that repository> //shows content in the file
 vi <file name> // can make changes
*/to escape from edit mode
 press esc button then type ":x!" and hit enter you will get out of it/*

git remote add origin <URL>  //origin means this is our url after forking
git remote add upstream <URL> //upstream is one from where we have forked it

before commit anything first and foremost we have to make a branch 
and then commit changes on that branch
git branch <give branch name> //this will create a branch
git checkout <branch name> // this will switched branch from main branch to desired branch

By the way, here's a shortcut: if you want to create a new branch AND check it out at the same time, 
you can simply type  "git checkout -b [yourbranchname]"

when we delete some file in the repository 
then we want to push it again 
then we have to force push it
****git push origin <branch name> -f *****



for every small bug, every problem create a new pull request so that it is easier to do conversation on that topic
if you resolve 10-20 bugs in only 1 pull request how difficult it would be to talk about
1 branch = 1 bug = 1 pull request
make more branches


 git remote set-url origin <URL> //to change the remote url



*SUMMARY*
mkdir
cd
git init
git clone //if repository is not personal.
git remote add origin <URL>
git remote add upstream <URL>
git remote -v
touch <file name>
git add .
git commit -m "<message>" //first and foremost commit something on main or master branch
git status
git log
git branch <enter branch name>
git checkout <branch name> //we have headed this branch, now all the commit we will do be saved in this branch
touch <file name>
git add .
git commit -m "<message>"
git push origin <branch name> //which branch do you wanna push enter that branch name
Now, Create a new pull request


