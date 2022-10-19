import win32gui
import win32ui
import win32con
import win32api
import uuid
import os
import pathlib
import tarfile
from os import listdir
from os.path import isfile, join
from PIL import Image

# Class that I wrote, used on a school project for SDD1001
class Screenshotter():
    def __init__(self):
        # grab a handle to the main desktop window
        self.hdesktop = win32gui.GetDesktopWindow()

        # determine the size of all monitors in pixels
        self.width = win32api.GetSystemMetrics(win32con.SM_CXVIRTUALSCREEN)
        self.height = win32api.GetSystemMetrics(win32con.SM_CYVIRTUALSCREEN)
        self.left = win32api.GetSystemMetrics(win32con.SM_XVIRTUALSCREEN)
        self.top = win32api.GetSystemMetrics(win32con.SM_YVIRTUALSCREEN)

        self.PATH = f'c:\\WINDOWS\\Temp\\screenshot__{uuid.uuid1()}.bmp'
        self.DIR_PATH = f'c:\\WINDOWS\\Temp\\'
        self.BMP_EXT = '.bmp'
        self.PNG_EXT = '.png'

        self.SCREENSHOT_ARCHIVE = 'screenshots_archive'


    def __call__(self):
        return self.take_screenshot()


    def take_screenshot(self):
        # create a device context
        desktop_dc = win32gui.GetWindowDC(self.hdesktop)
        img_dc = win32ui.CreateDCFromHandle(desktop_dc)

        # create a memory based device context
        mem_dc = img_dc.CreateCompatibleDC()

        # create a bitmap object
        screenshot = win32ui.CreateBitmap()
        screenshot.CreateCompatibleBitmap(img_dc, self.width, self.height)
        mem_dc.SelectObject(screenshot)

        # copy the screen into our memory device context
        mem_dc.BitBlt((0, 0), (self.width, self.height), img_dc, (self.left, self.top), win32con.SRCCOPY)

        # save the bitmap to a file
        screenshot.SaveBitmapFile(mem_dc, self.PATH)

        # free our objects
        mem_dc.DeleteDC()
        win32gui.DeleteObject(screenshot.GetHandle())
    


    def retrieve_all_screenshots(self):
        bmp_screenshots = []
        png_screenshots = []
        files_in_current_folder = self.get_file_in_current_folder()

        for file in files_in_current_folder:
            if 'screenshot__' in os.path.basename(file) and self.BMP_EXT == pathlib.Path(file).suffix:
                bmp_screenshots.append(file)

        if len(bmp_screenshots) != 0:
            for screenshot in bmp_screenshots:
                self.convert_bmp_to_png(bmp=screenshot)
        
        files_in_current_folder = self.get_file_in_current_folder()

        for file in files_in_current_folder:
            if 'screenshot__' in os.path.basename(file) and self.PNG_EXT == pathlib.Path(file).suffix:
                png_screenshots.append(file)
        
        if len(png_screenshots) != 0:
            self.generate_tar_gz(output_name=self.SCREENSHOT_ARCHIVE, filename_list=png_screenshots)



    def get_file_in_current_folder(self):
        return [f for f in listdir(self.DIR_PATH) if isfile(join(self.DIR_PATH, f))]



    def convert_bmp_to_png(self, bmp):
        Image.open(bmp).save(os.path.join(self.DIR_PATH + '\\' + str(bmp).replace(self.BMP_EXT, self.PNG_EXT)))
        os.remove(os.path.join(self.DIR_PATH + '\\' + bmp))
        


    def generate_tar_gz(self, output_name, filename_list):
        tar = tarfile.open(f'{output_name}__{uuid.uuid1()}.tar.gz', 'w:gz')
        for name in filename_list:
            tar.add(name)

        tar.close()

        for name in filename_list:
            os.remove(name)