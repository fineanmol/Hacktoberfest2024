# -*- coding: utf-8 -*-
"""3D Object Detection Classifier
Program by : Swayamshree Mohanty 
Github : https://github.com/Swayms-stack
"""

# Commented out IPython magic to ensure Python compatibility.
!pip install trimesh
import os
import glob    # The glob module finds all the pathnames matching a specified pattern according to the rules used by the Unix shell
import trimesh    # loading and using triangular meshes which allow for easy manipulation and analysis, in the style of the Polygon object
import numpy as np
import tensorflow as tf      # numerical computation and large-scale machine learning
from tensorflow import keras         # Keras is a powerful easy-to-use Python library for developing and evaluating deep learning models
from tensorflow.keras import layers    
from matplotlib import pyplot as plt
!pip install tqdm
from tqdm import *         # tqdm progress bar not only shows how much time has elapsed, but also shows the estimated time remaining for the iterable

tf.random.set_seed(1234)
# %matplotlib inline

# 3D object detection classifier used is Kaolin framework

!git clone https://github.com/gkadusumilli/kaolin_1.git

# Commented out IPython magic to ensure Python compatibility.
'''Kaolin is an open-source PyTorch library developed by a team of NVIDIA, aimed at accelerating 3D deep learning research.
Kaolin framework converts the 3D models into deep learning datasets with few lines of code. '''

# %cd /content/kaolin_1/Documents/kaolin-0.1
!python setup.py build_ext --inplace

DATA_DIR = tf.keras.utils.get_file(
    "modelnet.zip",
    "http://3dvision.princeton.edu/projects/2014/3DShapeNets/ModelNet10.zip",
    extract=True,
)
DATA_DIR = os.path.join(os.path.dirname(DATA_DIR), "ModelNet10")

mesh = trimesh.load(os.path.join(DATA_DIR, "chair/train/chair_0001.off"))
mesh.show()

mesh = trimesh.load(os.path.join(DATA_DIR, "bed/train/bed_0001.off"))
mesh.show()

import torch
from torch.utils.data import DataLoader
!pip install pptk
import kaolin as kal
from kaolin import ClassificationEngine
from kaolin.datasets import ModelNet
from kaolin.models.PointNet import PointNetClassifier
import kaolin.transforms as tfs
from torchvision.transforms import Lambda

# model_path the variable will hold the path to the ModelNet10 dataset
modelnet_path = os.path.join(os.path.dirname(DATA_DIR), "ModelNet10")
print(modelnet_path)
# categories variable to specify which classes we want to learn to classify
categories = ['chair', 'sofa', 'bed','night_stand']
# num_points is the number of points we will sample from the mesh when transforming it to a point cloud
num_points=1024
device='cuda'   # disable multiprocessing and memory pinning
workers = 8

#training parameters
batch_size = 12
learning_rate = 1e-3
epochs = 10

'''This command defines a transform that first converts a mesh representation to a point cloud and then normalizes it to be centered at the origin, 
and has a standard deviation of 1. 
Much like images, 3D data such as point clouds need to be normalized for better classification performance.'''

def to_device(inp):
    inp.to(device)
    return inp

transform = tfs.Compose([
    to_device,
    tfs.TriangleMeshToPointCloud(num_samples=num_points),
    tfs.NormalizePointCloud()
])

num_workers = 0 if device == 'cuda' else workers
pin_memory = device != 'cuda'

# split='train' argument indicates that the 'train' split is loading.
train_loader = DataLoader(ModelNet(modelnet_path, categories=categories,
                                   split='train', transform=transform),
                          batch_size=batch_size, shuffle=True, 
                          num_workers=num_workers, pin_memory=pin_memory)

val_loader = DataLoader(ModelNet(modelnet_path, categories=categories,
                                 split='test',transform=transform),
                        batch_size=batch_size, num_workers=num_workers,
                        pin_memory=pin_memory)

# Setting up our model, optimizer, and loss criterion
model = PointNetClassifier(num_classes=len(categories)).to(device)
optimizer = torch.optim.Adam(model.parameters(), lr=learning_rate)
criterion = torch.nn.CrossEntropyLoss()

# Training & Validating the PointNet classifier 
# 3D object detection classifier using Kaolin
for e in range(epochs):
    print(f'{"":-<10}\nEpoch: {e}\n{"":-<10}')

    train_loss = 0.
    train_accuracy = 0.

    model.train()
    for batch_idx, (data, attributes) in enumerate(tqdm(train_loader)):
        category = attributes['category'].to(device)
        pred = model(data)
        loss = criterion(pred, category.view(-1))
        train_loss += loss.item()
        loss.backward()
        optimizer.step()
        optimizer.zero_grad()

        # Compute accuracy
        pred_label = torch.argmax(pred, dim=1)
        train_accuracy += torch.mean((pred_label == category.view(-1)).float()).item()

    print('Train loss:', train_loss / len(train_loader))
    print('Train accuracy:', train_accuracy / len(train_loader))

    val_loss = 0.
    val_accuracy = 0.

    model.eval()
    with torch.no_grad():
        for batch_idx, (data, attributes) in enumerate(tqdm(val_loader)):
            category = attributes['category'].to(device)
            pred = model(data)
            loss = criterion(pred, category.view(-1))
            val_loss += loss.item()

            # Compute accuracy
            pred_label = torch.argmax(pred, dim=1)
            val_accuracy += torch.mean((pred_label == category.view(-1)).float()).item()

    print('Val loss:', val_loss / len(val_loader))
    print('Val accuracy:', val_accuracy / len(val_loader))

# Evaluating the trained 3D object detection model on test data
'''A new data loader that will load the same data as the previous val_loader 
 but with shuffling, and taking a sample batch is created.'''
test_loader = DataLoader(ModelNet(modelnet_path, categories=categories,
                                  split='test',transform=transform),
                        shuffle=True, batch_size=15)

data, attr = next(iter(test_loader))
data = data.to('cuda')
labels = attr['category'].to('cuda')
preds = model(data)
pred_labels = torch.max(preds, axis=1)[1]

# Commented out IPython magic to ensure Python compatibility.
'''A plot to visualize the point cloud, ground-truth label, and the prediction using a small visualization function.
color-coded the results — green for correct and red for incorrect.'''
color-coded the results — green for correct and red for incorrect.
from mpl_toolkits.mplot3d import Axes3D     # import necessary to have access to 3d projection 
import matplotlib.pyplot as plt
# %matplotlib inline


def visualize_batch(pointclouds, pred_labels, labels, categories):
    batch_size = len(pointclouds)
    fig = plt.figure(figsize=(8, batch_size / 2))

    ncols = 5
    nrows = max(1, batch_size // 5)
    for idx, pc in enumerate(pointclouds):
        label = categories[labels[idx].item()]
        pred = categories[pred_labels[idx]]
        colour = 'g' if label == pred else 'r'
        pc = pc.cpu().numpy()
        ax = fig.add_subplot(nrows, ncols, idx + 1, projection='3d')
        ax.scatter(pc[:, 0], pc[:, 1], pc[:, 2], c=colour, s=2)
        ax.axis('off')
        ax.set_title('GT: {0}\nPred: {1}'.format(label, pred))

    plt.show()
visualize_batch(data, pred_labels, labels, categories)

# GT- Ground Truth, Pred- Prediction.