%
% example11_8.m - MATLAB script for Example 11.8
%   This routine is a 2-D DWT/iDWT demo program
%
% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

%%%%%%%%%%%%%%%%%%%%%%%%%%%% 2D DWT %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The current extension mode is zero-padding (see dwtmode).
clear;
[X,map] = imread('example11.8.bmp'); % Read the image in

% Map contains the loaded colormap. 
nbcol = size(map,1);

% generate Decomposition and Reconstruction filter coefficients
[L_D,H_D,L_R,H_R] = wfilters('db2'); % Lowpass decomposite, highpass decomposite
                                     %   lowpass reconstruction, and highpass reconstruction

% Perform single-level decomposition 
[LL,LH,HL,HH] = dwt2(X,L_D,H_D);	% 2-D DWT

% Images coding
dec2d = [... 
        LL,     LH;     ... 
        HL,     HH      ... 
        ];
% Construction filter
LL = zeros(size(LL));              % Zero out the LL

% Reconstruct the image
Y = idwt2(LL,LH,HL,HH,L_R,H_R);    % Inverse 2-D DWT

% Make the image B&W
[height, width] = size(X);
for i=1:height
  for j=1:width
    if Y(i,j) < 42
      Y(i,j) = 10;
    else
      Y(i,j) = 240;
    end
  end
end

% Plotting
figure;
clf
imagesc(X);
axis equal
axis off
colormap(gray(128));
title('The original image');

figure;
imagesc(dec2d) ;
axis equal
axis off
colormap(gray(128));
title('Decomposed image');

figure;
imagesc(Y); 
axis equal
axis off
colormap(gray(128));
title('Reconstructed image without the LL subband');
