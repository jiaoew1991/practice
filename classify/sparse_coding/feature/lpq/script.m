 LPQfilters=createLPQfilters(9);
 Files = dir(fullfile('E:\\test\\','*.jpg'));
 file = fopen('E:\\train_C', 'w');
 LengthFiles = length(Files);
 for i = 1:LengthFiles;
 	img = imread(strcat('E:\\test\\',Files(i).name));
 	gray_img = rgb2gray(img);
 	charOri=charOrientation(gray_img);
    LPQhist=ri_lpq(gray_img,LPQfilters,charOri);
    fprintf(file, '+1 ');
    arrayLength = length(LPQhist);
    for j = 1:arrayLength;
        fprintf(file, '%d:%.10f ', j, LPQhist(j));
    end
    fprintf(file, '\n');
    disp(i);
 end
 fclose(file);
