{
 "cells": [
  {
   "cell_type": "markdown",
   "id": "d9d9f5c4",
   "metadata": {},
   "source": [
    "### Importing Libraries"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 25,
   "id": "b1aae89a",
   "metadata": {},
   "outputs": [],
   "source": [
    "import pandas as pd\n",
    "import numpy as np\n",
    "import matplotlib.pyplot as plt\n",
    "import seaborn as sbn\n",
    "import tensorflow as tf"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "4127dabc",
   "metadata": {},
   "source": [
    "### Importing Dataset"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 26,
   "id": "bf195ad4",
   "metadata": {},
   "outputs": [],
   "source": [
    "from tensorflow import keras\n",
    "dataset = tf.keras.datasets.mnist"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "0045c312",
   "metadata": {},
   "source": [
    "### Arranging data into training and test set"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 27,
   "id": "e3ccfdc8",
   "metadata": {},
   "outputs": [],
   "source": [
    "(x_train,y_train),(x_test,y_test) = dataset.load_data()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 28,
   "id": "d2bd24ac",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "(60000, 28, 28)"
      ]
     },
     "execution_count": 28,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "x_train.shape  # 60000 images of 28X28 px"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 29,
   "id": "e82a2916",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "(10000, 28, 28)"
      ]
     },
     "execution_count": 29,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "x_test.shape   # 10000 images of 28X28 px"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "6a6df7b4",
   "metadata": {},
   "source": [
    "### Previewing data"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 30,
   "id": "747f0fae",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "array([[  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   3,\n",
       "         18,  18,  18, 126, 136, 175,  26, 166, 255, 247, 127,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,  30,  36,  94, 154, 170,\n",
       "        253, 253, 253, 253, 253, 225, 172, 253, 242, 195,  64,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,  49, 238, 253, 253, 253, 253,\n",
       "        253, 253, 253, 253, 251,  93,  82,  82,  56,  39,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,  18, 219, 253, 253, 253, 253,\n",
       "        253, 198, 182, 247, 241,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,  80, 156, 107, 253, 253,\n",
       "        205,  11,   0,  43, 154,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,  14,   1, 154, 253,\n",
       "         90,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 139, 253,\n",
       "        190,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  11, 190,\n",
       "        253,  70,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  35,\n",
       "        241, 225, 160, 108,   1,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "         81, 240, 253, 253, 119,  25,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,  45, 186, 253, 253, 150,  27,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0,  16,  93, 252, 253, 187,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0,   0,   0, 249, 253, 249,  64,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,  46, 130, 183, 253, 253, 207,   2,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  39,\n",
       "        148, 229, 253, 253, 253, 250, 182,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  24, 114, 221,\n",
       "        253, 253, 253, 253, 201,  78,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,  23,  66, 213, 253, 253,\n",
       "        253, 253, 198,  81,   2,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,  18, 171, 219, 253, 253, 253, 253,\n",
       "        195,  80,   9,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,  55, 172, 226, 253, 253, 253, 253, 244, 133,\n",
       "         11,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0, 136, 253, 253, 253, 212, 135, 132,  16,   0,\n",
       "          0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0],\n",
       "       [  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,\n",
       "          0,   0]], dtype=uint8)"
      ]
     },
     "execution_count": 30,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "x_train[0]"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 31,
   "id": "952a7470",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "5"
      ]
     },
     "execution_count": 31,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "y_train[0]"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 32,
   "id": "8cc56cda",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "<matplotlib.image.AxesImage at 0x1a249cc7160>"
      ]
     },
     "execution_count": 32,
     "metadata": {},
     "output_type": "execute_result"
    },
    {
     "data": {
      "image/png": "iVBORw0KGgoAAAANSUhEUgAAAPsAAAD4CAYAAAAq5pAIAAAAOXRFWHRTb2Z0d2FyZQBNYXRwbG90bGliIHZlcnNpb24zLjQuMywgaHR0cHM6Ly9tYXRwbG90bGliLm9yZy/MnkTPAAAACXBIWXMAAAsTAAALEwEAmpwYAAAOX0lEQVR4nO3dbYxc5XnG8euKbUwxJvHGseMQFxzjFAg0Jl0ZkBFQoVCCIgGKCLGiiFBapwlOQutKUFoVWtHKrRIiSimSKS6m4iWQgPAHmsSyECRqcFmoAROHN+MS4+0aswIDIfZ6fffDjqsFdp5dZs68eO//T1rNzLnnzLk1cPmcmeeceRwRAjD5faDTDQBoD8IOJEHYgSQIO5AEYQeSmNrOjR3i6XGoZrRzk0Aqv9Fb2ht7PFatqbDbPkfS9ZKmSPrXiFhVev6hmqGTfVYzmwRQsDE21K01fBhve4qkGyV9TtLxkpbZPr7R1wPQWs18Zl8i6fmI2BoReyXdJem8atoCULVmwn6kpF+Nery9tuwdbC+33We7b0h7mtgcgGY0E/axvgR4z7m3EbE6InojoneapjexOQDNaCbs2yXNH/X445J2NNcOgFZpJuyPSlpke4HtQyR9SdK6atoCULWGh94iYp/tFZJ+rJGhtzUR8XRlnQGoVFPj7BHxgKQHKuoFQAtxuiyQBGEHkiDsQBKEHUiCsANJEHYgCcIOJEHYgSQIO5AEYQeSIOxAEoQdSIKwA0kQdiAJwg4kQdiBJAg7kARhB5Ig7EAShB1IgrADSRB2IAnCDiRB2IEkCDuQBGEHkiDsQBKEHUiCsANJNDWLK7qfp5b/E0/5yOyWbv+ZPz+6bm34sP3FdY9auLNYP+wbLtb/97pD6tYe7/1+cd1dw28V6yffs7JYP+bPHinWO6GpsNveJukNScOS9kVEbxVNAaheFXv234+IXRW8DoAW4jM7kESzYQ9JP7H9mO3lYz3B9nLbfbb7hrSnyc0BaFSzh/FLI2KH7TmS1tv+ZUQ8PPoJEbFa0mpJOsI90eT2ADSoqT17ROyo3e6UdJ+kJVU0BaB6DYfd9gzbMw/cl3S2pM1VNQagWs0cxs+VdJ/tA69zR0T8qJKuJpkpxy0q1mP6tGJ9xxkfKtbfPqX+mHDPB8vjxT/9dHm8uZP+49czi/V/+OdzivWNJ95Rt/bi0NvFdVcNfLZY/9hPD75PpA2HPSK2Svp0hb0AaCGG3oAkCDuQBGEHkiDsQBKEHUiCS1wrMHzmZ4r16269sVj/5LT6l2JOZkMxXKz/9Q1fLdanvlUe/jr1nhV1azNf3ldcd/qu8tDcYX0bi/VuxJ4dSIKwA0kQdiAJwg4kQdiBJAg7kARhB5JgnL0C05/ZUaw/9pv5xfonpw1U2U6lVvafUqxvfbP8U9S3LvxB3drr+8vj5HP/6T+L9VY6+C5gHR97diAJwg4kQdiBJAg7kARhB5Ig7EAShB1IwhHtG1E8wj1xss9q2/a6xeAlpxbru88p/9zzlCcPL9af+MYN77unA67d9bvF+qNnlMfRh197vViPU+v/APG2bxVX1YJlT5SfgPfYGBu0OwbHnMuaPTuQBGEHkiDsQBKEHUiCsANJEHYgCcIOJME4exeYMvvDxfrwq4PF+ot31B8rf/r0NcV1l/z9N4v1OTd27ppyvH9NjbPbXmN7p+3No5b12F5v+7na7awqGwZQvYkcxt8q6d2z3l8paUNELJK0ofYYQBcbN+wR8bCkdx9Hnidpbe3+WknnV9sWgKo1+gXd3Ijol6Ta7Zx6T7S93Haf7b4h7WlwcwCa1fJv4yNidUT0RkTvNE1v9eYA1NFo2Adsz5Ok2u3O6loC0AqNhn2dpItr9y+WdH817QBolXF/N972nZLOlDTb9nZJV0taJelu25dKeknSha1scrIb3vVqU+sP7W58fvdPffkXxforN00pv8D+8hzr6B7jhj0iltUpcXYMcBDhdFkgCcIOJEHYgSQIO5AEYQeSYMrmSeC4K56tW7vkxPKgyb8dtaFYP+PCy4r1md9/pFhH92DPDiRB2IEkCDuQBGEHkiDsQBKEHUiCsANJMM4+CZSmTX7168cV131p3dvF+pXX3las/8UXLyjW478/WLc2/+9+XlxXbfyZ8wzYswNJEHYgCcIOJEHYgSQIO5AEYQeSIOxAEkzZnNzgH55arN9+9XeK9QVTD21425+6bUWxvujm/mJ939ZtDW97smpqymYAkwNhB5Ig7EAShB1IgrADSRB2IAnCDiTBODuKYuniYv2IVduL9Ts/8eOGt33sg39UrP/O39S/jl+Shp/b2vC2D1ZNjbPbXmN7p+3No5ZdY/tl25tqf+dW2TCA6k3kMP5WSeeMsfx7EbG49vdAtW0BqNq4YY+IhyUNtqEXAC3UzBd0K2w/WTvMn1XvSbaX2+6z3TekPU1sDkAzGg37TZIWSlosqV/Sd+s9MSJWR0RvRPRO0/QGNwegWQ2FPSIGImI4IvZLulnSkmrbAlC1hsJue96ohxdI2lzvuQC6w7jj7LbvlHSmpNmSBiRdXXu8WFJI2ibpaxFRvvhYjLNPRlPmzinWd1x0TN3axiuuL677gXH2RV9+8exi/fXTXi3WJ6PSOPu4k0RExLIxFt/SdFcA2orTZYEkCDuQBGEHkiDsQBKEHUiCS1zRMXdvL0/ZfJgPKdZ/HXuL9c9/8/L6r33fxuK6Byt+ShoAYQeyIOxAEoQdSIKwA0kQdiAJwg4kMe5Vb8ht/2mLi/UXLixP2XzC4m11a+ONo4/nhsGTivXD7u9r6vUnG/bsQBKEHUiCsANJEHYgCcIOJEHYgSQIO5AE4+yTnHtPKNaf/VZ5rPvmpWuL9dMPLV9T3ow9MVSsPzK4oPwC+8f9dfNU2LMDSRB2IAnCDiRB2IEkCDuQBGEHkiDsQBKMsx8Epi44qlh/4ZKP1a1dc9FdxXW/cPiuhnqqwlUDvcX6Q9efUqzPWlv+3Xm807h7dtvzbT9oe4vtp21/u7a8x/Z628/Vbme1vl0AjZrIYfw+SSsj4jhJp0i6zPbxkq6UtCEiFknaUHsMoEuNG/aI6I+Ix2v335C0RdKRks6TdOBcyrWSzm9RjwAq8L6+oLN9tKSTJG2UNDci+qWRfxAkzamzznLbfbb7hrSnyXYBNGrCYbd9uKQfSro8InZPdL2IWB0RvRHRO03TG+kRQAUmFHbb0zQS9Nsj4t7a4gHb82r1eZJ2tqZFAFUYd+jNtiXdImlLRFw3qrRO0sWSVtVu729Jh5PA1KN/u1h//ffmFesX/e2PivU/+dC9xXorrewvD4/9/F/qD6/13PpfxXVn7WdorUoTGWdfKukrkp6yvam27CqNhPxu25dKeknShS3pEEAlxg17RPxM0piTu0s6q9p2ALQKp8sCSRB2IAnCDiRB2IEkCDuQBJe4TtDUeR+tWxtcM6O47tcXPFSsL5s50FBPVVjx8mnF+uM3LS7WZ/9gc7He8wZj5d2CPTuQBGEHkiDsQBKEHUiCsANJEHYgCcIOJJFmnH3vH5R/tnjvnw4W61cd80Dd2tm/9VZDPVVlYPjturXT160srnvsX/2yWO95rTxOvr9YRTdhzw4kQdiBJAg7kARhB5Ig7EAShB1IgrADSaQZZ992fvnftWdPvKdl277xtYXF+vUPnV2se7jej/uOOPbaF+vWFg1sLK47XKxiMmHPDiRB2IEkCDuQBGEHkiDsQBKEHUiCsANJOCLKT7DnS7pN0kc1cvny6oi43vY1kv5Y0iu1p14VEfUv+pZ0hHviZDPxK9AqG2ODdsfgmCdmTOSkmn2SVkbE47ZnSnrM9vpa7XsR8Z2qGgXQOhOZn71fUn/t/hu2t0g6stWNAajW+/rMbvtoSSdJOnAO5grbT9peY3tWnXWW2+6z3TekPc11C6BhEw677cMl/VDS5RGxW9JNkhZKWqyRPf93x1ovIlZHRG9E9E7T9OY7BtCQCYXd9jSNBP32iLhXkiJiICKGI2K/pJslLWldmwCaNW7YbVvSLZK2RMR1o5bPG/W0CySVp/ME0FET+TZ+qaSvSHrK9qbasqskLbO9WFJI2ibpay3oD0BFJvJt/M8kjTVuVxxTB9BdOIMOSIKwA0kQdiAJwg4kQdiBJAg7kARhB5Ig7EAShB1IgrADSRB2IAnCDiRB2IEkCDuQxLg/JV3pxuxXJP3PqEWzJe1qWwPvT7f21q19SfTWqCp7OyoiPjJWoa1hf8/G7b6I6O1YAwXd2lu39iXRW6Pa1RuH8UAShB1IotNhX93h7Zd0a2/d2pdEb41qS28d/cwOoH06vWcH0CaEHUiiI2G3fY7tZ2w/b/vKTvRQj+1ttp+yvcl2X4d7WWN7p+3No5b12F5v+7na7Zhz7HWot2tsv1x77zbZPrdDvc23/aDtLbaftv3t2vKOvneFvtryvrX9M7vtKZKelfRZSdslPSppWUT8oq2N1GF7m6TeiOj4CRi2T5f0pqTbIuKE2rJ/lDQYEatq/1DOiogruqS3ayS92elpvGuzFc0bPc24pPMlfVUdfO8KfX1RbXjfOrFnXyLp+YjYGhF7Jd0l6bwO9NH1IuJhSYPvWnyepLW1+2s18j9L29XprStERH9EPF67/4akA9OMd/S9K/TVFp0I+5GSfjXq8XZ113zvIeknth+zvbzTzYxhbkT0SyP/80ia0+F+3m3cabzb6V3TjHfNe9fI9OfN6kTYx5pKqpvG/5ZGxGckfU7SZbXDVUzMhKbxbpcxphnvCo1Of96sToR9u6T5ox5/XNKODvQxpojYUbvdKek+dd9U1AMHZtCt3e7scD//r5um8R5rmnF1wXvXyenPOxH2RyUtsr3A9iGSviRpXQf6eA/bM2pfnMj2DElnq/umol4n6eLa/Ysl3d/BXt6hW6bxrjfNuDr83nV8+vOIaPufpHM18o38C5L+shM91OnrE5KeqP093eneJN2pkcO6IY0cEV0q6cOSNkh6rnbb00W9/bukpyQ9qZFgzetQb6dp5KPhk5I21f7O7fR7V+irLe8bp8sCSXAGHZAEYQeSIOxAEoQdSIKwA0kQdiAJwg4k8X+zhHFo7nUhhwAAAABJRU5ErkJggg==\n",
      "text/plain": [
       "<Figure size 432x288 with 1 Axes>"
      ]
     },
     "metadata": {
      "needs_background": "light"
     },
     "output_type": "display_data"
    }
   ],
   "source": [
    "plt.imshow(x_train[0])"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "c438bff4",
   "metadata": {},
   "source": [
    "### Putting values in a range"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 33,
   "id": "7368e206",
   "metadata": {},
   "outputs": [],
   "source": [
    "x_train = x_train/255  # for balancing weights in ANN\n",
    "x_test = x_test/255"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 34,
   "id": "d14a133b",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "array([[0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.01176471, 0.07058824, 0.07058824,\n",
       "        0.07058824, 0.49411765, 0.53333333, 0.68627451, 0.10196078,\n",
       "        0.65098039, 1.        , 0.96862745, 0.49803922, 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.11764706, 0.14117647,\n",
       "        0.36862745, 0.60392157, 0.66666667, 0.99215686, 0.99215686,\n",
       "        0.99215686, 0.99215686, 0.99215686, 0.88235294, 0.6745098 ,\n",
       "        0.99215686, 0.94901961, 0.76470588, 0.25098039, 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.19215686, 0.93333333, 0.99215686,\n",
       "        0.99215686, 0.99215686, 0.99215686, 0.99215686, 0.99215686,\n",
       "        0.99215686, 0.99215686, 0.98431373, 0.36470588, 0.32156863,\n",
       "        0.32156863, 0.21960784, 0.15294118, 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.07058824, 0.85882353, 0.99215686,\n",
       "        0.99215686, 0.99215686, 0.99215686, 0.99215686, 0.77647059,\n",
       "        0.71372549, 0.96862745, 0.94509804, 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.31372549, 0.61176471,\n",
       "        0.41960784, 0.99215686, 0.99215686, 0.80392157, 0.04313725,\n",
       "        0.        , 0.16862745, 0.60392157, 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.05490196,\n",
       "        0.00392157, 0.60392157, 0.99215686, 0.35294118, 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.54509804, 0.99215686, 0.74509804, 0.00784314,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.04313725, 0.74509804, 0.99215686, 0.2745098 ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.1372549 , 0.94509804, 0.88235294,\n",
       "        0.62745098, 0.42352941, 0.00392157, 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.31764706, 0.94117647,\n",
       "        0.99215686, 0.99215686, 0.46666667, 0.09803922, 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.17647059,\n",
       "        0.72941176, 0.99215686, 0.99215686, 0.58823529, 0.10588235,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.0627451 , 0.36470588, 0.98823529, 0.99215686, 0.73333333,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.97647059, 0.99215686, 0.97647059,\n",
       "        0.25098039, 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.18039216,\n",
       "        0.50980392, 0.71764706, 0.99215686, 0.99215686, 0.81176471,\n",
       "        0.00784314, 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.15294118, 0.58039216, 0.89803922,\n",
       "        0.99215686, 0.99215686, 0.99215686, 0.98039216, 0.71372549,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.09411765, 0.44705882, 0.86666667, 0.99215686, 0.99215686,\n",
       "        0.99215686, 0.99215686, 0.78823529, 0.30588235, 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.09019608, 0.25882353,\n",
       "        0.83529412, 0.99215686, 0.99215686, 0.99215686, 0.99215686,\n",
       "        0.77647059, 0.31764706, 0.00784314, 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.07058824, 0.67058824, 0.85882353, 0.99215686,\n",
       "        0.99215686, 0.99215686, 0.99215686, 0.76470588, 0.31372549,\n",
       "        0.03529412, 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.21568627,\n",
       "        0.6745098 , 0.88627451, 0.99215686, 0.99215686, 0.99215686,\n",
       "        0.99215686, 0.95686275, 0.52156863, 0.04313725, 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.53333333,\n",
       "        0.99215686, 0.99215686, 0.99215686, 0.83137255, 0.52941176,\n",
       "        0.51764706, 0.0627451 , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ],\n",
       "       [0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        , 0.        , 0.        ,\n",
       "        0.        , 0.        , 0.        ]])"
      ]
     },
     "execution_count": 34,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "x_train[0]"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "093f4fa5",
   "metadata": {},
   "source": [
    "### Building model"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "9fd02c2d",
   "metadata": {},
   "source": [
    "##### Initializing model\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 35,
   "id": "9ee4c84a",
   "metadata": {},
   "outputs": [],
   "source": [
    "model = tf.keras.models.Sequential()"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "6d2cb91b",
   "metadata": {},
   "source": [
    "##### Flattening layer"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 36,
   "id": "9c388927",
   "metadata": {},
   "outputs": [],
   "source": [
    "from tensorflow.keras.layers import Dense,Flatten"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 37,
   "id": "2f1c15fc",
   "metadata": {},
   "outputs": [],
   "source": [
    "model.add(Flatten(input_shape=(28,28)))"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "b80bd865",
   "metadata": {},
   "source": [
    "##### Adding first layer"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 38,
   "id": "2415455a",
   "metadata": {},
   "outputs": [],
   "source": [
    "model.add(Dense(units=128,activation='relu'))"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "a949d2fc",
   "metadata": {},
   "source": [
    "##### Adding second layer"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 39,
   "id": "0a97a444",
   "metadata": {},
   "outputs": [],
   "source": [
    "model.add(Dense(units=32,activation='relu'))"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "187d7703",
   "metadata": {},
   "source": [
    "### Adding Output layer"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 41,
   "id": "842fffd3",
   "metadata": {},
   "outputs": [],
   "source": [
    "model.add(Dense(units='10',activation='softmax'))"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 42,
   "id": "8e7d1a40",
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "Model: \"sequential_1\"\n",
      "_________________________________________________________________\n",
      " Layer (type)                Output Shape              Param #   \n",
      "=================================================================\n",
      " flatten_1 (Flatten)         (None, 784)               0         \n",
      "                                                                 \n",
      " dense_3 (Dense)             (None, 128)               100480    \n",
      "                                                                 \n",
      " dense_4 (Dense)             (None, 32)                4128      \n",
      "                                                                 \n",
      " dense_5 (Dense)             (None, 10)                330       \n",
      "                                                                 \n",
      " dense_6 (Dense)             (None, 10)                110       \n",
      "                                                                 \n",
      "=================================================================\n",
      "Total params: 105,048\n",
      "Trainable params: 105,048\n",
      "Non-trainable params: 0\n",
      "_________________________________________________________________\n"
     ]
    }
   ],
   "source": [
    "model.summary()"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "844090dc",
   "metadata": {},
   "source": [
    "##### Compiling ANN"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 50,
   "id": "70a36b6e",
   "metadata": {},
   "outputs": [],
   "source": [
    "model.compile(optimizer='adam',loss='sparse_categorical_crossentropy',metrics=['accuracy'])"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "1d7d5829",
   "metadata": {},
   "source": [
    "##### Training ANN"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 51,
   "id": "e57261f0",
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "Epoch 1/50\n",
      "1500/1500 [==============================] - 9s 5ms/step - loss: 0.0323 - accuracy: 0.9935 - val_loss: 0.1425 - val_accuracy: 0.9712\n",
      "Epoch 2/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0266 - accuracy: 0.9950 - val_loss: 0.1302 - val_accuracy: 0.9732\n",
      "Epoch 3/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0251 - accuracy: 0.9951 - val_loss: 0.1334 - val_accuracy: 0.9739\n",
      "Epoch 4/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0260 - accuracy: 0.9950 - val_loss: 0.1273 - val_accuracy: 0.9743\n",
      "Epoch 5/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0250 - accuracy: 0.9949 - val_loss: 0.1361 - val_accuracy: 0.9732\n",
      "Epoch 6/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0208 - accuracy: 0.9961 - val_loss: 0.1403 - val_accuracy: 0.9722\n",
      "Epoch 7/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0257 - accuracy: 0.9946 - val_loss: 0.1519 - val_accuracy: 0.9710\n",
      "Epoch 8/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0209 - accuracy: 0.9958 - val_loss: 0.1390 - val_accuracy: 0.9738\n",
      "Epoch 9/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0186 - accuracy: 0.9960 - val_loss: 0.1367 - val_accuracy: 0.9743\n",
      "Epoch 10/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0211 - accuracy: 0.9957 - val_loss: 0.1270 - val_accuracy: 0.9750\n",
      "Epoch 11/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0182 - accuracy: 0.9960 - val_loss: 0.1389 - val_accuracy: 0.9728\n",
      "Epoch 12/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0163 - accuracy: 0.9967 - val_loss: 0.1435 - val_accuracy: 0.9728\n",
      "Epoch 13/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0167 - accuracy: 0.9967 - val_loss: 0.1392 - val_accuracy: 0.9738\n",
      "Epoch 14/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0164 - accuracy: 0.9968 - val_loss: 0.1287 - val_accuracy: 0.9756\n",
      "Epoch 15/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0193 - accuracy: 0.9959 - val_loss: 0.1393 - val_accuracy: 0.9740\n",
      "Epoch 16/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0139 - accuracy: 0.9974 - val_loss: 0.1398 - val_accuracy: 0.9742\n",
      "Epoch 17/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0164 - accuracy: 0.9966 - val_loss: 0.1560 - val_accuracy: 0.9714\n",
      "Epoch 18/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0168 - accuracy: 0.9966 - val_loss: 0.1527 - val_accuracy: 0.9739\n",
      "Epoch 19/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0143 - accuracy: 0.9973 - val_loss: 0.1468 - val_accuracy: 0.9736\n",
      "Epoch 20/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0160 - accuracy: 0.9967 - val_loss: 0.1503 - val_accuracy: 0.9732\n",
      "Epoch 21/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0158 - accuracy: 0.9969 - val_loss: 0.1437 - val_accuracy: 0.9753\n",
      "Epoch 22/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0137 - accuracy: 0.9973 - val_loss: 0.1525 - val_accuracy: 0.9738\n",
      "Epoch 23/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0139 - accuracy: 0.9970 - val_loss: 0.1539 - val_accuracy: 0.9733\n",
      "Epoch 24/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0130 - accuracy: 0.9976 - val_loss: 0.1434 - val_accuracy: 0.9750\n",
      "Epoch 25/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0069 - accuracy: 0.9989 - val_loss: 0.1653 - val_accuracy: 0.9715\n",
      "Epoch 26/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0163 - accuracy: 0.9966 - val_loss: 0.1473 - val_accuracy: 0.9753\n",
      "Epoch 27/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0128 - accuracy: 0.9973 - val_loss: 0.1769 - val_accuracy: 0.9690\n",
      "Epoch 28/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0134 - accuracy: 0.9974 - val_loss: 0.1419 - val_accuracy: 0.9753\n",
      "Epoch 29/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0123 - accuracy: 0.9975 - val_loss: 0.1516 - val_accuracy: 0.9742\n",
      "Epoch 30/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0094 - accuracy: 0.9983 - val_loss: 0.1609 - val_accuracy: 0.9741\n",
      "Epoch 31/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0099 - accuracy: 0.9981 - val_loss: 0.1425 - val_accuracy: 0.9757\n",
      "Epoch 32/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0129 - accuracy: 0.9975 - val_loss: 0.1597 - val_accuracy: 0.9747\n",
      "Epoch 33/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0119 - accuracy: 0.9975 - val_loss: 0.1449 - val_accuracy: 0.9750\n",
      "Epoch 34/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0113 - accuracy: 0.9975 - val_loss: 0.1415 - val_accuracy: 0.9756\n",
      "Epoch 35/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0085 - accuracy: 0.9984 - val_loss: 0.1463 - val_accuracy: 0.9748\n",
      "Epoch 36/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0132 - accuracy: 0.9974 - val_loss: 0.1412 - val_accuracy: 0.9766\n",
      "Epoch 37/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0095 - accuracy: 0.9982 - val_loss: 0.1687 - val_accuracy: 0.9734\n",
      "Epoch 38/50\n",
      "1500/1500 [==============================] - 8s 5ms/step - loss: 0.0132 - accuracy: 0.9973 - val_loss: 0.1579 - val_accuracy: 0.9733\n",
      "Epoch 39/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0103 - accuracy: 0.9981 - val_loss: 0.1495 - val_accuracy: 0.9758\n",
      "Epoch 40/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0109 - accuracy: 0.9979 - val_loss: 0.1607 - val_accuracy: 0.9742\n",
      "Epoch 41/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0124 - accuracy: 0.9976 - val_loss: 0.1576 - val_accuracy: 0.9748\n",
      "Epoch 42/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0112 - accuracy: 0.9977 - val_loss: 0.1526 - val_accuracy: 0.9756\n",
      "Epoch 43/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0095 - accuracy: 0.9984 - val_loss: 0.1561 - val_accuracy: 0.9748\n",
      "Epoch 44/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0103 - accuracy: 0.9979 - val_loss: 0.1605 - val_accuracy: 0.9739\n",
      "Epoch 45/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0091 - accuracy: 0.9983 - val_loss: 0.1454 - val_accuracy: 0.9759\n",
      "Epoch 46/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0094 - accuracy: 0.9981 - val_loss: 0.1517 - val_accuracy: 0.9758\n",
      "Epoch 47/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0061 - accuracy: 0.9990 - val_loss: 0.1442 - val_accuracy: 0.9768\n",
      "Epoch 48/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0125 - accuracy: 0.9976 - val_loss: 0.1571 - val_accuracy: 0.9741\n",
      "Epoch 49/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0081 - accuracy: 0.9984 - val_loss: 0.1559 - val_accuracy: 0.9758\n",
      "Epoch 50/50\n",
      "1500/1500 [==============================] - 7s 5ms/step - loss: 0.0112 - accuracy: 0.9977 - val_loss: 0.1702 - val_accuracy: 0.9736\n"
     ]
    }
   ],
   "source": [
    "history = model.fit(x_train,y_train,validation_split=0.2,epochs=50)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 52,
   "id": "f3d60808",
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "313/313 [==============================] - 1s 3ms/step\n"
     ]
    }
   ],
   "source": [
    "y_pred = model.predict(x_test)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 53,
   "id": "8ac27dc5",
   "metadata": {},
   "outputs": [],
   "source": [
    "y_pred = y_pred.argmax(axis=1)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 54,
   "id": "959c43f5",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "array([7, 2, 1, ..., 4, 5, 6], dtype=int64)"
      ]
     },
     "execution_count": 54,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "y_pred"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "5e73169c",
   "metadata": {},
   "source": [
    "### Checking accuracy"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 55,
   "id": "e69fc10f",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "0.9764"
      ]
     },
     "execution_count": 55,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    " from sklearn.metrics import accuracy_score\n",
    " accuracy_score(y_test,y_pred)   "
   ]
  },
  {
   "cell_type": "markdown",
   "id": "d7212c9d",
   "metadata": {},
   "source": [
    "### Plotting Accuracy"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 56,
   "id": "a9f4d4cb",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "Text(0.5, 1.0, 'Accuracy')"
      ]
     },
     "execution_count": 56,
     "metadata": {},
     "output_type": "execute_result"
    },
    {
     "data": {
      "image/png": "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\n",
      "text/plain": [
       "<Figure size 432x288 with 1 Axes>"
      ]
     },
     "metadata": {
      "needs_background": "light"
     },
     "output_type": "display_data"
    }
   ],
   "source": [
    "plt.plot(history.history['loss'])\n",
    "plt.plot(history.history['val_loss'])\n",
    "plt.title(\"Accuracy\")"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 57,
   "id": "ab75e562",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "[<matplotlib.lines.Line2D at 0x1a267d56940>]"
      ]
     },
     "execution_count": 57,
     "metadata": {},
     "output_type": "execute_result"
    },
    {
     "data": {
      "image/png": "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\n",
      "text/plain": [
       "<Figure size 432x288 with 1 Axes>"
      ]
     },
     "metadata": {
      "needs_background": "light"
     },
     "output_type": "display_data"
    }
   ],
   "source": [
    "plt.plot(history.history['accuracy'])\n",
    "plt.plot(history.history['val_accuracy'])"
   ]
  },
  {
   "cell_type": "markdown",
   "id": "3dd9a26a",
   "metadata": {},
   "source": [
    "### Testing predicted results"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 58,
   "id": "fc35c559",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "<matplotlib.image.AxesImage at 0x1a2679f4f70>"
      ]
     },
     "execution_count": 58,
     "metadata": {},
     "output_type": "execute_result"
    },
    {
     "data": {
      "image/png": "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\n",
      "text/plain": [
       "<Figure size 432x288 with 1 Axes>"
      ]
     },
     "metadata": {
      "needs_background": "light"
     },
     "output_type": "display_data"
    }
   ],
   "source": [
    "plt.imshow(np.squeeze(x_test[10]))"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 64,
   "id": "a1877b49",
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "0\n"
     ]
    }
   ],
   "source": [
    "print(y_pred[10])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 62,
   "id": "ee7b0d30",
   "metadata": {},
   "outputs": [
    {
     "data": {
      "text/plain": [
       "<matplotlib.image.AxesImage at 0x1a267af9f10>"
      ]
     },
     "execution_count": 62,
     "metadata": {},
     "output_type": "execute_result"
    },
    {
     "data": {
      "image/png": "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\n",
      "text/plain": [
       "<Figure size 432x288 with 1 Axes>"
      ]
     },
     "metadata": {
      "needs_background": "light"
     },
     "output_type": "display_data"
    }
   ],
   "source": [
    "plt.imshow(np.squeeze(x_test[100]))"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 63,
   "id": "9692e2b0",
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "6\n"
     ]
    }
   ],
   "source": [
    "print(y_pred[100])"
   ]
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3 (ipykernel)",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.9.7"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 5
}
