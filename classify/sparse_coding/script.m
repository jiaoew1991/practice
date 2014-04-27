%  LPQfilters=createLPQfilters(9);
originTrainDir = '/Users/jiaoew/workspace/practice/classify/test/origin/';
recaptureTrainDir = '/Users/jiaoew/workspace/practice/classify/test/recapture/';
Da = gendict(originTrainDir);
Db = gendict(recaptureTrainDir);

Files = dir(fullfile(originTrainDir, '*.jpg'));
file = fopen('train', 'w');
LengthFiles = length(Files);
for i = 1:LengthFiles;
    daVector = calculate(strcat(originTrainDir, Files(i).name), Da, 5, 8);
    dbVector = calculate(strcat(originTrainDir,  Files(i).name), Db, 5, 8);
    row = vertcat(daVector, dbVector);

    fprintf(file, '+1 ');
    arrayLength = length(row);
    for j = 1:arrayLength;
        fprintf(file, '%d:%.10f ', j, row(j));
    end
    fprintf(file, '\n');

    disp(i);
end

Files = dir(fullfile(recaptureTrainDir, '*.jpg'));
LengthFiles = length(Files);
for i = 1:LengthFiles;
    daVector = calculate(strcat(recaptureTrainDir, Files(i).name), Da, 5, 8);
    dbVector = calculate(strcat(recaptureTrainDir,  Files(i).name), Db, 5, 8);
    row = vertcat(daVector, dbVector);

    fprintf(file, '-1 ');
    arrayLength = length(row);
    for j = 1:arrayLength;
        fprintf(file, '%d:%.10f ', j, row(j));
    end
    fprintf(file, '\n');

    disp(i);
end

fclose(file);
