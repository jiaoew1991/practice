originTrainDir = '/Users/jiaoew/workspace/practice/classify/test/origin/';
recaptureTrainDir = '/Users/jiaoew/workspace/practice/classify/test/recapture/';

Da = gendict(originTrainDir, 'lpq');
Db = gendict(recaptureTrainDir, 'lpq');

writeModel(originTrainDir, Da, Db, 'train', '+1', 'lpq');
writeModel(recaptureTrainDir, Da, Db, 'train', '-1', 'lpq');
