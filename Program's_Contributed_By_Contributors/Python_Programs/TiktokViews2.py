import datetime
import random
import time
from colorama import init, Fore
from src import process


def main():
    init(autoreset=True)
    inject = process.ZefoyViews()
    print(
        Fore.GREEN + """
      _____ _ _  __   ___
     |_   _(_) |_\ \ / (_)_____ __ _____
       | | | | / /\ V /| / -_) V  V (_-<
       |_| |_|_\_\ \_/ |_\___|\_/\_//__/
          Ahmad Chen Wang Xuesi
    """
    )
    print(Fore.LIGHTYELLOW_EX + "Contoh: https://www.tiktok.com/@anonsecteaminc/video/6993753284267740443")
    url_video = input("Enter URL Video: ")

    inject.get_session_captcha()
    time.sleep(1)

    if inject.post_solve_captcha(captcha_result=inject.captcha_solver()):

        print("\n[ " + str(datetime.datetime.now()) + " ] " + Fore.LIGHTGREEN_EX + "Berhasil Bypass Captcha" + "\n")

        while True:

            inject_views = inject.send_views(
                url_video=url_video
            )
            if inject_views:

                if "Silakan coba lagi nanti" in inject_views:
                    print("[ " + str(datetime.datetime.now()) + " ] " + Fore.LIGHTRED_EX + inject_views)
                    exit()

                elif "Views berhasil dikirim." in inject_views:
                    print("[ " + str(
                        datetime.datetime.now()) + " ] " + Fore.LIGHTGREEN_EX + inject_views + " to " + Fore.LIGHTYELLOW_EX + "" + url_video,
                          end="\n\n")

                elif "Sesi berakhir. Silahkan Login Ulang!" in inject_views:
                    print("[ " + str(datetime.datetime.now()) + " ] " + Fore.LIGHTRED_EX + inject_views)
                    exit()

                elif "Please try again later. Server too busy." in inject_views:
                    print("[ " + str(datetime.datetime.now()) + " ] " + Fore.LIGHTRED_EX + inject_views)
                    time.sleep(random.randint(300, 600))
                    exit()

                else:
                    for i in range(int(inject_views), 0, -1):
                        print("[ " + str(datetime.datetime.now()) + " ] " + Fore.LIGHTYELLOW_EX + "Mohon Tunggu " + str(
                            i) + " detik untuk mengirim tampilan lagi.", end="\r")
                        time.sleep(1)

                time.sleep(random.randint(1, 5))

            else:
                pass

    else:
        print(Fore.RED + "Gagal Bypass captcha.")


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print(Fore.RED + "Exit")
        exit()
