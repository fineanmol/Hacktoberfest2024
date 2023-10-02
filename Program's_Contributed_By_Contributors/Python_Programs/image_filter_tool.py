import ctypes
import os.path
from tkinter import *
from tkinter import filedialog, ttk
import cv2 as cv
import numpy as np
import scipy.signal
from matplotlib import image as mpimg
from matplotlib import pyplot as plt
from PIL import Image, ImageTk

ctypes.windll.shcore.SetProcessDpiAwareness(True)
root = Tk()
ttk.Style().configure("TButton", justify=CENTER)

"""----------------x-----Global Variable------x----------------"""

gui_width = 1385
gui_height = 595
ip_file = ""
op_file = ""
original_img = None
modified_img = None
user_arg = None
popup = None
popup_input = None

root.title(" Digital Image Processing Visualization Made By Prashant Singh")

root.minsize(gui_width, gui_height)

"""----------------x-----Global Variable------x----------------"""


def set_user_arg():
    global user_arg
    user_arg = popup_input.get()
    popup.destroy
    popup.quit()


def open_popup_input(text):
    global popup, popup_input
    popup = Toplevel(root)
    popup.resizable(False, False)
    popup.title("User Input")
    text_label = ttk.Label(popup, text=text, justify=LEFT)
    text_label.pack(side=TOP, anchor=W, padx=15, pady=10)
    popup_input = ttk.Entry(popup)
    popup_input.pack(side=TOP, anchor=NW, fill=X, padx=15)
    ttk.Button(popup, text="OK", command=set_user_arg).pack(pady=10)
    popup.geometry(f"400x{104 + text_label.winfo_reqheight()}")
    popup_input.focus()

    popup.mainloop()


def draw_before_canvas():
    global original_img, ip_file
    original_img = Image.open(ip_file)
    original_img = original_img.convert("RGB")
    img = ImageTk.PhotoImage(original_img)
    before_canvas.create_image(
        256,
        256,
        image=img,
        anchor="center",
    )
    before_canvas.img = img


def draw_after_canvas(mimg):
    global modified_img

    modified_img = Image.fromarray(mimg)
    img = ImageTk.PhotoImage(modified_img)
    after_canvas.create_image(
        256,
        256,
        image=img,
        anchor="center",
    )
    after_canvas.img = img


def load_file():
    global ip_file
    ip_file = filedialog.askopenfilename(
        title="Open an Image fill",
        initialdir=".",
        filetypes=[("All Image Files", "*.*")],

    )
    draw_before_canvas()
    print(f"Image load from: {ip_file}")
    print(f"Image: {original_img}")


def save_file():
    global ip_file, original_img, modified_img
    file_ext = os.path.splitext(ip_file)[1][1:]
    op_file = filedialog.asksaveasfilename(
        filetypes=[
            (
                f"{file_ext.upper()}",
                f"*.{file_ext}",

            )
        ],
        defaultextension=[
            (
                f"{file_ext.upper()}",
                f"*.{file_ext}",
            )
        ],
    )
    modified_img = modified_img.convert("RGB")
    modified_img.save(op_file)
    print(f"Image saved at:{op_file}")
    print(f"Image: {original_img}")


"""--------------x---------Frame-----------x-------------"""

left_frame = ttk.LabelFrame(root, text="Original Image", labelanchor=N)
left_frame.pack(fill=BOTH, side=LEFT, padx=10, pady=10, expand=1)

middle_frame = ttk.LabelFrame(root, text="Algorithms", labelanchor=N)
middle_frame.pack(fill=BOTH, side=LEFT, padx=5, pady=10)

right_frame = ttk.LabelFrame(root, text="Modified Image", labelanchor=N)
right_frame.pack(fill=BOTH, side=LEFT, padx=10, pady=10, expand=1)

# left frame contents
before_canvas = Canvas(left_frame, bg="white", width=512, height=512)
before_canvas.pack(expand=1)

browse_btn = ttk.Button(left_frame, text="Browse", command=load_file)
browse_btn.pack(expand=1, anchor=SW, pady=(5, 0))
"""--------------x---------Frame-----------x-------------"""

"""--------------x---------Middle frame contents-----------x-------------"""

algo_canvas = Canvas(middle_frame, width=260, highlightthickness=0)
scrollable_algo_frame = Frame(algo_canvas)
scrollbar = Scrollbar(
    middle_frame, orient="vertical", command=algo_canvas.yview, width=15
)
scrollbar.pack(side="right", fill="y")
algo_canvas.pack(fill=BOTH, expand=1)
algo_canvas.configure(yscrollcommand=scrollbar.set)
algo_canvas.create_window((0, 0), window=scrollable_algo_frame, anchor="nw")
scrollable_algo_frame.bind(
    "<Configure>", lambda _: algo_canvas.configure(scrollregion=algo_canvas.bbox("all"))
)
"""--------------x---------Middle frame contents-----------x-------------"""

"""--------------x---------Right frame contents-----------x-------------"""
after_canvas = Canvas(right_frame, bg="white", width=512, height=512)
after_canvas.pack(expand=1)

save_btn = ttk.Button(right_frame, text="Save", command=save_file)
save_btn.pack(expand=1, anchor=SE, pady=(5, 0))

"""--------------x---------Right frame contents-----------x-------------"""

"""-----------x---------Digital Image Processing Algorithms------------x-----------"""


# def RGB2Gray():
#     img = mpimg.imread(ip_file)
#     R, G, B = img[:, :, 0], img[:, :, 1], img[:, :, 2]
#     # return 0.299 * R + 0.58 * G + 0.114 * B
#     return 299 / 1000 * R + 587 / 1000 * G + 114 / 1000 * B
#
#
# def callRGB2Gray():
#     grayscale = RGB2Gray()
#     draw_after_canvas(grayscale)
#
#
# def RGB2HSI():
#     img = mpimg.imread(ip_file)
#     R, G, B = img[:, :, 0], img[:, :, 1], img[:, :, 2]
#     return R + G + B / 3
#
#
# def callRGB2HSI():
#     blackNwhite = RGB2HSI()
#     draw_after_canvas(blackNwhite)
#
# def negative(set_gray):
#     img = RGB2Gray() if set_gray else Image.open(ip_file)
#     img = np.array(img)
#     img = 255 - img
#     draw_after_canvas(img)
#
#
def redImg():
    img = mpimg.imread(ip_file)
    img[:, :, 1] = 0
    img[:, :, 2] = 0
    draw_after_canvas(img)


def greenImg():
    img = mpimg.imread(ip_file)
    img[:, :, 0] = 0
    img[:, :, 2] = 0
    draw_after_canvas(img)


def blueImg():
    img = mpimg.imread(ip_file)
    img[:, :, 0] = 0
    img[:, :, 1] = 0
    draw_after_canvas(img)


#
#
# def plot_histogram(label, img, index):
#     hist, bins = np.histogram(img, 256, [0, 256])
#     cdf = hist.cumsum()
#     cdf_normalized = cdf * float(hist.max()) / cdf.max()
#     plt.subplot(1, 2, index)
#     plt.title(label)
#     plt.plot(cdf_normalized, color="b")
#     plt.hist(img.flatten(), 256, [0, 256], color="r")
#     plt.xlim([0, 256])
#     plt.legend(("CDF", "Histogram"), loc="upper left")
#     plt.xlabel("Pixel Intensity")
#     plt.ylabel("Distribution")
#     plt.tight_layout()
#
#
# def histogram_eq():
#     plt.figure(num=1, figsize=(11, 5), dpi=100)
#     img = cv.imread(ip_file, 0)
#     plot_histogram("Original Histogram", img, 1)
#     equ_img = cv.equalizeHist(img)
#     plot_histogram("Equalized Histogram", equ_img, 2)
#     draw_after_canvas(equ_img)
#     plt.show()
#
#
# def custom_correlate(kernel):
#     image = cv.imread(ip_file)
#
#     filtered_image = cv.filter2D(src=image, ddepth=-1, kernel=kernel)
#     filtered_image = filtered_image[:, :, ::-1]
#     draw_after_canvas(filtered_image)
#
#
# def box_fileter():
#     global user_arg
#     open_popup_input("Enter n for (n*n) filter")
#     user_arg = int(user_arg)
#     kernel = np.ones([user_arg, user_arg], dtype=int)
#     kernel = kernel / (user_arg ** 2)
#     print(kernel)
#     print(sum(map(sum, kernel)))
#     custom_correlate(kernel)
#
#
# def wt_avg_filter():
#     global user_arg
#     open_popup_input("Enter n for (n*n) filter")
#     user_arg = int(user_arg)
#     seed = kernel = (
#             np.array(
#                 [
#                     [1, 1],
#                     [1, 1],
#                 ]
#             )
#             * (1 / 4)
#     )
#     for _ in range(user_arg - 2):
#         kernel = scipy.signal.convolve2d(kernel, seed)
#         print(kernel)
#         print(sum(map(sum, kernel)))
#
#         custom_correlate(kernel)
#
#
# def median_fileter():
#     global user_arg
#     open_popup_input("Enter n for (n*n) fileter")
#     msize = int(user_arg)
#     img = output = cv.imread(ip_file, 0)
#     h, w = img.shape
#     img = np.pad(img, msize // 2, mode="symmetric")
#     center = msize ** 2 // 2
#
#     for i in range(h):
#         for j in range(w):
#             temp = img[i: msize + i, j: msize + j].flatten()
#             temp.sort()
#             output[i][j] = temp[center]
#
#     draw_after_canvas(output)

def RGB2Gray():
    img = mpimg.imread(ip_file)
    R, G, B = img[:, :, 0], img[:, :, 1], img[:, :, 2]
    return 0.299 * R + 0.58 * G + 0.114 * B


def callRGB2Gray():
    grayscale = RGB2Gray()
    draw_after_canvas(grayscale)


def negative(set_gray):
    img = RGB2Gray() if (set_gray) else Image.open(ip_file)
    img = np.array(img)
    img = 255 - img
    draw_after_canvas(img)


def gray_slice(img, lower_limit, upper_limit, fn):
    # general function
    if lower_limit <= img <= upper_limit:
        return 255
    else:
        return fn


def call_gray_slice(retain):
    img = RGB2Gray()
    # input 100,180
    open_popup_input("Enter lower limit, upper limit\n(Separate inputs with a comma)")
    arg_list = user_arg.replace(" ", "").split(",")
    print(arg_list)
    lower_limit = int(arg_list[0])
    upper_limit = int(arg_list[1])
    img_thresh = np.vectorize(gray_slice)
    fn = img if retain else 0
    draw_after_canvas(img_thresh(img, lower_limit, upper_limit, fn))


def bit_slice(img, k):
    # create an image for the k bit plane
    plane = np.full((img.shape[0], img.shape[1]), 2 ** k, np.uint8)
    # execute bitwise and operation
    res = cv.bitwise_and(plane, img)
    # multiply ones (bit plane sliced) with 255 just for better visualization
    return res * 255


def call_bit_slice():
    global user_arg
    bitplanes = []
    img = cv.imread(ip_file, 0)
    open_popup_input(
        "Enter bit plane no k (0-7)\n(or leave it blank to display all 8 planes together)"
    )
    if not user_arg:
        for k in range(9):
            bslice = bit_slice(img, k)
            # append to the output list
            bslice = cv.resize(bslice, (171, 171))
            bitplanes.append(bslice)

        # concat all 8 bit planes into one image
        row1 = cv.hconcat([bitplanes[0], bitplanes[1], bitplanes[2]])
        row2 = cv.hconcat([bitplanes[3], bitplanes[4], bitplanes[5]])
        row3 = cv.hconcat([bitplanes[6], bitplanes[7], bitplanes[8]])
        final_img = cv.vconcat([row1, row2, row3])
    else:
        final_img = bit_slice(img, int(user_arg))

    draw_after_canvas(final_img)


def c_stretch(img, r1, r2, s1, s2):
    # general function
    if img < r1:
        return s1
    elif img > r2:
        return s2
    else:
        return s1 + ((s2 - s1) * (img - r1) / (r2 - r1))


def call_c_stretch(limited):
    img = RGB2Gray()
    r1 = np.min(img)
    r2 = np.max(img)
    if limited:
        # input 25,220
        open_popup_input("Enter s1,s2\n(Separate inputs with a comma)")  # user input
        arg_list = user_arg.replace(" ", "").split(",")
        s1, s2 = int(arg_list[0]), int(arg_list[1])
    else:
        s1, s2 = (0, 255)
    image_cs = np.vectorize(c_stretch)
    draw_after_canvas(image_cs(img, r1, r2, s1, s2))


def plot_histogram(label, img, index):
    hist, bins = np.histogram(img, 256, [0, 256])
    cdf = hist.cumsum()
    cdf_normalized = cdf * float(hist.max()) / cdf.max()
    plt.subplot(1, 2, index)
    plt.title(label)
    plt.plot(cdf_normalized, color="b")
    plt.hist(img.flatten(), 256, [0, 256], color="r")
    plt.xlim([0, 256])
    plt.legend(("cdf", "histogram"), loc="upper left")
    plt.xlabel("Pixel intensity")
    plt.ylabel("Distirbution")
    plt.tight_layout()


def histogram_eq():
    plt.figure(num=1, figsize=(11, 5), dpi=100)
    img = cv.imread(ip_file, 0)
    plot_histogram("Original Histogram", img, 1)
    equ_img = cv.equalizeHist(img)
    plot_histogram("Equalized Histogram", equ_img, 2)
    draw_after_canvas(equ_img)
    plt.show()


def custom_correlate(kernel):
    image = cv.imread(ip_file)
    # filtered_image = image
    # for i in range(image.shape[-1]):
    #     filtered_image[:, :, i] = scipy.signal.correlate2d(
    #         image[:, :, i], kernel, mode="same", boundary="symm"  # extended padding
    #     )
    filtered_image = cv.filter2D(src=image, ddepth=-1, kernel=kernel)
    filtered_image = filtered_image[:, :, ::-1]  # converts BGR to RGB
    draw_after_canvas(filtered_image)


def box_filter():
    global user_arg
    open_popup_input("Enter n for (nxn) filter")
    user_arg = int(user_arg)
    kernel = np.ones([user_arg, user_arg], dtype=int)
    kernel = kernel / (user_arg ** 2)
    # print(kernel)
    # print(sum(map(sum, kernel)))
    custom_correlate(kernel)


def wt_avg_filter():
    global user_arg
    open_popup_input("Enter n for (nxn) filter")
    user_arg = int(user_arg)
    seed = kernel = (
            np.array(
                [
                    [1, 1],
                    [1, 1],
                ]
            )
            * (1 / 4)
    )
    for _ in range(user_arg - 2):
        kernel = scipy.signal.correlate2d(kernel, seed)
    # print(kernel)
    # print(sum(map(sum, kernel)))
    custom_correlate(kernel)


def median_filter():
    global user_arg
    open_popup_input("Enter n for (nxn) filter")
    msize = int(user_arg)
    img = output = cv.imread(ip_file, 0)
    h, w = img.shape
    img = np.pad(img, msize // 2, mode="symmetric")
    center = msize ** 2 // 2

    for i in range(h):
        for j in range(w):
            temp = img[i: msize + i, j: msize + j].flatten()
            temp.sort()
            output[i][j] = temp[center]
    draw_after_canvas(output)


def wt_median_filter():
    img = output = cv.imread(ip_file, 0)
    m, n = img.shape

    for i in range(1, m - 1):
        for j in range(1, n - 1):
            temp = [
                img[i - 1, j - 1],
                img[i - 1, j],
                img[i - 1, j],
                img[i - 1, j + 1],
                img[i, j - 1],
                img[i, j - 1],
                img[i, j],
                img[i, j],
                img[i, j],
                img[i, j + 1],
                img[i, j + 1],
                img[i + 1, j - 1],
                img[i + 1, j],
                img[i + 1, j],
                img[i + 1, j + 1],
            ]

            temp.sort()
            output[i, j] = temp[7]
    draw_after_canvas(output)


def find_gradient(hx, hy):
    image = cv.imread(ip_file, 0)
    pdx = scipy.signal.correlate2d(image, hx, mode="same", boundary="symm")
    pdy = scipy.signal.correlate2d(image, hy, mode="same", boundary="symm")
    gradient = np.add(np.abs(pdx), np.abs(pdy))
    # sharpened_img=np.add(image,gradient)
    # draw_after_canvas(sharpened_img)
    draw_after_canvas(gradient)


def robert_op():
    hx = np.array(
        [
            [1, 0],
            [0, -1],
        ]
    )
    hy = np.array(
        [
            [0, -1],
            [1, 0],
        ]
    )
    find_gradient(hx, hy)


def prewitt_op():
    hx = np.array(
        [
            [1, 1, 1],
            [0, 0, 0],
            [-1, -1, -1],
        ]
    )
    hy = np.array(
        [
            [1, 0, -1],
            [1, 0, -1],
            [1, 0, -1],
        ]
    )
    find_gradient(hx, hy)


def sobel_op():
    hx = np.array(
        [
            [1, 2, 1],
            [0, 0, 0],
            [-1, -2, -1],
        ]
    )
    hy = np.array(
        [
            [1, 0, -1],
            [2, 0, -2],
            [1, 0, -1],
        ]
    )
    find_gradient(hx, hy)


def laplacian_op():
    kernel = [
        [-1, -1, -1],
        [-1, 8, -1],
        [-1, -1, -1],
    ]
    image = cv.imread(ip_file, 0)
    laplace = scipy.signal.correlate2d(image, kernel, mode="same", boundary="symm")
    # sharpened_img = np.add(image, laplace)
    draw_after_canvas(laplace)


def canny():  # sourcery no-metrics
    sigma = 1
    kernel_size = 5
    weak_pixel = 75
    strong_pixel = 255
    lowthreshold = 0.05
    highthreshold = 0.15

    img = cv.imread(ip_file, 0)
    M, N = img.shape

    # 1) Noise reduction
    size = kernel_size // 2
    x, y = np.mgrid[-size: size + 1, -size: size + 1]
    normal = 1 / (2.0 * np.pi * sigma ** 2)
    kernel = np.exp(-((x ** 2 + y ** 2) / (2.0 * sigma ** 2))) * normal
    img_smoothed = scipy.signal.convolve2d(img, kernel, mode="same", boundary="symm")

    # 2) Gradient calc (sobel)
    hx = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]])
    hy = np.array([[1, 2, 1], [0, 0, 0], [-1, -2, -1]])

    pdx = scipy.signal.convolve2d(img_smoothed, hx, mode="same", boundary="symm")
    pdy = scipy.signal.convolve2d(img_smoothed, hy, mode="same", boundary="symm")

    gradient = np.sqrt(pdx ** 2 + pdy ** 2)
    gradient = gradient / gradient.max() * 255
    theta = np.arctan2(pdy, pdx)

    # 3) Non Max supression
    nonmax = np.zeros((M, N), dtype=np.int32)
    angle = theta * 180.0 / np.pi
    angle[angle < 0] += 180

    for i in range(1, M - 1):
        for j in range(1, N - 1):
            q = 255
            r = 255

            # angle 0
            if (0 <= angle[i, j] < 22.5) or (157.5 <= angle[i, j] <= 180):
                q = gradient[i, j + 1]
                r = gradient[i, j - 1]
            # angle 45
            elif 22.5 <= angle[i, j] < 67.5:
                q = gradient[i + 1, j - 1]
                r = gradient[i - 1, j + 1]
            # angle 90
            elif 67.5 <= angle[i, j] < 112.5:
                q = gradient[i + 1, j]
                r = gradient[i - 1, j]
            # angle 135
            elif 112.5 <= angle[i, j] < 157.5:
                q = gradient[i - 1, j - 1]
                r = gradient[i + 1, j + 1]

            if (gradient[i, j] >= q) and (gradient[i, j] >= r):
                nonmax[i, j] = gradient[i, j]
            else:
                nonmax[i, j] = 0

    # 4) Double threshold
    highThreshold = nonmax.max() * highthreshold
    lowThreshold = highThreshold * lowthreshold

    thresh = np.zeros((M, N), dtype=np.int32)

    strong_i, strong_j = np.where(nonmax >= highThreshold)
    weak_i, weak_j = np.where((nonmax <= highThreshold) & (nonmax >= lowThreshold))

    thresh[strong_i, strong_j] = strong_pixel
    thresh[weak_i, weak_j] = weak_pixel

    # 5) Hysteresis
    for i in range(1, M - 1):
        for j in range(1, N - 1):
            if thresh[i, j] == weak_pixel:

                if (
                        (thresh[i + 1, j - 1] == strong_pixel)
                        or (thresh[i + 1, j] == strong_pixel)
                        or (thresh[i + 1, j + 1] == strong_pixel)
                        or (thresh[i, j - 1] == strong_pixel)
                        or (thresh[i, j + 1] == strong_pixel)
                        or (thresh[i - 1, j - 1] == strong_pixel)
                        or (thresh[i - 1, j] == strong_pixel)
                        or (thresh[i - 1, j + 1] == strong_pixel)
                ):
                    thresh[i, j] = strong_pixel
                else:
                    thresh[i, j] = 0

    draw_after_canvas(thresh)


"""-----------x---------Digital Image Processing Algorithms------------x-----------"""

"""----------------x--------Buttons for Algorithms---------x---------------"""
# ttk.Button(
#     scrollable_algo_frame,
#     text="RGB to grayscale",
#     width=30,
#     command=callRGB2Gray) \
#     .pack(expand=1, padx=5, pady=2, ipady=2)
#


# ttk.Button(
#     scrollable_algo_frame,
#     text="Negative",
#     width=30,
#     command=lambda: negative(set_gray=False)) \
#     .pack(pady=2, ipady=2)
#
# ttk.Button(
#     scrollable_algo_frame,
#     text="Negative/(Grayscale output)",
#     width=30,
#     command=lambda: negative(set_gray=True),
# ).pack(pady=2, ipady=2)
#
# ttk.Button(
#     scrollable_algo_frame,
#     text="Histogram Equalization",
#     width=30,
#     command=histogram_eq,
# ).pack(pady=2, ipady=2)
# ttk.Button(
#     scrollable_algo_frame, text="gray-contrast", width=30, command=callRGB2HSI).pack(pady=2, ipady=2)
#
#
# ttk.Button(
#     scrollable_algo_frame,
#     text="Image Smoothing - Liner/n(nxm Avg/Box filter)",
#     width=30,
#     command=box_fileter,
# ).pack(pady=2, ipady=2)
#
# ttk.Button(
#     scrollable_algo_frame,
#     text="Image Smotting - Non Liner\n(n*n Median filter)",
#     width=30,
#     command=median_fileter,
# ).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame, text="RGB to Grayscale", width=30, command=callRGB2Gray
).pack(expand=1, padx=5, pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Red Image", width=30,
    command=redImg) \
    .pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Green Image",
    width=30,
    command=greenImg) \
    .pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Blue Image",
    width=30,
    command=blueImg) \
    .pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Negative",
    width=30,
    command=lambda: negative(set_gray=False),
).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Negative\n(Grayscale output)",
    width=30,
    command=lambda: negative(set_gray=True),
).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Gray level slicing\n(retaining background)",
    width=30,
    command=lambda: call_gray_slice(retain=True),
).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Gray level slicing\n(lowering background)",
    width=30,
    command=lambda: call_gray_slice(retain=False),
).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Bit plane slicing",
    width=30,
    command=call_bit_slice,
).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Contrast Stretching\n(Linear)",
    width=30,
    command=lambda: call_c_stretch(limited=False),
).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Contrast Stretching\n(Limited Linear)",
    width=30,
    command=lambda: call_c_stretch(limited=True),
).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Histogram Equalization",
    width=30,
    command=histogram_eq,
).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Image Smoothing - Linear\n(nxn Avg/Box Filter)",
    width=30,
    command=box_filter,
).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Image Smoothing - Linear\n(nxn Weighted Avg Filter)",
    width=30,
    command=wt_avg_filter,
).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Image Smoothing - Non Linear\n(nxn Median Filter)",
    width=30,
    command=median_filter,
).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Image Smoothing - Non Linear\n(3x3 Weighted Median Filter)",
    width=30,
    command=wt_median_filter,
).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Image Sharpening - Gradient\n(Roberts operator)",
    width=30,
    command=robert_op,
).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Image Sharpening - Gradient\n(Prewitt operator)",
    width=30,
    command=prewitt_op,
).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Image Sharpening - Gradient\n(Sobel operator)",
    width=30,
    command=sobel_op,
).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Image Sharpening - Laplacian",
    width=30,
    command=laplacian_op,
).pack(pady=2, ipady=2)

ttk.Button(
    scrollable_algo_frame,
    text="Canny Edge Detection",
    width=30,
    command=canny,
).pack(pady=2, ipady=2)

"""----------------x--------Buttons for Algorithms---------x---------------"""

root.mainloop()
