function [ output ] = calculate( imagePath, D, T, patchSize )
%CALCULATE Summary of this function goes here
%   Detailed explanation goes here

% image = imread(imagePath);
[targetImg, width, height] = scalaImage(imagePath);
uWidth = (width - patchSize + 1);
uHeight = (height - patchSize + 1);
patchMatrix = zeros(patchSize * patchSize, uWidth * uHeight);

printf('%d, %d', uWidth, uHeight);

for i = 1:uWidth
    for j = 1:uHeight
        tmp = patchImage(targetImg, i, j);
        patchMatrix(:, (i -1) * uHeight + j) = tmp(:);
    end
end
gamma = omp(D' * patchMatrix, D' * D, T);

output = full(sum(gamma, 2));

end

