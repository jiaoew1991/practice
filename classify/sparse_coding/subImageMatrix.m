function[ output ] = subImageMatrix( subImageMatrix, patchSize )

[width, height] = size(subImageMatrix);
uWidth = width - patchSize + 1;
uHeight = height - patchSize + 1;
patchMatrix = zeros(patchSize * patchSize, uWidth * uHeight);

for i = 1:uWidth
    for j = 1:uHeight
        tmp = patchImage(subImageMatrix, i, j);
        patchMatrix(:, (i -1) * uHeight + j) = tmp(:);
    end
end

output = patchMatrix;

end
