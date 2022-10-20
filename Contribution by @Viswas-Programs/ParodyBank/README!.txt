NOTE: THIS PROGRAM IS NOT CURRENTLY UPDATED ANYMORE, SO USING THIS PROGRAM IS NOT RECOMMMENDED AT ALL FOR ANY CAUSES UNLESS ABSOLUTELY NEEDED!

DOCUMENTATION:->
    This program is a basic banking program written completely in Python with
    shelves. This will and should within Windows and linux computers, the app
    will work as it uses both OS module and the platform module to identify.
    this one logs every action in the program with the logger() function to
    the respective users' home directory. that uses the pytz module so that 
    it can log at which time the particular action has happened. this also 
    encrypts the password and account number with standard base64 encoding.
    -account.__init__(self, name, password, balance)
        The constructor for the class that the program is using. uses the
        __init__ constructor to construct. and also, it calls the logger()
        function to log when the program started up.
        this doesn't use __new__ at all!
    -account.Deposit(self, amount, userName)
        Deposits the "amount" to "userName". it checks whether "userName" is a
        child account or a normal account. if it's a child account, the balance
        limit comes into action at max about 5000 INR. and can't deposit more
        than 2000 INR when it's a child account. normal account is unrestricted.
    -account.Withdraw(self, total, username)
        Withdraws the "total" to "username". it checks whether "username" is a
        child account or a normal account. if it's a child account, the balance
        limit comes into action at max about 5000 INR. and can't withdraw more
        than 2000 INR when it's a child account. normal account is unrestricted.
    -account.Transfer(self, username, amount)
        Transfers the "amount" to "username". it checks where "username" is a
        child account or a normal account. if it's a child account, the balance
        limit comes into action at max about 5000 INR. and can't transfer more
        than 2000 INR when it's a child account. normal account is unrestricted.
    -account.FD(self, principle, rate, time)
        Fixed deposit with the principle of "principle" and the rate of interest
        is "rate" and the time is "time". this uses compound interest and no
        simple interest at all! it checks whether the balance in your account
        and the bank balance is more than "principle" and if it is (why
        wouldn't it?), it successfully logs it to the shelves, the "principle"
    -account.__str__(self)
        The _-str__ method, to print the homepage whenever a transaction has
        happened, any for the matter. so that it doesn't require manual print
        lines and also, no need of shrinking information as the FD feature
        requires extra info to be displayed that's not a single line.


PRE-REQUISITES:->
    These program require the following modules-
    -pytz
    -shelve
    -platform
    -shelve
    -datetime
    -base64
    -getpass
    And also, for this to work, you at the least need to have python 3.5 or more
    as this uses advanced functions. python 2 is completely different, so won't
    work with python 2 at all.
    This also needs to be running on a terminal for the os modules' actions to
    take action.
    This also, needs to have popular OSes, and won't support obscure bootlegs
    or any other obscure OSes, you name it!


FEEDBACK:->
    You can either send me a personal email, or make a pull request in GitHub.
    I will respond to you within a week or so.
    The email to contact me is "viswas.anand@outlook.com" or
    "viswas.vijay2009@gmail.com"


UPDATE LIFECYCLE:->
    The normal versions will be supported that was newer than a month old.
    versions that are more than a month old, will not be getting ANY updates.
    the latest version will get ALL updates, and the previous versions will get
    some features from the new release.
    The major releases, which are a multiple of 5, receive support from the DEV
    stage. so it depends upon how many days its in DEV channel. and also, they
    have support for 1.5 months (1 and half months). so using the major versions
    can be classified as using the LTS version, except these are the major ones.

    -EOL CHART:->
        v1:
          START: 19/04/2022
          END: 19/05/2022
        v2:
          START:20/04/2022
          END:20/05/2022
        v3:
          START:21/04/2022
          END:21/05/2022
        v4:
          START:22/04/2022
          END:22/05/2022
        v5:
          START:23/04/2022
          END:07/06/2022
	v6:
	  START:25/05/2022
	  END:24/06/2022

STABLE FEATURES:->
    Transfer, Withdraw, Logger, Deposit, Loans, FD, GUI

UNSTABLE FEATURES:->
    MacOS compatibility, SQL(STILL IN DEV! DON'T USE!)


UPDATE CHANGELOGS:->

The v1 changelogs. (was updated last on 20\4\2022.)
Changelog-
*Adds password system, child accounts, transfer of money, and also withdraw and
 deposit.
*this program now has a coexist program which will create the users and their
 very essentials
*this program now is portable within Windows computers running Vista or later as
 it's using the Public user instead of my own user.
*More modularity as if the child accounts control variables are changed, they
 change everywhere where the child accounts can use(which is everything for now)
*(29/4/2022) ADDED BASE64 ENCRYPTION!
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
The v2 changelog! (updated in 20\04\2022 at approximately 22:30-23:30)
Changelog - 
*Changed the withdrawal maximum from 100 to 2000 to make it convenient. (!fixed)
*Added a validation check where when given loan from the db program, it checks
 whether the account specified is a child or a normal account and if it was
 child, then 3000 was the max loan money that the child could request.
*Fixed a bug where after paying back the loan, the "account.balance"
 method wouldn't update but only the shelf was updated.
*Fixed a bug where when deleting users, it wouldn't delete the permissions of
 the user like a Normal or a child account, and it would stay back.
*changed the print statement after deleting users to tell you how many users was
 deleted after the deletion process
*of course, changed the logging to _bank_log_v2.txt
*updated documentation for the logging function both in v1 and v2
*(29/4/2022) ADDED BASE64 ENCRYPTION!
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
The v3 changelog (program update in 21/04/2022)
Changelog-
*Added a function to set up accounts and delete accounts in the DB program, so
 manual setup is not required.
*added a __str__() method where it prints out the things without manual print
 lines.
*Started to log at when the program started, and also, when exiting, it logs
 when it exited
*fixed a probable issue where we didn't close the account permission shelve
 in the main program.
*updated the error message in child account withdrawal system where it would
 print out the wrong error message when exceeding the maximum withdrawal amount
 set in kidWithdrawMax
*Updated the title in program so that it's easier to differentiate between
 versions of programs when running simultaneously.
*(29/4/2022) ADDED BASE64 ENCRYPTION!
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
The v4 update (program update in 22/04/2022)
Changelog-
*Using the OS module and using environment variables to use shelves and logging,
 and now It's cross-platform across windows and linux!
*Changed the shelves' directory from Public user to the respective user's
 documents\bank accounts essentials folder
*in the logger() function, now it has a check if the file is readable, writable
 and if not any of those or none of those, it will raise a PermissionError()
*Fixed the output string in the __str__ method
*when using a console, after every action in the account, it will clear the
 terminal and show you only the __str__, and the options.
*(29/4/2022) ADDED BASE64 ENCRYPTION!

NOTE: FOR THIS UPDATE TO WORK, YOU NEED TO CREATE THE USER, AS IT'S USING A
DIFFERENT PATH AND YOU NEED TO RUN THIS IN A TERMINAL FOR THE SCREEN CLEAR TO
WORK! AND ALSO, WHEN IN A DIFFERENT COMPUTER, PLEASE RUN THE DB PROGRAM FIRST!
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
The v5 [DEV BUILD 4858] Changelogs- (Development started at 23/04/2022)
*A new FD feature that allows you to pick from Months or Years, and has options
 for 1, 5, 10 years or months.
*Fixed a fatal flaw in which the else clause isn't needed and repeatedly crashed
 the program when calling the logger() function.
*Fixed a major bug where we can deposit or withdraw or transfer amounts in
 negative numbers, resulting in free money (minus of minus is plus).
*Mixed the feature of setupAccount() and delAccount() into setupAccount() with a
 new parameter called "mode" to handle deletion and addition of users to the db.
*Added a parameter in the new setupAccount() function of fd so that we don't
 need to worry about a non-initialized object that's called and resulting in an
 error.
*Fixed a major flaw with the cross compatibility when it detects as a non
 Windows OS, it still defaulted to backslash instead of the UNIX-Style
 fronts-lash.
*Shrunk some line of code by defining a variable for the path of the files
 needed, and the shelves opening will be containing the path variable, and the
 shelves name with it (example = shelve.open(f"{path}\\bankMoney").)
*Fixed a cross-compatibility issue where even if it's a UNIX based one, the
 command to clear the screen was hardcoded and used the NT command. now it's a
 dynamic variable. it uses "cls" if it's NT, and uses "clear" if UNIX(based).

The v5 [DEV BUILD 4932] Changelog
*Changed the FD feature to use CI and implemented with a formula instead of a
 for-loop.
*Added a print statement in the db program after it created and deleted users in
 the function itself rather than in the program.

The v5 [DEV BUILD 4999] Changelog
*Added a os.system(clearScreen) after logging in.
*Added an "update reminder" system where it checks the date of the time, and if
 it passes  the EOL date, that version of the program will give you warning.
*Now added a try except clause, where when the user is exiting with
 KeyboardInterrupt or  in IDEs, clicking the force stop button, it now logs that
 error.

The v5 RTM CHANGELOG!-
*The all of the above features have been implemented from the
*Added basic base64_standard encoding to the password, so that, it won't be easy
 to crack passwords, it requires base64 decoding! (but who doesn't know how to
 decode   them? haha. this is a niche feature BTW :D)
*When in the __str__() method, the password is not shown with the 'b' prefix as
 it denotes it as a bytes object. so when displaying, bytes is converted to str.

The v5 DEV BUILD 5043 CHANGELOG!- (update on 29/04/2022)
*Used the getpass module to not show passwords while typing in te input field.
 this has been added to the pre-requisites.

The v6 [DEV BUILD 5762] Changelog!-
*Transformation to GUI from CLI., using raw tkinter 8.6
NOTE:-> This build is based on v5 build 5043, not 5062, which is the newer one.

The v6 [DEV BUILD 5876] Changelog!-
*Transferred the PayBack loan system from CLI to GUI.
*Implemented a frame so that the buttons will be a bit closer together
*Added a backwards compatibility feature where if they check a box in login, it
 will use base64.standard_b64decode, which enables them to use older accounts
 from older versions
(UPDATE FROM 28-05-2022)->
START:
*Transformed the errors to a GUI, error box, so that it's
 consistent. while some tracebacks still will come in the console.
*Made the values a floating point integer. so that transactions in Paise can be
 made available to customers.
