import os
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent.parent


class CCExtractor:
    
    '''
    This class is used to extract subtitles from a video file.
    Note: CCextractor should be installed on your system.
    '''
    
    def __init__(self, video_name: str, video_path: str):
        self.video_name = video_name
        self.path = video_path
        self.subtitle_name = self.video_name.replace(" ", "_").split(".")[0] + ".srt"
        self.subtitle_path = f"{BASE_DIR}/temp/{self.subtitle_name}"

    def __run_extractor(self) -> bool:
        print("Extracting subtitles from video...")
        try:
            print(self.subtitle_path)
            os.system(f"ccextractor {self.path} -o {self.subtitle_path}")
            return True
        except Exception as e:
            print(e)
            return False

    def extract_time_text_from_srt(self) -> list:
        if self.__run_extractor():
            with open(self.subtitle_path, "r") as f:
                data = f.read()
            data = data.split("\n\n")
            data = [i.split("\n") for i in data]
            output = []
            for i in data:
                if len(i) >= 3:
                    output.append({
                        "start": i[1].split(" --> ")[0],
                        "end": i[1].split(" --> ")[1],
                        "text": ", ".join(i[2:])
                    })
            self.delete_temp_files()
            return output
        else:
            raise Exception("Error while extracting subtitles from video")

    def delete_temp_files(self) -> bool:
        os.system(f"rm {self.subtitle_path}")
        for file in os.listdir(BASE_DIR):
            if file.endswith(".srt"):
                os.system(f"rm {BASE_DIR}/{file}")
                break 
        return True
