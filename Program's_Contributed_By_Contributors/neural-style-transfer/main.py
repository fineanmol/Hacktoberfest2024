from torchvision import models
from torchvision import transforms
from PIL import Image
import argparse
import torch
import torchvision
import torch.nn as nn
import numpy as np
from types import SimpleNamespace

config = SimpleNamespace()
config.folder = "Ballet\\"
config.content = config.folder + 'content.jpg'
config.style = config.folder + 'style.jpg'
config.max_size = 400
config.total_step = 2000
config.log_step = 10 #10
config.sample_step = 50 #500
config.style_weight = 2000
config.lr = 0.05

# Device configuration
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

class PretrainedNet(nn.Module):
    def __init__(self):
        """Select conv1_1 ~ conv5_1 activation maps."""
        super(PretrainedNet, self).__init__()
        #FIRST LAYERS
        #self.select = [5, 10, 17, 21, 28] #set of selected feature maps
        
        self.select = [5, 10, 14, 21, 28]
        self.select = [str(el) for el in self.select]
        self.pretrainedNet = models.vgg19(pretrained=True).features
        
    def forward(self, x):
        """Extract multiple (5 is good) convolutional feature maps."""
        features = []
        
        for name, layer in self.pretrainedNet._modules.items():
            #print(name, layer)
            x = layer(x)
            if name in self.select:
                features.append(x)
        return features
    
def load_image(image_path, transform=None, max_size=None, shape=None):
    """Load an image and convert it to a torch tensor."""
    image = Image.open(image_path)
    
    if max_size:
        scale = max_size / max(image.size)
        size = np.array(image.size) * scale
        image = image.resize(size.astype(int), Image.ANTIALIAS)
    
    if shape:
        image = image.resize(shape, Image.LANCZOS)
    
    if transform:
        image = transform(image).unsqueeze(0)
    
    return image.to(device)

transform = transforms.Compose([transforms.ToTensor(), transforms.Normalize(mean=(0.485, 0.456, 0.406), std=(0.229, 0.224, 0.225))])

content = load_image(config.content, transform, max_size=config.max_size)
style = load_image(config.style, transform, shape=[content.size(2), content.size(3)])

target = content.clone().requires_grad_(True)
optimizer = torch.optim.Adam([target], lr=config.lr)
net = PretrainedNet().to(device).eval()# Initialize your pretrained neural net and don't forget to put it in evaluation mode.

for step in range(config.total_step):
    # Extract multiple(5) feature maps
        
    target_features = net(target)
    content_features = net(content)
    style_features = net(style)

    style_loss = 0
    content_loss = 0
    
    for f1, f2, f3 in zip(target_features, content_features, style_features):
        # Compute content loss with target and content images
        content_loss += torch.mean((f1 - f2)**2)

        # Reshape convolutional feature maps
        _, c, h, w = f1.size()
        #print(f1.shape, f2.shape, f3.shape)
        f1 = f1.view(c, h * w)
        f3 = f3.view(c, h * w)

        # Compute gram matrix

        target_gram = torch.mm(f1, f1.t())
        style_gram = torch.mm(f3, f3.t())
        style_loss += torch.sum((target_gram - style_gram)**2) / (4 * (c * h * w) ** 2)
        #print(style_loss)
        
    # Compute total loss, backprop and optimize (4 lines of code in total)
    loss = content_loss + config.style_weight * style_loss
    
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

    # Output
    if (step+1) % config.log_step == 0:
        # Change this print into a log with tensorboardx
        print ('Step [{}/{}], Content Loss: {:.4f}, Style Loss: {:.4f}' 
               .format(step+1, config.total_step, content_loss.item(), style_loss.item()))

    if (step+1) % config.sample_step == 0:
        # Save the generated image (you can also change it to see it with tensorboardx)
        denorm = transforms.Normalize((-2.12, -2.04, -1.80), (4.37, 4.46, 4.44))
        img = target.clone().squeeze()
        img = denorm(img).clamp_(0, 1)
        torchvision.utils.save_image(img, config.folder + 'output-{}.png'.format(step+1))