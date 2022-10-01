# Dictionary Attack in GMail

> 1. Dictionary/Brute Force Attack can be performed using this script  
> 2. SMTP is used to connect over TLS
> 3. No need to install any module/package  
> 4. Just need mail id of the target & a password list file  


# Working

1. Just provide 2 inputs:
   1. mail id of target
   2. password recovery list inside a txt file
2. The script will perform the attack & tell which credential is correct in console  


# Modules used

1. ```import smtplib```
2. ```from past.builtins import raw_input```


# Limitations

1. Will not work for 2-F auth enabled accounts
2. Change your proxy before hitting gmail 100 times else your IP will be blocked


# Author


|                                                                                                                                                                                                         <a href="https://nitin-kr.onrender.com/"><img src="https://github.com/nitinkumar30/nitscv/blob/main/image/nitin-1.jpg" width="150px " height="150px" /></a>                                                                                                                                                                                                          |
|:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|
|                                                                                                                                                                                                                                                                 **[Nitin Kumar](https://nitin-kr.onrender.com/)**                                                                                                                                                                                                                                                                  |
| <a href="https://twitter.com/nitinkumar30"><img src="https://raw.githubusercontent.com/vinitshahdeo/Water-Monitoring-System/master/assets/twitter.png" width="32px" height="32px"></a> <a href="https://www.facebook.com/b1AcK6AG16"><img src="https://raw.githubusercontent.com/vinitshahdeo/Water-Monitoring-System/master/assets/facebook.png" width="32px" height="32px"></a> <a href="https://www.linkedin.com/in/nitin30kumar/"><img src="https://raw.githubusercontent.com/vinitshahdeo/Water-Monitoring-System/master/assets/linkedin.png" width="32px" height="32px"></a> |