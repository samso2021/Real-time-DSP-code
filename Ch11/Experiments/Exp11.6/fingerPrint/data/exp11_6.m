% Exp11_6.m - show resized BMP images

resize = 16;
RGB = imread('fingerprint64x64.bmp');           % Read the image in
figure;
imshow(imresize(RGB, resize));
xlabel('Original fingerprint image');

RGB2 = imread('2_Graystretch.bmp');		% Read the image in
figure;
imshow(imresize(RGB2, resize))
xlabel('Gray stretch result');

RGB4 = imread('5_Binarization.bmp');		% Read the image in
figure;
imshow(imresize(RGB4, resize))
xlabel('Binarization result');

RGB6 = imread('6_Thinning.bmp');		% Read the image in
figure;
imshow(imresize(RGB6, resize))
xlabel('Thinning result');