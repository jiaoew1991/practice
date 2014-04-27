function [ patchMatrix ] = patchImage ( image, x, y )

patchMatrix = image(x:x+7, y:y+7);

end
