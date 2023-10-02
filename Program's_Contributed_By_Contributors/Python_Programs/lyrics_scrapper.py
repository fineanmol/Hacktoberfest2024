# importing modules
from lyrics_extractor import SongLyrics
 
# Create GCS_API_KEY & GCS_ENGINE_ID
GDC_API_KEY = '<Your Google Custom Search API KEY>'
GCS_ENGINE_ID = '<Your Google Custome Search Engine ID>'

extract_lyrics = SongLyrics(GDC_API_KEY, GCS_ENGINE_ID)

query = input('Enter the song name:')
out = extract_lyrics.get_lyrics(query)
print(
    f"""
    Title: {out["title"]}\n
    Lyrics:\n
    {out["lyrics"]}
    """
)
