%
% example11_1.m - MATLAB script for Example 11.1
%   This routine converts RGB color space data to YCbCr color space
%
%
% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

clear;
% Read in R,G, and B data
fid = fopen('Sunset800x600R8.RGB','r');
R=fread(fid);
fclose(fid);
fid = fopen('Sunset800x600G8.RGB','r');
G=fread(fid);
fclose(fid);
fid = fopen('Sunset800x600B8.RGB','r');
B=fread(fid);
fclose(fid);

% Form the RGB color space
RGB = cat(3, reshape(R, 800, 600)', ...
             reshape(G, 800, 600)', ...
             reshape(B, 800, 600)');

% Convert double to uint8
RGB = uint8(RGB);

% Show original RGB image
figure, imshow(RGB),  title('Origianl RGB Image');

% RGB to YCbCr conversion
YCbCr = rgb2ycbcr(RGB);

% Show Y component of YCbCr data
figure, imshow(YCbCr(:,:,1)),  title('Y of the YCbCr Image');

% Write 8-bit data out to files
fid=fopen('Sunset800x600Y8.dat', 'wb');
fwrite(fid, YCbCr(:,:,1)', 'uint8');  % Write Y
fclose(fid);
fid=fopen('Sunset800x600Cb8.dat', 'wb');
fwrite(fid, YCbCr(:,:,2)', 'uint8');  % Write Cb
fclose(fid);
fid=fopen('Sunset800x600Cr8.dat', 'wb');
fwrite(fid, YCbCr(:,:,3)', 'uint8');  % Write Cr
fclose(fid);

% Read back 8-bit YCbCr data 
fid=fopen('Sunset800x600Y8.dat', 'rb');
Y = fread(fid, inf, 'uint8');		% Read Y
fclose(fid);
fid=fopen('Sunset800x600Cb8.dat', 'rb');
Cb = fread(fid, inf, 'uint8');		% Read Cb
fclose(fid);
fid=fopen('Sunset800x600Cr8.dat', 'rb');
Cr = fread(fid, inf, 'uint8');		% Read Cr
fclose(fid);

Y = Y/255;
Cb = Cb/255;
Cr = Cr/255;
YCbCr1 = cat(3, reshape(Y, 800, 600)', ...
                reshape(Cb, 800, 600)', ...
                reshape(Cr, 800, 600)');
RGB1 = ycbcr2rgb(YCbCr1);
RGB1 = uint8(RGB1*255);

% Show images
figure, imshow(RGB1), title('The RGB->YCbCr->RGB Converted Image');

    
