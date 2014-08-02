function [ output_args ] = genlbpdict( image_dir )
%%GENDICT Summary of this function goes here
%   Detailed explanation goes here
RANDOM_NUM = 200;
PATCH_SIZE = 8;
SPARSITY = 5;

images = dir(fullfile(image_dir, '*.jpg'));
% images = images(3:length(images));

dataMatrix = zeros(PATCH_SIZE * PATCH_SIZE, length(images) * RANDOM_NUM);
mapping = getmapping(8, 'riu2');

for i=1:length(images)
%     printf('%s', strcat(image_dir, images(i).name));
    [targetImg, newWidth, newHeight] = scalaImage(strcat(image_dir, images(i).name));
    
    lbpImg = lbp(targetImg, 1, 8, mapping, 'i');
    [newWidth, newHeight] = size(lbpImg);
    newWidth = int32(newWidth);
    newHeight = int32(newHeight);
    
    randPointX = randi([1, newWidth - PATCH_SIZE + 1], 1, RANDOM_NUM);
    randPointY = randi([1, newHeight - PATCH_SIZE + 1], 1, RANDOM_NUM);
    for j=1:RANDOM_NUM
        patchMatrix = patchImage(lbpImg, randPointX(j), randPointY(j));
%         dataMatrix = [dataMatrix;patchMatrix(:)'];
        dataMatrix(:, (i - 1)*RANDOM_NUM + j) = patchMatrix(:);
    end
end

params.data = dataMatrix;
params.Tdata = SPARSITY;
params.dictsize = 50;
params.iternum = 30;
params.memusage = 'high';
[Dksvd,g,err] = ksvd(params,'');
output_args = Dksvd;
end

