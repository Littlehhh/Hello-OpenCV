import cv2
import numpy as np
import matplotlib
matplotlib.use("Qt5Agg")
from matplotlib import pyplot as plt

"""
img = cv2.imread('blurred.png')
img.shape
img.size
img.all()
img.view()
plt.show()
cv2.imshow('lena',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
"""

img = cv2.imread('test.jpg')
#img2 = cv2.cvtColor(img,cv2.COLOR_BGR2RGB)

#b,g,r = cv2.split(img)
#img2 = cv2.merge([r,g,b])

img2 = img[:,:,::-1]  #numpy ways
# three ways for BGR2RGB
img2
plt.imshow(img2)
plt.show()
