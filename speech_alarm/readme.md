# Alarm using speech recognition

## Steps to set an alarm : 
1. run the script `AlarmClock.py` using python3.  
    On Unix based systems the command looks like : 
    ```bash
    python3 Alarm.py
    ```
    or
    ```bash
    python Alarm.py
    ```

2. After execution of the script you will be prompted to say the time to set an alarm in HH:MM format. Which looks something as shown below : 
    ```
    say "set alarm for (for eg)5:30am"
    ``

3. Then you will get a looping output of the current time and set time on the CLI as shown below : 
    ```
    set alarm for 5:30am
    
4. When the alarm goes off you will __hear a sound__ and get the following lines on the prompt :
    ```
    Time to Wake up
   
    ```