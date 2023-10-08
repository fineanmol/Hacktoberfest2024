import spotipy
from spotipy.oauth2 import SpotifyClientCredentials

# Replace these with your actual Spotify API credentials
client_id = ""
client_secret = ""

# Initialize the Spotify API client
auth_manager = SpotifyClientCredentials(client_id=client_id, client_secret=client_secret)
sp = spotipy.Spotify(auth_manager=auth_manager)

# Replace '2qgXrzJsry4KgYoJCpuaul' with the actual Spotify ID of the track
track_id = '5iCY0TXNImK4hyKfcplQsg'

# Retrieve track details
track_info = sp.track(track_id)

# Get the preview URL from the track details
preview_url = track_info['preview_url']

print(f"Preview URL: {preview_url}")
