from bs4 import BeautifulSoup
import cloudscraper
import urllib.parse

url = input("Enter a URL:")  #Enter HTPMovies URL of the type /exit.php?id=


def htpmovies(url):
    client = cloudscraper.create_scraper(allow_brotli=False)
    url = url.replace("exit", "go")
    download = client.get(url, stream=True, allow_redirects=False)
    xurl = download.headers["location"]
    p = urllib.parse.urlparse(xurl)
    final_url = f"{p.scheme}://{p.netloc}/links/go"
    res = client.head(xurl)
    header_loc = res.headers["location"]
    param = xurl.split("/")[-1]
    req_url = f"{p.scheme}://{p.netloc}/{param}"
    p = urllib.parse.urlparse(header_loc)
    ref_url = f"{p.scheme}://{p.netloc}/"
    h = {"referer": ref_url}
    res = client.get(req_url, headers=h, allow_redirects=False)
    bs4 = BeautifulSoup(res.content, "html.parser")
    inputs = bs4.find_all("input")
    data = {input.get("name"): input.get("value") for input in inputs}
    h = {
        "referer": ref_url,
        "x-requested-with": "XMLHttpRequest",
    }
    time.sleep(10)
    res = client.post(final_url, headers=h, data=data)
    return res.json()["url"].replace("\/", "/")

print(htpmovies(url=url))
