rimg = imread('../test/origin/im91_c.jpg');
rimg = rgb2gray(rimg);
cimg = imread('../test/recapture/im92_tc.jpg');
cimg = rgb2gray(cimg);

mapping1 = getmapping(8, 'riu2');
mapping2 = getmapping(16, 'riu2');
mapping3 = getmapping(24, 'riu2');

lbprimg = lbp(rimg, 4, 24, mapping3, 'i');
lbpcimg = lbp(cimg, 4, 24, mapping3, 'i');

histr = imhist(lbprimg);
histc = imhist(lbpcimg);

x = [1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26];
% bar(x-.2, histr(1:18), .4, 'b');
% hold
% bar(x+.2, histc(1:18), .4, 'r');

axes1 = axes('YGrid','on','FontSize',14);
%% Uncomment the following line to preserve the X-limits of the axes
% xlim(axes1,[0 11]);
box(axes1,'on');
hold(axes1,'all');

% Create bar
bar(x-0.2,histr(1:26),'FaceColor',[0 0 1],'BarWidth',0.4,...
    'DisplayName','原始图像');

% Create bar
bar(x+0.2,histc(1:26),...
    'FaceColor',[0.800000011920929 0.800000011920929 0.800000011920929],...
    'BarWidth',0.4,...
    'Parent',axes1,...
    'DisplayName','翻拍图像');

% Create xlabel
xlabel('lbp统计','FontSize',20);

% Create ylabel
ylabel({'个数'},'FontSize',20);