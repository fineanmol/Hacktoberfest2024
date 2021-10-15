# downloadXkcd.py - Downloads every single XKCD comic.

import requests
import os
import bs4


def download_image(imageUrl):
    print("Downloading {0} ......".format(imageUrl))
    image = requests.get(imageUrl)
    image.raise_for_status()
    return image


def save_image(img_req_obj, comicUrl):
    imageFile = open(os.path.join('xkcd', os.path.basename(comicUrl)), 'wb')
    for chunks in img_req_obj.iter_content():
        imageFile.write(chunks)

    imageFile.close()


url = 'http://xkcd.com/'             # starting url
os.makedirs('xkcd', exist_ok=True)   # store comics in ./xkcd

print("Press ctrl+c to stop")

try:
    while not url.endswith("#"):
        # Download the page.
        print("Downloading {}...\n".format(url))
        comicPage = requests.get(url)
        comicPage.raise_for_status()
        # Parse the html
        soup = bs4.BeautifulSoup(comicPage.text, 'lxml')

        # the image is stored inside a div with id comic
        image = soup.select("#comic img")

        if image == []:
            print('some error occurred')

        else:
            imgSource = image[0].get('src')
            # We need to replace the // with https protocol
            imgSource = imgSource.replace("//", "https://")

        # Download the image.
        downloadedImage = download_image(imgSource)

        # Save the image to ./xkcd.
        save_image(downloadedImage,imgSource)

        # Get the Prev button's url.
        soup = bs4.BeautifulSoup(comicPage.text,'lxml')

        prevLink = soup.select('a[rel="prev"]')[0]
        url = "https://xkcd.com" + prevLink.get('href')

except Exception as e:
    print("Some error occurred....")
    print(e)
