function [ output_args ] = writeModel( imageDir, Da, Db, outputFile, pos, feature )
%WRITEMODEL Summary of this function goes here
%   Detailed explanation goes here
Files = dir(fullfile(imageDir, '*.jpg'));
file = fopen(outputFile, 'a');
LengthFiles = length(Files);

for i = 1:LengthFiles;
    daVector = calculate(strcat(imageDir, Files(i).name), Da, 5, 8, feature);
    dbVector = calculate(strcat(imageDir,  Files(i).name), Db, 5, 8, feature);
    row = vertcat(daVector, dbVector);

    fprintf(file, pos);
    fprintf(file, ' ');
    
    arrayLength = length(row);
    for j = 1:arrayLength;
        fprintf(file, '%d:%.10f ', j, row(j));
    end
    fprintf(file, '\n');

    disp(i);
end

fclose(file);

end

