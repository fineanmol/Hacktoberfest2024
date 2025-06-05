import subprocess

""" a fuction that will fetch and store all the wifi profiles from your pc to a list """
def get_wifi_profiles():
    """ this will fetch all the profiles of wifi that are being stored in your pc """
    wifi_meta_data = subprocess.check_output(['netsh','wlan','show','profiles'])
    wifi_data = wifi_meta_data.decode('utf-8')
    wifi_data = wifi_data.split('\n')

    """ this part will help us to store the profiles name in a list """
    wifi_profiles = []
    for line in wifi_data:
        if "All User Profile     : " in line :
            wifi = line.split(':')[1]
            wifi_profiles.append(wifi[1:-1])
    return wifi_profiles

print('\n'+"***** FETCHING SUCCESSFULL *****" +'\n')
""" this will fetch the password for a all the profiles """
for wifi_names in get_wifi_profiles():
    wifiP_meta_data = subprocess.check_output(['netsh','wlan','show','profile',wifi_names,'key=clear'])
    wifiP_data = wifiP_meta_data.decode('utf-8',errors='backslashreplace')
    wifiP_data = wifiP_data.split('\n')
    wifi_password = []
    
    for wifi_password in wifiP_data:
        if "Key Content            :" in wifi_password:
            wifi_password = wifi_password.split(':')[1]
            print(wifi_names,":",wifi_password)
