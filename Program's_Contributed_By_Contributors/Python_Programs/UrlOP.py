import pyshorteners as shortURL

link = input("Enter URL To Short :")

s = shortURL.Shortener()
x = (s.tinyurl.short(link))

print(f"Original URL : {link}")
print(f"Shorted URL : {x}")