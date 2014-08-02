originTrainDir = '/Users/jiaoew/workspace/practice/classify/test/origin/';
recaptureTrainDir = '/Users/jiaoew/workspace/practice/classify/test/recapture/';

Da = genlbpdict(originTrainDir);
Db = genlbpdict(recaptureTrainDir);

writeModel(originTrainDir, Da, Db, 'train', '+1', 'lbp8_1');
writeModel(recaptureTrainDir, Da, Db, 'train', '-1', 'lbp8_1');
