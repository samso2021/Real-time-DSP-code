%
% example11_3.m - MATLAB script for Example 11.3
%   This routine generates 8-bit gamma table
%
%
% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

clear;
RGB = imread('example11.3.bmp');   % Read the image in
figure(1), image(RGB);             % Display the original image
title('Origianl BMP Image');       

[height, width, color]=size(RGB);
gamma=2.2;                         % Default to 2.20 for Window PC

x=0:255;                           % 256 linear input data
y=power(x, 1/gamma);               % Generate x^1/gamma
gammaTable = floor(255*y/y(256));  % Normalize and make 8-bit gamma table

figure(2), plot(gammaTable); grid; % Display gamma curve
title('8-bit gamma curve');

fid=fopen('gammaTable.txt', 'w');  % Open file to write

fprintf(fid, 'char gammaTable[256]={%4d,\n\r',gammaTable(1));
for i=2:255
   fprintf(fid,'%4d,\n\r',gammaTable(i));
end
fprintf(fid,'%4d};\n\r',gammaTable(256));

fclose(fid);                      % Close file


R = RGB(:,:,1);                   % Get the R, G, andB from RGB array
G = RGB(:,:,2);
B = RGB(:,:,3);

for i=1:height                    % Apply gamma correction to R, G, and B
    for j=1:width
      if R(i,j) > 0
         Rgamma(i,j) = gammaTable(R(i,j));
      else
         Rgamma(i,j) = 0;
      end
    
      if G(i,j) > 0
         Ggamma(i,j) = gammaTable(G(i,j));
      else
         Ggamma(i,j) = 0;
      end
    
      if B(i,j) > 0
         Bgamma(i,j) = gammaTable(B(i,j));
      else
         Bgamma(i,j) = 0;
      end
    end
end

RGBgamma(:,:,1) = Rgamma;
RGBgamma(:,:,2) = Ggamma;
RGBgamma(:,:,3) = Bgamma;
RGBgamma = uint8(RGBgamma);              
figure(3), image(RGBgamma);       % Display gamma corrected image 
title('Gamma Corrected RGB Image');


