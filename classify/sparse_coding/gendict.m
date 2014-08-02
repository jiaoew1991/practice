function [ output_args ] = gendict( image_dir, varargin )
%GENDICT Summary of this function goes here
%   Detailed explanation goes here
RANDOM_NUM = 200;
PATCH_SIZE = 8;
SPARSITY = 5;

images = dir(fullfile(image_dir, '*.jpg'));
% images = images(3:length(images));

mode = 'normal';
if nargin > 1
    mode = varargin{1};
end

dataMatrix = zeros(PATCH_SIZE * PATCH_SIZE, length(images) * RANDOM_NUM);

lpqFilters = createLPQfilters(9);

for i=1:length(images)
%     printf('%s', strcat(image_dir, images(i).name));
    [tmpImg, newWidth, newHeight] = scalaImage(strcat(image_dir, images(i).name));
    if strcmp(mode, 'normal') 
        targetImg = tmpImg;
    elseif strcmp(mode, 'lpq')
        charOri = charOrientation(tmpImg);
        targetImg = ri_lpq(tmpImg, lpqFilters, charOri, 'im');
        [newWidth, newHeight] = size(targetImg);
        newWidth = int32(newWidth);
        newHeight = int32(newHeight);
    end
    randPointX = randi([1, newWidth - PATCH_SIZE + 1], 1, RANDOM_NUM);
    randPointY = randi([1, newHeight - PATCH_SIZE + 1], 1, RANDOM_NUM);
    for j=1:RANDOM_NUM
        patchMatrix = patchImage(targetImg, randPointX(j), randPointY(j));
%         dataMatrix = [dataMatrix;patchMatrix(:)'];
        dataMatrix(:, (i - 1)*RANDOM_NUM + j) = patchMatrix(:);
    end
end

params.data = dataMatrix;
params.Tdata = SPARSITY;
params.dictsize = 500;
params.iternum = 30;
params.memusage = 'high';
[Dksvd,g,err] = ksvd(params,'');
output_args = Dksvd;
end

