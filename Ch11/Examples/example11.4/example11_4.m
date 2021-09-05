%
% example11_4.m - MATLAB script for Example 11.4
%   This routine generates 8-bit image histogram and eqaulizes the image
%
% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

clear;
RGB = imread('example11.4.jpg');    % Read the image in
[height, width, color] = size(RGB); % Get the width and height
len = 256;

YCbCr = rgb2ycbcr(RGB);             % RGB to YCbCr conversion

Y = double(YCbCr(:,:,1));           % Get Y only

hist = zeros(1,len);
hist2 = imhist(uint8(Y));           % Use MATLAB built-in histogram func

for i=1:height                      % Compute histogram of image
    for j=1:width              
        index = uint8((Y(i,j))+1);
        hist(index) = hist(index) + 1;
    end
end

imageSize = width * height;         % Create equalize look up table
eqFactor = 255 / imageSize;         
sum = 0;
for i=1:len
    sum = sum + hist(i);
    eqValue = sum * eqFactor;
    if eqValue > 255;               % Limit upper data
        eqValue = 255;
    end    
    eqTable(i) = uint8(eqValue);
end

for i=1:height                      % Image equalization, new Y       
    for j=1:width              
        index = uint8((Y(i,j))+1);
        newY(i,j) = eqTable(index);
    end
end

newY2 = histeq(uint8(Y),256);       % Use MATLAB built-in histeq funciton

newYCbCr(:,:,1) = newY;
newYCbCr(:,:,2) = YCbCr(:,:,2);
newYCbCr(:,:,3) = YCbCr(:,:,3);
newYCbCr2(:,:,1) = newY2;
newYCbCr2(:,:,2) = YCbCr(:,:,2);
newYCbCr2(:,:,3) = YCbCr(:,:,3);

newRGB  = ycbcr2rgb(newYCbCr);
newRGB2 = ycbcr2rgb(newYCbCr2);

Y   = double(newYCbCr(:,:,1));     % Example result
Y2  = double(newYCbCr2(:,:,1));    % Result from MATLAB function

newHist  = zeros(1,len);
newHist2  = zeros(1,len);

for i=1:height                     % Compute new image histogram
    for j=1:width              
        index = uint8((Y(i,j))+1);
        newHist(index) = newHist(index) + 1;
        index = uint8((Y2(i,j))+1);
        newHist2(index) = newHist2(index) + 1;        
    end
end

figure(1), image(RGB);             % Display the original image
title('Origianl JPEG Image');      

figure(2), image(newRGB);          % Display equalized image 
title('Equalized Image');

figure(3), image(newRGB2);         % Display MATLAB equalized image 
title('Equalized Image Using MATLAB histeq');


x = 0:len-1;

figure(4), subplot(2,1,1);
imhist(YCbCr(:,:,1));
title('Histograms of original image');

figure(4), subplot(2,1,2);
imhist(newY); 
title('Histograms equalized image');

figure(5), subplot(2,1,1);
imhist(newY2); 
title('MATLAB histeq equalized');

