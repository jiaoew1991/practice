function [ output, newWidth, newHeight ] = scalaImage( imagePath )
%SCALAIMAGE Summary of this function goes here
%   Detailed explanation goes here
IMAGE_MAX_SIZE = 300;

img = imread(imagePath);
[width, height, channel] = size(img);
if width > height
    ratio = IMAGE_MAX_SIZE / width;
else
    ratio = IMAGE_MAX_SIZE / height;
end
newWidth = int32(ratio * width);
newHeight = int32(ratio * height);
output = imresize(img, ratio);

end

