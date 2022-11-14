import whois

import dns.resolver

import shodan

import requests

import argparse

import socket

argparse = argparse.ArgumentParser(description="This is a basic information gathering tool.",

                                   usage="python3 info_gathering.py -d DOMAIN [-s IP]")

argparse.add_argument("-d", "--domain", help="Enter the domain name for footprinting.", required=True)

argparse.add_argument("-s", "--shodan", help="Enter the IP  for Shodan search.")

argparse.add_argument("-o", "--output", help="Enter the file name to save the output.")

args = argparse.parse_args()

domain = args.domain

ip = args.shodan

output = args.output

# Whois module

print("[+] Getting whois info.....")

whois_result = ''

# using whois library,creating instances

try:

    py = whois.query(domain)

    print("[+] Whois info found.")

    whois_result += "Name: {}".format(py.name) + '\n'

    whois_result += "Registrar: {} ".format(py.registrar + '\n')

    whois_result += "Creation Date: {} ".format(py.creation_date + '\n')

    whois_result += "Expiry Date: {} ".format(py.expiration_date + '\n')

    whois_result += "Registrant: {}".format(py.registrant + '\n')

    whois_result += "Registrant Country: {}".format(py.registrant_country) + '\n'

except:

    print("Whois not found")

# Dns module

print("[+] Getting DNS info...")

dns_result = ''

# implementation of dns.resolver from dnspython

try:

    for a in dns.resolver.resolve(domain, 'A'):

        dns_result += "[+] A Record: {}".format(a.to_text()) + '\n'

    for ns in dns.resolver.resolve(domain, 'NS'):

        dns_result += "[+] NS Record: {}".format(ns.to_text()) + '\n'

    for mx in dns.resolver.resolve(domain, 'MX'):

        dns_result += "[+] MX Record: {}".format(mx.to_text()) + '\n'

    for txt in dns.resolver.resolve(domain, 'TXT'):

        dns_result += "[+] TXT Record: {}".format(txt.to_text()) + '\n'

except:

    print("[-] DNS")

# Geolocation module

print("[+] Getting geolocation info.....")

geo_result = ''

# implementing for web request

try:

    response = requests.Request('GET', "https://geolocation-db.com/json/" + socket.gethostname(domain)).json()

    geo_result += "[+] Country: {}".format(response['country_name']) + '\n'

    geo_result += "[+] Latitude: {}".format(response['latitude']) + '\n'

    geo_result += "[+] Longitude: {}".format(response['longitude']) + '\n'

    geo_result += "[+] City: {}".format(response['city']) + '\n'

    geo_result += "[+] State: {}".format(response['state']) + '\n'

except:

    pass

# shodan module

if ip:

    print("[+] Getting info from Shodan for IP {} ".format(ip))

    # shodan api

    api = shodan.Shodan("XwgRirBNBMwIyNjmllYnbtFXywjnHnar")

    try:

        results = api.search(ip)

        print("[+] Results found : {}".format(results['total']))

        for result in results['matches']:

            print("[+] Ip : {}".format(result['ip_str']))

            print("[+] Data : \n {} ".format(result['data']))

            print()

    except:

        print("[-] Shodan search error.")

if output:

    with open(output, 'w') as file:

        file.write(whois_result + '\n\n')

        file.write(dns_result + '\n\n')
