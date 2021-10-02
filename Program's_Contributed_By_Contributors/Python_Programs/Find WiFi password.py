import subprocess

names = subprocess.Popen("netsh wlan show profiles", shell=True, stdout=subprocess.PIPE)
names_return = names.stdout.read()
print(names_return.decode('utf-8')[118:])

def start():
    global netname, sub, sub_return, index
    netname = input('Type network name: ')
    sub = subprocess.Popen("netsh wlan show profiles \""+ netname +"\" key=clear", shell=True, stdout=subprocess.PIPE)
    sub_return = sub.stdout.read()
    index = sub_return.decode('utf-8').find('Key Content')

    if netname != 'exit':
        if "is not found on the system" in sub_return.decode('utf-8'):
            print('WiFi name invalid')
        else:
            if not index == -1:
                print('Password: ', end = '')
                print((sub_return.decode('utf-8')[index+25:]).split()[0])
            else:
                print('Password not found!')

        print()
        start()

start()
