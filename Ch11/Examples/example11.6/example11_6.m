%
% example11_6.m - MATLAB script for Example 11.6
%   This routine uses 2-D filter in frequncy domain for image filter 
%
%
%
% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

clear;
delta_filt = [0  0  0  0  0  0  0  0  0; ...  % Delat filter
              0  0  0  0  0  0  0  0  0; ...
              0  0  0  0  0  0  0  0  0; ...
              0  0  0  0  0  0  0  0  0; ...
              0  0  0  0  1  0  0  0  0; ...
              0  0  0  0  0  0  0  0  0; ...
              0  0  0  0  0  0  0  0  0; ...
              0  0  0  0  0  0  0  0  0; ...
              0  0  0  0  0  0  0  0  0];            

edge_filt = [-1 -1 -1 -1 -1 -1 -1 -1 -1; ... % Edge filter
             -1 -1 -1 -1 -1 -1 -1 -1 -1; ...
             -1 -1  1  1  1  1  1 -1 -1; ...
             -1 -1  1  1  1  1  1 -1 -1; ...
             -1 -1  1  1 31  1  1 -1 -1; ...
             -1 -1  1  1  1  1  1 -1 -1; ...
             -1 -1  1  1  1  1  1 -1 -1; ...
             -1 -1 -1 -1 -1 -1 -1 -1 -1; ...
             -1 -1 -1 -1 -1 -1 -1 -1 -1];                          

motion_filt = [1  0  0  0  0  0  0  0  0; ... % Motion filter
               0  1  0  0  0  0  0  0  0; ...
               0  0  1  0  0  0  0  0  0; ...
               0  0  0  1  0  0  0  0  0; ...
               0  0  0  0  1  0  0  0  0; ...
               0  0  0  0  0  1  0  0  0; ...
               0  0  0  0  0  0  1  0  0; ...
               0  0  0  0  0  0  0  1  0; ...
               0  0  0  0  0  0  0  0  1]/9;                          

gaussian_filt = [0  0  0  0  0  0  0  0  0; ... % Gaussian filter
                 0  0  0  0  0  0  0  0  0; ...
                 0  0  1  4  6  4  1  0  0; ...
                 0  0  4 16 24 16  4  0  0; ...
                 0  0  6 24 36 24  6  0  0; ...
                 0  0  4 16 24 16  4  0  0; ...
                 0  0  1  4  6  4  1  0  0; ...
                 0  0  0  0  0  0  0  0  0; ...
                 0  0  0  0  0  0  0  0  0]/256;                          


RGB1 = imread('example11.6.jpg');   % Read the image in
RGB=padarray(RGB1,[8,8],0, 'post'); % Padding 8 rows and 8 columns zeros at the end
fft2R = fft2(double(RGB(:,:,1)));  % 2-D FFT of R component
fft2G = fft2(double(RGB(:,:,2)));  % 2-D FFT of G component
fft2B = fft2(double(RGB(:,:,3)));  % 2-D FFT of B component

[imHeight imWidth] = size(fft2R);  % Find image width and height

figure(1), image(RGB);             % Display the original image
title('Origianl JPEG Image');      

for i=2:5
    if i == 2                      % Load filter
        filt = delta_filt;
    elseif i == 3
        filt = edge_filt;
    elseif i == 4
        filt = motion_filt;
    else
        filt = gaussian_filt;
    end

    fft2Filt = fft2(filt, imHeight, imWidth);  % 2-D FFT of filter kernel

    fft2FiltR = fft2Filt .* fft2R;             % 2-D fast convolution
    fft2FiltG = fft2Filt .* fft2G;
    fft2FiltB = fft2Filt .* fft2B;

    newRGB(:,:,1) = uint8(ifft2(fft2FiltR));   % Inverse 2-D FFT of R component
    newRGB(:,:,2) = uint8(ifft2(fft2FiltG));   % Inverse 2-D FFT of G component
    newRGB(:,:,3) = uint8(ifft2(fft2FiltB));   % Inverse 2-D FFT of B component

    figure(i), image(newRGB);                  % Display filtered image 
	if 0
    if i == 2                                  % Find which filter was used
        title('Delta Filtered Image');
    elseif i == 3
        title('edge Filtered Image');
    elseif i == 4
        title('Motion Filtered Image');
    else
        title('Gaussian Filtered Image');
    end
end
end

