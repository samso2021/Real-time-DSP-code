%
% example11_7.m - MATLAB script for Example 11.7
%   This routine is a 1-D DCT/iDCT demo program
%
%
% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd




%%%%%%%%%%%%%%%%%%%%%%%%%%%% DCT %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear;
RGB = imread('example11.7.jpg');            % Read the image in
fid = fopen('dctFile.dat', 'w');
[imHeight imwidth color] = size(RGB);       % Get image dimensions

YCbCr = rgb2ycbcr(RGB);                     % Converts to YCbCr color space
Y = double(YCbCr(:,:,1));                   % Change to YUV space 
U = double(YCbCr(:,:,2))-128;
V = double(YCbCr(:,:,3))-128;

for n=1:8:imHeight                         % Each block is 8 pixels in height
  for m=1:8:imwidth                        % Each block is 8 pixels in width
    for i=0:7
      for j=0:7
        mbY(i+1,j+1) = Y(n+i,m+j,1);       % Form 8x8 micro-block for Y          
        mbU(i+1,j+1) = U(n+i,m+j,1);       % Form 8x8 micro-block for U     
        mbV(i+1,j+1) = V(n+i,m+j,1);       % Form 8x8 micro-block for V     
      end
    end
    
    mbY = dct(double(mbY));                % Perform 1-D DCT horizontally          
    mbY = dct(double(mbY'));               % Perform 1-D DCT vertically          
    mbU = dct(double(mbU));                % Perform 1-D DCT horizontally          
    mbU = dct(double(mbU'));               % Perform 1-D DCT vertically          
    mbV = dct(double(mbV));                % Perform 1-D DCT horizontally          
    mbV = dct(double(mbV'));               % Perform 1-D DCT vertically          
    oY = int16(mbY);  
    oU = int16(mbU);  
    oV = int16(mbV);      
    fwrite(fid, oY, 'int16');  
    fwrite(fid, oU, 'int16');  
    fwrite(fid, oV, 'int16');  
    
  end
end

fclose(fid);                              % Close DCT data file

%%%%%%%%%%%%%%%%%%%%%%%%%%%% iDCT %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fid = fopen('dctFile.dat', 'r');          % Open DCT data file to read
dctData = fread(fid, inf, 'int16');       % Read DCT data in
dctData = int16(dctData);

k = 1;
for n=1:8:imHeight
  for m=1:8:imwidth
      
    for j=1:8
      for i=1:8
         imbY(i,j) = dctData(k);
         k = k+1;
      end
    end
    for j=1:8
      for i=1:8
        imbU(i,j) = dctData(k);
        k = k+1;
      end
    end
    for j=1:8
      for i=1:8
       imbV(i,j) = dctData(k);
       k = k+1;
      end
    end

    imbY = idct(double(imbY));            % 1-D iDCT horizontally
    imbY = idct(double(imbY'));           % 1-D iDCT vertically
    imbU = idct(double(imbU));            % 1-D iDCT horizontally
    imbU = idct(double(imbU'));           % 1-D iDCT vertically
    imbV = idct(double(imbV));            % 1-D iDCT horizontally
    imbV = idct(double(imbV'));           % 1-D iDCT vertically

    for i=0:7
      for j=0:7
        iY(n+i,m+j) = imbY(i+1,j+1);
        iU(n+i,m+j) = imbU(i+1,j+1);
        iV(n+i,m+j) = imbV(i+1,j+1);
      end
    end
    
  end
end

newYCbCr(:,:,1) = uint8(round(iY));      % Form YCbCr data format  
newYCbCr(:,:,2) = uint8(round(iU) + 128);
newYCbCr(:,:,3) = uint8(round(iV) + 128);

newRGB = ycbcr2rgb(newYCbCr);            % Convert YCbCr to RGB color space

err = RGB - newRGB;

figure (1), imshow(RGB);                 % Show the original image
title('The original image');

figure (2), imshow(newRGB);              % Show the reconstructed image
title('The DCT/IDCT reconstructed image');

figure (3), plot(err(:,:,1), 'red');	% Show the error in R
title('The error of R');
figure (4), plot(err(:,:,2), 'green');	% Show the error in G
title('The error of G');
figure (5), plot(err(:,:,3), 'blue');	% Show the error in B
title('The error of B');

fclose(fid);							% Close DCT data file
delete .\\dctFile.dat;
