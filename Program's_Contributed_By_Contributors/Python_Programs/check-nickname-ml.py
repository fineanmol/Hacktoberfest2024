import json, requests


print("Cek Nickname ML menggunakan Python")
print("================================")
nomorid= input("Masukkan Nomor ID : ")
nomorserver = input("Masukkan nomor Server: ")
print("================================")
print("Nomor ID: ", nomorid)
print("Nomor Server: ", nomorserver)
print("================================")

url = "https://www.smile.one/merchant/mobilelegends/checkrole"

payload={'user_id': nomorid,
'zone_id': nomorserver}

response = requests.request("POST", url, data=payload,)

nicname = json.loads(response.text)
print("Nickname Anda Adalah : " + nicname['username'])


