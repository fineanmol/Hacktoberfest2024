'''

Create on Sun Apr 31 19:00 2020
@author : Rivas Frits Sasia

'''

#Import Module
from colorama import Fore, Back, Style
from datetime import datetime
from os import system, name
import urllib
import json

#Color
RED = Fore.RED
WHITE = Fore.WHITE
YELLOW = Fore.YELLOW
GREEN = Fore.GREEN
CYAN = Fore.CYAN
BLUE = Fore.BLUE


#Detect OS and Clear Terminal
if name == 'posix':
    _ = system('clear')
elif name == 'nt':
    _ = system('cls')

#Header
print "    " + RED +   "  ______   ______     ____    ____      __    ___       __  .__   __.  _______  "
print "    " + RED +   " /       | /  __  \  \   \  /   /     /_ |  / _ \     |  | |  \ |  | |       \  "
print "    " + RED +   " |  ,----'|  |  |  |  \   \/   / ______| | | (_) |    |  | |   \|  | |  .--.  | "
print "    " + WHITE + " |  |     |  |  |  |   \      / |______| |  \__, |    |  | |  . `  | |  |  |  | "
print "    " + WHITE + " |  `----.|  `--'  |    \    /         | |    / /     |  | |  |\   | |  '--'  | "
print "    " + WHITE + "  \______| \______/      \__/          |_|   /_/      |__| |__| \__| |_______/  "
print "    " + GREEN + "                              TRACKING COVID-19                                 "
print "    " + RED +   "                            Country  : "+ WHITE +" Indonesia                     "
print "    " + GREEN + "                           Author    : Frits Sasia                             "

api = "https://coronavirus-19-api.herokuapp.com/countries/Indonesia" # API public
link_json = urllib.urlopen(api) # Mengakses API
status_code = link_json.getcode() # Mendapatkan response/status code

if status_code == 200: # if else
    data = json.loads(link_json.read()) # Membaca data berformat JSON, dari API
else:
    print RED+"ERROR"


now = datetime.now() # Waktu Sekarang
day = now.day #Tanggal
mounth = now.month # Bulan
year = now.year # Tahun
hour = now.hour # Jam
minute = now.minute # Menit
second = now.second # Detik

print ""
print GREEN+"Berikut Data Terbaru Tentang Perkembangan"+RED+" COVID-19"+WHITE+" Di Indonesia : "
print GREEN+"Tanggal & Waktu {}-{}-{}  {}:{}:{}".format(day, mounth, year, hour, minute, second) # Informasi Tanggal dan Waktu
print ""

# Fetching dan menampilkan data dari JSON
print GREEN+"Negara\t\t\t\t: %s" % data['country']
print YELLOW+"Kasus Hari Ini\t\t\t: %s" % data['todayCases'] + str(' Orang')
print RED+"Kematian Hari Ini\t\t: %s" % data['todayDeaths'] + str(' Orang')
print GREEN+"Sembuh\t\t\t\t: %s" % data['recovered'] + str(' Orang')
print YELLOW+"Total Kasus\t\t\t: %s" % data['cases'] + str(' Orang')
print RED+"Total Kematian\t\t\t: %s" % data['deaths'] + str(' Orang')
print ""
print GREEN+"Jangan panik, stay safe"+RED+" #TetapDi"+WHITE+"rumahAja "+GREEN+"dan jaga kesehatan kamu yaa :)"
