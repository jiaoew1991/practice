function [ output ] = calculate( imagePath, D, T, patchSize )
%CALCULATE Summary of this function goes here
%   Detailed explanation goes here

% image = imread(imagePath);
[targetImg, width, height] = scalaImage(imagePath);
%uWidth = (width - patchSize + 1);
%uHeight = (height - patchSize + 1);

patchMatrix = subImageMatrix(targetImg, patchSize);
patchMatrix2_1 = subImageMatrix(targetImg(1:width/2, 1:height/2), patchSize);
patchMatrix2_2 = subImageMatrix(targetImg((width/2 + 1):width, 1:height/2), patchSize);
patchMatrix2_3 = subImageMatrix(targetImg(1:width/2, (height/2 + 1):height), patchSize);
patchMatrix2_4 = subImageMatrix(targetImg((width/2 + 1):width, (height/2 + 1):height), patchSize);

patchMatrix3_1 = subImageMatrix(targetImg(1:width/3, 1:height/3), patchSize);
patchMatrix3_2 = subImageMatrix(targetImg((width/3 + 1):(width - width/3), 1:height/3), patchSize);
patchMatrix3_3 = subImageMatrix(targetImg((width - width/3+1):width, 1:height/3), patchSize);

patchMatrix3_4 = subImageMatrix(targetImg(1:width/3, (height/3+1):(height-height/3)), patchSize);
patchMatrix3_5 = subImageMatrix(targetImg((width/3 + 1):(width - width/3), (height/3+1):(height-height/3)), patchSize);
patchMatrix3_6 = subImageMatrix(targetImg((width - width/3+1):width, (height/3+1):(height-height/3)), patchSize);

patchMatrix3_7 = subImageMatrix(targetImg(1:width/3, (height-height/3+1):height), patchSize);
patchMatrix3_8 = subImageMatrix(targetImg((width/3 + 1):(width - width/3), (height-height/3+1):height), patchSize);
patchMatrix3_9 = subImageMatrix(targetImg((width - width/3+1):width, (height-height/3+1):height), patchSize);

%for i = 1:uWidth
    %for j = 1:uHeight
        %tmp = patchImage(targetImg, i, j);
        %patchMatrix(:, (i -1) * uHeight + j) = tmp(:);
    %end
%end
gamma = omp(D' * patchMatrix, D' * D, T);
vec = full(max(gamma, [], 2));

gamma = omp(D' * patchMatrix2_1, D' * D, T);
vec = vertcat(vec, full(max(gamma, [], 2)));
gamma = omp(D' * patchMatrix2_2, D' * D, T);
vec = vertcat(vec, full(max(gamma, [], 2)));
gamma = omp(D' * patchMatrix2_3, D' * D, T);
vec = vertcat(vec, full(max(gamma, [], 2)));
gamma = omp(D' * patchMatrix2_4, D' * D, T);
vec = vertcat(vec, full(max(gamma, [], 2)));

gamma = omp(D' * patchMatrix3_1, D' * D, T);
vec = vertcat(vec, full(max(gamma, [], 2)));
gamma = omp(D' * patchMatrix3_2, D' * D, T);
vec = vertcat(vec, full(max(gamma, [], 2)));
gamma = omp(D' * patchMatrix3_3, D' * D, T);
vec = vertcat(vec, full(max(gamma, [], 2)));
gamma = omp(D' * patchMatrix3_4, D' * D, T);
vec = vertcat(vec, full(max(gamma, [], 2)));
gamma = omp(D' * patchMatrix3_5, D' * D, T);
vec = vertcat(vec, full(max(gamma, [], 2)));
gamma = omp(D' * patchMatrix3_6, D' * D, T);
vec = vertcat(vec, full(max(gamma, [], 2)));
gamma = omp(D' * patchMatrix3_7, D' * D, T);
vec = vertcat(vec, full(max(gamma, [], 2)));
gamma = omp(D' * patchMatrix3_8, D' * D, T);
vec = vertcat(vec, full(max(gamma, [], 2)));
gamma = omp(D' * patchMatrix3_9, D' * D, T);
vec = vertcat(vec, full(max(gamma, [], 2)));

output = vec;
end
