from grabber import Webcam
from collections import Counter
import PIL
from PIL import Image,ImageDraw
import time
from math import sqrt
from numpy import mean
from numpy import subtract
from scipy.cluster.vq import vq,kmeans
import numpy

webcam = Webcam()

image = webcam.grab_image()
#image.show()
#http://www.cs.uregina.ca/Links/class-info/325/PythonPictures/ 

#http://stackoverflow.com/questions/12062920/how-do-i-create-an-image-in-pil-using-a-list-of-rgb-tuples
def grass(image):
    #first = list(image.getdata())
    box = (0,260,1024,768)
    region = image.crop(box)
    second = list(region.getdata())
    b = []
    for stuff in second:
        if stuff[1] > stuff[2]+25 and stuff[0]+25:
            a = (stuff[0]-25,stuff[2]-25,stuff[1]+100)
            #a = (0,0,255)
            b.append(a)
        else:
            b.append(stuff)
    im2 = PIL.Image.new(image.mode, region.size)
    im2.putdata(b)
    image.paste(im2,box)
    image.show()
            
def motion(image):
        image.show()
        time.sleep(2)
        x2 = webcam.grab_image()
        x2.show()

        a = list(image.getdata())
        b = list(x2.getdata())
                
        u = []
        contrast = []
        for i in range(len(a)):
            diff = tuple((subtract(b[i],a[i])))
            difference = tuple((subtract(b[i],a[i]))**2)
            euclid = sqrt((abs(sum(difference))))
            if euclid > 100:
                u.append(diff)
                contrast.append((255,255,255))
            else:
                u.append(b[i])
                contrast.append((0,0,0))
                
        im2 = PIL.Image.new(image.mode, image.size)
        im2.putdata(u)
        im2.show()

        im3 = PIL.Image.new(image.mode, image.size)
        im3.putdata(contrast)
        im3.show()
        pix = im3.load()

        box = (0,275,1000,668)
        region = im3.crop(box)
        print region.size
        
        other = []
        for x in xrange(region.size[0]):
            for y in xrange(region.size[1]):
                pix[x,y] = (pix[x, y][0], pix[x, y][1], pix[x, y][2])
                if pix[x,y][1] == 255 and pix[x,y][2] == 255:
                    other.append((x,y))
                else:
                    pass
                
        data = numpy.array(other)
        k = input('Enter k:')
        center, alpha = kmeans(data,k)

        r = 25
        ry = 50
        draw = ImageDraw.Draw(im2)
        for stuff in center:
            draw.ellipse((stuff[0]-r,stuff[1]-ry,stuff[0]+r,stuff[1]+ry))
        im2.show()
        

def kluster(image):
        image.show()
        time.sleep(2)
        x2 = webcam.grab_image()
        x2.show()

        a = (image.load())
        b = (x2.load())

        contrast = []
        for x in xrange(image.size[0]):
            for y in xrange(image.size[1]):
                a[x,y] = (a[x, y][0], a[x, y][1], a[x, y][2])
                b[x,y] = (b[x, y][0], b[x, y][1], b[x, y][2])
                difference = tuple((subtract(a[x,y],b[x,y]))**2)
                print difference

                euclid = sqrt(abs(sum(difference)))
                if euclid > 0:
                    contrast.append((difference))
                else:
                    contrast.append((255,255,255))


        im2 = PIL.Image.new(image.mode, image.size)
        im2.putdata(contrast)
        im2.show()

        data = numpy.array(contrast)
        k = input('Enter k:')
        center, alpha = kmeans(data,k)
        print center

        r = 50
        draw = ImageDraw.Draw(image)
        for stuff in center:
            draw.ellipse((stuff[0]-r,stuff[1]-r,stuff[0]+r,stuff[1]+r))
        image.show()
        print stuff


#grass(image)
#motion(image)
kluster(image)
