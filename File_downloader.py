import requests


def download_file_from_google_drive(id, destination):
    URL = "https://docs.google.com/uc?export=download"

    session = requests.Session()

    response = session.get(URL, params = { 'id' : id }, stream = True)
    token = get_confirm_token(response)

    if token:
        params = { 'id' : id, 'confirm' : token }
        response = session.get(URL, params = params, stream = True)

    save_response_content(response, destination)    

def get_confirm_token(response):
    for key, value in response.cookies.items():
        if key.startswith('download_warning'):
            return value

    return None

def save_response_content(response, destination):
    CHUNK_SIZE = 32768

    with open(destination, "wb") as f:
        for chunk in response.iter_content(CHUNK_SIZE):
            if chunk: # filter out keep-alive new chunks
                f.write(chunk)

if __name__ == "__main__":
    import os
    file_id = '1GHNLH3CM_0tkJha_IuR_kVWtw6NroT5Q'
    path = os.path.join(os.getcwd(), 'offer2.jpeg')  # path of pdf
    destination = path
    download_file_from_google_drive(file_id, destination)

from google_drive_downloader import GoogleDriveDownloader as gdd
import os
path = os.path.join(os.getcwd(), 'offer2.jpeg')  # path of pdf
gdd.download_file_from_google_drive(file_id='1GHNLH3CM_0tkJha_IuR_kVWtw6NroT5Q',
                                    dest_path=path)
